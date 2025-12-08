// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_
#define SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/msg/detail/battery_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace msg
{

namespace builder
{

class Init_BatteryStatus_charging_state
{
public:
  explicit Init_BatteryStatus_charging_state(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  ::san_msgs::msg::BatteryStatus charging_state(::san_msgs::msg::BatteryStatus::_charging_state_type arg)
  {
    msg_.charging_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_charging_jack_state
{
public:
  explicit Init_BatteryStatus_charging_jack_state(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_charging_state charging_jack_state(::san_msgs::msg::BatteryStatus::_charging_jack_state_type arg)
  {
    msg_.charging_jack_state = std::move(arg);
    return Init_BatteryStatus_charging_state(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_charge_relay
{
public:
  explicit Init_BatteryStatus_charge_relay(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_charging_jack_state charge_relay(::san_msgs::msg::BatteryStatus::_charge_relay_type arg)
  {
    msg_.charge_relay = std::move(arg);
    return Init_BatteryStatus_charging_jack_state(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_soh
{
public:
  explicit Init_BatteryStatus_soh(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_charge_relay soh(::san_msgs::msg::BatteryStatus::_soh_type arg)
  {
    msg_.soh = std::move(arg);
    return Init_BatteryStatus_charge_relay(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_soc
{
public:
  explicit Init_BatteryStatus_soc(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_soh soc(::san_msgs::msg::BatteryStatus::_soc_type arg)
  {
    msg_.soc = std::move(arg);
    return Init_BatteryStatus_soh(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_current
{
public:
  explicit Init_BatteryStatus_current(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_soc current(::san_msgs::msg::BatteryStatus::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_BatteryStatus_soc(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_voltage
{
public:
  explicit Init_BatteryStatus_voltage(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_current voltage(::san_msgs::msg::BatteryStatus::_voltage_type arg)
  {
    msg_.voltage = std::move(arg);
    return Init_BatteryStatus_current(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_soh_top
{
public:
  explicit Init_BatteryStatus_soh_top(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_voltage soh_top(::san_msgs::msg::BatteryStatus::_soh_top_type arg)
  {
    msg_.soh_top = std::move(arg);
    return Init_BatteryStatus_voltage(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_soc_top
{
public:
  explicit Init_BatteryStatus_soc_top(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_soh_top soc_top(::san_msgs::msg::BatteryStatus::_soc_top_type arg)
  {
    msg_.soc_top = std::move(arg);
    return Init_BatteryStatus_soh_top(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_current_top
{
public:
  explicit Init_BatteryStatus_current_top(::san_msgs::msg::BatteryStatus & msg)
  : msg_(msg)
  {}
  Init_BatteryStatus_soc_top current_top(::san_msgs::msg::BatteryStatus::_current_top_type arg)
  {
    msg_.current_top = std::move(arg);
    return Init_BatteryStatus_soc_top(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

class Init_BatteryStatus_voltage_top
{
public:
  Init_BatteryStatus_voltage_top()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BatteryStatus_current_top voltage_top(::san_msgs::msg::BatteryStatus::_voltage_top_type arg)
  {
    msg_.voltage_top = std::move(arg);
    return Init_BatteryStatus_current_top(msg_);
  }

private:
  ::san_msgs::msg::BatteryStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::msg::BatteryStatus>()
{
  return san_msgs::msg::builder::Init_BatteryStatus_voltage_top();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__BUILDER_HPP_
