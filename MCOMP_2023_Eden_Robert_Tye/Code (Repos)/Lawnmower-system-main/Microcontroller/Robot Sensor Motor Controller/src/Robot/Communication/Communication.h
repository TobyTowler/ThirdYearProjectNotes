#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Arduino.h>
#include "Robot/RobotConfig.h"


namespace Communication
{
    // Robot Serial object used for data communication
    extern HardwareSerial* robotSerial; // By default uses Arduino Frameworks default serial object

    // Comm connection check vars
    extern bool connected;
    extern long lastCheck;

    // command related vars
    extern char cmd_seg[CMD_ARG_LEN][ARG_LEN_MAX]; // Example: cmd_seg[0] = cmd (m - move, r - read IMU), cmd_seg[1] = arg1 (Motor1), , cmd_seg[2] = arg2 (Motor2)
    extern bool newCmd;

    // print the CMD (if we have one) to the serial monitor
    void printCMD();

    // clear the CMD contents
    void clearCommand();

    // read a CMD from the serial monitor (if serial is available)
    void readCommand();

    // check if serial available and update the conn
    //  still alive related vars and handle dead connection if appropiate
    bool isCommAlive();
}

#endif
