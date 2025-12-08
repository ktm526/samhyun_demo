// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from san_msgs:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__TASK__TRAITS_HPP_
#define SAN_MSGS__MSG__DETAIL__TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "san_msgs/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace san_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Task & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_load_started
  {
    out << "task_load_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_load_started, out);
    out << ", ";
  }

  // member: task_unload_started
  {
    out << "task_unload_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_unload_started, out);
    out << ", ";
  }

  // member: task_move_started
  {
    out << "task_move_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_move_started, out);
    out << ", ";
  }

  // member: task_home_started
  {
    out << "task_home_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_home_started, out);
    out << ", ";
  }

  // member: task_cancel_started
  {
    out << "task_cancel_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_cancel_started, out);
    out << ", ";
  }

  // member: task_load_completed
  {
    out << "task_load_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_load_completed, out);
    out << ", ";
  }

  // member: task_unload_completed
  {
    out << "task_unload_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_unload_completed, out);
    out << ", ";
  }

  // member: task_move_completed
  {
    out << "task_move_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_move_completed, out);
    out << ", ";
  }

  // member: task_home_completed
  {
    out << "task_home_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_home_completed, out);
    out << ", ";
  }

  // member: task_cancel_completed
  {
    out << "task_cancel_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_cancel_completed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_load_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_load_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_load_started, out);
    out << "\n";
  }

  // member: task_unload_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_unload_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_unload_started, out);
    out << "\n";
  }

  // member: task_move_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_move_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_move_started, out);
    out << "\n";
  }

  // member: task_home_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_home_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_home_started, out);
    out << "\n";
  }

  // member: task_cancel_started
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_cancel_started: ";
    rosidl_generator_traits::value_to_yaml(msg.task_cancel_started, out);
    out << "\n";
  }

  // member: task_load_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_load_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_load_completed, out);
    out << "\n";
  }

  // member: task_unload_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_unload_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_unload_completed, out);
    out << "\n";
  }

  // member: task_move_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_move_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_move_completed, out);
    out << "\n";
  }

  // member: task_home_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_home_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_home_completed, out);
    out << "\n";
  }

  // member: task_cancel_completed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_cancel_completed: ";
    rosidl_generator_traits::value_to_yaml(msg.task_cancel_completed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Task & msg, bool use_flow_style = false)
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
  const san_msgs::msg::Task & msg,
  std::ostream & out, size_t indentation = 0)
{
  san_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use san_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const san_msgs::msg::Task & msg)
{
  return san_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<san_msgs::msg::Task>()
{
  return "san_msgs::msg::Task";
}

template<>
inline const char * name<san_msgs::msg::Task>()
{
  return "san_msgs/msg/Task";
}

template<>
struct has_fixed_size<san_msgs::msg::Task>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<san_msgs::msg::Task>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<san_msgs::msg::Task>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SAN_MSGS__MSG__DETAIL__TASK__TRAITS_HPP_
