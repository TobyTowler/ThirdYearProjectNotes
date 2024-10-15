// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robot_interfaces:msg/RobotSendCMD.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/robot_send_cmd__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robot_interfaces/msg/detail/robot_send_cmd__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace robot_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
cdr_serialize(
  const robot_interfaces::msg::RobotSendCMD & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: cmd_chr
  cdr << ros_message.cmd_chr;
  // Member: arg1
  cdr << ros_message.arg1;
  // Member: arg2
  cdr << ros_message.arg2;
  // Member: arg3
  cdr << ros_message.arg3;
  // Member: arg4
  cdr << ros_message.arg4;
  // Member: arg5
  cdr << ros_message.arg5;
  // Member: arg6
  cdr << ros_message.arg6;
  // Member: arg7
  cdr << ros_message.arg7;
  // Member: arg8
  cdr << ros_message.arg8;
  // Member: arg9
  cdr << ros_message.arg9;
  // Member: arg10
  cdr << ros_message.arg10;
  // Member: arg11
  cdr << ros_message.arg11;
  // Member: arg12
  cdr << ros_message.arg12;
  // Member: arg13
  cdr << ros_message.arg13;
  // Member: arg14
  cdr << ros_message.arg14;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robot_interfaces::msg::RobotSendCMD & ros_message)
{
  // Member: cmd_chr
  cdr >> ros_message.cmd_chr;

  // Member: arg1
  cdr >> ros_message.arg1;

  // Member: arg2
  cdr >> ros_message.arg2;

  // Member: arg3
  cdr >> ros_message.arg3;

  // Member: arg4
  cdr >> ros_message.arg4;

  // Member: arg5
  cdr >> ros_message.arg5;

  // Member: arg6
  cdr >> ros_message.arg6;

  // Member: arg7
  cdr >> ros_message.arg7;

  // Member: arg8
  cdr >> ros_message.arg8;

  // Member: arg9
  cdr >> ros_message.arg9;

  // Member: arg10
  cdr >> ros_message.arg10;

  // Member: arg11
  cdr >> ros_message.arg11;

  // Member: arg12
  cdr >> ros_message.arg12;

  // Member: arg13
  cdr >> ros_message.arg13;

  // Member: arg14
  cdr >> ros_message.arg14;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
get_serialized_size(
  const robot_interfaces::msg::RobotSendCMD & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: cmd_chr
  {
    size_t item_size = sizeof(ros_message.cmd_chr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg1
  {
    size_t item_size = sizeof(ros_message.arg1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg2
  {
    size_t item_size = sizeof(ros_message.arg2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg3
  {
    size_t item_size = sizeof(ros_message.arg3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg4
  {
    size_t item_size = sizeof(ros_message.arg4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg5
  {
    size_t item_size = sizeof(ros_message.arg5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg6
  {
    size_t item_size = sizeof(ros_message.arg6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg7
  {
    size_t item_size = sizeof(ros_message.arg7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg8
  {
    size_t item_size = sizeof(ros_message.arg8);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg9
  {
    size_t item_size = sizeof(ros_message.arg9);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg10
  {
    size_t item_size = sizeof(ros_message.arg10);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg11
  {
    size_t item_size = sizeof(ros_message.arg11);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg12
  {
    size_t item_size = sizeof(ros_message.arg12);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg13
  {
    size_t item_size = sizeof(ros_message.arg13);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arg14
  {
    size_t item_size = sizeof(ros_message.arg14);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
max_serialized_size_RobotSendCMD(
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


  // Member: cmd_chr
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: arg1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg5
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg6
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg7
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg8
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg9
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg10
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg11
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg12
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg13
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arg14
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _RobotSendCMD__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robot_interfaces::msg::RobotSendCMD *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotSendCMD__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_interfaces::msg::RobotSendCMD *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotSendCMD__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_interfaces::msg::RobotSendCMD *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotSendCMD__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotSendCMD(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotSendCMD__callbacks = {
  "robot_interfaces::msg",
  "RobotSendCMD",
  _RobotSendCMD__cdr_serialize,
  _RobotSendCMD__cdr_deserialize,
  _RobotSendCMD__get_serialized_size,
  _RobotSendCMD__max_serialized_size
};

static rosidl_message_type_support_t _RobotSendCMD__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotSendCMD__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robot_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robot_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_interfaces::msg::RobotSendCMD>()
{
  return &robot_interfaces::msg::typesupport_fastrtps_cpp::_RobotSendCMD__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_interfaces, msg, RobotSendCMD)() {
  return &robot_interfaces::msg::typesupport_fastrtps_cpp::_RobotSendCMD__handle;
}

#ifdef __cplusplus
}
#endif
