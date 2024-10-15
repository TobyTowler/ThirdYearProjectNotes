// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/RobotSerialReceived.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SERIAL_RECEIVED__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SERIAL_RECEIVED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/robot_serial_received__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotSerialReceived_data
{
public:
  Init_RobotSerialReceived_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::msg::RobotSerialReceived data(::robot_interfaces::msg::RobotSerialReceived::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::RobotSerialReceived msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::RobotSerialReceived>()
{
  return robot_interfaces::msg::builder::Init_RobotSerialReceived_data();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SERIAL_RECEIVED__BUILDER_HPP_
