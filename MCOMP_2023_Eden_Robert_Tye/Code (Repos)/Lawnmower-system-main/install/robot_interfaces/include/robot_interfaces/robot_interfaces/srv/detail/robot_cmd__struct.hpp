// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/RobotCMD.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__RobotCMD_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__RobotCMD_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RobotCMD_Request_
{
  using Type = RobotCMD_Request_<ContainerAllocator>;

  explicit RobotCMD_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->cmd_chr = 64;
      this->arg1 = 0l;
      this->arg2 = 0l;
      this->arg3 = 0l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->cmd_chr = 0;
      this->arg1 = 0l;
      this->arg2 = 0l;
      this->arg3 = 0l;
    }
  }

  explicit RobotCMD_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->cmd_chr = 64;
      this->arg1 = 0l;
      this->arg2 = 0l;
      this->arg3 = 0l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->cmd_chr = 0;
      this->arg1 = 0l;
      this->arg2 = 0l;
      this->arg3 = 0l;
    }
  }

  // field types and members
  using _cmd_chr_type =
    uint8_t;
  _cmd_chr_type cmd_chr;
  using _arg1_type =
    int32_t;
  _arg1_type arg1;
  using _arg2_type =
    int32_t;
  _arg2_type arg2;
  using _arg3_type =
    int32_t;
  _arg3_type arg3;

  // setters for named parameter idiom
  Type & set__cmd_chr(
    const uint8_t & _arg)
  {
    this->cmd_chr = _arg;
    return *this;
  }
  Type & set__arg1(
    const int32_t & _arg)
  {
    this->arg1 = _arg;
    return *this;
  }
  Type & set__arg2(
    const int32_t & _arg)
  {
    this->arg2 = _arg;
    return *this;
  }
  Type & set__arg3(
    const int32_t & _arg)
  {
    this->arg3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__RobotCMD_Request
    std::shared_ptr<robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__RobotCMD_Request
    std::shared_ptr<robot_interfaces::srv::RobotCMD_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotCMD_Request_ & other) const
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
    return true;
  }
  bool operator!=(const RobotCMD_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotCMD_Request_

// alias to use template instance with default allocator
using RobotCMD_Request =
  robot_interfaces::srv::RobotCMD_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__RobotCMD_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__RobotCMD_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RobotCMD_Response_
{
  using Type = RobotCMD_Response_<ContainerAllocator>;

  explicit RobotCMD_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->controller_data = "";
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->controller_data = "";
    }
  }

  explicit RobotCMD_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : controller_data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->controller_data = "";
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->controller_data = "";
    }
  }

  // field types and members
  using _controller_data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _controller_data_type controller_data;

  // setters for named parameter idiom
  Type & set__controller_data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->controller_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__RobotCMD_Response
    std::shared_ptr<robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__RobotCMD_Response
    std::shared_ptr<robot_interfaces::srv::RobotCMD_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotCMD_Response_ & other) const
  {
    if (this->controller_data != other.controller_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotCMD_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotCMD_Response_

// alias to use template instance with default allocator
using RobotCMD_Response =
  robot_interfaces::srv::RobotCMD_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct RobotCMD
{
  using Request = robot_interfaces::srv::RobotCMD_Request;
  using Response = robot_interfaces::srv::RobotCMD_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ROBOT_CMD__STRUCT_HPP_
