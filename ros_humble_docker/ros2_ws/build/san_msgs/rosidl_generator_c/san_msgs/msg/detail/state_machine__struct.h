// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_H_
#define SAN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'INIT'.
/**
  * 0
 */
enum
{
  san_msgs__msg__StateMachine__INIT = 0
};

/// Constant 'IDLE'.
/**
  * 16
 */
enum
{
  san_msgs__msg__StateMachine__IDLE = 16
};

/// Constant 'AUTO'.
/**
  * 32
 */
enum
{
  san_msgs__msg__StateMachine__AUTO = 32
};

/// Constant 'MANUAL'.
/**
  * 48
 */
enum
{
  san_msgs__msg__StateMachine__MANUAL = 48
};

/// Constant 'DOCKING'.
/**
  * 64
 */
enum
{
  san_msgs__msg__StateMachine__DOCKING = 64
};

/// Constant 'UNDOCKING'.
/**
  * 80
 */
enum
{
  san_msgs__msg__StateMachine__UNDOCKING = 80
};

/// Constant 'CHARGING'.
/**
  * 96
 */
enum
{
  san_msgs__msg__StateMachine__CHARGING = 96
};

/// Constant 'MANIPULATION'.
/**
  * 112  Send for Robot Arm
 */
enum
{
  san_msgs__msg__StateMachine__MANIPULATION = 112
};

/// Constant 'EMERGENCY'.
/**
  * 128
 */
enum
{
  san_msgs__msg__StateMachine__EMERGENCY = 128
};

/// Constant 'STOP'.
/**
  * 144
 */
enum
{
  san_msgs__msg__StateMachine__STOP = 144
};

/// Constant 'RUNNING'.
/**
  * Status
 */
enum
{
  san_msgs__msg__StateMachine__RUNNING = 0
};

/// Constant 'SUCCESS'.
enum
{
  san_msgs__msg__StateMachine__SUCCESS = 1
};

/// Constant 'FAIL'.
enum
{
  san_msgs__msg__StateMachine__FAIL = 2
};

/// Struct defined in msg/StateMachine in the package san_msgs.
/**
  * State
 */
typedef struct san_msgs__msg__StateMachine
{
  /// uint8 SLAM           = 0x100     # 160 Back to the Docking Waypoint Node
  uint8_t state;
  uint8_t status;
} san_msgs__msg__StateMachine;

// Struct for a sequence of san_msgs__msg__StateMachine.
typedef struct san_msgs__msg__StateMachine__Sequence
{
  san_msgs__msg__StateMachine * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__msg__StateMachine__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_H_
