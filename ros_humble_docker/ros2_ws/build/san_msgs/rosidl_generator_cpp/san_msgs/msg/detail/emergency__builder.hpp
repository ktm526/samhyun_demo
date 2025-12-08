// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:msg/Emergency.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__EMERGENCY__BUILDER_HPP_
#define SAN_MSGS__MSG__DETAIL__EMERGENCY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/msg/detail/emergency__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace msg
{

namespace builder
{

class Init_Emergency_emergency
{
public:
  Init_Emergency_emergency()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::san_msgs::msg::Emergency emergency(::san_msgs::msg::Emergency::_emergency_type arg)
  {
    msg_.emergency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::msg::Emergency msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::msg::Emergency>()
{
  return san_msgs::msg::builder::Init_Emergency_emergency();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__EMERGENCY__BUILDER_HPP_
