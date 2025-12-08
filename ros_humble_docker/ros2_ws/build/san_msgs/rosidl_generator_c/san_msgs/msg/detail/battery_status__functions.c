// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/battery_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
san_msgs__msg__BatteryStatus__init(san_msgs__msg__BatteryStatus * msg)
{
  if (!msg) {
    return false;
  }
  // voltage_top
  // current_top
  // soc_top
  // soh_top
  // voltage
  // current
  // soc
  // soh
  // charge_relay
  // charging_jack_state
  // charging_state
  return true;
}

void
san_msgs__msg__BatteryStatus__fini(san_msgs__msg__BatteryStatus * msg)
{
  if (!msg) {
    return;
  }
  // voltage_top
  // current_top
  // soc_top
  // soh_top
  // voltage
  // current
  // soc
  // soh
  // charge_relay
  // charging_jack_state
  // charging_state
}

bool
san_msgs__msg__BatteryStatus__are_equal(const san_msgs__msg__BatteryStatus * lhs, const san_msgs__msg__BatteryStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // voltage_top
  if (lhs->voltage_top != rhs->voltage_top) {
    return false;
  }
  // current_top
  if (lhs->current_top != rhs->current_top) {
    return false;
  }
  // soc_top
  if (lhs->soc_top != rhs->soc_top) {
    return false;
  }
  // soh_top
  if (lhs->soh_top != rhs->soh_top) {
    return false;
  }
  // voltage
  if (lhs->voltage != rhs->voltage) {
    return false;
  }
  // current
  if (lhs->current != rhs->current) {
    return false;
  }
  // soc
  if (lhs->soc != rhs->soc) {
    return false;
  }
  // soh
  if (lhs->soh != rhs->soh) {
    return false;
  }
  // charge_relay
  if (lhs->charge_relay != rhs->charge_relay) {
    return false;
  }
  // charging_jack_state
  if (lhs->charging_jack_state != rhs->charging_jack_state) {
    return false;
  }
  // charging_state
  if (lhs->charging_state != rhs->charging_state) {
    return false;
  }
  return true;
}

bool
san_msgs__msg__BatteryStatus__copy(
  const san_msgs__msg__BatteryStatus * input,
  san_msgs__msg__BatteryStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // voltage_top
  output->voltage_top = input->voltage_top;
  // current_top
  output->current_top = input->current_top;
  // soc_top
  output->soc_top = input->soc_top;
  // soh_top
  output->soh_top = input->soh_top;
  // voltage
  output->voltage = input->voltage;
  // current
  output->current = input->current;
  // soc
  output->soc = input->soc;
  // soh
  output->soh = input->soh;
  // charge_relay
  output->charge_relay = input->charge_relay;
  // charging_jack_state
  output->charging_jack_state = input->charging_jack_state;
  // charging_state
  output->charging_state = input->charging_state;
  return true;
}

san_msgs__msg__BatteryStatus *
san_msgs__msg__BatteryStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__BatteryStatus * msg = (san_msgs__msg__BatteryStatus *)allocator.allocate(sizeof(san_msgs__msg__BatteryStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__msg__BatteryStatus));
  bool success = san_msgs__msg__BatteryStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__msg__BatteryStatus__destroy(san_msgs__msg__BatteryStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__msg__BatteryStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__msg__BatteryStatus__Sequence__init(san_msgs__msg__BatteryStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__BatteryStatus * data = NULL;

  if (size) {
    data = (san_msgs__msg__BatteryStatus *)allocator.zero_allocate(size, sizeof(san_msgs__msg__BatteryStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__msg__BatteryStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__msg__BatteryStatus__fini(&data[i - 1]);
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
san_msgs__msg__BatteryStatus__Sequence__fini(san_msgs__msg__BatteryStatus__Sequence * array)
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
      san_msgs__msg__BatteryStatus__fini(&array->data[i]);
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

san_msgs__msg__BatteryStatus__Sequence *
san_msgs__msg__BatteryStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__BatteryStatus__Sequence * array = (san_msgs__msg__BatteryStatus__Sequence *)allocator.allocate(sizeof(san_msgs__msg__BatteryStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__msg__BatteryStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__msg__BatteryStatus__Sequence__destroy(san_msgs__msg__BatteryStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__msg__BatteryStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__msg__BatteryStatus__Sequence__are_equal(const san_msgs__msg__BatteryStatus__Sequence * lhs, const san_msgs__msg__BatteryStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__msg__BatteryStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__msg__BatteryStatus__Sequence__copy(
  const san_msgs__msg__BatteryStatus__Sequence * input,
  san_msgs__msg__BatteryStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__msg__BatteryStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__msg__BatteryStatus * data =
      (san_msgs__msg__BatteryStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__msg__BatteryStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__msg__BatteryStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__msg__BatteryStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
