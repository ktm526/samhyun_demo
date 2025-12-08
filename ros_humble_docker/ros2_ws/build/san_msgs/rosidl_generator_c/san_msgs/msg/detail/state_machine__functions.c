// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/state_machine__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
san_msgs__msg__StateMachine__init(san_msgs__msg__StateMachine * msg)
{
  if (!msg) {
    return false;
  }
  // state
  // status
  return true;
}

void
san_msgs__msg__StateMachine__fini(san_msgs__msg__StateMachine * msg)
{
  if (!msg) {
    return;
  }
  // state
  // status
}

bool
san_msgs__msg__StateMachine__are_equal(const san_msgs__msg__StateMachine * lhs, const san_msgs__msg__StateMachine * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
san_msgs__msg__StateMachine__copy(
  const san_msgs__msg__StateMachine * input,
  san_msgs__msg__StateMachine * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  output->state = input->state;
  // status
  output->status = input->status;
  return true;
}

san_msgs__msg__StateMachine *
san_msgs__msg__StateMachine__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__StateMachine * msg = (san_msgs__msg__StateMachine *)allocator.allocate(sizeof(san_msgs__msg__StateMachine), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__msg__StateMachine));
  bool success = san_msgs__msg__StateMachine__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__msg__StateMachine__destroy(san_msgs__msg__StateMachine * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__msg__StateMachine__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__msg__StateMachine__Sequence__init(san_msgs__msg__StateMachine__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__StateMachine * data = NULL;

  if (size) {
    data = (san_msgs__msg__StateMachine *)allocator.zero_allocate(size, sizeof(san_msgs__msg__StateMachine), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__msg__StateMachine__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__msg__StateMachine__fini(&data[i - 1]);
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
san_msgs__msg__StateMachine__Sequence__fini(san_msgs__msg__StateMachine__Sequence * array)
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
      san_msgs__msg__StateMachine__fini(&array->data[i]);
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

san_msgs__msg__StateMachine__Sequence *
san_msgs__msg__StateMachine__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__StateMachine__Sequence * array = (san_msgs__msg__StateMachine__Sequence *)allocator.allocate(sizeof(san_msgs__msg__StateMachine__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__msg__StateMachine__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__msg__StateMachine__Sequence__destroy(san_msgs__msg__StateMachine__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__msg__StateMachine__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__msg__StateMachine__Sequence__are_equal(const san_msgs__msg__StateMachine__Sequence * lhs, const san_msgs__msg__StateMachine__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__msg__StateMachine__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__msg__StateMachine__Sequence__copy(
  const san_msgs__msg__StateMachine__Sequence * input,
  san_msgs__msg__StateMachine__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__msg__StateMachine);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__msg__StateMachine * data =
      (san_msgs__msg__StateMachine *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__msg__StateMachine__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__msg__StateMachine__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__msg__StateMachine__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
