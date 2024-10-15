// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/RobotSendCMD.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__RobotSendCMD __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__RobotSendCMD __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotSendCMD_
{
  using Type = RobotSendCMD_<ContainerAllocator>;

  explicit RobotSendCMD_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->cmd_chr = 64;
      this->arg1 = 0.0f;
      this->arg2 = 0.0f;
      this->arg3 = 0.0f;
      this->arg4 = 0.0f;
      this->arg5 = 0.0f;
      this->arg6 = 0.0f;
      this->arg7 = 0.0f;
      this->arg8 = 0.0f;
      this->arg9 = 0.0f;
      this->arg10 = 0.0f;
      this->arg11 = 0.0f;
      this->arg12 = 0.0f;
      this->arg13 = 0.0f;
      this->arg14 = 0.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->cmd_chr = 0;
      this->arg1 = 0.0f;
      this->arg2 = 0.0f;
      this->arg3 = 0.0f;
      this->arg4 = 0.0f;
      this->arg5 = 0.0f;
      this->arg6 = 0.0f;
      this->arg7 = 0.0f;
      this->arg8 = 0.0f;
      this->arg9 = 0.0f;
      this->arg10 = 0.0f;
      this->arg11 = 0.0f;
      this->arg12 = 0.0f;
      this->arg13 = 0.0f;
      this->arg14 = 0.0f;
    }
  }

  explicit RobotSendCMD_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->cmd_chr = 64;
      this->arg1 = 0.0f;
      this->arg2 = 0.0f;
      this->arg3 = 0.0f;
      this->arg4 = 0.0f;
      this->arg5 = 0.0f;
      this->arg6 = 0.0f;
      this->arg7 = 0.0f;
      this->arg8 = 0.0f;
      this->arg9 = 0.0f;
      this->arg10 = 0.0f;
      this->arg11 = 0.0f;
      this->arg12 = 0.0f;
      this->arg13 = 0.0f;
      this->arg14 = 0.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->cmd_chr = 0;
      this->arg1 = 0.0f;
      this->arg2 = 0.0f;
      this->arg3 = 0.0f;
      this->arg4 = 0.0f;
      this->arg5 = 0.0f;
      this->arg6 = 0.0f;
      this->arg7 = 0.0f;
      this->arg8 = 0.0f;
      this->arg9 = 0.0f;
      this->arg10 = 0.0f;
      this->arg11 = 0.0f;
      this->arg12 = 0.0f;
      this->arg13 = 0.0f;
      this->arg14 = 0.0f;
    }
  }

  // field types and members
  using _cmd_chr_type =
    uint8_t;
  _cmd_chr_type cmd_chr;
  using _arg1_type =
    float;
  _arg1_type arg1;
  using _arg2_type =
    float;
  _arg2_type arg2;
  using _arg3_type =
    float;
  _arg3_type arg3;
  using _arg4_type =
    float;
  _arg4_type arg4;
  using _arg5_type =
    float;
  _arg5_type arg5;
  using _arg6_type =
    float;
  _arg6_type arg6;
  using _arg7_type =
    float;
  _arg7_type arg7;
  using _arg8_type =
    float;
  _arg8_type arg8;
  using _arg9_type =
    float;
  _arg9_type arg9;
  using _arg10_type =
    float;
  _arg10_type arg10;
  using _arg11_type =
    float;
  _arg11_type arg11;
  using _arg12_type =
    float;
  _arg12_type arg12;
  using _arg13_type =
    float;
  _arg13_type arg13;
  using _arg14_type =
    float;
  _arg14_type arg14;

  // setters for named parameter idiom
  Type & set__cmd_chr(
    const uint8_t & _arg)
  {
    this->cmd_chr = _arg;
    return *this;
  }
  Type & set__arg1(
    const float & _arg)
  {
    this->arg1 = _arg;
    return *this;
  }
  Type & set__arg2(
    const float & _arg)
  {
    this->arg2 = _arg;
    return *this;
  }
  Type & set__arg3(
    const float & _arg)
  {
    this->arg3 = _arg;
    return *this;
  }
  Type & set__arg4(
    const float & _arg)
  {
    this->arg4 = _arg;
    return *this;
  }
  Type & set__arg5(
    const float & _arg)
  {
    this->arg5 = _arg;
    return *this;
  }
  Type & set__arg6(
    const float & _arg)
  {
    this->arg6 = _arg;
    return *this;
  }
  Type & set__arg7(
    const float & _arg)
  {
    this->arg7 = _arg;
    return *this;
  }
  Type & set__arg8(
    const float & _arg)
  {
    this->arg8 = _arg;
    return *this;
  }
  Type & set__arg9(
    const float & _arg)
  {
    this->arg9 = _arg;
    return *this;
  }
  Type & set__arg10(
    const float & _arg)
  {
    this->arg10 = _arg;
    return *this;
  }
  Type & set__arg11(
    const float & _arg)
  {
    this->arg11 = _arg;
    return *this;
  }
  Type & set__arg12(
    const float & _arg)
  {
    this->arg12 = _arg;
    return *this;
  }
  Type & set__arg13(
    const float & _arg)
  {
    this->arg13 = _arg;
    return *this;
  }
  Type & set__arg14(
    const float & _arg)
  {
    this->arg14 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::RobotSendCMD_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::RobotSendCMD_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::RobotSendCMD_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::RobotSendCMD_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::RobotSendCMD_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::RobotSendCMD_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::RobotSendCMD_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::RobotSendCMD_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::RobotSendCMD_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::RobotSendCMD_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__RobotSendCMD
    std::shared_ptr<robot_interfaces::msg::RobotSendCMD_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__RobotSendCMD
    std::shared_ptr<robot_interfaces::msg::RobotSendCMD_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotSendCMD_ & other) const
  {
    if (this->cmd_chr != other.cmd_chr) {
      return false;
    }
    if (this->arg1 != other.arg1) {
      return false;
    }
    if (this->arg2 != other.arg2) {
      return false;
    }
    if (this->arg3 != other.arg3) {
      return false;
    }
    if (this->arg4 != other.arg4) {
      return false;
    }
    if (this->arg5 != other.arg5) {
      return false;
    }
    if (this->arg6 != other.arg6) {
      return false;
    }
    if (this->arg7 != other.arg7) {
      return false;
    }
    if (this->arg8 != other.arg8) {
      return false;
    }
    if (this->arg9 != other.arg9) {
      return false;
    }
    if (this->arg10 != other.arg10) {
      return false;
    }
    if (this->arg11 != other.arg11) {
      return false;
    }
    if (this->arg12 != other.arg12) {
      return false;
    }
    if (this->arg13 != other.arg13) {
      return false;
    }
    if (this->arg14 != other.arg14) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotSendCMD_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotSendCMD_

// alias to use template instance with default allocator
using RobotSendCMD =
  robot_interfaces::msg::RobotSendCMD_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ROBOT_SEND_CMD__STRUCT_HPP_
