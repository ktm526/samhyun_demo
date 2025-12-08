// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from san_msgs:msg/Behavior.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/behavior__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "san_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "san_msgs/msg/detail/behavior__struct.h"
#include "san_msgs/msg/detail/behavior__functions.h"
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


using _Behavior__ros_msg_type = san_msgs__msg__Behavior;

static bool _Behavior__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Behavior__ros_msg_type * ros_message = static_cast<const _Behavior__ros_msg_type *>(untyped_ros_message);
  // Field name: behavior_auto_started
  {
    cdr << (ros_message->behavior_auto_started ? true : false);
  }

  // Field name: behavior_slam_started
  {
    cdr << (ros_message->behavior_slam_started ? true : false);
  }

  // Field name: behavior_charge_started
  {
    cdr << (ros_message->behavior_charge_started ? true : false);
  }

  // Field name: behavior_docking_started
  {
    cdr << (ros_message->behavior_docking_started ? true : false);
  }

  // Field name: behavior_undocking_started
  {
    cdr << (ros_message->behavior_undocking_started ? true : false);
  }

  // Field name: behavior_auto_completed
  {
    cdr << (ros_message->behavior_auto_completed ? true : false);
  }

  // Field name: behavior_slam_completed
  {
    cdr << (ros_message->behavior_slam_completed ? true : false);
  }

  // Field name: behavior_charge_completed
  {
    cdr << (ros_message->behavior_charge_completed ? true : false);
  }

  // Field name: behavior_docking_completed
  {
    cdr << (ros_message->behavior_docking_completed ? true : false);
  }

  // Field name: behavior_undocking_completed
  {
    cdr << (ros_message->behavior_undocking_completed ? true : false);
  }

  // Field name: behavior_auto_canceled
  {
    cdr << (ros_message->behavior_auto_canceled ? true : false);
  }

  // Field name: behavior_docking_canceled
  {
    cdr << (ros_message->behavior_docking_canceled ? true : false);
  }

  // Field name: behavior_manipulation_redocking_triggered
  {
    cdr << (ros_message->behavior_manipulation_redocking_triggered ? true : false);
  }

  // Field name: behavior_charging_redocking_triggered
  {
    cdr << (ros_message->behavior_charging_redocking_triggered ? true : false);
  }

  // Field name: behavior_manipulator_completed
  {
    cdr << (ros_message->behavior_manipulator_completed ? true : false);
  }

  // Field name: behavior_manipulator_emergency_triggered
  {
    cdr << (ros_message->behavior_manipulator_emergency_triggered ? true : false);
  }

  // Field name: behavior_manual_mode_triggered
  {
    cdr << (ros_message->behavior_manual_mode_triggered ? true : false);
  }

  return true;
}

static bool _Behavior__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Behavior__ros_msg_type * ros_message = static_cast<_Behavior__ros_msg_type *>(untyped_ros_message);
  // Field name: behavior_auto_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_auto_started = tmp ? true : false;
  }

  // Field name: behavior_slam_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_slam_started = tmp ? true : false;
  }

  // Field name: behavior_charge_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_charge_started = tmp ? true : false;
  }

  // Field name: behavior_docking_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_docking_started = tmp ? true : false;
  }

  // Field name: behavior_undocking_started
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_undocking_started = tmp ? true : false;
  }

  // Field name: behavior_auto_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_auto_completed = tmp ? true : false;
  }

  // Field name: behavior_slam_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_slam_completed = tmp ? true : false;
  }

  // Field name: behavior_charge_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_charge_completed = tmp ? true : false;
  }

  // Field name: behavior_docking_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_docking_completed = tmp ? true : false;
  }

  // Field name: behavior_undocking_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_undocking_completed = tmp ? true : false;
  }

  // Field name: behavior_auto_canceled
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_auto_canceled = tmp ? true : false;
  }

  // Field name: behavior_docking_canceled
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_docking_canceled = tmp ? true : false;
  }

  // Field name: behavior_manipulation_redocking_triggered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_manipulation_redocking_triggered = tmp ? true : false;
  }

  // Field name: behavior_charging_redocking_triggered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_charging_redocking_triggered = tmp ? true : false;
  }

  // Field name: behavior_manipulator_completed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_manipulator_completed = tmp ? true : false;
  }

  // Field name: behavior_manipulator_emergency_triggered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_manipulator_emergency_triggered = tmp ? true : false;
  }

  // Field name: behavior_manual_mode_triggered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->behavior_manual_mode_triggered = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_san_msgs
size_t get_serialized_size_san_msgs__msg__Behavior(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Behavior__ros_msg_type * ros_message = static_cast<const _Behavior__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name behavior_auto_started
  {
    size_t item_size = sizeof(ros_message->behavior_auto_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_slam_started
  {
    size_t item_size = sizeof(ros_message->behavior_slam_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_charge_started
  {
    size_t item_size = sizeof(ros_message->behavior_charge_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_docking_started
  {
    size_t item_size = sizeof(ros_message->behavior_docking_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_undocking_started
  {
    size_t item_size = sizeof(ros_message->behavior_undocking_started);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_auto_completed
  {
    size_t item_size = sizeof(ros_message->behavior_auto_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_slam_completed
  {
    size_t item_size = sizeof(ros_message->behavior_slam_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_charge_completed
  {
    size_t item_size = sizeof(ros_message->behavior_charge_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_docking_completed
  {
    size_t item_size = sizeof(ros_message->behavior_docking_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_undocking_completed
  {
    size_t item_size = sizeof(ros_message->behavior_undocking_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_auto_canceled
  {
    size_t item_size = sizeof(ros_message->behavior_auto_canceled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_docking_canceled
  {
    size_t item_size = sizeof(ros_message->behavior_docking_canceled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_manipulation_redocking_triggered
  {
    size_t item_size = sizeof(ros_message->behavior_manipulation_redocking_triggered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_charging_redocking_triggered
  {
    size_t item_size = sizeof(ros_message->behavior_charging_redocking_triggered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_manipulator_completed
  {
    size_t item_size = sizeof(ros_message->behavior_manipulator_completed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_manipulator_emergency_triggered
  {
    size_t item_size = sizeof(ros_message->behavior_manipulator_emergency_triggered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name behavior_manual_mode_triggered
  {
    size_t item_size = sizeof(ros_message->behavior_manual_mode_triggered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Behavior__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_san_msgs__msg__Behavior(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_san_msgs
size_t max_serialized_size_san_msgs__msg__Behavior(
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

  // member: behavior_auto_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_slam_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_charge_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_docking_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_undocking_started
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_auto_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_slam_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_charge_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_docking_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_undocking_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_auto_canceled
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_docking_canceled
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_manipulation_redocking_triggered
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_charging_redocking_triggered
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_manipulator_completed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_manipulator_emergency_triggered
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: behavior_manual_mode_triggered
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
    using DataType = san_msgs__msg__Behavior;
    is_plain =
      (
      offsetof(DataType, behavior_manual_mode_triggered) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Behavior__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_san_msgs__msg__Behavior(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Behavior = {
  "san_msgs::msg",
  "Behavior",
  _Behavior__cdr_serialize,
  _Behavior__cdr_deserialize,
  _Behavior__get_serialized_size,
  _Behavior__max_serialized_size
};

static rosidl_message_type_support_t _Behavior__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Behavior,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, msg, Behavior)() {
  return &_Behavior__type_support;
}

#if defined(__cplusplus)
}
#endif
