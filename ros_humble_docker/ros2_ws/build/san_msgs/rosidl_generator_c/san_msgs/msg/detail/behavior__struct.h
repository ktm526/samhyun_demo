// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:msg/Behavior.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__BEHAVIOR__STRUCT_H_
#define SAN_MSGS__MSG__DETAIL__BEHAVIOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Behavior in the package san_msgs.
/**
  * bool behavior_load_started
  * bool behavior_unload_started
 */
typedef struct san_msgs__msg__Behavior
{
  bool behavior_auto_started;
  bool behavior_slam_started;
  bool behavior_charge_started;
  bool behavior_docking_started;
  bool behavior_undocking_started;
  /// bool behavior_load_completed
  /// bool behavior_unload_completed
  bool behavior_auto_completed;
  bool behavior_slam_completed;
  bool behavior_charge_completed;
  bool behavior_docking_completed;
  bool behavior_undocking_completed;
  bool behavior_auto_canceled;
  bool behavior_docking_canceled;
  bool behavior_manipulation_redocking_triggered;
  bool behavior_charging_redocking_triggered;
  bool behavior_manipulator_completed;
  bool behavior_manipulator_emergency_triggered;
  bool behavior_manual_mode_triggered;
} san_msgs__msg__Behavior;

// Struct for a sequence of san_msgs__msg__Behavior.
typedef struct san_msgs__msg__Behavior__Sequence
{
  san_msgs__msg__Behavior * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__msg__Behavior__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__MSG__DETAIL__BEHAVIOR__STRUCT_H_
