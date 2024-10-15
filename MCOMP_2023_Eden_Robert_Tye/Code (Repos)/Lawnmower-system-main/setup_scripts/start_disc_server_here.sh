#!/bin/bash
server_ip=192.168.1.31 #Set this ip to the ip address that will act as our discovery server that is on the ROS Robot's LAN
server_port=11811
#starts a fast discovery server in this terminal
fastdds discovery --server-id 0 --ip-address $server_ip --port $server_port