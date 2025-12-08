// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_
#define SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BatteryStatus in the package san_msgs.
typedef struct san_msgs__msg__BatteryStatus
{
  /// TOP Battery Voltage (V)
  float voltage_top;
  /// TOP Battery Current (A)
  float current_top;
  /// TOP Battery State of Charge
  float soc_top;
  /// TOP Battery State of Health
  float soh_top;
  /// Voltage (V)
  float voltage;
  /// Current (A)
  float current;
  /// State of Charge
  float soc;
  /// State of Health
  float soh;
  /// Charge Relay
  bool charge_relay;
  /// Charging Jack State (True: Other position, False: Home position)
  bool charging_jack_state;
  bool charging_state;
} san_msgs__msg__BatteryStatus;

// Struct for a sequence of san_msgs__msg__BatteryStatus.
typedef struct san_msgs__msg__BatteryStatus__Sequence
{
  san_msgs__msg__BatteryStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__msg__BatteryStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_H_
