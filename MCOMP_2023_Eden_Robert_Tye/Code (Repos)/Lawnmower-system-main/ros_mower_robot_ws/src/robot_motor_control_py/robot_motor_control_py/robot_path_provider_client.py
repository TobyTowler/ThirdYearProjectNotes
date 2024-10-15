import threading
import time
import rclpy
from rclpy.node import Node
from robot_interfaces.msg import RobotSendCMD
from robot_interfaces.msg import RobotSerialReceived

import Pathing.Path_to_CMDs
import Pathing.Sample_Co_ordinates

class PathClient(Node):
    def __init__(self):
        super().__init__('serial_client')
        self.client_send = self.create_publisher(
            RobotSendCMD,
            'Robot_Bridge_CMD',
            10)
        
        self.client_read = self.create_subscription(
            RobotSerialReceived,
            'Robot_Bridge_Response',
            self.serial_received_callback,
            10
        )

        # create and start a thread which will handle sending the CMD to the robot so that i follows the planned path
        self.path_CMD_thread = threading.Thread(target=self.get_CMD)
        self.path_CMD_thread.start()

        # store the planned paths CMDs
        self.Path_CMDs = []
        # index var for knowing what CMD are currently on
        self.path_CMD_index = 0
        #var for checking if we can send the next command
        self.next_Path_CMD = True
        # var for determining is we need to interrupt the planned path
        self.path_interrupt = False

    def serial_received_callback(self, msg):
        # get the msg data
        recv_msg = msg.data
        self.get_logger().info("Serial received: %s" % recv_msg)
        # TODO: check if we did a planned CMD or a 'interrupt type' CMD
        if recv_msg == 'CMD DONE':
            # We just finish a Planned Path CMD, then...
            if self.next_Path_CMD == False:
                #signal the next path CMD and move the current CMD index to it
                self.next_Path_CMD = True
                self.path_CMD_index += 1
                
            else:
            # TODO: Handle is we just finish a NON Planned Path CMD, then...
                pass
        else:
            self.get_logger().info("CMD NOT DONE")

    def get_CMD(self):
        #TODO: get the planned path as a list of CMDs
        self.Path_CMDs = Pathing.Path_to_CMDs.generate_CMDs(Pathing.Sample_Co_ordinates.PATH_UTM)
        self.get_logger().info("Path_CMDs:\n %s" % self.Path_CMDs)
        self.get_logger().info("index:\n %s" % self.Path_CMDs[self.path_CMD_index])
        while True and self.path_CMD_index < len(self.Path_CMDs):
            # check that we can send a different CMD, eg. Correct the Robot as its off gone off course
            if self.path_interrupt:
                #TODO: Do different CMD, eg. Correct the Robot as its off gone off course
                pass
            else:
                # check that we can send the next CMD
                if self.next_Path_CMD:
                    self.get_logger().info("wait 3 secs")
                    time.sleep(3);
                    # build the command
                    cmd_msg = RobotSendCMD()
                    cmd_msg.cmd_chr = ord(self.Path_CMDs[self.path_CMD_index][0])
                    cmd_msg.arg1 = float(self.Path_CMDs[self.path_CMD_index][1])
                    cmd_msg.arg2 = float(self.Path_CMDs[self.path_CMD_index][2])
                    # cmd_msg.arg3 = int(0)
                    # send the CMD message to the bridge
                    self.client_send.publish(cmd_msg)
                    self.get_logger().info("Sent CMD message: %s" % cmd_msg)
                    self.next_Path_CMD = False

    def shutdown(self):
        # close the thread
        self.path_CMD_thread.join()
        super().shutdown()
    
def main(args=None):
    rclpy.init(args=args)
    serial_client = PathClient()
    
    try:
        rclpy.spin(serial_client)
    except KeyboardInterrupt:
        pass
    
    serial_client.destroy_node()
    rclpy.shutdown()
    
if __name__ == '__main__':
    main()
