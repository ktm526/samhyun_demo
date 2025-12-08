// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:msg/Emergency.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/emergency__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
san_msgs__msg__Emergency__init(san_msgs__msg__Emergency * msg)
{
  if (!msg) {
    return false;
  }
  // emergency
  return true;
}

void
san_msgs__msg__Emergency__fini(san_msgs__msg__Emergency * msg)
{
  if (!msg) {
    return;
  }
  // emergency
}

bool
san_msgs__msg__Emergency__are_equal(const san_msgs__msg__Emergency * lhs, const san_msgs__msg__Emergency * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // emergency
  if (lhs->emergency != rhs->emergency) {
    return false;
  }
  return true;
}

bool
san_msgs__msg__Emergency__copy(
  const san_msgs__msg__Emergency * input,
  san_msgs__msg__Emergency * output)
{
  if (!input || !output) {
    return false;
  }
  // emergency
  output->emergency = input->emergency;
  return true;
}

san_msgs__msg__Emergency *
san_msgs__msg__Emergency__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Emergency * msg = (san_msgs__msg__Emergency *)allocator.allocate(sizeof(san_msgs__msg__Emergency), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__msg__Emergency));
  bool success = san_msgs__msg__Emergency__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__msg__Emergency__destroy(san_msgs__msg__Emergency * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__msg__Emergency__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__msg__Emergency__Sequence__init(san_msgs__msg__Emergency__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Emergency * data = NULL;

  if (size) {
    data = (san_msgs__msg__Emergency *)allocator.zero_allocate(size, sizeof(san_msgs__msg__Emergency), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__msg__Emergency__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__msg__Emergency__fini(&data[i - 1]);
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
san_msgs__msg__Emergency__Sequence__fini(san_msgs__msg__Emergency__Sequence * array)
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
      san_msgs__msg__Emergency__fini(&array->data[i]);
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

san_msgs__msg__Emergency__Sequence *
san_msgs__msg__Emergency__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Emergency__Sequence * array = (san_msgs__msg__Emergency__Sequence *)allocator.allocate(sizeof(san_msgs__msg__Emergency__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__msg__Emergency__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__msg__Emergency__Sequence__destroy(san_msgs__msg__Emergency__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__msg__Emergency__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__msg__Emergency__Sequence__are_equal(const san_msgs__msg__Emergency__Sequence * lhs, const san_msgs__msg__Emergency__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__msg__Emergency__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__msg__Emergency__Sequence__copy(
  const san_msgs__msg__Emergency__Sequence * input,
  san_msgs__msg__Emergency__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__msg__Emergency);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__msg__Emergency * data =
      (san_msgs__msg__Emergency *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__msg__Emergency__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__msg__Emergency__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__msg__Emergency__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
