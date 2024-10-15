// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/RobotCMD.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RobotCMD in the package robot_interfaces.
typedef struct robot_interfaces__srv__RobotCMD_Request
{
  /// default: 64 (@), as this default values is highly unlikely to not be used for anything in deployemnt
  uint8_t cmd_chr;
  /// default: 0
  int32_t arg1;
  /// default: 0
  int32_t arg2;
  /// default: 0
  int32_t arg3;
} robot_interfaces__srv__RobotCMD_Request;

// Struct for a sequence of robot_interfaces__srv__RobotCMD_Request.
typedef struct robot_interfaces__srv__RobotCMD_Request__Sequence
{
  robot_interfaces__srv__RobotCMD_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__RobotCMD_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'controller_data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RobotCMD in the package robot_interfaces.
typedef struct robot_interfaces__srv__RobotCMD_Response
{
  /// default: empty string
  rosidl_runtime_c__String controller_data;
} robot_interfaces__srv__RobotCMD_Response;

// Struct for a sequence of robot_interfaces__srv__RobotCMD_Response.
typedef struct robot_interfaces__srv__RobotCMD_Response__Sequence
{
  robot_interfaces__srv__RobotCMD_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__RobotCMD_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__STRUCT_H_
