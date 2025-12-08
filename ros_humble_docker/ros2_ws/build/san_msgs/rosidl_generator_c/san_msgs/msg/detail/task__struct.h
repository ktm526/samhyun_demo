// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__TASK__STRUCT_H_
#define SAN_MSGS__MSG__DETAIL__TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Task in the package san_msgs.
typedef struct san_msgs__msg__Task
{
  bool task_load_started;
  bool task_unload_started;
  bool task_move_started;
  bool task_home_started;
  bool task_cancel_started;
  bool task_load_completed;
  bool task_unload_completed;
  bool task_move_completed;
  bool task_home_completed;
  bool task_cancel_completed;
} san_msgs__msg__Task;

// Struct for a sequence of san_msgs__msg__Task.
typedef struct san_msgs__msg__Task__Sequence
{
  san_msgs__msg__Task * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__msg__Task__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__MSG__DETAIL__TASK__STRUCT_H_
