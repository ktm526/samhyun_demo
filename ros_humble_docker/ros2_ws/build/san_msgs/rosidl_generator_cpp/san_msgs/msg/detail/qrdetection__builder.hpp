// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:msg/Qrdetection.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__QRDETECTION__BUILDER_HPP_
#define SAN_MSGS__MSG__DETAIL__QRDETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/msg/detail/qrdetection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace msg
{

namespace builder
{

class Init_Qrdetection_rotation
{
public:
  explicit Init_Qrdetection_rotation(::san_msgs::msg::Qrdetection & msg)
  : msg_(msg)
  {}
  ::san_msgs::msg::Qrdetection rotation(::san_msgs::msg::Qrdetection::_rotation_type arg)
  {
    msg_.rotation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::msg::Qrdetection msg_;
};

class Init_Qrdetection_translation
{
public:
  explicit Init_Qrdetection_translation(::san_msgs::msg::Qrdetection & msg)
  : msg_(msg)
  {}
  Init_Qrdetection_rotation translation(::san_msgs::msg::Qrdetection::_translation_type arg)
  {
    msg_.translation = std::move(arg);
    return Init_Qrdetection_rotation(msg_);
  }

private:
  ::san_msgs::msg::Qrdetection msg_;
};

class Init_Qrdetection_id
{
public:
  explicit Init_Qrdetection_id(::san_msgs::msg::Qrdetection & msg)
  : msg_(msg)
  {}
  Init_Qrdetection_translation id(::san_msgs::msg::Qrdetection::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Qrdetection_translation(msg_);
  }

private:
  ::san_msgs::msg::Qrdetection msg_;
};

class Init_Qrdetection_cam_num
{
public:
  Init_Qrdetection_cam_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Qrdetection_id cam_num(::san_msgs::msg::Qrdetection::_cam_num_type arg)
  {
    msg_.cam_num = std::move(arg);
    return Init_Qrdetection_id(msg_);
  }

private:
  ::san_msgs::msg::Qrdetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::msg::Qrdetection>()
{
  return san_msgs::msg::builder::Init_Qrdetection_cam_num();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__QRDETECTION__BUILDER_HPP_
