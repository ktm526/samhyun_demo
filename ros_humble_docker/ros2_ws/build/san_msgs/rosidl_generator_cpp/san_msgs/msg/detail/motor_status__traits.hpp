// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_
#define SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/msg/detail/motor_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace san_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorStatus & msg, bool use_flow_style = false)
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
  const san_msgs::msg::MotorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::msg::MotorStatus & msg)
{
  return san_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::msg::MotorStatus>()
{
  return "san_msgs::msg::MotorStatus";
}

template<>
inline const char * name<san_msgs::msg::MotorStatus>()
{
  return "san_msgs/msg/MotorStatus";
}

template<>
struct has_fixed_size<san_msgs::msg::MotorStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<san_msgs::msg::MotorStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<san_msgs::msg::MotorStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_
