// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/RobotSerialReceived.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SERIAL_RECEIVED__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SERIAL_RECEIVED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RobotSerialReceived in the package robot_interfaces.
typedef struct robot_interfaces__msg__RobotSerialReceived
{
  rosidl_runtime_c__String data;
} robot_interfaces__msg__RobotSerialReceived;

// Struct for a sequence of robot_interfaces__msg__RobotSerialReceived.
typedef struct robot_interfaces__msg__RobotSerialReceived__Sequence
{
  robot_interfaces__msg__RobotSerialReceived * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__RobotSerialReceived__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SERIAL_RECEIVED__STRUCT_H_
