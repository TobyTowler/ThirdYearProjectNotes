# ros2 bridge node that connects to the robots serial port and sends commands to the robot which are received from a publisher

import serial

import rclpy
from rclpy.node import Node

from robot_interfaces.msg import RobotSendCMD
from robot_interfaces.msg import RobotSerialReceived

class RobotBridge(Node):
    def __init__(self):
        super().__init__('Robot_Bridge')
        # service that will be used to receive commands from the clients
        self.srv = self.create_subscription(
            RobotSendCMD, 
            'Robot_Bridge_CMD',
            self.robot_comm_callback,
            10)
        
        # publisher that will be used to send the robots serial data response back to the client
        self.serial_pub = self.create_publisher(
            RobotSerialReceived, 
            'Robot_Bridge_Response',
            10) 
        
        # Create a timer that periodically checks the serial port for any data and publishes it
        self.serial_timer = self.create_timer(0.1, self.serial_read)

        # initialize the serial port
        self.microcontroller = serial.Serial()
        # Set the Port and Baudrate 
        self.microcontroller.port = '/dev/ttyUSB2'
        self.microcontroller.baudrate = 115200
        self.microcontroller.timeout = 0.2 # timeout after 0.5 second
        
        # open the serial port connection
        self.microcontroller.open()
        #check if the microcontroller port opened successfully
        if not self.microcontroller.isOpen():
            self.get_logger().info('Could not open the microcontroller serial port')
            raise Exception('Could not open the microcontroller serial port')
        self.get_logger().info('Microcontroller serial port opened successfully')

    def robot_comm_callback(self, msg):
        cmd = '{0} {1} {2} {3}\n'.format(
            chr(msg.cmd_chr),
            str(msg.arg1),
            str(msg.arg2),
            str(msg.arg3)
        )
        self.get_logger().info('Received command from the robot: {}'.format(cmd))
        # send the command to the microcontroller
        self.microcontroller.write(cmd.encode())
    
    def serial_read(self):
        # Read from the serial port until no more data is received
        data = b''
        while True:
            temp_data = self.microcontroller.read(16)
            if len(temp_data) == 0:
                break
            data += temp_data

        # see if any data is received
        if (data != b''):
            # decode the received data and strip it of any leading and trailing whitespace before returning it
            data = data.decode().strip()
            # publish the data
            msg = RobotSerialReceived()
            msg.data = data
            self.serial_pub.publish(msg)
            
            self.get_logger().info("Published: %s" % msg.data)



#main function
def main(args=None):
    rclpy.init(args=args)

    try:
        bridge_node = RobotBridge()

        rclpy.spin(bridge_node)

        rclpy.shutdown()
    except Exception as e:
        print('Exception occurred')
        print(e)
        return
    except KeyboardInterrupt:
        pass
