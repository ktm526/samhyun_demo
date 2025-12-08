// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:msg/Task.idl
// generated code does not contain a copyright notice
#include "san_msgs/msg/detail/task__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
san_msgs__msg__Task__init(san_msgs__msg__Task * msg)
{
  if (!msg) {
    return false;
  }
  // task_load_started
  // task_unload_started
  // task_move_started
  // task_home_started
  // task_cancel_started
  // task_load_completed
  // task_unload_completed
  // task_move_completed
  // task_home_completed
  // task_cancel_completed
  return true;
}

void
san_msgs__msg__Task__fini(san_msgs__msg__Task * msg)
{
  if (!msg) {
    return;
  }
  // task_load_started
  // task_unload_started
  // task_move_started
  // task_home_started
  // task_cancel_started
  // task_load_completed
  // task_unload_completed
  // task_move_completed
  // task_home_completed
  // task_cancel_completed
}

bool
san_msgs__msg__Task__are_equal(const san_msgs__msg__Task * lhs, const san_msgs__msg__Task * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_load_started
  if (lhs->task_load_started != rhs->task_load_started) {
    return false;
  }
  // task_unload_started
  if (lhs->task_unload_started != rhs->task_unload_started) {
    return false;
  }
  // task_move_started
  if (lhs->task_move_started != rhs->task_move_started) {
    return false;
  }
  // task_home_started
  if (lhs->task_home_started != rhs->task_home_started) {
    return false;
  }
  // task_cancel_started
  if (lhs->task_cancel_started != rhs->task_cancel_started) {
    return false;
  }
  // task_load_completed
  if (lhs->task_load_completed != rhs->task_load_completed) {
    return false;
  }
  // task_unload_completed
  if (lhs->task_unload_completed != rhs->task_unload_completed) {
    return false;
  }
  // task_move_completed
  if (lhs->task_move_completed != rhs->task_move_completed) {
    return false;
  }
  // task_home_completed
  if (lhs->task_home_completed != rhs->task_home_completed) {
    return false;
  }
  // task_cancel_completed
  if (lhs->task_cancel_completed != rhs->task_cancel_completed) {
    return false;
  }
  return true;
}

bool
san_msgs__msg__Task__copy(
  const san_msgs__msg__Task * input,
  san_msgs__msg__Task * output)
{
  if (!input || !output) {
    return false;
  }
  // task_load_started
  output->task_load_started = input->task_load_started;
  // task_unload_started
  output->task_unload_started = input->task_unload_started;
  // task_move_started
  output->task_move_started = input->task_move_started;
  // task_home_started
  output->task_home_started = input->task_home_started;
  // task_cancel_started
  output->task_cancel_started = input->task_cancel_started;
  // task_load_completed
  output->task_load_completed = input->task_load_completed;
  // task_unload_completed
  output->task_unload_completed = input->task_unload_completed;
  // task_move_completed
  output->task_move_completed = input->task_move_completed;
  // task_home_completed
  output->task_home_completed = input->task_home_completed;
  // task_cancel_completed
  output->task_cancel_completed = input->task_cancel_completed;
  return true;
}

san_msgs__msg__Task *
san_msgs__msg__Task__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Task * msg = (san_msgs__msg__Task *)allocator.allocate(sizeof(san_msgs__msg__Task), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__msg__Task));
  bool success = san_msgs__msg__Task__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__msg__Task__destroy(san_msgs__msg__Task * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__msg__Task__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__msg__Task__Sequence__init(san_msgs__msg__Task__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Task * data = NULL;

  if (size) {
    data = (san_msgs__msg__Task *)allocator.zero_allocate(size, sizeof(san_msgs__msg__Task), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__msg__Task__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__msg__Task__fini(&data[i - 1]);
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
san_msgs__msg__Task__Sequence__fini(san_msgs__msg__Task__Sequence * array)
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
      san_msgs__msg__Task__fini(&array->data[i]);
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

san_msgs__msg__Task__Sequence *
san_msgs__msg__Task__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__msg__Task__Sequence * array = (san_msgs__msg__Task__Sequence *)allocator.allocate(sizeof(san_msgs__msg__Task__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__msg__Task__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__msg__Task__Sequence__destroy(san_msgs__msg__Task__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__msg__Task__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__msg__Task__Sequence__are_equal(const san_msgs__msg__Task__Sequence * lhs, const san_msgs__msg__Task__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__msg__Task__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__msg__Task__Sequence__copy(
  const san_msgs__msg__Task__Sequence * input,
  san_msgs__msg__Task__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__msg__Task);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__msg__Task * data =
      (san_msgs__msg__Task *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__msg__Task__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__msg__Task__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__msg__Task__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
