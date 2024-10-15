// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:action/RobotCMDdepressiated.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__ACTION__DETAIL__ROBOT_CM_DDEPRESSIATED__STRUCT_H_
#define ROBOT_INTERFACES__ACTION__DETAIL__ROBOT_CM_DDEPRESSIATED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/RobotCMDdepressiated in the package robot_interfaces.
typedef struct robot_interfaces__action__RobotCMDdepressiated_Goal
{
  /// default: 64 (@), as this default values is highly unlikely to not be used for anything in deployemnt
  uint8_t cmd_chr;
  /// default: 0
  int32_t arg1;
  /// default: 0
  int32_t arg2;
  /// default: 0
  int32_t arg3;
} robot_interfaces__action__RobotCMDdepressiated_Goal;

// Struct for a sequence of robot_interfaces__action__RobotCMDdepressiated_Goal.
typedef struct robot_interfaces__action__RobotCMDdepressiated_Goal__Sequence
{
  robot_interfaces__action__RobotCMDdepressiated_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__action__RobotCMDdepressiated_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'data_string'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotCMDdepressiated in the package robot_interfaces.
typedef struct robot_interfaces__action__RobotCMDdepressiated_Result
{
  /// default: blank string
  rosidl_runtime_c__String data_string;
} robot_interfaces__action__RobotCMDdepressiated_Result;

// Struct for a sequence of robot_interfaces__action__RobotCMDdepressiated_Result.
typedef struct robot_interfaces__action__RobotCMDdepressiated_Result__Sequence
{
  robot_interfaces__action__RobotCMDdepressiated_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__action__RobotCMDdepressiated_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/RobotCMDdepressiated in the package robot_interfaces.
typedef struct robot_interfaces__action__RobotCMDdepressiated_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} robot_interfaces__action__RobotCMDdepressiated_Feedback;

// Struct for a sequence of robot_interfaces__action__RobotCMDdepressiated_Feedback.
typedef struct robot_interfaces__action__RobotCMDdepressiated_Feedback__Sequence
{
  robot_interfaces__action__RobotCMDdepressiated_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__action__RobotCMDdepressiated_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "robot_interfaces/action/detail/robot_cm_ddepressiated__struct.h"

/// Struct defined in action/RobotCMDdepressiated in the package robot_interfaces.
typedef struct robot_interfaces__action__RobotCMDdepressiated_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  robot_interfaces__action__RobotCMDdepressiated_Goal goal;
} robot_interfaces__action__RobotCMDdepressiated_SendGoal_Request;

// Struct for a sequence of robot_interfaces__action__RobotCMDdepressiated_SendGoal_Request.
typedef struct robot_interfaces__action__RobotCMDdepressiated_SendGoal_Request__Sequence
{
  robot_interfaces__action__RobotCMDdepressiated_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__action__RobotCMDdepressiated_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/RobotCMDdepressiated in the package robot_interfaces.
typedef struct robot_interfaces__action__RobotCMDdepressiated_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} robot_interfaces__action__RobotCMDdepressiated_SendGoal_Response;

// Struct for a sequence of robot_interfaces__action__RobotCMDdepressiated_SendGoal_Response.
typedef struct robot_interfaces__action__RobotCMDdepressiated_SendGoal_Response__Sequence
{
  robot_interfaces__action__RobotCMDdepressiated_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__action__RobotCMDdepressiated_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/RobotCMDdepressiated in the package robot_interfaces.
typedef struct robot_interfaces__action__RobotCMDdepressiated_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} robot_interfaces__action__RobotCMDdepressiated_GetResult_Request;

// Struct for a sequence of robot_interfaces__action__RobotCMDdepressiated_GetResult_Request.
typedef struct robot_interfaces__action__RobotCMDdepressiated_GetResult_Request__Sequence
{
  robot_interfaces__action__RobotCMDdepressiated_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__action__RobotCMDdepressiated_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "robot_interfaces/action/detail/robot_cm_ddepressiated__struct.h"

/// Struct defined in action/RobotCMDdepressiated in the package robot_interfaces.
typedef struct robot_interfaces__action__RobotCMDdepressiated_GetResult_Response
{
  int8_t status;
  robot_interfaces__action__RobotCMDdepressiated_Result result;
} robot_interfaces__action__RobotCMDdepressiated_GetResult_Response;

// Struct for a sequence of robot_interfaces__action__RobotCMDdepressiated_GetResult_Response.
typedef struct robot_interfaces__action__RobotCMDdepressiated_GetResult_Response__Sequence
{
  robot_interfaces__action__RobotCMDdepressiated_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__action__RobotCMDdepressiated_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "robot_interfaces/action/detail/robot_cm_ddepressiated__struct.h"

/// Struct defined in action/RobotCMDdepressiated in the package robot_interfaces.
typedef struct robot_interfaces__action__RobotCMDdepressiated_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  robot_interfaces__action__RobotCMDdepressiated_Feedback feedback;
} robot_interfaces__action__RobotCMDdepressiated_FeedbackMessage;

// Struct for a sequence of robot_interfaces__action__RobotCMDdepressiated_FeedbackMessage.
typedef struct robot_interfaces__action__RobotCMDdepressiated_FeedbackMessage__Sequence
{
  robot_interfaces__action__RobotCMDdepressiated_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__action__RobotCMDdepressiated_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__ACTION__DETAIL__ROBOT_CM_DDEPRESSIATED__STRUCT_H_
