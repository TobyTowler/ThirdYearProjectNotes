import threading
import rclpy
from rclpy.node import Node
from robot_interfaces.msg import RobotSendCMD
from robot_interfaces.msg import RobotSerialReceived

class SerialClient(Node):
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

        # create and start a thread to receive the user input CMD
        self.input_CMD_thread = threading.Thread(target=self.get_user_input_CMD)
        self.input_CMD_thread.start()

    def serial_received_callback(self, msg):
        # get the msg data
        recv_msg = msg.data
        # print the recv_msg
        self.get_logger().info("Received: %s" % recv_msg)
    
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

    def get_user_input_CMD(self):
        while True:
            user_input = self.get_user_input()
            if user_input[0].lower() == 'q' or user_input[0].lower() == 'quit':
                break
            else:
                # check if user entered any valid command character
                if len(user_input[0]) > 0:
                    # build the command
                    cmd_msg = RobotSendCMD()
                    cmd_msg.cmd_chr = ord(user_input[0])
                    cmd_msg.arg1    = float(user_input[1])
                    cmd_msg.arg2    = float(user_input[2])
                    cmd_msg.arg3    = float(user_input[3])
                    cmd_msg.arg4    = float(user_input[4])
                    cmd_msg.arg5    = float(user_input[5])
                    cmd_msg.arg6    = float(user_input[6])
                    cmd_msg.arg7    = float(user_input[7])
                    cmd_msg.arg8    = float(user_input[8])
                    cmd_msg.arg9    = float(user_input[9])
                    cmd_msg.arg10   = float(user_input[10])
                    cmd_msg.arg11   = float(user_input[11])
                    cmd_msg.arg12   = float(user_input[12])
                    cmd_msg.arg13   = float(user_input[13])
                    cmd_msg.arg14   = float(user_input[14])

                    # send the CMD message to the bridge
                    self.client_send.publish(cmd_msg)

    def shutdown(self):
        # close the thread
        self.input_CMD_thread.join()
        super().shutdown()
    
def main(args=None):
    rclpy.init(args=args)
    serial_client = SerialClient()
    
    try:
        rclpy.spin(serial_client)
    except KeyboardInterrupt:
        pass
    
    serial_client.shutdown()
    serial_client.destroy_node()
    rclpy.shutdown()
    
if __name__ == '__main__':
    main()
