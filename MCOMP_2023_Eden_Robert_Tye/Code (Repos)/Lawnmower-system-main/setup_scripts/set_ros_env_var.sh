#!/bin/bash 
server_ip=192.168.1.31 #Set this ip to the ip address that will act as our discovery server that is on the ROS Robot's LAN
server_port=11811
#adds the ROS2 Discovery Server ip and port address to the ROS environment variables
export ROS_DISCOVERY_SERVER=$server_ip:$server_port