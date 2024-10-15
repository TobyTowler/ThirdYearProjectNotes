# Resources:
# - https://docs.ros.org/en/humble/Concepts/About-ROS-Interfaces.html#field-types
# - https://docs.ros.org/en/humble/Tutorials/Intermediate/Writing-an-Action-Server-Client/Py.html
# - https://github.com/ros2/demos/tree/humble/action_tutorials/action_tutorials_py
# - https://github.com/ros2/examples/tree/humble/rclpy/actions
# - https://github.com/ros2/examples/blob/humble/rclpy/actions/minimal_action_server/examples_rclpy_minimal_action_server/server_single_goal.py
# - 

import asyncio
import serial
import threading
import time

import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node

from robot_interfaces.action import RobotCMD

# Single goals processing action server
class RobotControllerBridgeServer(Node):
    def __init__(self):
        super().__init__('robot_controller_bridge_action_server')
        self._goal_handle = None
        self._goal_lock = threading.Lock()
        self._action_server = ActionServer(
            self,
            RobotCMD,
            'RobotBridge', # need to be the same as client
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            handle_accepted_callback=self.handle_accepted_callback,
            cancel_callback=self.cancel_callback,
            callback_group=ReentrantCallbackGroup()
        )
        self.serial_recv = None
        
        # create a microcontroller object that connect to the robot for 
        # commanding the motor and getting imu data
        self.microcontroller = serial.Serial()
        # Set the Port and Baudrate 
        self.microcontroller.port = '/dev/ttyUSB0'
        self.microcontroller.baudrate = 115200
        self.microcontroller.timeout = 0.2 # timeout after 0.5 second
        # open the serial port connection
        self.microcontroller.open()
        # check if serial port is open successfully
        if (not self.microcontroller.isOpen()):
            # close the node as the serial port connection could be made
            # by throwing a system exit exception to exit 'rclpy.spin()'
            # Inspiration src: https://answers.ros.org/question/406469/ros-2-how-to-quit-a-node-from-within-a-callback/?answer=406554
            self.get_logger().info('Serial port failed to open. Exiting.')
            raise SystemExit
        self.get_logger().info('Serial port opened Successfully')

    def destroy(self):
        self._action_server.destroy()
        self.microcontroller.close()
        super().destroy_node()
    
    def goal_callback(self, goal_request):
        # Accept a client request to begin an action
        self.get_logger().info('Received goal request')
        return GoalResponse.ACCEPT

    def handle_accepted_callback(self, goal_handle):
        with self._goal_lock:
            # This server only allows one goal at a time
            # Check if we have a goal and if it is active 
            if self._goal_handle is not None and self._goal_handle.is_active:
                self.get_logger().info('Aborting previous goal')
                # Abort the existing goal
                self._goal_handle.abort()
            # set new goal 
            self._goal_handle = goal_handle
        # execute new goal
        goal_handle.execute()

    def cancel_callback(self, goal):
        # Accept a client request to cancel an action
        self.get_logger().info('Received cancel request')
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')

        # get CMD parts from goal request and build command to send
        cmd = "{0} {1} {2} {3}\n".format(
            chr(goal_handle.request.cmd_chr),
            str(goal_handle.request.arg1),
            str(goal_handle.request.arg2),
            str(goal_handle.request.arg3)
        )
        # print received command
        self.get_logger().info("Received CMD: {0}".format(cmd))
        
        # create the write loop
        # write_loop = asyncio.get_event_loop()

        # send CMD (Encode string for serial writing)
        # write_loop.run_until_complete(self.send_write_cmd(cmd))
        self.send_write_cmd(cmd)
        
        # Return Result
        result = RobotCMD.Result()
        result.data_string = self.serial_recv
        self.get_logger().info("Sending Result: {0}".format(result))
        # Goal succeeds
        goal_handle.succeed()
        return result

    def send_write_cmd(self, strCmd):
        self.microcontroller.write(str(strCmd).encode())
        
        # await asyncio.sleep(0.01)
        time.sleep(0.01)

        # read any data from the serial port that we received after sending the command
        #self.serial_recv = self.microcontroller.readline().decode()
        self.serial_recv = self.serial_read()

    def serial_read(self):
        # Read from the serial port until no more data is received
        data = b''
        while True:
            temp_data = self.microcontroller.read(10)
            if len(temp_data) == 0:
                break
            data += temp_data
        return data.decode()
        


def main(args=None):
    rclpy.init(args=args)

    try:
        robot_controller_bridge_action_server = RobotControllerBridgeServer()

        # We use a MultiThreadedExecutor to handle incoming goal requests concurrently
        executor = MultiThreadedExecutor()

        # start the node
        rclpy.spin(robot_controller_bridge_action_server)
        
        # # cleanup code
        # robot_controller_bridge_action_server.destroy()
        # rclpy.shutdown()
    
    except SystemExit: # Process the node termination
        rclpy.logging.get_logger("Quitting").info('Done')


if __name__ == '__main__':
    main()