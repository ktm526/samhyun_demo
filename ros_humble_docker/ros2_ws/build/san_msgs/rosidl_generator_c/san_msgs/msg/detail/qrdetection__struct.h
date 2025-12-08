// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:msg/Qrdetection.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__QRDETECTION__STRUCT_H_
#define SAN_MSGS__MSG__DETAIL__QRDETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'translation'
// Member 'rotation'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/Qrdetection in the package san_msgs.
typedef struct san_msgs__msg__Qrdetection
{
  int32_t cam_num;
  int32_t id;
  geometry_msgs__msg__Vector3 translation;
  geometry_msgs__msg__Vector3 rotation;
} san_msgs__msg__Qrdetection;

// Struct for a sequence of san_msgs__msg__Qrdetection.
typedef struct san_msgs__msg__Qrdetection__Sequence
{
  san_msgs__msg__Qrdetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__msg__Qrdetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__MSG__DETAIL__QRDETECTION__STRUCT_H_
