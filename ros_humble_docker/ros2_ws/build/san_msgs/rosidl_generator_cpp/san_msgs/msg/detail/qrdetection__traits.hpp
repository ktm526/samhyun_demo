// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:msg/Qrdetection.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__QRDETECTION__TRAITS_HPP_
#define SAN_MSGS__MSG__DETAIL__QRDETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/msg/detail/qrdetection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'translation'
// Member 'rotation'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace san_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Qrdetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: cam_num
  {
    out << "cam_num: ";
    rosidl_generator_traits::value_to_yaml(msg.cam_num, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: translation
  {
    out << "translation: ";
    to_flow_style_yaml(msg.translation, out);
    out << ", ";
  }

  // member: rotation
  {
    out << "rotation: ";
    to_flow_style_yaml(msg.rotation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Qrdetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cam_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam_num: ";
    rosidl_generator_traits::value_to_yaml(msg.cam_num, out);
    out << "\n";
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: translation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "translation:\n";
    to_block_style_yaml(msg.translation, out, indentation + 2);
  }

  // member: rotation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotation:\n";
    to_block_style_yaml(msg.rotation, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Qrdetection & msg, bool use_flow_style = false)
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
  const san_msgs::msg::Qrdetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::msg::Qrdetection & msg)
{
  return san_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::msg::Qrdetection>()
{
  return "san_msgs::msg::Qrdetection";
}

template<>
inline const char * name<san_msgs::msg::Qrdetection>()
{
  return "san_msgs/msg/Qrdetection";
}

template<>
struct has_fixed_size<san_msgs::msg::Qrdetection>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<san_msgs::msg::Qrdetection>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<san_msgs::msg::Qrdetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SAN_MSGS__MSG__DETAIL__QRDETECTION__TRAITS_HPP_
