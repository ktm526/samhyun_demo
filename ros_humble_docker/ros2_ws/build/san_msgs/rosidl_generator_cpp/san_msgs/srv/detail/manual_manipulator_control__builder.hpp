// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:srv/ManualManipulatorControl.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__MANUAL_MANIPULATOR_CONTROL__BUILDER_HPP_
#define SAN_MSGS__SRV__DETAIL__MANUAL_MANIPULATOR_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/srv/detail/manual_manipulator_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_ManualManipulatorControl_Request_position
{
public:
  explicit Init_ManualManipulatorControl_Request_position(::san_msgs::srv::ManualManipulatorControl_Request & msg)
  : msg_(msg)
  {}
  ::san_msgs::srv::ManualManipulatorControl_Request position(::san_msgs::srv::ManualManipulatorControl_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::ManualManipulatorControl_Request msg_;
};

class Init_ManualManipulatorControl_Request_command
{
public:
  Init_ManualManipulatorControl_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManualManipulatorControl_Request_position command(::san_msgs::srv::ManualManipulatorControl_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_ManualManipulatorControl_Request_position(msg_);
  }

private:
  ::san_msgs::srv::ManualManipulatorControl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::ManualManipulatorControl_Request>()
{
  return san_msgs::srv::builder::Init_ManualManipulatorControl_Request_command();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_ManualManipulatorControl_Response_success
{
public:
  Init_ManualManipulatorControl_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::srv::ManualManipulatorControl_Response success(::san_msgs::srv::ManualManipulatorControl_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::ManualManipulatorControl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::ManualManipulatorControl_Response>()
{
  return san_msgs::srv::builder::Init_ManualManipulatorControl_Response_success();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__MANUAL_MANIPULATOR_CONTROL__BUILDER_HPP_
