// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:msg/Behavior.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/behavior__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
san_msgs__msg__Behavior__init(san_msgs__msg__Behavior * msg)
{
  if (!msg) {
    return false;
  }
  // behavior_auto_started
  // behavior_slam_started
  // behavior_charge_started
  // behavior_docking_started
  // behavior_undocking_started
  // behavior_auto_completed
  // behavior_slam_completed
  // behavior_charge_completed
  // behavior_docking_completed
  // behavior_undocking_completed
  // behavior_auto_canceled
  // behavior_docking_canceled
  // behavior_manipulation_redocking_triggered
  // behavior_charging_redocking_triggered
  // behavior_manipulator_completed
  // behavior_manipulator_emergency_triggered
  // behavior_manual_mode_triggered
  return true;
}

void
san_msgs__msg__Behavior__fini(san_msgs__msg__Behavior * msg)
{
  if (!msg) {
    return;
  }
  // behavior_auto_started
  // behavior_slam_started
  // behavior_charge_started
  // behavior_docking_started
  // behavior_undocking_started
  // behavior_auto_completed
  // behavior_slam_completed
  // behavior_charge_completed
  // behavior_docking_completed
  // behavior_undocking_completed
  // behavior_auto_canceled
  // behavior_docking_canceled
  // behavior_manipulation_redocking_triggered
  // behavior_charging_redocking_triggered
  // behavior_manipulator_completed
  // behavior_manipulator_emergency_triggered
  // behavior_manual_mode_triggered
}

bool
san_msgs__msg__Behavior__are_equal(const san_msgs__msg__Behavior * lhs, const san_msgs__msg__Behavior * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // behavior_auto_started
  if (lhs->behavior_auto_started != rhs->behavior_auto_started) {
    return false;
  }
  // behavior_slam_started
  if (lhs->behavior_slam_started != rhs->behavior_slam_started) {
    return false;
  }
  // behavior_charge_started
  if (lhs->behavior_charge_started != rhs->behavior_charge_started) {
    return false;
  }
  // behavior_docking_started
  if (lhs->behavior_docking_started != rhs->behavior_docking_started) {
    return false;
  }
  // behavior_undocking_started
  if (lhs->behavior_undocking_started != rhs->behavior_undocking_started) {
    return false;
  }
  // behavior_auto_completed
  if (lhs->behavior_auto_completed != rhs->behavior_auto_completed) {
    return false;
  }
  // behavior_slam_completed
  if (lhs->behavior_slam_completed != rhs->behavior_slam_completed) {
    return false;
  }
  // behavior_charge_completed
  if (lhs->behavior_charge_completed != rhs->behavior_charge_completed) {
    return false;
  }
  // behavior_docking_completed
  if (lhs->behavior_docking_completed != rhs->behavior_docking_completed) {
    return false;
  }
  // behavior_undocking_completed
  if (lhs->behavior_undocking_completed != rhs->behavior_undocking_completed) {
    return false;
  }
  // behavior_auto_canceled
  if (lhs->behavior_auto_canceled != rhs->behavior_auto_canceled) {
    return false;
  }
  // behavior_docking_canceled
  if (lhs->behavior_docking_canceled != rhs->behavior_docking_canceled) {
    return false;
  }
  // behavior_manipulation_redocking_triggered
  if (lhs->behavior_manipulation_redocking_triggered != rhs->behavior_manipulation_redocking_triggered) {
    return false;
  }
  // behavior_charging_redocking_triggered
  if (lhs->behavior_charging_redocking_triggered != rhs->behavior_charging_redocking_triggered) {
    return false;
  }
  // behavior_manipulator_completed
  if (lhs->behavior_manipulator_completed != rhs->behavior_manipulator_completed) {
    return false;
  }
  // behavior_manipulator_emergency_triggered
  if (lhs->behavior_manipulator_emergency_triggered != rhs->behavior_manipulator_emergency_triggered) {
    return false;
  }
  // behavior_manual_mode_triggered
  if (lhs->behavior_manual_mode_triggered != rhs->behavior_manual_mode_triggered) {
    return false;
  }
  return true;
}

