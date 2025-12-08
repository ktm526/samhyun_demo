// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:msg/Behavior.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__BEHAVIOR__BUILDER_HPP_
#define SAN_MSGS__MSG__DETAIL__BEHAVIOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/msg/detail/behavior__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace msg
{

namespace builder
{

class Init_Behavior_behavior_manual_mode_triggered
{
public:
  explicit Init_Behavior_behavior_manual_mode_triggered(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  ::san_msgs::msg::Behavior behavior_manual_mode_triggered(::san_msgs::msg::Behavior::_behavior_manual_mode_triggered_type arg)
  {
    msg_.behavior_manual_mode_triggered = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_manipulator_emergency_triggered
{
public:
  explicit Init_Behavior_behavior_manipulator_emergency_triggered(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_manual_mode_triggered behavior_manipulator_emergency_triggered(::san_msgs::msg::Behavior::_behavior_manipulator_emergency_triggered_type arg)
  {
    msg_.behavior_manipulator_emergency_triggered = std::move(arg);
    return Init_Behavior_behavior_manual_mode_triggered(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_manipulator_completed
{
public:
  explicit Init_Behavior_behavior_manipulator_completed(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_manipulator_emergency_triggered behavior_manipulator_completed(::san_msgs::msg::Behavior::_behavior_manipulator_completed_type arg)
  {
    msg_.behavior_manipulator_completed = std::move(arg);
    return Init_Behavior_behavior_manipulator_emergency_triggered(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_charging_redocking_triggered
{
public:
  explicit Init_Behavior_behavior_charging_redocking_triggered(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_manipulator_completed behavior_charging_redocking_triggered(::san_msgs::msg::Behavior::_behavior_charging_redocking_triggered_type arg)
  {
    msg_.behavior_charging_redocking_triggered = std::move(arg);
    return Init_Behavior_behavior_manipulator_completed(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_manipulation_redocking_triggered
{
public:
  explicit Init_Behavior_behavior_manipulation_redocking_triggered(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_charging_redocking_triggered behavior_manipulation_redocking_triggered(::san_msgs::msg::Behavior::_behavior_manipulation_redocking_triggered_type arg)
  {
    msg_.behavior_manipulation_redocking_triggered = std::move(arg);
    return Init_Behavior_behavior_charging_redocking_triggered(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_docking_canceled
{
public:
  explicit Init_Behavior_behavior_docking_canceled(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_manipulation_redocking_triggered behavior_docking_canceled(::san_msgs::msg::Behavior::_behavior_docking_canceled_type arg)
  {
    msg_.behavior_docking_canceled = std::move(arg);
    return Init_Behavior_behavior_manipulation_redocking_triggered(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_auto_canceled
{
public:
  explicit Init_Behavior_behavior_auto_canceled(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_docking_canceled behavior_auto_canceled(::san_msgs::msg::Behavior::_behavior_auto_canceled_type arg)
  {
    msg_.behavior_auto_canceled = std::move(arg);
    return Init_Behavior_behavior_docking_canceled(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_undocking_completed
{
public:
  explicit Init_Behavior_behavior_undocking_completed(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_auto_canceled behavior_undocking_completed(::san_msgs::msg::Behavior::_behavior_undocking_completed_type arg)
  {
    msg_.behavior_undocking_completed = std::move(arg);
    return Init_Behavior_behavior_auto_canceled(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_docking_completed
{
public:
  explicit Init_Behavior_behavior_docking_completed(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_undocking_completed behavior_docking_completed(::san_msgs::msg::Behavior::_behavior_docking_completed_type arg)
  {
    msg_.behavior_docking_completed = std::move(arg);
    return Init_Behavior_behavior_undocking_completed(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_charge_completed
{
public:
  explicit Init_Behavior_behavior_charge_completed(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_docking_completed behavior_charge_completed(::san_msgs::msg::Behavior::_behavior_charge_completed_type arg)
  {
    msg_.behavior_charge_completed = std::move(arg);
    return Init_Behavior_behavior_docking_completed(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_slam_completed
{
public:
  explicit Init_Behavior_behavior_slam_completed(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_charge_completed behavior_slam_completed(::san_msgs::msg::Behavior::_behavior_slam_completed_type arg)
  {
    msg_.behavior_slam_completed = std::move(arg);
    return Init_Behavior_behavior_charge_completed(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_auto_completed
{
public:
  explicit Init_Behavior_behavior_auto_completed(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_slam_completed behavior_auto_completed(::san_msgs::msg::Behavior::_behavior_auto_completed_type arg)
  {
    msg_.behavior_auto_completed = std::move(arg);
    return Init_Behavior_behavior_slam_completed(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_undocking_started
{
public:
  explicit Init_Behavior_behavior_undocking_started(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_auto_completed behavior_undocking_started(::san_msgs::msg::Behavior::_behavior_undocking_started_type arg)
  {
    msg_.behavior_undocking_started = std::move(arg);
    return Init_Behavior_behavior_auto_completed(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_docking_started
{
public:
  explicit Init_Behavior_behavior_docking_started(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_undocking_started behavior_docking_started(::san_msgs::msg::Behavior::_behavior_docking_started_type arg)
  {
    msg_.behavior_docking_started = std::move(arg);
    return Init_Behavior_behavior_undocking_started(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_charge_started
{
public:
  explicit Init_Behavior_behavior_charge_started(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_docking_started behavior_charge_started(::san_msgs::msg::Behavior::_behavior_charge_started_type arg)
  {
    msg_.behavior_charge_started = std::move(arg);
    return Init_Behavior_behavior_docking_started(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_slam_started
{
public:
  explicit Init_Behavior_behavior_slam_started(::san_msgs::msg::Behavior & msg)
  : msg_(msg)
  {}
  Init_Behavior_behavior_charge_started behavior_slam_started(::san_msgs::msg::Behavior::_behavior_slam_started_type arg)
  {
    msg_.behavior_slam_started = std::move(arg);
    return Init_Behavior_behavior_charge_started(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

class Init_Behavior_behavior_auto_started
{
public:
  Init_Behavior_behavior_auto_started()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Behavior_behavior_slam_started behavior_auto_started(::san_msgs::msg::Behavior::_behavior_auto_started_type arg)
  {
    msg_.behavior_auto_started = std::move(arg);
    return Init_Behavior_behavior_slam_started(msg_);
  }

private:
  ::san_msgs::msg::Behavior msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::msg::Behavior>()
{
  return san_msgs::msg::builder::Init_Behavior_behavior_auto_started();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__BEHAVIOR__BUILDER_HPP_
