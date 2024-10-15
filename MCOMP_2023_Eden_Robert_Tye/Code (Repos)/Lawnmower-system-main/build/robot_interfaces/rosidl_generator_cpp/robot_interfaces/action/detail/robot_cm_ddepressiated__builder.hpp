// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:action/RobotCMDdepressiated.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__ACTION__DETAIL__ROBOT_CM_DDEPRESSIATED__BUILDER_HPP_
#define ROBOT_INTERFACES__ACTION__DETAIL__ROBOT_CM_DDEPRESSIATED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/action/detail/robot_cm_ddepressiated__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotCMDdepressiated_Goal_arg3
{
public:
  explicit Init_RobotCMDdepressiated_Goal_arg3(::robot_interfaces::action::RobotCMDdepressiated_Goal & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::action::RobotCMDdepressiated_Goal arg3(::robot_interfaces::action::RobotCMDdepressiated_Goal::_arg3_type arg)
  {
    msg_.arg3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_Goal msg_;
};

class Init_RobotCMDdepressiated_Goal_arg2
{
public:
  explicit Init_RobotCMDdepressiated_Goal_arg2(::robot_interfaces::action::RobotCMDdepressiated_Goal & msg)
  : msg_(msg)
  {}
  Init_RobotCMDdepressiated_Goal_arg3 arg2(::robot_interfaces::action::RobotCMDdepressiated_Goal::_arg2_type arg)
  {
    msg_.arg2 = std::move(arg);
    return Init_RobotCMDdepressiated_Goal_arg3(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_Goal msg_;
};

class Init_RobotCMDdepressiated_Goal_arg1
{
public:
  explicit Init_RobotCMDdepressiated_Goal_arg1(::robot_interfaces::action::RobotCMDdepressiated_Goal & msg)
  : msg_(msg)
  {}
  Init_RobotCMDdepressiated_Goal_arg2 arg1(::robot_interfaces::action::RobotCMDdepressiated_Goal::_arg1_type arg)
  {
    msg_.arg1 = std::move(arg);
    return Init_RobotCMDdepressiated_Goal_arg2(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_Goal msg_;
};

class Init_RobotCMDdepressiated_Goal_cmd_chr
{
public:
  Init_RobotCMDdepressiated_Goal_cmd_chr()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotCMDdepressiated_Goal_arg1 cmd_chr(::robot_interfaces::action::RobotCMDdepressiated_Goal::_cmd_chr_type arg)
  {
    msg_.cmd_chr = std::move(arg);
    return Init_RobotCMDdepressiated_Goal_arg1(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::action::RobotCMDdepressiated_Goal>()
{
  return robot_interfaces::action::builder::Init_RobotCMDdepressiated_Goal_cmd_chr();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotCMDdepressiated_Result_data_string
{
public:
  Init_RobotCMDdepressiated_Result_data_string()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::action::RobotCMDdepressiated_Result data_string(::robot_interfaces::action::RobotCMDdepressiated_Result::_data_string_type arg)
  {
    msg_.data_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::action::RobotCMDdepressiated_Result>()
{
  return robot_interfaces::action::builder::Init_RobotCMDdepressiated_Result_data_string();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::action::RobotCMDdepressiated_Feedback>()
{
  return ::robot_interfaces::action::RobotCMDdepressiated_Feedback(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotCMDdepressiated_SendGoal_Request_goal
{
public:
  explicit Init_RobotCMDdepressiated_SendGoal_Request_goal(::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Request goal(::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Request msg_;
};

class Init_RobotCMDdepressiated_SendGoal_Request_goal_id
{
public:
  Init_RobotCMDdepressiated_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotCMDdepressiated_SendGoal_Request_goal goal_id(::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotCMDdepressiated_SendGoal_Request_goal(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Request>()
{
  return robot_interfaces::action::builder::Init_RobotCMDdepressiated_SendGoal_Request_goal_id();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotCMDdepressiated_SendGoal_Response_stamp
{
public:
  explicit Init_RobotCMDdepressiated_SendGoal_Response_stamp(::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Response stamp(::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Response msg_;
};

class Init_RobotCMDdepressiated_SendGoal_Response_accepted
{
public:
  Init_RobotCMDdepressiated_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotCMDdepressiated_SendGoal_Response_stamp accepted(::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_RobotCMDdepressiated_SendGoal_Response_stamp(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::action::RobotCMDdepressiated_SendGoal_Response>()
{
  return robot_interfaces::action::builder::Init_RobotCMDdepressiated_SendGoal_Response_accepted();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotCMDdepressiated_GetResult_Request_goal_id
{
public:
  Init_RobotCMDdepressiated_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::action::RobotCMDdepressiated_GetResult_Request goal_id(::robot_interfaces::action::RobotCMDdepressiated_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::action::RobotCMDdepressiated_GetResult_Request>()
{
  return robot_interfaces::action::builder::Init_RobotCMDdepressiated_GetResult_Request_goal_id();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotCMDdepressiated_GetResult_Response_result
{
public:
  explicit Init_RobotCMDdepressiated_GetResult_Response_result(::robot_interfaces::action::RobotCMDdepressiated_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::action::RobotCMDdepressiated_GetResult_Response result(::robot_interfaces::action::RobotCMDdepressiated_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_GetResult_Response msg_;
};

class Init_RobotCMDdepressiated_GetResult_Response_status
{
public:
  Init_RobotCMDdepressiated_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotCMDdepressiated_GetResult_Response_result status(::robot_interfaces::action::RobotCMDdepressiated_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RobotCMDdepressiated_GetResult_Response_result(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::action::RobotCMDdepressiated_GetResult_Response>()
{
  return robot_interfaces::action::builder::Init_RobotCMDdepressiated_GetResult_Response_status();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotCMDdepressiated_FeedbackMessage_feedback
{
public:
  explicit Init_RobotCMDdepressiated_FeedbackMessage_feedback(::robot_interfaces::action::RobotCMDdepressiated_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::action::RobotCMDdepressiated_FeedbackMessage feedback(::robot_interfaces::action::RobotCMDdepressiated_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_FeedbackMessage msg_;
};

class Init_RobotCMDdepressiated_FeedbackMessage_goal_id
{
public:
  Init_RobotCMDdepressiated_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotCMDdepressiated_FeedbackMessage_feedback goal_id(::robot_interfaces::action::RobotCMDdepressiated_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotCMDdepressiated_FeedbackMessage_feedback(msg_);
  }

private:
  ::robot_interfaces::action::RobotCMDdepressiated_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::action::RobotCMDdepressiated_FeedbackMessage>()
{
  return robot_interfaces::action::builder::Init_RobotCMDdepressiated_FeedbackMessage_goal_id();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__ACTION__DETAIL__ROBOT_CM_DDEPRESSIATED__BUILDER_HPP_
