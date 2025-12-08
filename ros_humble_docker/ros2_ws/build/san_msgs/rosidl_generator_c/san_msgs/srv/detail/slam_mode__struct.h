// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:srv/SlamMode.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__SLAM_MODE__STRUCT_H_
#define SAN_MSGS__SRV__DETAIL__SLAM_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SlamMode in the package san_msgs.
typedef struct san_msgs__srv__SlamMode_Request
{
  bool slam_start;
} san_msgs__srv__SlamMode_Request;

// Struct for a sequence of san_msgs__srv__SlamMode_Request.
typedef struct san_msgs__srv__SlamMode_Request__Sequence
{
  san_msgs__srv__SlamMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__srv__SlamMode_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SlamMode in the package san_msgs.
typedef struct san_msgs__srv__SlamMode_Response
{
  bool success;
  rosidl_runtime_c__String message;
} san_msgs__srv__SlamMode_Response;

// Struct for a sequence of san_msgs__srv__SlamMode_Response.
typedef struct san_msgs__srv__SlamMode_Response__Sequence
{
  san_msgs__srv__SlamMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__srv__SlamMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__SRV__DETAIL__SLAM_MODE__STRUCT_H_
