// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/RobotSendCMD.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RobotSendCMD in the package robot_interfaces.
typedef struct robot_interfaces__msg__RobotSendCMD
{
  /// default: 64 (@), as this default values is highly unlikely to not be used for anything in deployemnt
  uint8_t cmd_chr;
  /// default: 0
  float arg1;
  /// default: 0
  float arg2;
  /// default: 0
  float arg3;
  /// default: 0
  float arg4;
  /// default: 0
  float arg5;
  /// default: 0
  float arg6;
  /// default: 0
  float arg7;
  /// default: 0
  float arg8;
  /// default: 0
  float arg9;
  /// default: 0
  float arg10;
  /// default: 0
  float arg11;
  /// default: 0
  float arg12;
  /// default: 0
  float arg13;
  /// default: 0
  float arg14;
} robot_interfaces__msg__RobotSendCMD;

// Struct for a sequence of robot_interfaces__msg__RobotSendCMD.
typedef struct robot_interfaces__msg__RobotSendCMD__Sequence
{
  robot_interfaces__msg__RobotSendCMD * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__RobotSendCMD__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__STRUCT_H_
