// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from san_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/battery_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "san_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "san_msgs/msg/detail/battery_status__struct.h"
#include "san_msgs/msg/detail/battery_status__functions.h"
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


using _BatteryStatus__ros_msg_type = san_msgs__msg__BatteryStatus;

static bool _BatteryStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BatteryStatus__ros_msg_type * ros_message = static_cast<const _BatteryStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: voltage_top
  {
    cdr << ros_message->voltage_top;
  }

  // Field name: current_top
  {
    cdr << ros_message->current_top;
  }

  // Field name: soc_top
  {
    cdr << ros_message->soc_top;
  }

  // Field name: soh_top
  {
    cdr << ros_message->soh_top;
  }

  // Field name: voltage
  {
    cdr << ros_message->voltage;
  }

  // Field name: current
  {
    cdr << ros_message->current;
  }

  // Field name: soc
  {
    cdr << ros_message->soc;
  }

  // Field name: soh
  {
    cdr << ros_message->soh;
  }

  // Field name: charge_relay
  {
    cdr << (ros_message->charge_relay ? true : false);
  }

  // Field name: charging_jack_state
  {
    cdr << (ros_message->charging_jack_state ? true : false);
  }

  // Field name: charging_state
  {
    cdr << (ros_message->charging_state ? true : false);
  }

  return true;
}

static bool _BatteryStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BatteryStatus__ros_msg_type * ros_message = static_cast<_BatteryStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: voltage_top
  {
    cdr >> ros_message->voltage_top;
  }

  // Field name: current_top
  {
    cdr >> ros_message->current_top;
  }

  // Field name: soc_top
  {
    cdr >> ros_message->soc_top;
  }

  // Field name: soh_top
  {
    cdr >> ros_message->soh_top;
  }

  // Field name: voltage
  {
    cdr >> ros_message->voltage;
  }

  // Field name: current
  {
    cdr >> ros_message->current;
  }

  // Field name: soc
  {
    cdr >> ros_message->soc;
  }

  // Field name: soh
  {
    cdr >> ros_message->soh;
  }

  // Field name: charge_relay
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->charge_relay = tmp ? true : false;
  }

  // Field name: charging_jack_state
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->charging_jack_state = tmp ? true : false;
  }

  // Field name: charging_state
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->charging_state = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_san_msgs
size_t get_serialized_size_san_msgs__msg__BatteryStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BatteryStatus__ros_msg_type * ros_message = static_cast<const _BatteryStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name voltage_top
  {
    size_t item_size = sizeof(ros_message->voltage_top);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_top
  {
    size_t item_size = sizeof(ros_message->current_top);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name soc_top
  {
    size_t item_size = sizeof(ros_message->soc_top);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name soh_top
  {
    size_t item_size = sizeof(ros_message->soh_top);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name voltage
  {
    size_t item_size = sizeof(ros_message->voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current
  {
    size_t item_size = sizeof(ros_message->current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name soc
  {
    size_t item_size = sizeof(ros_message->soc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name soh
  {
    size_t item_size = sizeof(ros_message->soh);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name charge_relay
  {
    size_t item_size = sizeof(ros_message->charge_relay);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name charging_jack_state
  {
    size_t item_size = sizeof(ros_message->charging_jack_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name charging_state
  {
    size_t item_size = sizeof(ros_message->charging_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BatteryStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_san_msgs__msg__BatteryStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_san_msgs
size_t max_serialized_size_san_msgs__msg__BatteryStatus(
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

  // member: voltage_top
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current_top
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: soc_top
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: soh_top
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: soc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: soh
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: charge_relay
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: charging_jack_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: charging_state
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
    using DataType = san_msgs__msg__BatteryStatus;
    is_plain =
      (
      offsetof(DataType, charging_state) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BatteryStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_san_msgs__msg__BatteryStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BatteryStatus = {
  "san_msgs::msg",
  "BatteryStatus",
  _BatteryStatus__cdr_serialize,
  _BatteryStatus__cdr_deserialize,
  _BatteryStatus__get_serialized_size,
  _BatteryStatus__max_serialized_size
};

static rosidl_message_type_support_t _BatteryStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BatteryStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, msg, BatteryStatus)() {
  return &_BatteryStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
