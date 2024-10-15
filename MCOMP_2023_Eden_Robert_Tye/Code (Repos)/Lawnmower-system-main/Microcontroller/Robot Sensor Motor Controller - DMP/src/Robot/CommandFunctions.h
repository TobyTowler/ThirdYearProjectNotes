#ifndef COMMAND_FUNCTIONS_H
#define COMMAND_FUNCTIONS_H

#include <arduino.h>
#include "Robot/IMU/IMU.h"
#include "Robot/Motors/Motors.h"
#include "Robot/Communication/Communication.h"
#include "Robot/Orientation.h"

void cmdPrintIMUData(){
    EulerAngles angles;
    IMU::getOrientationAngles(&angles);
//     Serial.println("Controller: IMU DATA");
    Serial.print(angles.heading, 6);
    Serial.print(", ");
    Serial.print(angles.pitch, 6);
    Serial.print(", ");
    Serial.println(angles.roll, 6);
    Serial.println();
//     Serial.print("Controller: IMU UPDATE RATE: ");
//     Serial.print(IMU::fusionFilter.invSampleFreq, 8); // This requires the changing the adafruit library so that the variable is public accessible 
//     Serial.print(", ");
//     Serial.println(IMU::FILTER_UPDATE_RATE_HZ, 8);
//     Serial.print("Controller: IMU FILTER (Kp, Ki): ");
//     Serial.print(IMU::fusionFilter.getKp(), 8);
//     Serial.print(", ");
//     Serial.println(IMU::fusionFilter.getKi(), 8);
}

/// @brief Print the Orientation quaternion, the gyroscope's angular velocity (in rad/s) and the IMU's accelerometer data (in m/s^2) to the serial port
void cmdPrintEKFIMUData(){
    Quaternion rotation;
    float ax, ay, az, gx, gy, gz;

    IMU::getEKFData(&rotation, &ax, &ay, &az, &gx, &gy, &gz);

    Serial.print(rotation.w, 6);
    Serial.print(",");
    Serial.print(rotation.x, 6);
    Serial.print(",");
    Serial.print(rotation.y, 6);
    Serial.print(",");
    Serial.print(rotation.z, 6);
    Serial.print(",");
    Serial.print(gx, 6);
    Serial.print(",");
    Serial.print(gy, 6);
    Serial.print(",");
    Serial.print(gz, 6);
    Serial.print(",");
    Serial.print(ax, 6);
    Serial.print(",");
    Serial.print(ay, 6);
    Serial.print(",");
    Serial.print(az, 6);
    Serial.println();
}

void cmdPrintRobotData(){
        Serial.println("Controller: CURRENT MOTORS RPM");
        Serial.print("Left Motor: ");
        Serial.print(Motors::motorCurrentRPML);
        Serial.print(" ||| Right Motor: ");
        Serial.print(Motors::motorCurrentRPMR);
        Serial.println();
        Serial.println("Controller: TARGET MOTORS RPM");
        Serial.print("Left Motor: ");
        Serial.print(Motors::motorTargetRPML);
        Serial.print(" ||| Right Motor: ");
        Serial.print(Motors::motorTargetRPMR);
        Serial.println();
        Serial.println("Controller: CURRENT MOTORS PWM");
        Serial.print("Left Motor: ");
        Serial.print(Motors::motorPWML);
        Serial.print(" ||| Right Motor: ");
        Serial.print(Motors::motorPWMR);
        Serial.println();
        Serial.println("Controller: MOTORS DIRECTION");
        Serial.print("Left Motor: ");
        Serial.print(Motors::motorTargetDirL);
        Serial.print(" ||| Right Motor: ");
        Serial.print(Motors::motorTargetDirR);
        Serial.println();
        Serial.println("Controller: CURRENT MOTORS ENCODER COUNT");
        Serial.print("Left Motor: ");
        Serial.print(Motors::motorCountL);
        Serial.print(" ||| Right Motor: ");
        Serial.print(Motors::motorCountR);
        Serial.println();
}

void cmdTunePID(){
        Serial.print("Controller: OLD PID tuning values:\n");
        Serial.print("kd:");
        Serial.print(Motors::kd, 6);
        Serial.print(" ki:");
        Serial.print(Motors::ki, 6);
        Serial.print(" kd:");
        Serial.print(Motors::kd, 6);
        Serial.println();
        Serial.println(atoff(Communication::cmd_seg[1]), 6);

        Motors::tunePID(atoff(Communication::cmd_seg[1]), atoff(Communication::cmd_seg[2]), atoff(Communication::cmd_seg[3]));

        Serial.print("Controller: NEW PID tuning values:\n");
        Serial.print("kd:");
        Serial.print(Motors::kd, 6);
        Serial.print(" ki:");
        Serial.print(Motors::ki, 6);
        Serial.print(" kd:");
        Serial.print(Motors::kd, 6);
        Serial.println();
}
#endif