// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:srv/TaskCommand.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__TASK_COMMAND__BUILDER_HPP_
#define SAN_MSGS__SRV__DETAIL__TASK_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/srv/detail/task_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskCommand_Request_target_goal
{
public:
  explicit Init_TaskCommand_Request_target_goal(::san_msgs::srv::TaskCommand_Request & msg)
  : msg_(msg)
  {}
  ::san_msgs::srv::TaskCommand_Request target_goal(::san_msgs::srv::TaskCommand_Request::_target_goal_type arg)
  {
    msg_.target_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::TaskCommand_Request msg_;
};

class Init_TaskCommand_Request_waypoint_lists
{
public:
  explicit Init_TaskCommand_Request_waypoint_lists(::san_msgs::srv::TaskCommand_Request & msg)
  : msg_(msg)
  {}
  Init_TaskCommand_Request_target_goal waypoint_lists(::san_msgs::srv::TaskCommand_Request::_waypoint_lists_type arg)
  {
    msg_.waypoint_lists = std::move(arg);
    return Init_TaskCommand_Request_target_goal(msg_);
  }

private:
  ::san_msgs::srv::TaskCommand_Request msg_;
};

class Init_TaskCommand_Request_goal_node
{
public:
  explicit Init_TaskCommand_Request_goal_node(::san_msgs::srv::TaskCommand_Request & msg)
  : msg_(msg)
  {}
  Init_TaskCommand_Request_waypoint_lists goal_node(::san_msgs::srv::TaskCommand_Request::_goal_node_type arg)
  {
    msg_.goal_node = std::move(arg);
    return Init_TaskCommand_Request_waypoint_lists(msg_);
  }

private:
  ::san_msgs::srv::TaskCommand_Request msg_;
};

class Init_TaskCommand_Request_start_node
{
public:
  explicit Init_TaskCommand_Request_start_node(::san_msgs::srv::TaskCommand_Request & msg)
  : msg_(msg)
  {}
  Init_TaskCommand_Request_goal_node start_node(::san_msgs::srv::TaskCommand_Request::_start_node_type arg)
  {
    msg_.start_node = std::move(arg);
    return Init_TaskCommand_Request_goal_node(msg_);
  }

private:
  ::san_msgs::srv::TaskCommand_Request msg_;
};

class Init_TaskCommand_Request_mission
{
public:
  Init_TaskCommand_Request_mission()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskCommand_Request_start_node mission(::san_msgs::srv::TaskCommand_Request::_mission_type arg)
  {
    msg_.mission = std::move(arg);
    return Init_TaskCommand_Request_start_node(msg_);
  }

private:
  ::san_msgs::srv::TaskCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::TaskCommand_Request>()
{
  return san_msgs::srv::builder::Init_TaskCommand_Request_mission();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskCommand_Response_message
{
public:
  explicit Init_TaskCommand_Response_message(::san_msgs::srv::TaskCommand_Response & msg)
  : msg_(msg)
  {}
  ::san_msgs::srv::TaskCommand_Response message(::san_msgs::srv::TaskCommand_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::TaskCommand_Response msg_;
};

class Init_TaskCommand_Response_success
{
public:
  Init_TaskCommand_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskCommand_Response_message success(::san_msgs::srv::TaskCommand_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_TaskCommand_Response_message(msg_);
  }

private:
  ::san_msgs::srv::TaskCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::TaskCommand_Response>()
{
  return san_msgs::srv::builder::Init_TaskCommand_Response_success();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__TASK_COMMAND__BUILDER_HPP_
