// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from san_msgs:msg/Task.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/task__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "san_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "san_msgs/msg/detail/task__struct.h"
#include "san_msgs/msg/detail/task__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Task__ros_msg_type = san_msgs__msg__Task;

static bool _Task__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Task__ros_msg_type * ros_message = static_cast<const _Task__ros_msg_type *>(untyped_ros_message);
  // Field name: task_load_started
  {
    cdr << (ros_message->task_load_started ? true : false);
  }

  // Field name: task_unload_started
  {
    cdr << (ros_message->task_unload_started ? true : false);
  }

  // Field name: task_move_started
  {
    cdr << (ros_message->task_move_started ? true : false);
  }

  // Field name: task_home_started
  {
    cdr << (ros_message->task_home_started ? true : false);
  }

  // Field name: task_cancel_started
  {
    cdr << (ros_message->task_cancel_started ? true : false);
  }

  // Field name: task_load_completed
  {
    cdr << (ros_message->task_load_completed ? true : false);
  }

  // Field name: task_unload_completed
  {
    cdr << (ros_message->task_unload_completed ? true : false);
  }

  // Field name: task_move_completed
  {
    cdr << (ros_message->task_move_completed ? true : false);
  }

  // Field name: task_home_completed
  {
    cdr << (ros_message->task_home_completed ? true : false);
  }

  // Field name: task_cancel_completed
  {
    cdr << (ros_message->task_cancel_completed ? true : false);
  }

  return true;
}

static bool _Task__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Task__ros_msg_type * ros_message = static_cast<_Task__ros_msg_type *>(untyped_ros_message);
  // Field name: task_load_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_load_started = tmp ? true : false;
  }

  // Field name: task_unload_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_unload_started = tmp ? true : false;
  }

  // Field name: task_move_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_move_started = tmp ? true : false;
  }

  // Field name: task_home_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_home_started = tmp ? true : false;
  }

  // Field name: task_cancel_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_cancel_started = tmp ? true : false;
  }

  // Field name: task_load_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_load_completed = tmp ? true : false;
  }

  // Field name: task_unload_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_unload_completed = tmp ? true : false;
  }

  // Field name: task_move_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_move_completed = tmp ? true : false;
  }

  // Field name: task_home_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_home_completed = tmp ? true : false;
  }

  // Field name: task_cancel_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->task_cancel_completed = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_san_msgs
size_t get_serialized_size_san_msgs__msg__Task(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Task__ros_msg_type * ros_message = static_cast<const _Task__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name task_load_started
  {
    size_t item_size = sizeof(ros_message->task_load_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_unload_started
  {
    size_t item_size = sizeof(ros_message->task_unload_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_move_started
  {
    size_t item_size = sizeof(ros_message->task_move_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_home_started
  {
    size_t item_size = sizeof(ros_message->task_home_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_cancel_started
  {
    size_t item_size = sizeof(ros_message->task_cancel_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_load_completed
  {
    size_t item_size = sizeof(ros_message->task_load_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_unload_completed
  {
    size_t item_size = sizeof(ros_message->task_unload_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_move_completed
  {
    size_t item_size = sizeof(ros_message->task_move_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_home_completed
  {
    size_t item_size = sizeof(ros_message->task_home_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name task_cancel_completed
  {
    size_t item_size = sizeof(ros_message->task_cancel_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Task__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_san_msgs__msg__Task(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_san_msgs
size_t max_serialized_size_san_msgs__msg__Task(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: task_load_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_unload_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_move_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_home_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_cancel_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_load_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_unload_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_move_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_home_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: task_cancel_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = san_msgs__msg__Task;
    is_plain =
      (
      offsetof(DataType, task_cancel_completed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Task__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_san_msgs__msg__Task(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Task = {
  "san_msgs::msg",
  "Task",
  _Task__cdr_serialize,
  _Task__cdr_deserialize,
  _Task__get_serialized_size,
  _Task__max_serialized_size
};

static rosidl_message_type_support_t _Task__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Task,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, msg, Task)() {
  return &_Task__type_support;
}

#if defined(__cplusplus)
}
#endif
