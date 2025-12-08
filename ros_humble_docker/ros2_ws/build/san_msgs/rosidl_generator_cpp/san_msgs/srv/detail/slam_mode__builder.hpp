// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:srv/SlamMode.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__SLAM_MODE__BUILDER_HPP_
#define SAN_MSGS__SRV__DETAIL__SLAM_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/srv/detail/slam_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_SlamMode_Request_slam_start
{
public:
  Init_SlamMode_Request_slam_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::srv::SlamMode_Request slam_start(::san_msgs::srv::SlamMode_Request::_slam_start_type arg)
  {
    msg_.slam_start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::SlamMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::SlamMode_Request>()
{
  return san_msgs::srv::builder::Init_SlamMode_Request_slam_start();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_SlamMode_Response_message
{
public:
  explicit Init_SlamMode_Response_message(::san_msgs::srv::SlamMode_Response & msg)
  : msg_(msg)
  {}
  ::san_msgs::srv::SlamMode_Response message(::san_msgs::srv::SlamMode_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::SlamMode_Response msg_;
};

class Init_SlamMode_Response_success
{
public:
  Init_SlamMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SlamMode_Response_message success(::san_msgs::srv::SlamMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SlamMode_Response_message(msg_);
  }

private:
  ::san_msgs::srv::SlamMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::SlamMode_Response>()
{
  return san_msgs::srv::builder::Init_SlamMode_Response_success();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__SLAM_MODE__BUILDER_HPP_
