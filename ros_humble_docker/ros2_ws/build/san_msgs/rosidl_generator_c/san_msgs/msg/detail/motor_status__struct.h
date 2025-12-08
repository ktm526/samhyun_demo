// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_
#define SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorStatus in the package san_msgs.
/**
  * MotorStatus.msg
  * 0: STATE_MOTOR_SERVO_OFF
  * 1: STATE_MOTOR_SERVO_ON
  * 2: STATE_MOTOR_QUICK_STOP
  * 3: STATE_MOTOR_BRAKE_DISABLE
  * 4: STATE_MOTOR_STO
  * 6: STATE_BATTERY_CHARGING  
  * 8: STATE_MOTOR_SW_STOP
 */
typedef struct san_msgs__msg__MotorStatus
{
  uint8_t state;
} san_msgs__msg__MotorStatus;

// Struct for a sequence of san_msgs__msg__MotorStatus.
typedef struct san_msgs__msg__MotorStatus__Sequence
{
  san_msgs__msg__MotorStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__msg__MotorStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_
