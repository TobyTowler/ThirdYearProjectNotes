// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:msg/RobotSendCMD.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__TRAITS_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/msg/detail/robot_send_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotSendCMD & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd_chr
  {
    out << "cmd_chr: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_chr, out);
    out << ", ";
  }

  // member: arg1
  {
    out << "arg1: ";
    rosidl_generator_traits::value_to_yaml(msg.arg1, out);
    out << ", ";
  }

  // member: arg2
  {
    out << "arg2: ";
    rosidl_generator_traits::value_to_yaml(msg.arg2, out);
    out << ", ";
  }

  // member: arg3
  {
    out << "arg3: ";
    rosidl_generator_traits::value_to_yaml(msg.arg3, out);
    out << ", ";
  }

  // member: arg4
  {
    out << "arg4: ";
    rosidl_generator_traits::value_to_yaml(msg.arg4, out);
    out << ", ";
  }

  // member: arg5
  {
    out << "arg5: ";
    rosidl_generator_traits::value_to_yaml(msg.arg5, out);
    out << ", ";
  }

  // member: arg6
  {
    out << "arg6: ";
    rosidl_generator_traits::value_to_yaml(msg.arg6, out);
    out << ", ";
  }

  // member: arg7
  {
    out << "arg7: ";
    rosidl_generator_traits::value_to_yaml(msg.arg7, out);
    out << ", ";
  }

  // member: arg8
  {
    out << "arg8: ";
    rosidl_generator_traits::value_to_yaml(msg.arg8, out);
    out << ", ";
  }

  // member: arg9
  {
    out << "arg9: ";
    rosidl_generator_traits::value_to_yaml(msg.arg9, out);
    out << ", ";
  }

  // member: arg10
  {
    out << "arg10: ";
    rosidl_generator_traits::value_to_yaml(msg.arg10, out);
    out << ", ";
  }

  // member: arg11
  {
    out << "arg11: ";
    rosidl_generator_traits::value_to_yaml(msg.arg11, out);
    out << ", ";
  }

  // member: arg12
  {
    out << "arg12: ";
    rosidl_generator_traits::value_to_yaml(msg.arg12, out);
    out << ", ";
  }

  // member: arg13
  {
    out << "arg13: ";
    rosidl_generator_traits::value_to_yaml(msg.arg13, out);
    out << ", ";
  }

  // member: arg14
  {
    out << "arg14: ";
    rosidl_generator_traits::value_to_yaml(msg.arg14, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotSendCMD & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd_chr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_chr: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_chr, out);
    out << "\n";
  }

  // member: arg1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg1: ";
    rosidl_generator_traits::value_to_yaml(msg.arg1, out);
    out << "\n";
  }

  // member: arg2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg2: ";
    rosidl_generator_traits::value_to_yaml(msg.arg2, out);
    out << "\n";
  }

  // member: arg3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg3: ";
    rosidl_generator_traits::value_to_yaml(msg.arg3, out);
    out << "\n";
  }

  // member: arg4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg4: ";
    rosidl_generator_traits::value_to_yaml(msg.arg4, out);
    out << "\n";
  }

  // member: arg5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg5: ";
    rosidl_generator_traits::value_to_yaml(msg.arg5, out);
    out << "\n";
  }

  // member: arg6
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg6: ";
    rosidl_generator_traits::value_to_yaml(msg.arg6, out);
    out << "\n";
  }

  // member: arg7
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg7: ";
    rosidl_generator_traits::value_to_yaml(msg.arg7, out);
    out << "\n";
  }

  // member: arg8
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg8: ";
    rosidl_generator_traits::value_to_yaml(msg.arg8, out);
    out << "\n";
  }

  // member: arg9
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg9: ";
    rosidl_generator_traits::value_to_yaml(msg.arg9, out);
    out << "\n";
  }

  // member: arg10
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg10: ";
    rosidl_generator_traits::value_to_yaml(msg.arg10, out);
    out << "\n";
  }

  // member: arg11
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg11: ";
    rosidl_generator_traits::value_to_yaml(msg.arg11, out);
    out << "\n";
  }

  // member: arg12
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg12: ";
    rosidl_generator_traits::value_to_yaml(msg.arg12, out);
    out << "\n";
  }

  // member: arg13
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg13: ";
    rosidl_generator_traits::value_to_yaml(msg.arg13, out);
    out << "\n";
  }

  // member: arg14
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg14: ";
    rosidl_generator_traits::value_to_yaml(msg.arg14, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotSendCMD & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::msg::RobotSendCMD & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::msg::RobotSendCMD & msg)
{
  return robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::msg::RobotSendCMD>()
{
  return "robot_interfaces::msg::RobotSendCMD";
}

template<>
inline const char * name<robot_interfaces::msg::RobotSendCMD>()
{
  return "robot_interfaces/msg/RobotSendCMD";
}

template<>
struct has_fixed_size<robot_interfaces::msg::RobotSendCMD>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::msg::RobotSendCMD>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::msg::RobotSendCMD>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__TRAITS_HPP_
