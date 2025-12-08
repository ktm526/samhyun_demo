// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:msg/Behavior.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__BEHAVIOR__TRAITS_HPP_
#define SAN_MSGS__MSG__DETAIL__BEHAVIOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/msg/detail/behavior__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace san_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Behavior & msg,
  std::ostream & out)
{
  out << "{";
  // member: behavior_auto_started
  {
    out << "behavior_auto_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_auto_started, out);
    out << ", ";
  }

  // member: behavior_slam_started
  {
    out << "behavior_slam_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_slam_started, out);
    out << ", ";
  }

  // member: behavior_charge_started
  {
    out << "behavior_charge_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_charge_started, out);
    out << ", ";
  }

  // member: behavior_docking_started
  {
    out << "behavior_docking_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_docking_started, out);
    out << ", ";
  }

  // member: behavior_undocking_started
  {
    out << "behavior_undocking_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_undocking_started, out);
    out << ", ";
  }

  // member: behavior_auto_completed
  {
    out << "behavior_auto_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_auto_completed, out);
    out << ", ";
  }

  // member: behavior_slam_completed
  {
    out << "behavior_slam_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_slam_completed, out);
    out << ", ";
  }

  // member: behavior_charge_completed
  {
    out << "behavior_charge_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_charge_completed, out);
    out << ", ";
  }

  // member: behavior_docking_completed
  {
    out << "behavior_docking_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_docking_completed, out);
    out << ", ";
  }

  // member: behavior_undocking_completed
  {
    out << "behavior_undocking_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_undocking_completed, out);
    out << ", ";
  }

  // member: behavior_auto_canceled
  {
    out << "behavior_auto_canceled: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_auto_canceled, out);
    out << ", ";
  }

  // member: behavior_docking_canceled
  {
    out << "behavior_docking_canceled: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_docking_canceled, out);
    out << ", ";
  }

  // member: behavior_manipulation_redocking_triggered
  {
    out << "behavior_manipulation_redocking_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_manipulation_redocking_triggered, out);
    out << ", ";
  }

  // member: behavior_charging_redocking_triggered
  {
    out << "behavior_charging_redocking_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_charging_redocking_triggered, out);
    out << ", ";
  }

  // member: behavior_manipulator_completed
  {
    out << "behavior_manipulator_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_manipulator_completed, out);
    out << ", ";
  }

  // member: behavior_manipulator_emergency_triggered
  {
    out << "behavior_manipulator_emergency_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_manipulator_emergency_triggered, out);
    out << ", ";
  }

  // member: behavior_manual_mode_triggered
  {
    out << "behavior_manual_mode_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_manual_mode_triggered, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Behavior & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: behavior_auto_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_auto_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_auto_started, out);
    out << "\n";
  }

  // member: behavior_slam_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_slam_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_slam_started, out);
    out << "\n";
  }

  // member: behavior_charge_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_charge_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_charge_started, out);
    out << "\n";
  }

  // member: behavior_docking_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_docking_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_docking_started, out);
    out << "\n";
  }

  // member: behavior_undocking_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_undocking_started: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_undocking_started, out);
    out << "\n";
  }

  // member: behavior_auto_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_auto_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_auto_completed, out);
    out << "\n";
  }

  // member: behavior_slam_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_slam_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_slam_completed, out);
    out << "\n";
  }

  // member: behavior_charge_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_charge_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_charge_completed, out);
    out << "\n";
  }

  // member: behavior_docking_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_docking_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_docking_completed, out);
    out << "\n";
  }

  // member: behavior_undocking_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_undocking_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_undocking_completed, out);
    out << "\n";
  }

  // member: behavior_auto_canceled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_auto_canceled: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_auto_canceled, out);
    out << "\n";
  }

  // member: behavior_docking_canceled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_docking_canceled: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_docking_canceled, out);
    out << "\n";
  }

  // member: behavior_manipulation_redocking_triggered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_manipulation_redocking_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_manipulation_redocking_triggered, out);
    out << "\n";
  }

  // member: behavior_charging_redocking_triggered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_charging_redocking_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_charging_redocking_triggered, out);
    out << "\n";
  }

  // member: behavior_manipulator_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_manipulator_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_manipulator_completed, out);
    out << "\n";
  }

  // member: behavior_manipulator_emergency_triggered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_manipulator_emergency_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_manipulator_emergency_triggered, out);
    out << "\n";
  }

  // member: behavior_manual_mode_triggered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "behavior_manual_mode_triggered: ";
    rosidl_generator_traits::value_to_yaml(msg.behavior_manual_mode_triggered, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Behavior & msg, bool use_flow_style = false)
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
  const san_msgs::msg::Behavior & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::msg::Behavior & msg)
{
  return san_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::msg::Behavior>()
{
  return "san_msgs::msg::Behavior";
}

template<>
inline const char * name<san_msgs::msg::Behavior>()
{
  return "san_msgs/msg/Behavior";
}

template<>
struct has_fixed_size<san_msgs::msg::Behavior>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<san_msgs::msg::Behavior>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<san_msgs::msg::Behavior>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SAN_MSGS__MSG__DETAIL__BEHAVIOR__TRAITS_HPP_
