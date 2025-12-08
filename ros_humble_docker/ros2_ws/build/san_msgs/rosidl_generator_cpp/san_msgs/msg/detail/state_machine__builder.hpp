// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_
#define SAN_MSGS__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/msg/detail/state_machine__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace msg
{

namespace builder
{

class Init_StateMachine_status
{
public:
  explicit Init_StateMachine_status(::san_msgs::msg::StateMachine & msg)
  : msg_(msg)
  {}
  ::san_msgs::msg::StateMachine status(::san_msgs::msg::StateMachine::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::msg::StateMachine msg_;
};

class Init_StateMachine_state
{
public:
  Init_StateMachine_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateMachine_status state(::san_msgs::msg::StateMachine::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_StateMachine_status(msg_);
  }

private:
  ::san_msgs::msg::StateMachine msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::msg::StateMachine>()
{
  return san_msgs::msg::builder::Init_StateMachine_state();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__STATE_MACHINE__BUILDER_HPP_
