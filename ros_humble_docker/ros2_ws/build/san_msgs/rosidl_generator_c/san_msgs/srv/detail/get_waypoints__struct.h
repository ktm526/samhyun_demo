// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:srv/GetWaypoints.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__STRUCT_H_
#define SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'node_file'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetWaypoints in the package san_msgs.
typedef struct san_msgs__srv__GetWaypoints_Request
{
  uint16_t start_node;
  uint16_t goal_node;
  rosidl_runtime_c__String node_file;
} san_msgs__srv__GetWaypoints_Request;

// Struct for a sequence of san_msgs__srv__GetWaypoints_Request.
typedef struct san_msgs__srv__GetWaypoints_Request__Sequence
{
  san_msgs__srv__GetWaypoints_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__srv__GetWaypoints_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'waypoints'
#include "geometry_msgs/msg/detail/pose_array__struct.h"
// Member 'node_path'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GetWaypoints in the package san_msgs.
typedef struct san_msgs__srv__GetWaypoints_Response
{
  bool success;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__PoseArray waypoints;
  rosidl_runtime_c__uint16__Sequence node_path;
} san_msgs__srv__GetWaypoints_Response;

// Struct for a sequence of san_msgs__srv__GetWaypoints_Response.
typedef struct san_msgs__srv__GetWaypoints_Response__Sequence
{
  san_msgs__srv__GetWaypoints_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__srv__GetWaypoints_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__STRUCT_H_
