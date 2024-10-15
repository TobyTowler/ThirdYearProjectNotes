// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/RobotCMD.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/robot_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotCMD_Request_arg3
{
public:
  explicit Init_RobotCMD_Request_arg3(::robot_interfaces::srv::RobotCMD_Request & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::RobotCMD_Request arg3(::robot_interfaces::srv::RobotCMD_Request::_arg3_type arg)
  {
    msg_.arg3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::RobotCMD_Request msg_;
};

class Init_RobotCMD_Request_arg2
{
public:
  explicit Init_RobotCMD_Request_arg2(::robot_interfaces::srv::RobotCMD_Request & msg)
  : msg_(msg)
  {}
  Init_RobotCMD_Request_arg3 arg2(::robot_interfaces::srv::RobotCMD_Request::_arg2_type arg)
  {
    msg_.arg2 = std::move(arg);
    return Init_RobotCMD_Request_arg3(msg_);
  }

private:
  ::robot_interfaces::srv::RobotCMD_Request msg_;
};

class Init_RobotCMD_Request_arg1
{
public:
  explicit Init_RobotCMD_Request_arg1(::robot_interfaces::srv::RobotCMD_Request & msg)
  : msg_(msg)
  {}
  Init_RobotCMD_Request_arg2 arg1(::robot_interfaces::srv::RobotCMD_Request::_arg1_type arg)
  {
    msg_.arg1 = std::move(arg);
    return Init_RobotCMD_Request_arg2(msg_);
  }

private:
  ::robot_interfaces::srv::RobotCMD_Request msg_;
};

class Init_RobotCMD_Request_cmd_chr
{
public:
  Init_RobotCMD_Request_cmd_chr()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotCMD_Request_arg1 cmd_chr(::robot_interfaces::srv::RobotCMD_Request::_cmd_chr_type arg)
  {
    msg_.cmd_chr = std::move(arg);
    return Init_RobotCMD_Request_arg1(msg_);
  }

private:
  ::robot_interfaces::srv::RobotCMD_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::RobotCMD_Request>()
{
  return robot_interfaces::srv::builder::Init_RobotCMD_Request_cmd_chr();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotCMD_Response_controller_data
{
public:
  Init_RobotCMD_Response_controller_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::RobotCMD_Response controller_data(::robot_interfaces::srv::RobotCMD_Response::_controller_data_type arg)
  {
    msg_.controller_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::RobotCMD_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::RobotCMD_Response>()
{
  return robot_interfaces::srv::builder::Init_RobotCMD_Response_controller_data();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__BUILDER_HPP_
