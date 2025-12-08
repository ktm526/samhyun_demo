// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from san_msgs:srv/GetWaypoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "san_msgs/srv/detail/get_waypoints__rosidl_typesupport_introspection_c.h"
#include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "san_msgs/srv/detail/get_waypoints__functions.h"
#include "san_msgs/srv/detail/get_waypoints__struct.h"


// Include directives for member types
// Member `node_file`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__srv__GetWaypoints_Request__init(message_memory);
}

void san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_fini_function(void * message_memory)
{
  san_msgs__srv__GetWaypoints_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_member_array[3] = {
  {
    "start_node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__GetWaypoints_Request, start_node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__GetWaypoints_Request, goal_node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_file",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__GetWaypoints_Request, node_file),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_members = {
  "san_msgs__srv",  // message namespace
  "GetWaypoints_Request",  // message name
  3,  // number of fields
  sizeof(san_msgs__srv__GetWaypoints_Request),
  san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_member_array,  // message members
  san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_type_support_handle = {
  0,
  &san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, GetWaypoints_Request)() {
  if (!san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_type_support_handle.typesupport_identifier) {
    san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__srv__GetWaypoints_Request__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/srv/detail/get_waypoints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/srv/detail/get_waypoints__functions.h"
// already included above
// #include "san_msgs/srv/detail/get_waypoints__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `waypoints`
#include "geometry_msgs/msg/pose_array.h"
// Member `waypoints`
#include "geometry_msgs/msg/detail/pose_array__rosidl_typesupport_introspection_c.h"
// Member `node_path`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__srv__GetWaypoints_Response__init(message_memory);
}

void san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_fini_function(void * message_memory)
{
  san_msgs__srv__GetWaypoints_Response__fini(message_memory);
}

size_t san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__size_function__GetWaypoints_Response__node_path(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint16__Sequence * member =
    (const rosidl_runtime_c__uint16__Sequence *)(untyped_member);
  return member->size;
}

const void * san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__get_const_function__GetWaypoints_Response__node_path(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint16__Sequence * member =
    (const rosidl_runtime_c__uint16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__get_function__GetWaypoints_Response__node_path(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint16__Sequence * member =
    (rosidl_runtime_c__uint16__Sequence *)(untyped_member);
  return &member->data[index];
}

void san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__fetch_function__GetWaypoints_Response__node_path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__get_const_function__GetWaypoints_Response__node_path(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__assign_function__GetWaypoints_Response__node_path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__get_function__GetWaypoints_Response__node_path(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

bool san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__resize_function__GetWaypoints_Response__node_path(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint16__Sequence * member =
    (rosidl_runtime_c__uint16__Sequence *)(untyped_member);
  rosidl_runtime_c__uint16__Sequence__fini(member);
  return rosidl_runtime_c__uint16__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_member_array[4] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__GetWaypoints_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__GetWaypoints_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__GetWaypoints_Response, waypoints),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__srv__GetWaypoints_Response, node_path),  // bytes offset in struct
    NULL,  // default value
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__size_function__GetWaypoints_Response__node_path,  // size() function pointer
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__get_const_function__GetWaypoints_Response__node_path,  // get_const(index) function pointer
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__get_function__GetWaypoints_Response__node_path,  // get(index) function pointer
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__fetch_function__GetWaypoints_Response__node_path,  // fetch(index, &value) function pointer
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__assign_function__GetWaypoints_Response__node_path,  // assign(index, value) function pointer
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__resize_function__GetWaypoints_Response__node_path  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_members = {
  "san_msgs__srv",  // message namespace
  "GetWaypoints_Response",  // message name
  4,  // number of fields
  sizeof(san_msgs__srv__GetWaypoints_Response),
  san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_member_array,  // message members
  san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_type_support_handle = {
  0,
  &san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, GetWaypoints_Response)() {
  san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseArray)();
  if (!san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_type_support_handle.typesupport_identifier) {
    san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__srv__GetWaypoints_Response__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "san_msgs/srv/detail/get_waypoints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_service_members = {
  "san_msgs__srv",  // service namespace
  "GetWaypoints",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_Request_message_type_support_handle,
  NULL  // response message
  // san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_Response_message_type_support_handle
};

static rosidl_service_type_support_t san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_service_type_support_handle = {
  0,
  &san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, GetWaypoints_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, GetWaypoints_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, GetWaypoints)() {
  if (!san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_service_type_support_handle.typesupport_identifier) {
    san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, GetWaypoints_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, srv, GetWaypoints_Response)()->data;
  }

  return &san_msgs__srv__detail__get_waypoints__rosidl_typesupport_introspection_c__GetWaypoints_service_type_support_handle;
}
