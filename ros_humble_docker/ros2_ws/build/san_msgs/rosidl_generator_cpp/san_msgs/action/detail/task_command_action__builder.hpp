// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:action/TaskCommandAction.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__BUILDER_HPP_
#define SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/action/detail/task_command_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_TaskCommandAction_Goal_target_goal
{
public:
  explicit Init_TaskCommandAction_Goal_target_goal(::san_msgs::action::TaskCommandAction_Goal & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::TaskCommandAction_Goal target_goal(::san_msgs::action::TaskCommandAction_Goal::_target_goal_type arg)
  {
    msg_.target_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_Goal msg_;
};

class Init_TaskCommandAction_Goal_waypoint_lists
{
public:
  explicit Init_TaskCommandAction_Goal_waypoint_lists(::san_msgs::action::TaskCommandAction_Goal & msg)
  : msg_(msg)
  {}
  Init_TaskCommandAction_Goal_target_goal waypoint_lists(::san_msgs::action::TaskCommandAction_Goal::_waypoint_lists_type arg)
  {
    msg_.waypoint_lists = std::move(arg);
    return Init_TaskCommandAction_Goal_target_goal(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_Goal msg_;
};

class Init_TaskCommandAction_Goal_goal_node
{
public:
  explicit Init_TaskCommandAction_Goal_goal_node(::san_msgs::action::TaskCommandAction_Goal & msg)
  : msg_(msg)
  {}
  Init_TaskCommandAction_Goal_waypoint_lists goal_node(::san_msgs::action::TaskCommandAction_Goal::_goal_node_type arg)
  {
    msg_.goal_node = std::move(arg);
    return Init_TaskCommandAction_Goal_waypoint_lists(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_Goal msg_;
};

class Init_TaskCommandAction_Goal_start_node
{
public:
  explicit Init_TaskCommandAction_Goal_start_node(::san_msgs::action::TaskCommandAction_Goal & msg)
  : msg_(msg)
  {}
  Init_TaskCommandAction_Goal_goal_node start_node(::san_msgs::action::TaskCommandAction_Goal::_start_node_type arg)
  {
    msg_.start_node = std::move(arg);
    return Init_TaskCommandAction_Goal_goal_node(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_Goal msg_;
};

class Init_TaskCommandAction_Goal_mission
{
public:
  Init_TaskCommandAction_Goal_mission()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskCommandAction_Goal_start_node mission(::san_msgs::action::TaskCommandAction_Goal::_mission_type arg)
  {
    msg_.mission = std::move(arg);
    return Init_TaskCommandAction_Goal_start_node(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::TaskCommandAction_Goal>()
{
  return san_msgs::action::builder::Init_TaskCommandAction_Goal_mission();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_TaskCommandAction_Result_message
{
public:
  explicit Init_TaskCommandAction_Result_message(::san_msgs::action::TaskCommandAction_Result & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::TaskCommandAction_Result message(::san_msgs::action::TaskCommandAction_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_Result msg_;
};

class Init_TaskCommandAction_Result_success
{
public:
  Init_TaskCommandAction_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskCommandAction_Result_message success(::san_msgs::action::TaskCommandAction_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_TaskCommandAction_Result_message(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::TaskCommandAction_Result>()
{
  return san_msgs::action::builder::Init_TaskCommandAction_Result_success();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_TaskCommandAction_Feedback_current_behavior
{
public:
  Init_TaskCommandAction_Feedback_current_behavior()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::action::TaskCommandAction_Feedback current_behavior(::san_msgs::action::TaskCommandAction_Feedback::_current_behavior_type arg)
  {
    msg_.current_behavior = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::TaskCommandAction_Feedback>()
{
  return san_msgs::action::builder::Init_TaskCommandAction_Feedback_current_behavior();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_TaskCommandAction_SendGoal_Request_goal
{
public:
  explicit Init_TaskCommandAction_SendGoal_Request_goal(::san_msgs::action::TaskCommandAction_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::TaskCommandAction_SendGoal_Request goal(::san_msgs::action::TaskCommandAction_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_SendGoal_Request msg_;
};

class Init_TaskCommandAction_SendGoal_Request_goal_id
{
public:
  Init_TaskCommandAction_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskCommandAction_SendGoal_Request_goal goal_id(::san_msgs::action::TaskCommandAction_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_TaskCommandAction_SendGoal_Request_goal(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::TaskCommandAction_SendGoal_Request>()
{
  return san_msgs::action::builder::Init_TaskCommandAction_SendGoal_Request_goal_id();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_TaskCommandAction_SendGoal_Response_stamp
{
public:
  explicit Init_TaskCommandAction_SendGoal_Response_stamp(::san_msgs::action::TaskCommandAction_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::TaskCommandAction_SendGoal_Response stamp(::san_msgs::action::TaskCommandAction_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_SendGoal_Response msg_;
};

class Init_TaskCommandAction_SendGoal_Response_accepted
{
public:
  Init_TaskCommandAction_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskCommandAction_SendGoal_Response_stamp accepted(::san_msgs::action::TaskCommandAction_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_TaskCommandAction_SendGoal_Response_stamp(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::TaskCommandAction_SendGoal_Response>()
{
  return san_msgs::action::builder::Init_TaskCommandAction_SendGoal_Response_accepted();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_TaskCommandAction_GetResult_Request_goal_id
{
public:
  Init_TaskCommandAction_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::action::TaskCommandAction_GetResult_Request goal_id(::san_msgs::action::TaskCommandAction_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::TaskCommandAction_GetResult_Request>()
{
  return san_msgs::action::builder::Init_TaskCommandAction_GetResult_Request_goal_id();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_TaskCommandAction_GetResult_Response_result
{
public:
  explicit Init_TaskCommandAction_GetResult_Response_result(::san_msgs::action::TaskCommandAction_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::TaskCommandAction_GetResult_Response result(::san_msgs::action::TaskCommandAction_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_GetResult_Response msg_;
};

class Init_TaskCommandAction_GetResult_Response_status
{
public:
  Init_TaskCommandAction_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskCommandAction_GetResult_Response_result status(::san_msgs::action::TaskCommandAction_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_TaskCommandAction_GetResult_Response_result(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::TaskCommandAction_GetResult_Response>()
{
  return san_msgs::action::builder::Init_TaskCommandAction_GetResult_Response_status();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_TaskCommandAction_FeedbackMessage_feedback
{
public:
  explicit Init_TaskCommandAction_FeedbackMessage_feedback(::san_msgs::action::TaskCommandAction_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::TaskCommandAction_FeedbackMessage feedback(::san_msgs::action::TaskCommandAction_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_FeedbackMessage msg_;
};

class Init_TaskCommandAction_FeedbackMessage_goal_id
{
public:
  Init_TaskCommandAction_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskCommandAction_FeedbackMessage_feedback goal_id(::san_msgs::action::TaskCommandAction_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_TaskCommandAction_FeedbackMessage_feedback(msg_);
  }

private:
  ::san_msgs::action::TaskCommandAction_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::TaskCommandAction_FeedbackMessage>()
{
  return san_msgs::action::builder::Init_TaskCommandAction_FeedbackMessage_goal_id();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__BUILDER_HPP_
