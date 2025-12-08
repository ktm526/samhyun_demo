// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from san_msgs:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "san_msgs/msg/detail/motor_status__rosidl_typesupport_introspection_c.h"
#include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "san_msgs/msg/detail/motor_status__functions.h"
#include "san_msgs/msg/detail/motor_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__msg__MotorStatus__init(message_memory);
}

void san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_fini_function(void * message_memory)
{
  san_msgs__msg__MotorStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_message_member_array[1] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__msg__MotorStatus, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_message_members = {
  "san_msgs__msg",  // message namespace
  "MotorStatus",  // message name
  1,  // number of fields
  sizeof(san_msgs__msg__MotorStatus),
  san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_message_member_array,  // message members
  san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_message_type_support_handle = {
  0,
  &san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, msg, MotorStatus)() {
  if (!san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_message_type_support_handle.typesupport_identifier) {
    san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__msg__MotorStatus__rosidl_typesupport_introspection_c__MotorStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
