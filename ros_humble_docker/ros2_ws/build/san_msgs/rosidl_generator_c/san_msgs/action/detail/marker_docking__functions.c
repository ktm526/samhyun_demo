// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:action/MarkerDocking.idl
// generated code does not contain a copyright notice
#include "san_msgs/action/detail/marker_docking__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `camera_mode`
#include "rosidl_runtime_c/string_functions.h"

bool
san_msgs__action__MarkerDocking_Goal__init(san_msgs__action__MarkerDocking_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // camera_mode
  if (!rosidl_runtime_c__String__init(&msg->camera_mode)) {
    san_msgs__action__MarkerDocking_Goal__fini(msg);
    return false;
  }
  // marker_gap
  // marker_id
  return true;
}

void
san_msgs__action__MarkerDocking_Goal__fini(san_msgs__action__MarkerDocking_Goal * msg)
{
  if (!msg) {
    return;
  }
  // camera_mode
  rosidl_runtime_c__String__fini(&msg->camera_mode);
  // marker_gap
  // marker_id
}

bool
san_msgs__action__MarkerDocking_Goal__are_equal(const san_msgs__action__MarkerDocking_Goal * lhs, const san_msgs__action__MarkerDocking_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // camera_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->camera_mode), &(rhs->camera_mode)))
  {
    return false;
  }
  // marker_gap
  if (lhs->marker_gap != rhs->marker_gap) {
    return false;
  }
  // marker_id
  if (lhs->marker_id != rhs->marker_id) {
    return false;
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_Goal__copy(
  const san_msgs__action__MarkerDocking_Goal * input,
  san_msgs__action__MarkerDocking_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // camera_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->camera_mode), &(output->camera_mode)))
  {
    return false;
  }
  // marker_gap
  output->marker_gap = input->marker_gap;
  // marker_id
  output->marker_id = input->marker_id;
  return true;
}

san_msgs__action__MarkerDocking_Goal *
san_msgs__action__MarkerDocking_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Goal * msg = (san_msgs__action__MarkerDocking_Goal *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__action__MarkerDocking_Goal));
  bool success = san_msgs__action__MarkerDocking_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__action__MarkerDocking_Goal__destroy(san_msgs__action__MarkerDocking_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__action__MarkerDocking_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__action__MarkerDocking_Goal__Sequence__init(san_msgs__action__MarkerDocking_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Goal * data = NULL;

  if (size) {
    data = (san_msgs__action__MarkerDocking_Goal *)allocator.zero_allocate(size, sizeof(san_msgs__action__MarkerDocking_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__action__MarkerDocking_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__action__MarkerDocking_Goal__fini(&data[i - 1]);
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
san_msgs__action__MarkerDocking_Goal__Sequence__fini(san_msgs__action__MarkerDocking_Goal__Sequence * array)
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
      san_msgs__action__MarkerDocking_Goal__fini(&array->data[i]);
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

san_msgs__action__MarkerDocking_Goal__Sequence *
san_msgs__action__MarkerDocking_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Goal__Sequence * array = (san_msgs__action__MarkerDocking_Goal__Sequence *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__action__MarkerDocking_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__action__MarkerDocking_Goal__Sequence__destroy(san_msgs__action__MarkerDocking_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__action__MarkerDocking_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__action__MarkerDocking_Goal__Sequence__are_equal(const san_msgs__action__MarkerDocking_Goal__Sequence * lhs, const san_msgs__action__MarkerDocking_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__action__MarkerDocking_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_Goal__Sequence__copy(
  const san_msgs__action__MarkerDocking_Goal__Sequence * input,
  san_msgs__action__MarkerDocking_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__action__MarkerDocking_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__action__MarkerDocking_Goal * data =
      (san_msgs__action__MarkerDocking_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__action__MarkerDocking_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__action__MarkerDocking_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__action__MarkerDocking_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
san_msgs__action__MarkerDocking_Result__init(san_msgs__action__MarkerDocking_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
san_msgs__action__MarkerDocking_Result__fini(san_msgs__action__MarkerDocking_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
san_msgs__action__MarkerDocking_Result__are_equal(const san_msgs__action__MarkerDocking_Result * lhs, const san_msgs__action__MarkerDocking_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_Result__copy(
  const san_msgs__action__MarkerDocking_Result * input,
  san_msgs__action__MarkerDocking_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

san_msgs__action__MarkerDocking_Result *
san_msgs__action__MarkerDocking_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Result * msg = (san_msgs__action__MarkerDocking_Result *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__action__MarkerDocking_Result));
  bool success = san_msgs__action__MarkerDocking_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__action__MarkerDocking_Result__destroy(san_msgs__action__MarkerDocking_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__action__MarkerDocking_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__action__MarkerDocking_Result__Sequence__init(san_msgs__action__MarkerDocking_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Result * data = NULL;

  if (size) {
    data = (san_msgs__action__MarkerDocking_Result *)allocator.zero_allocate(size, sizeof(san_msgs__action__MarkerDocking_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__action__MarkerDocking_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__action__MarkerDocking_Result__fini(&data[i - 1]);
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
san_msgs__action__MarkerDocking_Result__Sequence__fini(san_msgs__action__MarkerDocking_Result__Sequence * array)
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
      san_msgs__action__MarkerDocking_Result__fini(&array->data[i]);
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

san_msgs__action__MarkerDocking_Result__Sequence *
san_msgs__action__MarkerDocking_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Result__Sequence * array = (san_msgs__action__MarkerDocking_Result__Sequence *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__action__MarkerDocking_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__action__MarkerDocking_Result__Sequence__destroy(san_msgs__action__MarkerDocking_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__action__MarkerDocking_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__action__MarkerDocking_Result__Sequence__are_equal(const san_msgs__action__MarkerDocking_Result__Sequence * lhs, const san_msgs__action__MarkerDocking_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__action__MarkerDocking_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_Result__Sequence__copy(
  const san_msgs__action__MarkerDocking_Result__Sequence * input,
  san_msgs__action__MarkerDocking_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__action__MarkerDocking_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__action__MarkerDocking_Result * data =
      (san_msgs__action__MarkerDocking_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__action__MarkerDocking_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__action__MarkerDocking_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__action__MarkerDocking_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
san_msgs__action__MarkerDocking_Feedback__init(san_msgs__action__MarkerDocking_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // step
  return true;
}

void
san_msgs__action__MarkerDocking_Feedback__fini(san_msgs__action__MarkerDocking_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // step
}

bool
san_msgs__action__MarkerDocking_Feedback__are_equal(const san_msgs__action__MarkerDocking_Feedback * lhs, const san_msgs__action__MarkerDocking_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // step
  if (lhs->step != rhs->step) {
    return false;
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_Feedback__copy(
  const san_msgs__action__MarkerDocking_Feedback * input,
  san_msgs__action__MarkerDocking_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // step
  output->step = input->step;
  return true;
}

san_msgs__action__MarkerDocking_Feedback *
san_msgs__action__MarkerDocking_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Feedback * msg = (san_msgs__action__MarkerDocking_Feedback *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__action__MarkerDocking_Feedback));
  bool success = san_msgs__action__MarkerDocking_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__action__MarkerDocking_Feedback__destroy(san_msgs__action__MarkerDocking_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__action__MarkerDocking_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__action__MarkerDocking_Feedback__Sequence__init(san_msgs__action__MarkerDocking_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Feedback * data = NULL;

  if (size) {
    data = (san_msgs__action__MarkerDocking_Feedback *)allocator.zero_allocate(size, sizeof(san_msgs__action__MarkerDocking_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__action__MarkerDocking_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__action__MarkerDocking_Feedback__fini(&data[i - 1]);
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
san_msgs__action__MarkerDocking_Feedback__Sequence__fini(san_msgs__action__MarkerDocking_Feedback__Sequence * array)
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
      san_msgs__action__MarkerDocking_Feedback__fini(&array->data[i]);
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

san_msgs__action__MarkerDocking_Feedback__Sequence *
san_msgs__action__MarkerDocking_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_Feedback__Sequence * array = (san_msgs__action__MarkerDocking_Feedback__Sequence *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__action__MarkerDocking_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__action__MarkerDocking_Feedback__Sequence__destroy(san_msgs__action__MarkerDocking_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__action__MarkerDocking_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__action__MarkerDocking_Feedback__Sequence__are_equal(const san_msgs__action__MarkerDocking_Feedback__Sequence * lhs, const san_msgs__action__MarkerDocking_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__action__MarkerDocking_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_Feedback__Sequence__copy(
  const san_msgs__action__MarkerDocking_Feedback__Sequence * input,
  san_msgs__action__MarkerDocking_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__action__MarkerDocking_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__action__MarkerDocking_Feedback * data =
      (san_msgs__action__MarkerDocking_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__action__MarkerDocking_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__action__MarkerDocking_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__action__MarkerDocking_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "san_msgs/action/detail/marker_docking__functions.h"

bool
san_msgs__action__MarkerDocking_SendGoal_Request__init(san_msgs__action__MarkerDocking_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    san_msgs__action__MarkerDocking_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!san_msgs__action__MarkerDocking_Goal__init(&msg->goal)) {
    san_msgs__action__MarkerDocking_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__action__MarkerDocking_SendGoal_Request__fini(san_msgs__action__MarkerDocking_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  san_msgs__action__MarkerDocking_Goal__fini(&msg->goal);
}

bool
san_msgs__action__MarkerDocking_SendGoal_Request__are_equal(const san_msgs__action__MarkerDocking_SendGoal_Request * lhs, const san_msgs__action__MarkerDocking_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!san_msgs__action__MarkerDocking_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_SendGoal_Request__copy(
  const san_msgs__action__MarkerDocking_SendGoal_Request * input,
  san_msgs__action__MarkerDocking_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!san_msgs__action__MarkerDocking_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

san_msgs__action__MarkerDocking_SendGoal_Request *
san_msgs__action__MarkerDocking_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_SendGoal_Request * msg = (san_msgs__action__MarkerDocking_SendGoal_Request *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__action__MarkerDocking_SendGoal_Request));
  bool success = san_msgs__action__MarkerDocking_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__action__MarkerDocking_SendGoal_Request__destroy(san_msgs__action__MarkerDocking_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__action__MarkerDocking_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__action__MarkerDocking_SendGoal_Request__Sequence__init(san_msgs__action__MarkerDocking_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_SendGoal_Request * data = NULL;

  if (size) {
    data = (san_msgs__action__MarkerDocking_SendGoal_Request *)allocator.zero_allocate(size, sizeof(san_msgs__action__MarkerDocking_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__action__MarkerDocking_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__action__MarkerDocking_SendGoal_Request__fini(&data[i - 1]);
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
san_msgs__action__MarkerDocking_SendGoal_Request__Sequence__fini(san_msgs__action__MarkerDocking_SendGoal_Request__Sequence * array)
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
      san_msgs__action__MarkerDocking_SendGoal_Request__fini(&array->data[i]);
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

san_msgs__action__MarkerDocking_SendGoal_Request__Sequence *
san_msgs__action__MarkerDocking_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_SendGoal_Request__Sequence * array = (san_msgs__action__MarkerDocking_SendGoal_Request__Sequence *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__action__MarkerDocking_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__action__MarkerDocking_SendGoal_Request__Sequence__destroy(san_msgs__action__MarkerDocking_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__action__MarkerDocking_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__action__MarkerDocking_SendGoal_Request__Sequence__are_equal(const san_msgs__action__MarkerDocking_SendGoal_Request__Sequence * lhs, const san_msgs__action__MarkerDocking_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__action__MarkerDocking_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_SendGoal_Request__Sequence__copy(
  const san_msgs__action__MarkerDocking_SendGoal_Request__Sequence * input,
  san_msgs__action__MarkerDocking_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__action__MarkerDocking_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__action__MarkerDocking_SendGoal_Request * data =
      (san_msgs__action__MarkerDocking_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__action__MarkerDocking_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__action__MarkerDocking_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__action__MarkerDocking_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
san_msgs__action__MarkerDocking_SendGoal_Response__init(san_msgs__action__MarkerDocking_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    san_msgs__action__MarkerDocking_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__action__MarkerDocking_SendGoal_Response__fini(san_msgs__action__MarkerDocking_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
san_msgs__action__MarkerDocking_SendGoal_Response__are_equal(const san_msgs__action__MarkerDocking_SendGoal_Response * lhs, const san_msgs__action__MarkerDocking_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_SendGoal_Response__copy(
  const san_msgs__action__MarkerDocking_SendGoal_Response * input,
  san_msgs__action__MarkerDocking_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

san_msgs__action__MarkerDocking_SendGoal_Response *
san_msgs__action__MarkerDocking_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_SendGoal_Response * msg = (san_msgs__action__MarkerDocking_SendGoal_Response *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__action__MarkerDocking_SendGoal_Response));
  bool success = san_msgs__action__MarkerDocking_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__action__MarkerDocking_SendGoal_Response__destroy(san_msgs__action__MarkerDocking_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__action__MarkerDocking_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__action__MarkerDocking_SendGoal_Response__Sequence__init(san_msgs__action__MarkerDocking_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_SendGoal_Response * data = NULL;

  if (size) {
    data = (san_msgs__action__MarkerDocking_SendGoal_Response *)allocator.zero_allocate(size, sizeof(san_msgs__action__MarkerDocking_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__action__MarkerDocking_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__action__MarkerDocking_SendGoal_Response__fini(&data[i - 1]);
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
san_msgs__action__MarkerDocking_SendGoal_Response__Sequence__fini(san_msgs__action__MarkerDocking_SendGoal_Response__Sequence * array)
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
      san_msgs__action__MarkerDocking_SendGoal_Response__fini(&array->data[i]);
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

san_msgs__action__MarkerDocking_SendGoal_Response__Sequence *
san_msgs__action__MarkerDocking_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_SendGoal_Response__Sequence * array = (san_msgs__action__MarkerDocking_SendGoal_Response__Sequence *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__action__MarkerDocking_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__action__MarkerDocking_SendGoal_Response__Sequence__destroy(san_msgs__action__MarkerDocking_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__action__MarkerDocking_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__action__MarkerDocking_SendGoal_Response__Sequence__are_equal(const san_msgs__action__MarkerDocking_SendGoal_Response__Sequence * lhs, const san_msgs__action__MarkerDocking_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__action__MarkerDocking_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_SendGoal_Response__Sequence__copy(
  const san_msgs__action__MarkerDocking_SendGoal_Response__Sequence * input,
  san_msgs__action__MarkerDocking_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__action__MarkerDocking_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__action__MarkerDocking_SendGoal_Response * data =
      (san_msgs__action__MarkerDocking_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__action__MarkerDocking_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__action__MarkerDocking_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__action__MarkerDocking_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
san_msgs__action__MarkerDocking_GetResult_Request__init(san_msgs__action__MarkerDocking_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    san_msgs__action__MarkerDocking_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__action__MarkerDocking_GetResult_Request__fini(san_msgs__action__MarkerDocking_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
san_msgs__action__MarkerDocking_GetResult_Request__are_equal(const san_msgs__action__MarkerDocking_GetResult_Request * lhs, const san_msgs__action__MarkerDocking_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_GetResult_Request__copy(
  const san_msgs__action__MarkerDocking_GetResult_Request * input,
  san_msgs__action__MarkerDocking_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

san_msgs__action__MarkerDocking_GetResult_Request *
san_msgs__action__MarkerDocking_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_GetResult_Request * msg = (san_msgs__action__MarkerDocking_GetResult_Request *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__action__MarkerDocking_GetResult_Request));
  bool success = san_msgs__action__MarkerDocking_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__action__MarkerDocking_GetResult_Request__destroy(san_msgs__action__MarkerDocking_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__action__MarkerDocking_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__action__MarkerDocking_GetResult_Request__Sequence__init(san_msgs__action__MarkerDocking_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_GetResult_Request * data = NULL;

  if (size) {
    data = (san_msgs__action__MarkerDocking_GetResult_Request *)allocator.zero_allocate(size, sizeof(san_msgs__action__MarkerDocking_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__action__MarkerDocking_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__action__MarkerDocking_GetResult_Request__fini(&data[i - 1]);
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
san_msgs__action__MarkerDocking_GetResult_Request__Sequence__fini(san_msgs__action__MarkerDocking_GetResult_Request__Sequence * array)
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
      san_msgs__action__MarkerDocking_GetResult_Request__fini(&array->data[i]);
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

san_msgs__action__MarkerDocking_GetResult_Request__Sequence *
san_msgs__action__MarkerDocking_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_GetResult_Request__Sequence * array = (san_msgs__action__MarkerDocking_GetResult_Request__Sequence *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__action__MarkerDocking_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__action__MarkerDocking_GetResult_Request__Sequence__destroy(san_msgs__action__MarkerDocking_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__action__MarkerDocking_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__action__MarkerDocking_GetResult_Request__Sequence__are_equal(const san_msgs__action__MarkerDocking_GetResult_Request__Sequence * lhs, const san_msgs__action__MarkerDocking_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__action__MarkerDocking_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_GetResult_Request__Sequence__copy(
  const san_msgs__action__MarkerDocking_GetResult_Request__Sequence * input,
  san_msgs__action__MarkerDocking_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__action__MarkerDocking_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__action__MarkerDocking_GetResult_Request * data =
      (san_msgs__action__MarkerDocking_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__action__MarkerDocking_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__action__MarkerDocking_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__action__MarkerDocking_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "san_msgs/action/detail/marker_docking__functions.h"

bool
san_msgs__action__MarkerDocking_GetResult_Response__init(san_msgs__action__MarkerDocking_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!san_msgs__action__MarkerDocking_Result__init(&msg->result)) {
    san_msgs__action__MarkerDocking_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__action__MarkerDocking_GetResult_Response__fini(san_msgs__action__MarkerDocking_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  san_msgs__action__MarkerDocking_Result__fini(&msg->result);
}

bool
san_msgs__action__MarkerDocking_GetResult_Response__are_equal(const san_msgs__action__MarkerDocking_GetResult_Response * lhs, const san_msgs__action__MarkerDocking_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!san_msgs__action__MarkerDocking_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_GetResult_Response__copy(
  const san_msgs__action__MarkerDocking_GetResult_Response * input,
  san_msgs__action__MarkerDocking_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!san_msgs__action__MarkerDocking_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

san_msgs__action__MarkerDocking_GetResult_Response *
san_msgs__action__MarkerDocking_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_GetResult_Response * msg = (san_msgs__action__MarkerDocking_GetResult_Response *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__action__MarkerDocking_GetResult_Response));
  bool success = san_msgs__action__MarkerDocking_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__action__MarkerDocking_GetResult_Response__destroy(san_msgs__action__MarkerDocking_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__action__MarkerDocking_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__action__MarkerDocking_GetResult_Response__Sequence__init(san_msgs__action__MarkerDocking_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_GetResult_Response * data = NULL;

  if (size) {
    data = (san_msgs__action__MarkerDocking_GetResult_Response *)allocator.zero_allocate(size, sizeof(san_msgs__action__MarkerDocking_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__action__MarkerDocking_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__action__MarkerDocking_GetResult_Response__fini(&data[i - 1]);
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
san_msgs__action__MarkerDocking_GetResult_Response__Sequence__fini(san_msgs__action__MarkerDocking_GetResult_Response__Sequence * array)
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
      san_msgs__action__MarkerDocking_GetResult_Response__fini(&array->data[i]);
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

san_msgs__action__MarkerDocking_GetResult_Response__Sequence *
san_msgs__action__MarkerDocking_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_GetResult_Response__Sequence * array = (san_msgs__action__MarkerDocking_GetResult_Response__Sequence *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__action__MarkerDocking_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__action__MarkerDocking_GetResult_Response__Sequence__destroy(san_msgs__action__MarkerDocking_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__action__MarkerDocking_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__action__MarkerDocking_GetResult_Response__Sequence__are_equal(const san_msgs__action__MarkerDocking_GetResult_Response__Sequence * lhs, const san_msgs__action__MarkerDocking_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__action__MarkerDocking_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_GetResult_Response__Sequence__copy(
  const san_msgs__action__MarkerDocking_GetResult_Response__Sequence * input,
  san_msgs__action__MarkerDocking_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__action__MarkerDocking_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__action__MarkerDocking_GetResult_Response * data =
      (san_msgs__action__MarkerDocking_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__action__MarkerDocking_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__action__MarkerDocking_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__action__MarkerDocking_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "san_msgs/action/detail/marker_docking__functions.h"

bool
san_msgs__action__MarkerDocking_FeedbackMessage__init(san_msgs__action__MarkerDocking_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    san_msgs__action__MarkerDocking_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!san_msgs__action__MarkerDocking_Feedback__init(&msg->feedback)) {
    san_msgs__action__MarkerDocking_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__action__MarkerDocking_FeedbackMessage__fini(san_msgs__action__MarkerDocking_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  san_msgs__action__MarkerDocking_Feedback__fini(&msg->feedback);
}

bool
san_msgs__action__MarkerDocking_FeedbackMessage__are_equal(const san_msgs__action__MarkerDocking_FeedbackMessage * lhs, const san_msgs__action__MarkerDocking_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!san_msgs__action__MarkerDocking_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_FeedbackMessage__copy(
  const san_msgs__action__MarkerDocking_FeedbackMessage * input,
  san_msgs__action__MarkerDocking_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!san_msgs__action__MarkerDocking_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

san_msgs__action__MarkerDocking_FeedbackMessage *
san_msgs__action__MarkerDocking_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_FeedbackMessage * msg = (san_msgs__action__MarkerDocking_FeedbackMessage *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__action__MarkerDocking_FeedbackMessage));
  bool success = san_msgs__action__MarkerDocking_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__action__MarkerDocking_FeedbackMessage__destroy(san_msgs__action__MarkerDocking_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__action__MarkerDocking_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__action__MarkerDocking_FeedbackMessage__Sequence__init(san_msgs__action__MarkerDocking_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_FeedbackMessage * data = NULL;

  if (size) {
    data = (san_msgs__action__MarkerDocking_FeedbackMessage *)allocator.zero_allocate(size, sizeof(san_msgs__action__MarkerDocking_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__action__MarkerDocking_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__action__MarkerDocking_FeedbackMessage__fini(&data[i - 1]);
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
san_msgs__action__MarkerDocking_FeedbackMessage__Sequence__fini(san_msgs__action__MarkerDocking_FeedbackMessage__Sequence * array)
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
      san_msgs__action__MarkerDocking_FeedbackMessage__fini(&array->data[i]);
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

san_msgs__action__MarkerDocking_FeedbackMessage__Sequence *
san_msgs__action__MarkerDocking_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__action__MarkerDocking_FeedbackMessage__Sequence * array = (san_msgs__action__MarkerDocking_FeedbackMessage__Sequence *)allocator.allocate(sizeof(san_msgs__action__MarkerDocking_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__action__MarkerDocking_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__action__MarkerDocking_FeedbackMessage__Sequence__destroy(san_msgs__action__MarkerDocking_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__action__MarkerDocking_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__action__MarkerDocking_FeedbackMessage__Sequence__are_equal(const san_msgs__action__MarkerDocking_FeedbackMessage__Sequence * lhs, const san_msgs__action__MarkerDocking_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__action__MarkerDocking_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__action__MarkerDocking_FeedbackMessage__Sequence__copy(
  const san_msgs__action__MarkerDocking_FeedbackMessage__Sequence * input,
  san_msgs__action__MarkerDocking_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__action__MarkerDocking_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__action__MarkerDocking_FeedbackMessage * data =
      (san_msgs__action__MarkerDocking_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__action__MarkerDocking_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__action__MarkerDocking_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__action__MarkerDocking_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
