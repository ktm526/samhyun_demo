// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:action/TaskCommandAction.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__TRAITS_HPP_
#define SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/action/detail/task_command_action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoint_lists'
#include "geometry_msgs/msg/detail/pose_array__traits.hpp"
// Member 'target_goal'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace san_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskCommandAction_Goal & msg,
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
  const TaskCommandAction_Goal & msg,
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

inline std::string to_yaml(const TaskCommandAction_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::action::TaskCommandAction_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::action::TaskCommandAction_Goal & msg)
{
  return san_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_Goal>()
{
  return "san_msgs::action::TaskCommandAction_Goal";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_Goal>()
{
  return "san_msgs/action/TaskCommandAction_Goal";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<san_msgs::action::TaskCommandAction_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace san_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskCommandAction_Result & msg,
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
  const TaskCommandAction_Result & msg,
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

inline std::string to_yaml(const TaskCommandAction_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::action::TaskCommandAction_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::action::TaskCommandAction_Result & msg)
{
  return san_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_Result>()
{
  return "san_msgs::action::TaskCommandAction_Result";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_Result>()
{
  return "san_msgs/action/TaskCommandAction_Result";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<san_msgs::action::TaskCommandAction_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'current_behavior'
#include "san_msgs/msg/detail/behavior__traits.hpp"

namespace san_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskCommandAction_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_behavior
  {
    out << "current_behavior: ";
    to_flow_style_yaml(msg.current_behavior, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskCommandAction_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_behavior
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_behavior:\n";
    to_block_style_yaml(msg.current_behavior, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskCommandAction_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::action::TaskCommandAction_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::action::TaskCommandAction_Feedback & msg)
{
  return san_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_Feedback>()
{
  return "san_msgs::action::TaskCommandAction_Feedback";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_Feedback>()
{
  return "san_msgs/action/TaskCommandAction_Feedback";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_Feedback>
  : std::integral_constant<bool, has_fixed_size<san_msgs::msg::Behavior>::value> {};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_Feedback>
  : std::integral_constant<bool, has_bounded_size<san_msgs::msg::Behavior>::value> {};

template<>
struct is_message<san_msgs::action::TaskCommandAction_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "san_msgs/action/detail/task_command_action__traits.hpp"

namespace san_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskCommandAction_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskCommandAction_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskCommandAction_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::action::TaskCommandAction_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::action::TaskCommandAction_SendGoal_Request & msg)
{
  return san_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_SendGoal_Request>()
{
  return "san_msgs::action::TaskCommandAction_SendGoal_Request";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_SendGoal_Request>()
{
  return "san_msgs/action/TaskCommandAction_SendGoal_Request";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<san_msgs::action::TaskCommandAction_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<san_msgs::action::TaskCommandAction_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<san_msgs::action::TaskCommandAction_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace san_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskCommandAction_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskCommandAction_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskCommandAction_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::action::TaskCommandAction_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::action::TaskCommandAction_SendGoal_Response & msg)
{
  return san_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_SendGoal_Response>()
{
  return "san_msgs::action::TaskCommandAction_SendGoal_Response";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_SendGoal_Response>()
{
  return "san_msgs/action/TaskCommandAction_SendGoal_Response";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<san_msgs::action::TaskCommandAction_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_SendGoal>()
{
  return "san_msgs::action::TaskCommandAction_SendGoal";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_SendGoal>()
{
  return "san_msgs/action/TaskCommandAction_SendGoal";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<san_msgs::action::TaskCommandAction_SendGoal_Request>::value &&
    has_fixed_size<san_msgs::action::TaskCommandAction_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<san_msgs::action::TaskCommandAction_SendGoal_Request>::value &&
    has_bounded_size<san_msgs::action::TaskCommandAction_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<san_msgs::action::TaskCommandAction_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<san_msgs::action::TaskCommandAction_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<san_msgs::action::TaskCommandAction_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace san_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskCommandAction_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskCommandAction_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskCommandAction_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::action::TaskCommandAction_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::action::TaskCommandAction_GetResult_Request & msg)
{
  return san_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_GetResult_Request>()
{
  return "san_msgs::action::TaskCommandAction_GetResult_Request";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_GetResult_Request>()
{
  return "san_msgs/action/TaskCommandAction_GetResult_Request";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<san_msgs::action::TaskCommandAction_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "san_msgs/action/detail/task_command_action__traits.hpp"

namespace san_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskCommandAction_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskCommandAction_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskCommandAction_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::action::TaskCommandAction_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::action::TaskCommandAction_GetResult_Response & msg)
{
  return san_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_GetResult_Response>()
{
  return "san_msgs::action::TaskCommandAction_GetResult_Response";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_GetResult_Response>()
{
  return "san_msgs/action/TaskCommandAction_GetResult_Response";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<san_msgs::action::TaskCommandAction_Result>::value> {};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<san_msgs::action::TaskCommandAction_Result>::value> {};

template<>
struct is_message<san_msgs::action::TaskCommandAction_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_GetResult>()
{
  return "san_msgs::action::TaskCommandAction_GetResult";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_GetResult>()
{
  return "san_msgs/action/TaskCommandAction_GetResult";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<san_msgs::action::TaskCommandAction_GetResult_Request>::value &&
    has_fixed_size<san_msgs::action::TaskCommandAction_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<san_msgs::action::TaskCommandAction_GetResult_Request>::value &&
    has_bounded_size<san_msgs::action::TaskCommandAction_GetResult_Response>::value
  >
{
};

template<>
struct is_service<san_msgs::action::TaskCommandAction_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<san_msgs::action::TaskCommandAction_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<san_msgs::action::TaskCommandAction_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "san_msgs/action/detail/task_command_action__traits.hpp"

namespace san_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const TaskCommandAction_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskCommandAction_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskCommandAction_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace san_msgs

namespace rosidl_generator_traits
{

[[deprecated("use san_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const san_msgs::action::TaskCommandAction_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::action::TaskCommandAction_FeedbackMessage & msg)
{
  return san_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::action::TaskCommandAction_FeedbackMessage>()
{
  return "san_msgs::action::TaskCommandAction_FeedbackMessage";
}

template<>
inline const char * name<san_msgs::action::TaskCommandAction_FeedbackMessage>()
{
  return "san_msgs/action/TaskCommandAction_FeedbackMessage";
}

template<>
struct has_fixed_size<san_msgs::action::TaskCommandAction_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<san_msgs::action::TaskCommandAction_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<san_msgs::action::TaskCommandAction_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<san_msgs::action::TaskCommandAction_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<san_msgs::action::TaskCommandAction_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<san_msgs::action::TaskCommandAction>
  : std::true_type
{
};

template<>
struct is_action_goal<san_msgs::action::TaskCommandAction_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<san_msgs::action::TaskCommandAction_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<san_msgs::action::TaskCommandAction_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__TRAITS_HPP_
