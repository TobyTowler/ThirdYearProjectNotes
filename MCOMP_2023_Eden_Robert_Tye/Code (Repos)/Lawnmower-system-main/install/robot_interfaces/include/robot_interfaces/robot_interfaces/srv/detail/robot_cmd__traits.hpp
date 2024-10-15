// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:srv/RobotCMD.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__TRAITS_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/srv/detail/robot_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotCMD_Request & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotCMD_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotCMD_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::RobotCMD_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::RobotCMD_Request & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::RobotCMD_Request>()
{
  return "robot_interfaces::srv::RobotCMD_Request";
}

template<>
inline const char * name<robot_interfaces::srv::RobotCMD_Request>()
{
  return "robot_interfaces/srv/RobotCMD_Request";
}

template<>
struct has_fixed_size<robot_interfaces::srv::RobotCMD_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::srv::RobotCMD_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::srv::RobotCMD_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotCMD_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: controller_data
  {
    out << "controller_data: ";
    rosidl_generator_traits::value_to_yaml(msg.controller_data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotCMD_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: controller_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "controller_data: ";
    rosidl_generator_traits::value_to_yaml(msg.controller_data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotCMD_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::RobotCMD_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::RobotCMD_Response & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::RobotCMD_Response>()
{
  return "robot_interfaces::srv::RobotCMD_Response";
}

template<>
inline const char * name<robot_interfaces::srv::RobotCMD_Response>()
{
  return "robot_interfaces/srv/RobotCMD_Response";
}

template<>
struct has_fixed_size<robot_interfaces::srv::RobotCMD_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::srv::RobotCMD_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::srv::RobotCMD_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_interfaces::srv::RobotCMD>()
{
  return "robot_interfaces::srv::RobotCMD";
}

template<>
inline const char * name<robot_interfaces::srv::RobotCMD>()
{
  return "robot_interfaces/srv/RobotCMD";
}

template<>
struct has_fixed_size<robot_interfaces::srv::RobotCMD>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_interfaces::srv::RobotCMD_Request>::value &&
    has_fixed_size<robot_interfaces::srv::RobotCMD_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_interfaces::srv::RobotCMD>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_interfaces::srv::RobotCMD_Request>::value &&
    has_bounded_size<robot_interfaces::srv::RobotCMD_Response>::value
  >
{
};

template<>
struct is_service<robot_interfaces::srv::RobotCMD>
  : std::true_type
{
};

template<>
struct is_service_request<robot_interfaces::srv::RobotCMD_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_interfaces::srv::RobotCMD_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__TRAITS_HPP_
