#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>
#include "CytronMotorDriver.h"
#include "PID_v1.h"
#include "../RobotConfig.h"

namespace Motors{
    // robot motor objects
    extern CytronMD motor1; // Left Motor
    extern CytronMD motor2; // Right Motor
    // robot PID motor controllers
    extern PID leftMotorPID;    
    extern PID rightMotorPID;

    // current motor encoder counts
    extern double motorCurrentRPMR, motorPWMR;
    extern double motorTargetRPMR;

    extern double motorCurrentRPML, motorPWML;
    extern double motorTargetRPML;

    // current motor Direction
    extern bool motorCurDirR; // false->forward 
    extern bool motorCurDirL; // false->forward
    // required motor Direction
    extern int16_t motorTargetDirR; // 1->forward, -1->Backward 
    extern int16_t motorTargetDirL; // 1->forward, -1->Backward
    //last motor interrupt time
    extern long motorLastTimeR;
    extern long motorLastTimeL;
    // motor encoder counts
    extern long motorCountL;
    extern long motorCountR;

    // tuning resource guide: https://pidexplained.com/how-to-tune-a-pid-controller/
    // tuning Sim. -> http://grauonline.de/alexwww/ardumower/pid/pid.html
    //PID constants
    extern float kp;
    extern float ki;
    extern float kd;
    
    // encoder interrupt methods 
    void leftMotorInterrupt();
    void rightMotorInterrupt();

    // init the motor encoders
    void initMotorEncoders();
    // init the PID controller settings
    void initPIDSettings();
    // set the robot motors speed to the cmd arg values
    void setMotorSpeedsPWM(int16_t _motorL, int16_t _motorR);
    void setMotorSpeedsRPM(int16_t _motorL, int16_t _motorR);
    // update the motor speed to hit the target RPM from the PID (ideally called before PID update)
    void updateMotorSpeed();
    // update PID controllers for the robots track motor  
    void updatePID();
    void tunePID(float _kp, float _ki, float _kd);
}

#endif
