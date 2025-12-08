// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:srv/GetWaypoints.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__BUILDER_HPP_
#define SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/srv/detail/get_waypoints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWaypoints_Request_node_file
{
public:
  explicit Init_GetWaypoints_Request_node_file(::san_msgs::srv::GetWaypoints_Request & msg)
  : msg_(msg)
  {}
  ::san_msgs::srv::GetWaypoints_Request node_file(::san_msgs::srv::GetWaypoints_Request::_node_file_type arg)
  {
    msg_.node_file = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::GetWaypoints_Request msg_;
};

class Init_GetWaypoints_Request_goal_node
{
public:
  explicit Init_GetWaypoints_Request_goal_node(::san_msgs::srv::GetWaypoints_Request & msg)
  : msg_(msg)
  {}
  Init_GetWaypoints_Request_node_file goal_node(::san_msgs::srv::GetWaypoints_Request::_goal_node_type arg)
  {
    msg_.goal_node = std::move(arg);
    return Init_GetWaypoints_Request_node_file(msg_);
  }

private:
  ::san_msgs::srv::GetWaypoints_Request msg_;
};

class Init_GetWaypoints_Request_start_node
{
public:
  Init_GetWaypoints_Request_start_node()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWaypoints_Request_goal_node start_node(::san_msgs::srv::GetWaypoints_Request::_start_node_type arg)
  {
    msg_.start_node = std::move(arg);
    return Init_GetWaypoints_Request_goal_node(msg_);
  }

private:
  ::san_msgs::srv::GetWaypoints_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::GetWaypoints_Request>()
{
  return san_msgs::srv::builder::Init_GetWaypoints_Request_start_node();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWaypoints_Response_node_path
{
public:
  explicit Init_GetWaypoints_Response_node_path(::san_msgs::srv::GetWaypoints_Response & msg)
  : msg_(msg)
  {}
  ::san_msgs::srv::GetWaypoints_Response node_path(::san_msgs::srv::GetWaypoints_Response::_node_path_type arg)
  {
    msg_.node_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::GetWaypoints_Response msg_;
};

class Init_GetWaypoints_Response_waypoints
{
public:
  explicit Init_GetWaypoints_Response_waypoints(::san_msgs::srv::GetWaypoints_Response & msg)
  : msg_(msg)
  {}
  Init_GetWaypoints_Response_node_path waypoints(::san_msgs::srv::GetWaypoints_Response::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return Init_GetWaypoints_Response_node_path(msg_);
  }

private:
  ::san_msgs::srv::GetWaypoints_Response msg_;
};

class Init_GetWaypoints_Response_message
{
public:
  explicit Init_GetWaypoints_Response_message(::san_msgs::srv::GetWaypoints_Response & msg)
  : msg_(msg)
  {}
  Init_GetWaypoints_Response_waypoints message(::san_msgs::srv::GetWaypoints_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetWaypoints_Response_waypoints(msg_);
  }

private:
  ::san_msgs::srv::GetWaypoints_Response msg_;
};

class Init_GetWaypoints_Response_success
{
public:
  Init_GetWaypoints_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWaypoints_Response_message success(::san_msgs::srv::GetWaypoints_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetWaypoints_Response_message(msg_);
  }

private:
  ::san_msgs::srv::GetWaypoints_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::GetWaypoints_Response>()
{
  return san_msgs::srv::builder::Init_GetWaypoints_Response_success();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__BUILDER_HPP_
