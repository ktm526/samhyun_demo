// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:msg/Qrdetection.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/qrdetection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `translation`
// Member `rotation`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
san_msgs__msg__Qrdetection__init(san_msgs__msg__Qrdetection * msg)
{
  if (!msg) {
    return false;
  }
  // cam_num
  // id
  // translation
  if (!geometry_msgs__msg__Vector3__init(&msg->translation)) {
    san_msgs__msg__Qrdetection__fini(msg);
    return false;
  }
  // rotation
  if (!geometry_msgs__msg__Vector3__init(&msg->rotation)) {
    san_msgs__msg__Qrdetection__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__msg__Qrdetection__fini(san_msgs__msg__Qrdetection * msg)
{
  if (!msg) {
    return;
  }
  // cam_num
  // id
  // translation
  geometry_msgs__msg__Vector3__fini(&msg->translation);
  // rotation
  geometry_msgs__msg__Vector3__fini(&msg->rotation);
}

bool
san_msgs__msg__Qrdetection__are_equal(const san_msgs__msg__Qrdetection * lhs, const san_msgs__msg__Qrdetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cam_num
  if (lhs->cam_num != rhs->cam_num) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // translation
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->translation), &(rhs->translation)))
  {
    return false;
  }
  // rotation
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->rotation), &(rhs->rotation)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__msg__Qrdetection__copy(
  const san_msgs__msg__Qrdetection * input,
  san_msgs__msg__Qrdetection * output)
{
  if (!input || !output) {
    return false;
  }
  // cam_num
  output->cam_num = input->cam_num;
  // id
  output->id = input->id;
  // translation
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->translation), &(output->translation)))
  {
    return false;
  }
  // rotation
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->rotation), &(output->rotation)))
  {
    return false;
  }
  return true;
}

san_msgs__msg__Qrdetection *
san_msgs__msg__Qrdetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Qrdetection * msg = (san_msgs__msg__Qrdetection *)allocator.allocate(sizeof(san_msgs__msg__Qrdetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__msg__Qrdetection));
  bool success = san_msgs__msg__Qrdetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__msg__Qrdetection__destroy(san_msgs__msg__Qrdetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__msg__Qrdetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__msg__Qrdetection__Sequence__init(san_msgs__msg__Qrdetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Qrdetection * data = NULL;

  if (size) {
    data = (san_msgs__msg__Qrdetection *)allocator.zero_allocate(size, sizeof(san_msgs__msg__Qrdetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__msg__Qrdetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__msg__Qrdetection__fini(&data[i - 1]);
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
san_msgs__msg__Qrdetection__Sequence__fini(san_msgs__msg__Qrdetection__Sequence * array)
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
      san_msgs__msg__Qrdetection__fini(&array->data[i]);
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

san_msgs__msg__Qrdetection__Sequence *
san_msgs__msg__Qrdetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Qrdetection__Sequence * array = (san_msgs__msg__Qrdetection__Sequence *)allocator.allocate(sizeof(san_msgs__msg__Qrdetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__msg__Qrdetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__msg__Qrdetection__Sequence__destroy(san_msgs__msg__Qrdetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__msg__Qrdetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__msg__Qrdetection__Sequence__are_equal(const san_msgs__msg__Qrdetection__Sequence * lhs, const san_msgs__msg__Qrdetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__msg__Qrdetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__msg__Qrdetection__Sequence__copy(
  const san_msgs__msg__Qrdetection__Sequence * input,
  san_msgs__msg__Qrdetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__msg__Qrdetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__msg__Qrdetection * data =
      (san_msgs__msg__Qrdetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__msg__Qrdetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__msg__Qrdetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__msg__Qrdetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
