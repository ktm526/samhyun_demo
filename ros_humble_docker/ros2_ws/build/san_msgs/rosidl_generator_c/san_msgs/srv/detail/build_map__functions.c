// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:srv/BuildMap.idl
// generated code does not contain a copyright notice
#include "san_msgs/srv/detail/build_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `map_name`
#include "rosidl_runtime_c/string_functions.h"

bool
san_msgs__srv__BuildMap_Request__init(san_msgs__srv__BuildMap_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command
  // map_name
  if (!rosidl_runtime_c__String__init(&msg->map_name)) {
    san_msgs__srv__BuildMap_Request__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__srv__BuildMap_Request__fini(san_msgs__srv__BuildMap_Request * msg)
{
  if (!msg) {
    return;
  }
  // command
  // map_name
  rosidl_runtime_c__String__fini(&msg->map_name);
}

bool
san_msgs__srv__BuildMap_Request__are_equal(const san_msgs__srv__BuildMap_Request * lhs, const san_msgs__srv__BuildMap_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (lhs->command != rhs->command) {
    return false;
  }
  // map_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->map_name), &(rhs->map_name)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__srv__BuildMap_Request__copy(
  const san_msgs__srv__BuildMap_Request * input,
  san_msgs__srv__BuildMap_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  output->command = input->command;
  // map_name
  if (!rosidl_runtime_c__String__copy(
      &(input->map_name), &(output->map_name)))
  {
    return false;
  }
  return true;
}

san_msgs__srv__BuildMap_Request *
san_msgs__srv__BuildMap_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__BuildMap_Request * msg = (san_msgs__srv__BuildMap_Request *)allocator.allocate(sizeof(san_msgs__srv__BuildMap_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__srv__BuildMap_Request));
  bool success = san_msgs__srv__BuildMap_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__srv__BuildMap_Request__destroy(san_msgs__srv__BuildMap_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__srv__BuildMap_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__srv__BuildMap_Request__Sequence__init(san_msgs__srv__BuildMap_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__BuildMap_Request * data = NULL;

  if (size) {
    data = (san_msgs__srv__BuildMap_Request *)allocator.zero_allocate(size, sizeof(san_msgs__srv__BuildMap_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__srv__BuildMap_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__srv__BuildMap_Request__fini(&data[i - 1]);
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
san_msgs__srv__BuildMap_Request__Sequence__fini(san_msgs__srv__BuildMap_Request__Sequence * array)
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
      san_msgs__srv__BuildMap_Request__fini(&array->data[i]);
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

san_msgs__srv__BuildMap_Request__Sequence *
san_msgs__srv__BuildMap_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__BuildMap_Request__Sequence * array = (san_msgs__srv__BuildMap_Request__Sequence *)allocator.allocate(sizeof(san_msgs__srv__BuildMap_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__srv__BuildMap_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__srv__BuildMap_Request__Sequence__destroy(san_msgs__srv__BuildMap_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__srv__BuildMap_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__srv__BuildMap_Request__Sequence__are_equal(const san_msgs__srv__BuildMap_Request__Sequence * lhs, const san_msgs__srv__BuildMap_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__srv__BuildMap_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__srv__BuildMap_Request__Sequence__copy(
  const san_msgs__srv__BuildMap_Request__Sequence * input,
  san_msgs__srv__BuildMap_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__srv__BuildMap_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__srv__BuildMap_Request * data =
      (san_msgs__srv__BuildMap_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__srv__BuildMap_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__srv__BuildMap_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__srv__BuildMap_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
san_msgs__srv__BuildMap_Response__init(san_msgs__srv__BuildMap_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    san_msgs__srv__BuildMap_Response__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__srv__BuildMap_Response__fini(san_msgs__srv__BuildMap_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
san_msgs__srv__BuildMap_Response__are_equal(const san_msgs__srv__BuildMap_Response * lhs, const san_msgs__srv__BuildMap_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__srv__BuildMap_Response__copy(
  const san_msgs__srv__BuildMap_Response * input,
  san_msgs__srv__BuildMap_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

san_msgs__srv__BuildMap_Response *
san_msgs__srv__BuildMap_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__BuildMap_Response * msg = (san_msgs__srv__BuildMap_Response *)allocator.allocate(sizeof(san_msgs__srv__BuildMap_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__srv__BuildMap_Response));
  bool success = san_msgs__srv__BuildMap_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__srv__BuildMap_Response__destroy(san_msgs__srv__BuildMap_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__srv__BuildMap_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__srv__BuildMap_Response__Sequence__init(san_msgs__srv__BuildMap_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__BuildMap_Response * data = NULL;

  if (size) {
    data = (san_msgs__srv__BuildMap_Response *)allocator.zero_allocate(size, sizeof(san_msgs__srv__BuildMap_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__srv__BuildMap_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__srv__BuildMap_Response__fini(&data[i - 1]);
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
san_msgs__srv__BuildMap_Response__Sequence__fini(san_msgs__srv__BuildMap_Response__Sequence * array)
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
      san_msgs__srv__BuildMap_Response__fini(&array->data[i]);
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

san_msgs__srv__BuildMap_Response__Sequence *
san_msgs__srv__BuildMap_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__BuildMap_Response__Sequence * array = (san_msgs__srv__BuildMap_Response__Sequence *)allocator.allocate(sizeof(san_msgs__srv__BuildMap_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__srv__BuildMap_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__srv__BuildMap_Response__Sequence__destroy(san_msgs__srv__BuildMap_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__srv__BuildMap_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__srv__BuildMap_Response__Sequence__are_equal(const san_msgs__srv__BuildMap_Response__Sequence * lhs, const san_msgs__srv__BuildMap_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__srv__BuildMap_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__srv__BuildMap_Response__Sequence__copy(
  const san_msgs__srv__BuildMap_Response__Sequence * input,
  san_msgs__srv__BuildMap_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__srv__BuildMap_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__srv__BuildMap_Response * data =
      (san_msgs__srv__BuildMap_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__srv__BuildMap_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__srv__BuildMap_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__srv__BuildMap_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
