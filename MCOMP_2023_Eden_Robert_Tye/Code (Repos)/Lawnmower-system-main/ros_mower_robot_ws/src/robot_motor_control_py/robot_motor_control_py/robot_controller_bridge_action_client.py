# Resources:
# - https://docs.ros.org/en/humble/Tutorials/Intermediate/Writing-an-Action-Server-Client/Py.html
# - https://github.com/ros2/examples/blob/humble/rclpy/actions/minimal_action_client/examples_rclpy_minimal_action_client/client.py
# - 


import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_msgs.msg import GoalStatus

from robot_interfaces.action import RobotCMD

class RobotControllerBridgeClient(Node):
    def __init__(self):
        super().__init__('robot_controller_bridge_action_client')
        # Node to add the client too, the action type, the action name
        self._action_client = ActionClient(
            self,
            RobotCMD,
            'RobotBridge' # need to be the same as the server we want to interact with
        )
        self.goal_handle = None
        self.user_input = None
        self.shutdown = False

    def goal_response_callback(self, future):
        goal_handle = self.goal_handle.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        result_future = goal_handle.get_result_async()
        # result_future.add_done_callback(self.goal_result_callback)
        result_future.add_feedback_callback(self.feedback_callback)
    
    def feedback_callback(self, future):
        self.get_logger().info('Received feedback: {0}'.format("This action doesn't give feedback."))

    def goal_result_callback(self, future):
        goal_handle = future.result()
        if goal_handle.status == GoalStatus.STATUS_SUCCEEDED:
            result = goal_handle.result.data_string
            self.get_logger().info('Goal succeeded! Result: {0}'.format(result.data_string))
        else:
            self.get_logger().info('Goal failed with status: {0}'.format(goal_handle.status))

        # Shutdown after receiving a result
        # rclpy.shutdown()

    def send_goal(self):
        # wait for action to be available
        self._action_client.wait_for_server()
        
        # prep the goal to send
        goal_msg = RobotCMD.Goal()        
        
        # get the user input
        self._logger.info('User input: {0}'.format(self.user_input))
        # build goal:
        goal_msg.cmd_chr = ord(self.user_input[0])
        goal_msg.arg1 = float(self.user_input[1])
        goal_msg.arg2 = float(self.user_input[2])
        goal_msg.arg3 = float(self.user_input[3])
        goal_msg.arg4 = float(self.user_input[4])
        goal_msg.arg5 = float(self.user_input[5])
        goal_msg.arg6 = float(self.user_input[6])
        goal_msg.arg7 = float(self.user_input[7])
        goal_msg.arg8 = float(self.user_input[8])
        goal_msg.arg9 = float(self.user_input[9])
        goal_msg.arg10 = float(self.user_input[10])
        goal_msg.arg11 = float(self.user_input[11])
        goal_msg.arg12 = float(self.user_input[12])
        goal_msg.arg13 = float(self.user_input[13])
        goal_msg.arg14 = float(self.user_input[14])
        
        # send the user input
        self.goal_handle = self._action_client.send_goal_async(
            goal_msg,
            self.goal_response_callback)

        self.goal_handle.add_done_callback(self.goal_result_callback)

        #self._send_goal_future.add_done_callback(self.goal_response_callback)

    # get user input
    def get_user_input(self):
        user_input = input('Enter a command: ')
        # print initial user input
        self.get_logger().info('User input: {0}'.format(user_input))

        # split the input into a list using a ' ' as the separator
        user_input = user_input.split(' ')
        # make sure the user input is always a list of 15 items, and 
        #   if it is less then extend the list till it is length 15
        while len(user_input) < 15:
            user_input.append(0)

        return user_input
    
    def main_Loop(self):
        # keep running while the node is OK or is shutdown
        while not self.shutdown and rclpy.ok():
            self.user_input = self.get_user_input()
            self.get_logger().info('User input: {0}'.format(self.user_input[0]))
            if self.user_input[0].lower() == 'q' or self.user_input[0].lower() == 'quit':
                self.shutdown = True
                rclpy.shutdown()
                break
        self.send_goal()


def main(args=None):
    rclpy.init(args=args)

    action_client = RobotControllerBridgeClient()

    while not action_client.shutdown and rclpy.ok():
        action_client.user_input = action_client.get_user_input()
        if action_client.user_input[0].lower() == 'q' or action_client.user_input[0].lower() == 'quit':
            action_client.shutdown = True
            break
        else:
            action_client.send_goal()
            rclpy.spin_until_future_complete(action_client, action_client.goal_handle)
            res = action_client.goal_handle.result()
            action_client.get_logger().info('(Main) Result : {0}'.format(res))
            action_client.get_logger().info('(Main) Result <data String>: {0}'.format(res.data_string))

    # clean up the node
    # action_client.destroy_node()
    # rclpy.shutdown()



if __name__ == '__main__':
    main()