// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from san_msgs:srv/ManualManipulatorControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "san_msgs/srv/detail/manual_manipulator_control__rosidl_typesupport_introspection_c.h"
#include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "san_msgs/srv/detail/manual_manipulator_control__functions.h"
#include "san_msgs/srv/detail/manual_manipulator_control__struct.h"


// Include directives for member types
// Member `command`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__srv__ManualManipulatorControl_Request__init(message_memory);
}

void san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_fini_function(void * message_memory)
{
  san_msgs__srv__ManualManipulatorControl_Request__fini(message_memory);
}

size_t san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__size_function__ManualManipulatorControl_Request__position(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__get_const_function__ManualManipulatorControl_Request__position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__get_function__ManualManipulatorControl_Request__position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__fetch_function__ManualManipulatorControl_Request__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__get_const_function__ManualManipulatorControl_Request__position(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__assign_function__ManualManipulatorControl_Request__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__get_function__ManualManipulatorControl_Request__position(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__resize_function__ManualManipulatorControl_Request__position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_member_array[2] = {
  {
    "command",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__ManualManipulatorControl_Request, command),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__ManualManipulatorControl_Request, position),  // bytes offset in struct
    NULL,  // default value
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__size_function__ManualManipulatorControl_Request__position,  // size() function pointer
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__get_const_function__ManualManipulatorControl_Request__position,  // get_const(index) function pointer
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__get_function__ManualManipulatorControl_Request__position,  // get(index) function pointer
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__fetch_function__ManualManipulatorControl_Request__position,  // fetch(index, &value) function pointer
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__assign_function__ManualManipulatorControl_Request__position,  // assign(index, value) function pointer
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__resize_function__ManualManipulatorControl_Request__position  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_members = {
  "san_msgs__srv",  // message namespace
  "ManualManipulatorControl_Request",  // message name
  2,  // number of fields
  sizeof(san_msgs__srv__ManualManipulatorControl_Request),
  san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_member_array,  // message members
  san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_type_support_handle = {
  0,
  &san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, ManualManipulatorControl_Request)() {
  if (!san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_type_support_handle.typesupport_identifier) {
    san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__srv__ManualManipulatorControl_Request__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/srv/detail/manual_manipulator_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/srv/detail/manual_manipulator_control__functions.h"
// already included above
// #include "san_msgs/srv/detail/manual_manipulator_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__srv__ManualManipulatorControl_Response__init(message_memory);
}

void san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_fini_function(void * message_memory)
{
  san_msgs__srv__ManualManipulatorControl_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__ManualManipulatorControl_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_members = {
  "san_msgs__srv",  // message namespace
  "ManualManipulatorControl_Response",  // message name
  1,  // number of fields
  sizeof(san_msgs__srv__ManualManipulatorControl_Response),
  san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_member_array,  // message members
  san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_type_support_handle = {
  0,
  &san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, ManualManipulatorControl_Response)() {
  if (!san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_type_support_handle.typesupport_identifier) {
    san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__srv__ManualManipulatorControl_Response__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "san_msgs/srv/detail/manual_manipulator_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_service_members = {
  "san_msgs__srv",  // service namespace
  "ManualManipulatorControl",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_Request_message_type_support_handle,
  NULL  // response message
  // san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_Response_message_type_support_handle
};

static rosidl_service_type_support_t san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_service_type_support_handle = {
  0,
  &san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, ManualManipulatorControl_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, ManualManipulatorControl_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, ManualManipulatorControl)() {
  if (!san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_service_type_support_handle.typesupport_identifier) {
    san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, ManualManipulatorControl_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, ManualManipulatorControl_Response)()->data;
  }

  return &san_msgs__srv__detail__manual_manipulator_control__rosidl_typesupport_introspection_c__ManualManipulatorControl_service_type_support_handle;
}
