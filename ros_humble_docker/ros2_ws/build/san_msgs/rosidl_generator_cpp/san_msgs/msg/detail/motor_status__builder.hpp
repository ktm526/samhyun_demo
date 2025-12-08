// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_
#define SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/msg/detail/motor_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorStatus_state
{
public:
  Init_MotorStatus_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::msg::MotorStatus state(::san_msgs::msg::MotorStatus::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::msg::MotorStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::msg::MotorStatus>()
{
  return san_msgs::msg::builder::Init_MotorStatus_state();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_
