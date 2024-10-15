// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robot_interfaces:msg/RobotSendCMD.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/robot_send_cmd__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/msg/detail/robot_send_cmd__struct.h"
#include "robot_interfaces/msg/detail/robot_send_cmd__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RobotSendCMD__ros_msg_type = robot_interfaces__msg__RobotSendCMD;

static bool _RobotSendCMD__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotSendCMD__ros_msg_type * ros_message = static_cast<const _RobotSendCMD__ros_msg_type *>(untyped_ros_message);
  // Field name: cmd_chr
  {
    cdr << ros_message->cmd_chr;
  }

  // Field name: arg1
  {
    cdr << ros_message->arg1;
  }

  // Field name: arg2
  {
    cdr << ros_message->arg2;
  }

  // Field name: arg3
  {
    cdr << ros_message->arg3;
  }

  // Field name: arg4
  {
    cdr << ros_message->arg4;
  }

  // Field name: arg5
  {
    cdr << ros_message->arg5;
  }

  // Field name: arg6
  {
    cdr << ros_message->arg6;
  }

  // Field name: arg7
  {
    cdr << ros_message->arg7;
  }

  // Field name: arg8
  {
    cdr << ros_message->arg8;
  }

  // Field name: arg9
  {
    cdr << ros_message->arg9;
  }

  // Field name: arg10
  {
    cdr << ros_message->arg10;
  }

  // Field name: arg11
  {
    cdr << ros_message->arg11;
  }

  // Field name: arg12
  {
    cdr << ros_message->arg12;
  }

  // Field name: arg13
  {
    cdr << ros_message->arg13;
  }

  // Field name: arg14
  {
    cdr << ros_message->arg14;
  }

  return true;
}

static bool _RobotSendCMD__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotSendCMD__ros_msg_type * ros_message = static_cast<_RobotSendCMD__ros_msg_type *>(untyped_ros_message);
  // Field name: cmd_chr
  {
    cdr >> ros_message->cmd_chr;
  }

  // Field name: arg1
  {
    cdr >> ros_message->arg1;
  }

  // Field name: arg2
  {
    cdr >> ros_message->arg2;
  }

  // Field name: arg3
  {
    cdr >> ros_message->arg3;
  }

  // Field name: arg4
  {
    cdr >> ros_message->arg4;
  }

  // Field name: arg5
  {
    cdr >> ros_message->arg5;
  }

  // Field name: arg6
  {
    cdr >> ros_message->arg6;
  }

  // Field name: arg7
  {
    cdr >> ros_message->arg7;
  }

  // Field name: arg8
  {
    cdr >> ros_message->arg8;
  }

  // Field name: arg9
  {
    cdr >> ros_message->arg9;
  }

  // Field name: arg10
  {
    cdr >> ros_message->arg10;
  }

  // Field name: arg11
  {
    cdr >> ros_message->arg11;
  }

  // Field name: arg12
  {
    cdr >> ros_message->arg12;
  }

  // Field name: arg13
  {
    cdr >> ros_message->arg13;
  }

  // Field name: arg14
  {
    cdr >> ros_message->arg14;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__msg__RobotSendCMD(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotSendCMD__ros_msg_type * ros_message = static_cast<const _RobotSendCMD__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name cmd_chr
  {
    size_t item_size = sizeof(ros_message->cmd_chr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg1
  {
    size_t item_size = sizeof(ros_message->arg1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg2
  {
    size_t item_size = sizeof(ros_message->arg2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg3
  {
    size_t item_size = sizeof(ros_message->arg3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg4
  {
    size_t item_size = sizeof(ros_message->arg4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg5
  {
    size_t item_size = sizeof(ros_message->arg5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg6
  {
    size_t item_size = sizeof(ros_message->arg6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg7
  {
    size_t item_size = sizeof(ros_message->arg7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg8
  {
    size_t item_size = sizeof(ros_message->arg8);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg9
  {
    size_t item_size = sizeof(ros_message->arg9);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg10
  {
    size_t item_size = sizeof(ros_message->arg10);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg11
  {
    size_t item_size = sizeof(ros_message->arg11);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg12
  {
    size_t item_size = sizeof(ros_message->arg12);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg13
  {
    size_t item_size = sizeof(ros_message->arg13);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arg14
  {
    size_t item_size = sizeof(ros_message->arg14);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RobotSendCMD__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__msg__RobotSendCMD(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__msg__RobotSendCMD(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: cmd_chr
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: arg1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg5
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg6
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg7
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg8
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg9
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg10
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg11
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg12
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg13
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arg14
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _RobotSendCMD__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__msg__RobotSendCMD(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotSendCMD = {
  "robot_interfaces::msg",
  "RobotSendCMD",
  _RobotSendCMD__cdr_serialize,
  _RobotSendCMD__cdr_deserialize,
  _RobotSendCMD__get_serialized_size,
  _RobotSendCMD__max_serialized_size
};

static rosidl_message_type_support_t _RobotSendCMD__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotSendCMD,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, msg, RobotSendCMD)() {
  return &_RobotSendCMD__type_support;
}

#if defined(__cplusplus)
}
#endif
