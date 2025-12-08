// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:srv/GetWaypoints.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__TRAITS_HPP_
#define SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/srv/detail/get_waypoints__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace san_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetWaypoints_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: start_node
  {
    out << "start_node: ";
    rosidl_generator_traits::value_to_yaml(msg.start_node, out);
    out << ", ";
  }

  // member: goal_node
  {
    out << "goal_node: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_node, out);
    out << ", ";
  }

  // member: node_file
  {
    out << "node_file: ";
    rosidl_generator_traits::value_to_yaml(msg.node_file, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetWaypoints_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start_node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_node: ";
    rosidl_generator_traits::value_to_yaml(msg.start_node, out);
    out << "\n";
  }

  // member: goal_node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_node: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_node, out);
    out << "\n";
  }

  // member: node_file
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_file: ";
    rosidl_generator_traits::value_to_yaml(msg.node_file, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetWaypoints_Request & msg, bool use_flow_style = false)
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
  const san_msgs::srv::GetWaypoints_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::srv::GetWaypoints_Request & msg)
{
  return san_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::srv::GetWaypoints_Request>()
{
  return "san_msgs::srv::GetWaypoints_Request";
}

template<>
inline const char * name<san_msgs::srv::GetWaypoints_Request>()
{
  return "san_msgs/srv/GetWaypoints_Request";
}

template<>
struct has_fixed_size<san_msgs::srv::GetWaypoints_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<san_msgs::srv::GetWaypoints_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<san_msgs::srv::GetWaypoints_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/pose_array__traits.hpp"

namespace san_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetWaypoints_Response & msg,
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
    out << ", ";
  }

  // member: waypoints
  {
    out << "waypoints: ";
    to_flow_style_yaml(msg.waypoints, out);
    out << ", ";
  }

  // member: node_path
  {
    if (msg.node_path.size() == 0) {
      out << "node_path: []";
    } else {
      out << "node_path: [";
      size_t pending_items = msg.node_path.size();
      for (auto item : msg.node_path) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetWaypoints_Response & msg,
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

  // member: waypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "waypoints:\n";
    to_block_style_yaml(msg.waypoints, out, indentation + 2);
  }

  // member: node_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.node_path.size() == 0) {
      out << "node_path: []\n";
    } else {
      out << "node_path:\n";
      for (auto item : msg.node_path) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetWaypoints_Response & msg, bool use_flow_style = false)
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
  const san_msgs::srv::GetWaypoints_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::srv::GetWaypoints_Response & msg)
{
  return san_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::srv::GetWaypoints_Response>()
{
  return "san_msgs::srv::GetWaypoints_Response";
}

template<>
inline const char * name<san_msgs::srv::GetWaypoints_Response>()
{
  return "san_msgs/srv/GetWaypoints_Response";
}

template<>
struct has_fixed_size<san_msgs::srv::GetWaypoints_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<san_msgs::srv::GetWaypoints_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<san_msgs::srv::GetWaypoints_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<san_msgs::srv::GetWaypoints>()
{
  return "san_msgs::srv::GetWaypoints";
}

template<>
inline const char * name<san_msgs::srv::GetWaypoints>()
{
  return "san_msgs/srv/GetWaypoints";
}

template<>
struct has_fixed_size<san_msgs::srv::GetWaypoints>
  : std::integral_constant<
    bool,
    has_fixed_size<san_msgs::srv::GetWaypoints_Request>::value &&
    has_fixed_size<san_msgs::srv::GetWaypoints_Response>::value
  >
{
};

template<>
struct has_bounded_size<san_msgs::srv::GetWaypoints>
  : std::integral_constant<
    bool,
    has_bounded_size<san_msgs::srv::GetWaypoints_Request>::value &&
    has_bounded_size<san_msgs::srv::GetWaypoints_Response>::value
  >
{
};

template<>
struct is_service<san_msgs::srv::GetWaypoints>
  : std::true_type
{
};

template<>
struct is_service_request<san_msgs::srv::GetWaypoints_Request>
  : std::true_type
{
};

template<>
struct is_service_response<san_msgs::srv::GetWaypoints_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__TRAITS_HPP_
