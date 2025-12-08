// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:srv/TaskCommand.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__TASK_COMMAND__TRAITS_HPP_
#define SAN_MSGS__SRV__DETAIL__TASK_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/srv/detail/task_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoint_lists'
#include "geometry_msgs/msg/detail/pose_array__traits.hpp"
// Member 'target_goal'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace san_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TaskCommand_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mission
  {
    out << "mission: ";
    rosidl_generator_traits::value_to_yaml(msg.mission, out);
    out << ", ";
  }

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

  // member: waypoint_lists
  {
    out << "waypoint_lists: ";
    to_flow_style_yaml(msg.waypoint_lists, out);
    out << ", ";
  }

  // member: target_goal
  {
    out << "target_goal: ";
    to_flow_style_yaml(msg.target_goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mission
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission: ";
    rosidl_generator_traits::value_to_yaml(msg.mission, out);
    out << "\n";
  }

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

  // member: waypoint_lists
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "waypoint_lists:\n";
    to_block_style_yaml(msg.waypoint_lists, out, indentation + 2);
  }

  // member: target_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_goal:\n";
    to_block_style_yaml(msg.target_goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskCommand_Request & msg, bool use_flow_style = false)
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
  const san_msgs::srv::TaskCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::srv::TaskCommand_Request & msg)
{
  return san_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::srv::TaskCommand_Request>()
{
  return "san_msgs::srv::TaskCommand_Request";
}

template<>
inline const char * name<san_msgs::srv::TaskCommand_Request>()
{
  return "san_msgs/srv/TaskCommand_Request";
}

template<>
struct has_fixed_size<san_msgs::srv::TaskCommand_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<san_msgs::srv::TaskCommand_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<san_msgs::srv::TaskCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace san_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TaskCommand_Response & msg,
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
  const TaskCommand_Response & msg,
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

inline std::string to_yaml(const TaskCommand_Response & msg, bool use_flow_style = false)
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
  const san_msgs::srv::TaskCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::srv::TaskCommand_Response & msg)
{
  return san_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::srv::TaskCommand_Response>()
{
  return "san_msgs::srv::TaskCommand_Response";
}

template<>
inline const char * name<san_msgs::srv::TaskCommand_Response>()
{
  return "san_msgs/srv/TaskCommand_Response";
}

template<>
struct has_fixed_size<san_msgs::srv::TaskCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<san_msgs::srv::TaskCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<san_msgs::srv::TaskCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<san_msgs::srv::TaskCommand>()
{
  return "san_msgs::srv::TaskCommand";
}

template<>
inline const char * name<san_msgs::srv::TaskCommand>()
{
  return "san_msgs/srv/TaskCommand";
}

template<>
struct has_fixed_size<san_msgs::srv::TaskCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<san_msgs::srv::TaskCommand_Request>::value &&
    has_fixed_size<san_msgs::srv::TaskCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<san_msgs::srv::TaskCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<san_msgs::srv::TaskCommand_Request>::value &&
    has_bounded_size<san_msgs::srv::TaskCommand_Response>::value
  >
{
};

template<>
struct is_service<san_msgs::srv::TaskCommand>
  : std::true_type
{
};

template<>
struct is_service_request<san_msgs::srv::TaskCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<san_msgs::srv::TaskCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SAN_MSGS__SRV__DETAIL__TASK_COMMAND__TRAITS_HPP_
