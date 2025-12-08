// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from san_msgs:action/TaskCommandAction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
#include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "san_msgs/action/detail/task_command_action__functions.h"
#include "san_msgs/action/detail/task_command_action__struct.h"


// Include directives for member types
// Member `mission`
#include "rosidl_runtime_c/string_functions.h"
// Member `waypoint_lists`
#include "geometry_msgs/msg/pose_array.h"
// Member `waypoint_lists`
#include "geometry_msgs/msg/detail/pose_array__rosidl_typesupport_introspection_c.h"
// Member `target_goal`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `target_goal`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__action__TaskCommandAction_Goal__init(message_memory);
}

void san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_fini_function(void * message_memory)
{
  san_msgs__action__TaskCommandAction_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_member_array[5] = {
  {
    "mission",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_Goal, mission),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_Goal, start_node),  // bytes offset in struct
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
    offsetof(san_msgs__action__TaskCommandAction_Goal, goal_node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoint_lists",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_Goal, waypoint_lists),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_Goal, target_goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_members = {
  "san_msgs__action",  // message namespace
  "TaskCommandAction_Goal",  // message name
  5,  // number of fields
  sizeof(san_msgs__action__TaskCommandAction_Goal),
  san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_member_array,  // message members
  san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_type_support_handle = {
  0,
  &san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_Goal)() {
  san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseArray)();
  san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_type_support_handle.typesupport_identifier) {
    san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__action__TaskCommandAction_Goal__rosidl_typesupport_introspection_c__TaskCommandAction_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__functions.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__action__TaskCommandAction_Result__init(message_memory);
}

void san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_fini_function(void * message_memory)
{
  san_msgs__action__TaskCommandAction_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_Result, success),  // bytes offset in struct
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
    offsetof(san_msgs__action__TaskCommandAction_Result, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_message_members = {
  "san_msgs__action",  // message namespace
  "TaskCommandAction_Result",  // message name
  2,  // number of fields
  sizeof(san_msgs__action__TaskCommandAction_Result),
  san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_message_member_array,  // message members
  san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_message_type_support_handle = {
  0,
  &san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_Result)() {
  if (!san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_message_type_support_handle.typesupport_identifier) {
    san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__action__TaskCommandAction_Result__rosidl_typesupport_introspection_c__TaskCommandAction_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__functions.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.h"


// Include directives for member types
// Member `current_behavior`
#include "san_msgs/msg/behavior.h"
// Member `current_behavior`
#include "san_msgs/msg/detail/behavior__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__action__TaskCommandAction_Feedback__init(message_memory);
}

void san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_fini_function(void * message_memory)
{
  san_msgs__action__TaskCommandAction_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_member_array[1] = {
  {
    "current_behavior",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_Feedback, current_behavior),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_members = {
  "san_msgs__action",  // message namespace
  "TaskCommandAction_Feedback",  // message name
  1,  // number of fields
  sizeof(san_msgs__action__TaskCommandAction_Feedback),
  san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_member_array,  // message members
  san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_type_support_handle = {
  0,
  &san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_Feedback)() {
  san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, msg, Behavior)();
  if (!san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_type_support_handle.typesupport_identifier) {
    san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__action__TaskCommandAction_Feedback__rosidl_typesupport_introspection_c__TaskCommandAction_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__functions.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "san_msgs/action/task_command_action.h"
// Member `goal`
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__action__TaskCommandAction_SendGoal_Request__init(message_memory);
}

void san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_fini_function(void * message_memory)
{
  san_msgs__action__TaskCommandAction_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_members = {
  "san_msgs__action",  // message namespace
  "TaskCommandAction_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(san_msgs__action__TaskCommandAction_SendGoal_Request),
  san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_member_array,  // message members
  san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_type_support_handle = {
  0,
  &san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_SendGoal_Request)() {
  san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_Goal)();
  if (!san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__action__TaskCommandAction_SendGoal_Request__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__functions.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__action__TaskCommandAction_SendGoal_Response__init(message_memory);
}

void san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_fini_function(void * message_memory)
{
  san_msgs__action__TaskCommandAction_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_members = {
  "san_msgs__action",  // message namespace
  "TaskCommandAction_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(san_msgs__action__TaskCommandAction_SendGoal_Response),
  san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_member_array,  // message members
  san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_type_support_handle = {
  0,
  &san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_SendGoal_Response)() {
  san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__action__TaskCommandAction_SendGoal_Response__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_service_members = {
  "san_msgs__action",  // service namespace
  "TaskCommandAction_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_service_type_support_handle = {
  0,
  &san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_SendGoal)() {
  if (!san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_service_type_support_handle.typesupport_identifier) {
    san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_SendGoal_Response)()->data;
  }

  return &san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__functions.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__action__TaskCommandAction_GetResult_Request__init(message_memory);
}

void san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_fini_function(void * message_memory)
{
  san_msgs__action__TaskCommandAction_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_members = {
  "san_msgs__action",  // message namespace
  "TaskCommandAction_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(san_msgs__action__TaskCommandAction_GetResult_Request),
  san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_member_array,  // message members
  san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_type_support_handle = {
  0,
  &san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_GetResult_Request)() {
  san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__action__TaskCommandAction_GetResult_Request__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__functions.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "san_msgs/action/task_command_action.h"
// Member `result`
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__action__TaskCommandAction_GetResult_Response__init(message_memory);
}

void san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_fini_function(void * message_memory)
{
  san_msgs__action__TaskCommandAction_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_members = {
  "san_msgs__action",  // message namespace
  "TaskCommandAction_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(san_msgs__action__TaskCommandAction_GetResult_Response),
  san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_member_array,  // message members
  san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_type_support_handle = {
  0,
  &san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_GetResult_Response)() {
  san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_Result)();
  if (!san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__action__TaskCommandAction_GetResult_Response__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_service_members = {
  "san_msgs__action",  // service namespace
  "TaskCommandAction_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_service_type_support_handle = {
  0,
  &san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_GetResult)() {
  if (!san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_service_type_support_handle.typesupport_identifier) {
    san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_GetResult_Response)()->data;
  }

  return &san_msgs__action__detail__task_command_action__rosidl_typesupport_introspection_c__TaskCommandAction_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "san_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__functions.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "san_msgs/action/task_command_action.h"
// Member `feedback`
// already included above
// #include "san_msgs/action/detail/task_command_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  san_msgs__action__TaskCommandAction_FeedbackMessage__init(message_memory);
}

void san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_fini_function(void * message_memory)
{
  san_msgs__action__TaskCommandAction_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs__action__TaskCommandAction_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_members = {
  "san_msgs__action",  // message namespace
  "TaskCommandAction_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(san_msgs__action__TaskCommandAction_FeedbackMessage),
  san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_member_array,  // message members
  san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_type_support_handle = {
  0,
  &san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_san_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_FeedbackMessage)() {
  san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, TaskCommandAction_Feedback)();
  if (!san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &san_msgs__action__TaskCommandAction_FeedbackMessage__rosidl_typesupport_introspection_c__TaskCommandAction_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
