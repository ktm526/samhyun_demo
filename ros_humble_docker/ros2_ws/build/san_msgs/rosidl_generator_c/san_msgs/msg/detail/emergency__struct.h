// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:msg/Emergency.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__EMERGENCY__STRUCT_H_
#define SAN_MSGS__MSG__DETAIL__EMERGENCY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'PHYSICAL_LAYER'.
enum
{
  san_msgs__msg__Emergency__PHYSICAL_LAYER = 0
};

/// Constant 'OBSTACLE'.
enum
{
  san_msgs__msg__Emergency__OBSTACLE = 1
};

/// Constant 'LOW_BATTERY'.
enum
{
  san_msgs__msg__Emergency__LOW_BATTERY = 2
};

/// Constant 'REDOCKING'.
enum
{
  san_msgs__msg__Emergency__REDOCKING = 3
};

/// Struct defined in msg/Emergency in the package san_msgs.
/**
  * Emergency Description
 */
typedef struct san_msgs__msg__Emergency
{
  uint8_t emergency;
} san_msgs__msg__Emergency;

// Struct for a sequence of san_msgs__msg__Emergency.
typedef struct san_msgs__msg__Emergency__Sequence
{
  san_msgs__msg__Emergency * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__msg__Emergency__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__MSG__DETAIL__EMERGENCY__STRUCT_H_
