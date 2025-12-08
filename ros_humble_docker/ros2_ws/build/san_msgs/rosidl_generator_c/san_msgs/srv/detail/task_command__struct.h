// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:srv/TaskCommand.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__TASK_COMMAND__STRUCT_H_
#define SAN_MSGS__SRV__DETAIL__TASK_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mission'
#include "rosidl_runtime_c/string.h"
// Member 'waypoint_lists'
#include "geometry_msgs/msg/detail/pose_array__struct.h"
// Member 'target_goal'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/TaskCommand in the package san_msgs.
typedef struct san_msgs__srv__TaskCommand_Request
{
  /// ex: "load", "unload", "move", "home"
  rosidl_runtime_c__String mission;
  uint16_t start_node;
  uint16_t goal_node;
  geometry_msgs__msg__PoseArray waypoint_lists;
  /// Nav2
  geometry_msgs__msg__PoseStamped target_goal;
} san_msgs__srv__TaskCommand_Request;

// Struct for a sequence of san_msgs__srv__TaskCommand_Request.
typedef struct san_msgs__srv__TaskCommand_Request__Sequence
{
  san_msgs__srv__TaskCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__srv__TaskCommand_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TaskCommand in the package san_msgs.
typedef struct san_msgs__srv__TaskCommand_Response
{
  bool success;
  rosidl_runtime_c__String message;
} san_msgs__srv__TaskCommand_Response;

// Struct for a sequence of san_msgs__srv__TaskCommand_Response.
typedef struct san_msgs__srv__TaskCommand_Response__Sequence
{
  san_msgs__srv__TaskCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__srv__TaskCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__SRV__DETAIL__TASK_COMMAND__STRUCT_H_
