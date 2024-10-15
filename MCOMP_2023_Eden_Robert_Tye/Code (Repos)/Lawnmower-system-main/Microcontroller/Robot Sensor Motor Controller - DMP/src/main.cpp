#include <Arduino.h>
#include <HardwareSerial.h>

#include "Robot/Communication/Communication.h"
#include "Robot/Motors/Motors.h"
#include "Robot/IMU/IMU.h"
#include "Robot/RobotConfig.h"
#include "Robot/CommandFunctions.h"
#include "Robot/Utility/RobotMovementUtil.h"

#include "GeneralUtility/utility.h"

//#define DEBUG_MESSAGES

#define LED_PIN 2

// HardwareSerial echoSerial(2);

/// @brief call to process any new cmd so we can determine the robot's action(s) required to complete the request
void processCMD(){
  //check that a new cmd was received before trying to process the cmd segments (Args)
  if (Communication::newCmd)
  {
    // Serial.println("CMD RECEIVED");
    //check which command was sent and process accordingly
    switch ((char)*Communication::cmd_seg[0])
    {

      case 'c': // c - Clear the robots tracking values
        // Serial.println("Controller: Clearing motors");
        RobotActions::robotClearValues();
        break;
      case 'm': // (NO LONGER FUNCTIONAL) m - motors : Set L and R motors to drive at speeds, arg1, arg 2
        // Serial.println("Controller: SET MOTORS TARGET RPM SPEED");
        Motors::setMotorSpeedsRPM(atoi(Communication::cmd_seg[1]), atoi(Communication::cmd_seg[2]));
        break;
      case 'd': // d - Move a specific amount of distance (mm) at a set RPM 
        // Serial.println("Controller: SET Target distance to travel");
        // reset current motor counts
        Motors::motorCountL = 0;
        Motors::motorCountR = 0;
        // get the target distance in encoder counts
        RobotActions::TargetLocationCounts = RobotActions::convertMilliToCounts(atoi(Communication::cmd_seg[2]));
        RobotActions::isMovingDistance = true;
        Motors::setMotorSpeedsRPM(atoi(Communication::cmd_seg[1]), atoi(Communication::cmd_seg[1]));
        break;
      case 'r': // r - Rotate on the spot by specific amount
        // Serial.println("Controller: SET Target amount that we want to rotate");
        IMU::getOrientationAngles(&RobotActions::startOrientationFrame);
        RobotActions::setTargetOrientationFrame(atof(Communication::cmd_seg[2]));
        RobotActions::isMovingRotating = true;
        // Serial.println("Controller: Start  Heading:");
        // Serial.println(RobotActions::startOrientationFrame.heading);
        
        Motors::setMotorSpeedsRPM(
          -atoi(Communication::cmd_seg[1]) * RobotActions::CCW,
           atoi(Communication::cmd_seg[1]) * RobotActions::CCW);
        break;
      case 'b': // b - Rotate on the spot to a specific bearing (TODO: Can still be optimised to rotate the shortest direction to the target)
        // Serial.println("Controller: SET Target bearing to rotate to");
        IMU::getOrientationAngles(&RobotActions::startOrientationFrame);
        // get the rotation amount needed to rotate to the CMD passed target heading        
        RobotActions::targetOrientationFrame.heading = atof(Communication::cmd_seg[2]);
        RobotActions::isMovingRotating = true;        
        // Serial.println("Controller: Start  Heading:");
        // Serial.println(RobotActions::startOrientationFrame.heading);
        
        Motors::setMotorSpeedsRPM(
          -atoi(Communication::cmd_seg[1]) * RobotActions::CCW,
           atoi(Communication::cmd_seg[1]) * RobotActions::CCW);
        break;
      case 's': // s - Print various information about the current state of the robot variables 
        cmdPrintRobotData();
        Serial.println("Controller: Target Count:");
        Serial.print(RobotActions::TargetLocationCounts);
        Serial.println();
        Serial.println("Controller: Current Rotation:");
        Serial.print(RobotActions::currentOrientationFrame.heading);
        Serial.println();
        Serial.println("Controller: Rotation Amount:");
        Serial.print(RobotActions::rotationAmount);
        Serial.println();
        Serial.println("Controller: Target Rotation:");
        Serial.print(RobotActions::targetOrientationFrame.heading);
        Serial.println();
        break;
      // case 't':
      //   cmdTunePID();
      //   break;
      case 'i': // i - IMU : Request IMU sensor data to be sent via serial
        cmdPrintIMUData();
        break;
      case 'e': // e - IMU EKF Data : Request IMU sensor data needed for the EKF with the GPS
        cmdPrintEKFIMUData();
        break;
      case 'h': // h - Halt. Halt/Stop all operation of the robot
        // Serial.println("Controller: ROBOT STOPPED");
        if(RobotActions::haltRobot()){
          Serial.println("CMD DONE");  // signal CMD action is done
        }
        break;
      case '@': // @ - get the IMU calibration data to the robot via serial at startup
          IMU_CAL_MAG_HARD_IRON[0] = atof(Communication::cmd_seg[1]);
          IMU_CAL_MAG_HARD_IRON[1] = atof(Communication::cmd_seg[2]);
          IMU_CAL_MAG_HARD_IRON[2] = atof(Communication::cmd_seg[3]);

          IMU_CAL_MAG_SOFT_IRON[0] = atof(Communication::cmd_seg[4]);
          IMU_CAL_MAG_SOFT_IRON[1] = atof(Communication::cmd_seg[5]);
          IMU_CAL_MAG_SOFT_IRON[2] = atof(Communication::cmd_seg[6]);
          IMU_CAL_MAG_SOFT_IRON[3] = atof(Communication::cmd_seg[7]);
          IMU_CAL_MAG_SOFT_IRON[4] = atof(Communication::cmd_seg[8]);
          IMU_CAL_MAG_SOFT_IRON[5] = atof(Communication::cmd_seg[9]);
          IMU_CAL_MAG_SOFT_IRON[6] = atof(Communication::cmd_seg[10]);
          IMU_CAL_MAG_SOFT_IRON[7] = atof(Communication::cmd_seg[11]);
          IMU_CAL_MAG_SOFT_IRON[8] = atof(Communication::cmd_seg[12]);

          IMU_CAL_MAG_FIELD = atof(Communication::cmd_seg[13]);

          // Serial.print(IMU_CAL_MAG_HARD_IRON[0]);
          // Serial.print(", ");
          // Serial.print(IMU_CAL_MAG_HARD_IRON[1]);
          // Serial.print(", ");
          // Serial.println(IMU_CAL_MAG_HARD_IRON[2]);
          // we have got the data ready for loading for calibration
          #if (IMU_CAL_VIA_SERIAL==true)
          cal_got = true;
          #endif
        break;
      default: // Throwaway any other command data
        break;
    }
    Communication::newCmd = false;
  }  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // echoSerial.begin(115200, SERIAL_8N1, 16, 17);
  // pinMode(LED_PIN, OUTPUT);

  #if (IMU_CAL_VIA_SERIAL==true)
    Serial.println("Waiting for calibration data (via serial) ....");
    // loop until we finish getting the calibration data
    while (!cal_got)
    {
      // reuse the read command functionality to get the calibration data via command
      Communication::readCommand();
      // try and process the cmd to get the calibration data
      processCMD();
      delay(500);
    }
    Serial.println("calibration data received (via serial)");
    // if we getting calibration data from serial to store, then we are not interested in loading the calibration data from EEPROM 
    IMU::setupIMU(250, false);
  #else
    IMU::setupIMU(250, true);
  #endif
  Motors::initMotorEncoders();
  Motors::initPIDSettings();
}

void loop() {
  //update IMU Data
  IMU::updateIMU();
  //update the PID controllers 
  Motors::updatePID();

  /*check if the serial connection is alive and signal via the builtin LED of 
  the ESP32 that the connection is alive or not (HIGH == Comms Dead)*/
  // Communication::isCommAlive() ? digitalWrite(LED_PIN, LOW) : digitalWrite(LED_PIN, HIGH);

  //Check if still connected (TODO: Current method is really inconvenient) 
  // if (Communication::connected || true){ //alway true for testing purpose.
    //set the motor speed
    Motors::updateMotorSpeed();

    // check if we are meant move, and move if so
    if(RobotActions::moveIfCan()){
      Serial.println("CMD DONE"); // signal CMD action is done
    }

    // check if we are meant rotate, and rotate if so
    if(RobotActions::rotateIfCan()){
      Serial.println("CMD DONE"); // signal CMD action is done
    }

    //Still connected and receiving data over serial
    Communication::clearCommand();
    Communication::readCommand();
    processCMD();  //processed the CMD that the robot has received
  // }else{
  //   //no serial connection detected
  //   RobotActions::haltRobot(); 
  // }
}