bool
san_msgs__msg__Behavior__copy(
  const san_msgs__msg__Behavior * input,
  san_msgs__msg__Behavior * output)
{
  if (!input || !output) {
    return false;
  }
  // behavior_auto_started
  output->behavior_auto_started = input->behavior_auto_started;
  // behavior_slam_started
  output->behavior_slam_started = input->behavior_slam_started;
  // behavior_charge_started
  output->behavior_charge_started = input->behavior_charge_started;
  // behavior_docking_started
  output->behavior_docking_started = input->behavior_docking_started;
  // behavior_undocking_started
  output->behavior_undocking_started = input->behavior_undocking_started;
  // behavior_auto_completed
  output->behavior_auto_completed = input->behavior_auto_completed;
  // behavior_slam_completed
  output->behavior_slam_completed = input->behavior_slam_completed;
  // behavior_charge_completed
  output->behavior_charge_completed = input->behavior_charge_completed;
  // behavior_docking_completed
  output->behavior_docking_completed = input->behavior_docking_completed;
  // behavior_undocking_completed
  output->behavior_undocking_completed = input->behavior_undocking_completed;
  // behavior_auto_canceled
  output->behavior_auto_canceled = input->behavior_auto_canceled;
  // behavior_docking_canceled
  output->behavior_docking_canceled = input->behavior_docking_canceled;
  // behavior_manipulation_redocking_triggered
  output->behavior_manipulation_redocking_triggered = input->behavior_manipulation_redocking_triggered;
  // behavior_charging_redocking_triggered
  output->behavior_charging_redocking_triggered = input->behavior_charging_redocking_triggered;
  // behavior_manipulator_completed
  output->behavior_manipulator_completed = input->behavior_manipulator_completed;
  // behavior_manipulator_emergency_triggered
  output->behavior_manipulator_emergency_triggered = input->behavior_manipulator_emergency_triggered;
  // behavior_manual_mode_triggered
  output->behavior_manual_mode_triggered = input->behavior_manual_mode_triggered;
  return true;
}

san_msgs__msg__Behavior *
san_msgs__msg__Behavior__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Behavior * msg = (san_msgs__msg__Behavior *)allocator.allocate(sizeof(san_msgs__msg__Behavior), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__msg__Behavior));
  bool success = san_msgs__msg__Behavior__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__msg__Behavior__destroy(san_msgs__msg__Behavior * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__msg__Behavior__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__msg__Behavior__Sequence__init(san_msgs__msg__Behavior__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Behavior * data = NULL;

  if (size) {
    data = (san_msgs__msg__Behavior *)allocator.zero_allocate(size, sizeof(san_msgs__msg__Behavior), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__msg__Behavior__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__msg__Behavior__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
san_msgs__msg__Behavior__Sequence__fini(san_msgs__msg__Behavior__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      san_msgs__msg__Behavior__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

san_msgs__msg__Behavior__Sequence *
san_msgs__msg__Behavior__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Behavior__Sequence * array = (san_msgs__msg__Behavior__Sequence *)allocator.allocate(sizeof(san_msgs__msg__Behavior__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__msg__Behavior__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__msg__Behavior__Sequence__destroy(san_msgs__msg__Behavior__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__msg__Behavior__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__msg__Behavior__Sequence__are_equal(const san_msgs__msg__Behavior__Sequence * lhs, const san_msgs__msg__Behavior__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__msg__Behavior__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__msg__Behavior__Sequence__copy(
  const san_msgs__msg__Behavior__Sequence * input,
  san_msgs__msg__Behavior__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__msg__Behavior);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__msg__Behavior * data =
      (san_msgs__msg__Behavior *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__msg__Behavior__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__msg__Behavior__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__msg__Behavior__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
