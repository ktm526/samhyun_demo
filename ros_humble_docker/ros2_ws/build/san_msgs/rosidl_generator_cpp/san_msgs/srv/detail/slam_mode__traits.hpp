// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:srv/SlamMode.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__SLAM_MODE__TRAITS_HPP_
#define SAN_MSGS__SRV__DETAIL__SLAM_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/srv/detail/slam_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace san_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SlamMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: slam_start
  {
    out << "slam_start: ";
    rosidl_generator_traits::value_to_yaml(msg.slam_start, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SlamMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: slam_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slam_start: ";
    rosidl_generator_traits::value_to_yaml(msg.slam_start, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SlamMode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::srv::SlamMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::srv::SlamMode_Request & msg)
{
  return san_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::srv::SlamMode_Request>()
{
  return "san_msgs::srv::SlamMode_Request";
}

template<>
inline const char * name<san_msgs::srv::SlamMode_Request>()
{
  return "san_msgs/srv/SlamMode_Request";
}

template<>
struct has_fixed_size<san_msgs::srv::SlamMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<san_msgs::srv::SlamMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<san_msgs::srv::SlamMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace san_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SlamMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SlamMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SlamMode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::srv::SlamMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::srv::SlamMode_Response & msg)
{
  return san_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::srv::SlamMode_Response>()
{
  return "san_msgs::srv::SlamMode_Response";
}

template<>
inline const char * name<san_msgs::srv::SlamMode_Response>()
{
  return "san_msgs/srv/SlamMode_Response";
}

template<>
struct has_fixed_size<san_msgs::srv::SlamMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<san_msgs::srv::SlamMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<san_msgs::srv::SlamMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<san_msgs::srv::SlamMode>()
{
  return "san_msgs::srv::SlamMode";
}

template<>
inline const char * name<san_msgs::srv::SlamMode>()
{
  return "san_msgs/srv/SlamMode";
}

template<>
struct has_fixed_size<san_msgs::srv::SlamMode>
  : std::integral_constant<
    bool,
    has_fixed_size<san_msgs::srv::SlamMode_Request>::value &&
    has_fixed_size<san_msgs::srv::SlamMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<san_msgs::srv::SlamMode>
  : std::integral_constant<
    bool,
    has_bounded_size<san_msgs::srv::SlamMode_Request>::value &&
    has_bounded_size<san_msgs::srv::SlamMode_Response>::value
  >
{
};

template<>
struct is_service<san_msgs::srv::SlamMode>
  : std::true_type
{
};

template<>
struct is_service_request<san_msgs::srv::SlamMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<san_msgs::srv::SlamMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SAN_MSGS__SRV__DETAIL__SLAM_MODE__TRAITS_HPP_
