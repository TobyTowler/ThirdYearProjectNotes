#ifndef ROBOT_MOVEMENT_UTIL_H
#define ROBOT_MOVEMENT_UTIL_H

#include "Robot/Communication/Communication.h"
#include "Robot/Motors/Motors.h"
#include "Robot/IMU/IMU.h"
#include "Robot/RobotConfig.h"

#include "GeneralUtility/utility.h"

namespace RobotActions
{
  /// @brief variable for stating if the robot is currently Moving a set distance
  bool isMovingDistance = false;
  /// @brief variable for stating if the robot is currently rotating
  bool isMovingRotating = false;

  /// @brief variable for storing the encoder counts that the robot need to reach to travel a specific distance
  long TargetLocationCounts = 0;

  /// @brief variable for storing the rotation amount the robot needs to rotate by
  float rotationAmount;
  /// @brief Counter-Clockwise var that used used to flip the Rotation direction. 1 : counter-clockwise, -1 : clockwise.
  int8_t CCW = -1; 
  /// @brief The robots orientation at the start of a rotation
  EulerAngles startOrientationFrame;
  /// @brief The robots current orientation
  EulerAngles currentOrientationFrame;
  /// @brief The robots target orientation at the end of a rotation
  EulerAngles targetOrientationFrame;

  bool moveIfCan();
  bool rotateIfCan();
  bool haltRobot();
  bool robotClearValues();
  long convertMilliToCounts(int32_t _milliDistance);
  void setTargetOrientationFrame(float _rotationAmount);

  /// @brief function to check if the robot should be moving (forward or backwards)
  /// @return returns true if the robot should be moving, false if the robot should not be moving
  bool moveIfCan()
  {
    if (RobotActions::isMovingDistance &&
        (abs(Motors::motorCountL) > RobotActions::TargetLocationCounts))
    {
      RobotActions::haltRobot(); // stop the robot
      Motors::motorCountL = 0;
      Motors::motorCountR = 0;
      RobotActions::TargetLocationCounts = 0;
      RobotActions::isMovingDistance = false;
      return true; // task completed
    }
    return false; // task not completed
  }

  /// @brief function to check if the robot should rotate
  /// @return returns true if the robot should rotate, false if the robot should not rotate
  bool rotateIfCan()
  {
    if (isMovingRotating)
    {
      IMU::getOrientationAngles(&RobotActions::currentOrientationFrame);
      // check if we have reached the target with an acceptable margin of error
      if (isbetween(
              RobotActions::currentOrientationFrame.heading,
              RobotActions::targetOrientationFrame.heading - ROBOT_ROTATE_ACCEPTANCE_ERROR,
              RobotActions::targetOrientationFrame.heading + ROBOT_ROTATE_ACCEPTANCE_ERROR))
      {
        // Serial.println("Controller: End Heading:");
        // Serial.print(RobotActions::currentOrientationFrame.heading, 6);
        // Serial.println();
        // Serial.println("Controller: Target Heading:");
        // Serial.print(RobotActions::targetOrientationFrame.heading, 6);
        // Serial.println();
        RobotActions::haltRobot(); // stop the robot
        RobotActions::isMovingRotating = false;
        return true; // task completed
      }
    }
    return false; // task not completed
  }

  /// @brief Resets/clear the a range of the robot's tracking related variables
  /// @return Always true when the function is done executing  
  bool robotClearValues()
  {
    // TODO: Handle any potential failures
    Motors::motorCountL = 0;
    Motors::motorCountR = 0;
    // Motors::motorPWML = 0;
    // Motors::motorPWMR = 0;
    RobotActions::TargetLocationCounts = 0;
    RobotActions::rotationAmount = 0;
    RobotActions::targetOrientationFrame.heading = 0;
    RobotActions::targetOrientationFrame.pitch = 0;
    RobotActions::targetOrientationFrame.roll = 0;
    RobotActions::isMovingDistance = false;
    RobotActions::isMovingRotating = false;

    return true;
  }

  /// @brief functions that halts the entire robots actions (E.g. Stop moving)
  /// @return Always true when the function is done executing
  bool haltRobot()
  {
    // TODO: Handle any potential failures

    // Serial.println("Controller <haltRobot()>: Halting");
    // stop the motors
    Motors::leftMotorPID.SetMode(MANUAL);
    Motors::rightMotorPID.SetMode(MANUAL);
    Motors::setMotorSpeedsRPM(0, 0);
    Motors::setMotorSpeedsPWM(0, 0);
    RobotActions::robotClearValues();
    Motors::leftMotorPID.SetMode(AUTOMATIC);
    Motors::rightMotorPID.SetMode(AUTOMATIC);

    return true;
  }

  /// @brief convert a distance (in millimeters) to the equivalent quantity of motor encoders count 
  /// @param _milliDistance Distance to convert (in millimeters)
  /// @return The equivalent motor encoders counts for the given distance
  long convertMilliToCounts(int32_t _milliDistance)
  {

    return (long)(CPM * _milliDistance);
  }

  /// @brief Set the the target orientation of the robot
  /// @param _rotationAmount The amount the robot should rotate by from the current orientation to hit the target orientation
  void setTargetOrientationFrame(float _rotationAmount)
  {
    RobotActions::rotationAmount = _rotationAmount;
    float tempHeading = RobotActions::startOrientationFrame.heading + RobotActions::rotationAmount;
    // determine if it is better to rotate clockwise or counter-clockwise to get to the target
    if (tempHeading < RobotActions::startOrientationFrame.heading)
    {
      RobotActions::CCW = -1;
    }
    else
    {
      RobotActions::CCW = 1;
    }

      // Serial.print("CCW Set: ");
      // Serial.println(RobotActions::CCW);
      
    // adjust the heading to be between 0 and 360 degrees, and cycling the heading around so that target values is reachable.
    if (tempHeading > 360)
    {
      tempHeading -= 360;
    }
    else if (tempHeading < 0)
    {
      tempHeading += 360;
    }
    // set the target orientation frame
    RobotActions::targetOrientationFrame.heading = tempHeading;
    RobotActions::targetOrientationFrame.pitch = startOrientationFrame.pitch;
    RobotActions::targetOrientationFrame.roll = startOrientationFrame.roll;
  }
}

#endif