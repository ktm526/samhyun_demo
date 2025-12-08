// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:action/MarkerDocking.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__ACTION__DETAIL__MARKER_DOCKING__BUILDER_HPP_
#define SAN_MSGS__ACTION__DETAIL__MARKER_DOCKING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/action/detail/marker_docking__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_MarkerDocking_Goal_marker_id
{
public:
  explicit Init_MarkerDocking_Goal_marker_id(::san_msgs::action::MarkerDocking_Goal & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::MarkerDocking_Goal marker_id(::san_msgs::action::MarkerDocking_Goal::_marker_id_type arg)
  {
    msg_.marker_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_Goal msg_;
};

class Init_MarkerDocking_Goal_marker_gap
{
public:
  explicit Init_MarkerDocking_Goal_marker_gap(::san_msgs::action::MarkerDocking_Goal & msg)
  : msg_(msg)
  {}
  Init_MarkerDocking_Goal_marker_id marker_gap(::san_msgs::action::MarkerDocking_Goal::_marker_gap_type arg)
  {
    msg_.marker_gap = std::move(arg);
    return Init_MarkerDocking_Goal_marker_id(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_Goal msg_;
};

class Init_MarkerDocking_Goal_camera_mode
{
public:
  Init_MarkerDocking_Goal_camera_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkerDocking_Goal_marker_gap camera_mode(::san_msgs::action::MarkerDocking_Goal::_camera_mode_type arg)
  {
    msg_.camera_mode = std::move(arg);
    return Init_MarkerDocking_Goal_marker_gap(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::MarkerDocking_Goal>()
{
  return san_msgs::action::builder::Init_MarkerDocking_Goal_camera_mode();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_MarkerDocking_Result_success
{
public:
  Init_MarkerDocking_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::action::MarkerDocking_Result success(::san_msgs::action::MarkerDocking_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::MarkerDocking_Result>()
{
  return san_msgs::action::builder::Init_MarkerDocking_Result_success();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_MarkerDocking_Feedback_step
{
public:
  Init_MarkerDocking_Feedback_step()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::action::MarkerDocking_Feedback step(::san_msgs::action::MarkerDocking_Feedback::_step_type arg)
  {
    msg_.step = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::MarkerDocking_Feedback>()
{
  return san_msgs::action::builder::Init_MarkerDocking_Feedback_step();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_MarkerDocking_SendGoal_Request_goal
{
public:
  explicit Init_MarkerDocking_SendGoal_Request_goal(::san_msgs::action::MarkerDocking_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::MarkerDocking_SendGoal_Request goal(::san_msgs::action::MarkerDocking_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_SendGoal_Request msg_;
};

class Init_MarkerDocking_SendGoal_Request_goal_id
{
public:
  Init_MarkerDocking_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkerDocking_SendGoal_Request_goal goal_id(::san_msgs::action::MarkerDocking_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MarkerDocking_SendGoal_Request_goal(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::MarkerDocking_SendGoal_Request>()
{
  return san_msgs::action::builder::Init_MarkerDocking_SendGoal_Request_goal_id();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_MarkerDocking_SendGoal_Response_stamp
{
public:
  explicit Init_MarkerDocking_SendGoal_Response_stamp(::san_msgs::action::MarkerDocking_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::MarkerDocking_SendGoal_Response stamp(::san_msgs::action::MarkerDocking_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_SendGoal_Response msg_;
};

class Init_MarkerDocking_SendGoal_Response_accepted
{
public:
  Init_MarkerDocking_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkerDocking_SendGoal_Response_stamp accepted(::san_msgs::action::MarkerDocking_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MarkerDocking_SendGoal_Response_stamp(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::MarkerDocking_SendGoal_Response>()
{
  return san_msgs::action::builder::Init_MarkerDocking_SendGoal_Response_accepted();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_MarkerDocking_GetResult_Request_goal_id
{
public:
  Init_MarkerDocking_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::action::MarkerDocking_GetResult_Request goal_id(::san_msgs::action::MarkerDocking_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::MarkerDocking_GetResult_Request>()
{
  return san_msgs::action::builder::Init_MarkerDocking_GetResult_Request_goal_id();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_MarkerDocking_GetResult_Response_result
{
public:
  explicit Init_MarkerDocking_GetResult_Response_result(::san_msgs::action::MarkerDocking_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::MarkerDocking_GetResult_Response result(::san_msgs::action::MarkerDocking_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_GetResult_Response msg_;
};

class Init_MarkerDocking_GetResult_Response_status
{
public:
  Init_MarkerDocking_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkerDocking_GetResult_Response_result status(::san_msgs::action::MarkerDocking_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MarkerDocking_GetResult_Response_result(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::MarkerDocking_GetResult_Response>()
{
  return san_msgs::action::builder::Init_MarkerDocking_GetResult_Response_status();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace action
{

namespace builder
{

class Init_MarkerDocking_FeedbackMessage_feedback
{
public:
  explicit Init_MarkerDocking_FeedbackMessage_feedback(::san_msgs::action::MarkerDocking_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::san_msgs::action::MarkerDocking_FeedbackMessage feedback(::san_msgs::action::MarkerDocking_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_FeedbackMessage msg_;
};

class Init_MarkerDocking_FeedbackMessage_goal_id
{
public:
  Init_MarkerDocking_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkerDocking_FeedbackMessage_feedback goal_id(::san_msgs::action::MarkerDocking_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MarkerDocking_FeedbackMessage_feedback(msg_);
  }

private:
  ::san_msgs::action::MarkerDocking_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::action::MarkerDocking_FeedbackMessage>()
{
  return san_msgs::action::builder::Init_MarkerDocking_FeedbackMessage_goal_id();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__ACTION__DETAIL__MARKER_DOCKING__BUILDER_HPP_
