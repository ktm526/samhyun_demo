// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_
#define SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/msg/detail/battery_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace san_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BatteryStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: voltage_top
  {
    out << "voltage_top: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_top, out);
    out << ", ";
  }

  // member: current_top
  {
    out << "current_top: ";
    rosidl_generator_traits::value_to_yaml(msg.current_top, out);
    out << ", ";
  }

  // member: soc_top
  {
    out << "soc_top: ";
    rosidl_generator_traits::value_to_yaml(msg.soc_top, out);
    out << ", ";
  }

  // member: soh_top
  {
    out << "soh_top: ";
    rosidl_generator_traits::value_to_yaml(msg.soh_top, out);
    out << ", ";
  }

  // member: voltage
  {
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << ", ";
  }

  // member: soc
  {
    out << "soc: ";
    rosidl_generator_traits::value_to_yaml(msg.soc, out);
    out << ", ";
  }

  // member: soh
  {
    out << "soh: ";
    rosidl_generator_traits::value_to_yaml(msg.soh, out);
    out << ", ";
  }

  // member: charge_relay
  {
    out << "charge_relay: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_relay, out);
    out << ", ";
  }

  // member: charging_jack_state
  {
    out << "charging_jack_state: ";
    rosidl_generator_traits::value_to_yaml(msg.charging_jack_state, out);
    out << ", ";
  }

  // member: charging_state
  {
    out << "charging_state: ";
    rosidl_generator_traits::value_to_yaml(msg.charging_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BatteryStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: voltage_top
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage_top: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage_top, out);
    out << "\n";
  }

  // member: current_top
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_top: ";
    rosidl_generator_traits::value_to_yaml(msg.current_top, out);
    out << "\n";
  }

  // member: soc_top
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "soc_top: ";
    rosidl_generator_traits::value_to_yaml(msg.soc_top, out);
    out << "\n";
  }

  // member: soh_top
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "soh_top: ";
    rosidl_generator_traits::value_to_yaml(msg.soh_top, out);
    out << "\n";
  }

  // member: voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << "\n";
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << "\n";
  }

  // member: soc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "soc: ";
    rosidl_generator_traits::value_to_yaml(msg.soc, out);
    out << "\n";
  }

  // member: soh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "soh: ";
    rosidl_generator_traits::value_to_yaml(msg.soh, out);
    out << "\n";
  }

  // member: charge_relay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charge_relay: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_relay, out);
    out << "\n";
  }

  // member: charging_jack_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charging_jack_state: ";
    rosidl_generator_traits::value_to_yaml(msg.charging_jack_state, out);
    out << "\n";
  }

  // member: charging_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charging_state: ";
    rosidl_generator_traits::value_to_yaml(msg.charging_state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BatteryStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::msg::BatteryStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::msg::BatteryStatus & msg)
{
  return san_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::msg::BatteryStatus>()
{
  return "san_msgs::msg::BatteryStatus";
}

template<>
inline const char * name<san_msgs::msg::BatteryStatus>()
{
  return "san_msgs/msg/BatteryStatus";
}

template<>
struct has_fixed_size<san_msgs::msg::BatteryStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<san_msgs::msg::BatteryStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<san_msgs::msg::BatteryStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__TRAITS_HPP_
