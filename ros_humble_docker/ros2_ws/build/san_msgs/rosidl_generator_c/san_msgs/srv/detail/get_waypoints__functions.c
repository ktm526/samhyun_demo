// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:srv/GetWaypoints.idl
// generated code does not contain a copyright notice
#include "san_msgs/srv/detail/get_waypoints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `node_file`
#include "rosidl_runtime_c/string_functions.h"

bool
san_msgs__srv__GetWaypoints_Request__init(san_msgs__srv__GetWaypoints_Request * msg)
{
  if (!msg) {
    return false;
  }
  // start_node
  // goal_node
  // node_file
  if (!rosidl_runtime_c__String__init(&msg->node_file)) {
    san_msgs__srv__GetWaypoints_Request__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__srv__GetWaypoints_Request__fini(san_msgs__srv__GetWaypoints_Request * msg)
{
  if (!msg) {
    return;
  }
  // start_node
  // goal_node
  // node_file
  rosidl_runtime_c__String__fini(&msg->node_file);
}

bool
san_msgs__srv__GetWaypoints_Request__are_equal(const san_msgs__srv__GetWaypoints_Request * lhs, const san_msgs__srv__GetWaypoints_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start_node
  if (lhs->start_node != rhs->start_node) {
    return false;
  }
  // goal_node
  if (lhs->goal_node != rhs->goal_node) {
    return false;
  }
  // node_file
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_file), &(rhs->node_file)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__srv__GetWaypoints_Request__copy(
  const san_msgs__srv__GetWaypoints_Request * input,
  san_msgs__srv__GetWaypoints_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // start_node
  output->start_node = input->start_node;
  // goal_node
  output->goal_node = input->goal_node;
  // node_file
  if (!rosidl_runtime_c__String__copy(
      &(input->node_file), &(output->node_file)))
  {
    return false;
  }
  return true;
}

san_msgs__srv__GetWaypoints_Request *
san_msgs__srv__GetWaypoints_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__GetWaypoints_Request * msg = (san_msgs__srv__GetWaypoints_Request *)allocator.allocate(sizeof(san_msgs__srv__GetWaypoints_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__srv__GetWaypoints_Request));
  bool success = san_msgs__srv__GetWaypoints_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__srv__GetWaypoints_Request__destroy(san_msgs__srv__GetWaypoints_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__srv__GetWaypoints_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__srv__GetWaypoints_Request__Sequence__init(san_msgs__srv__GetWaypoints_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__GetWaypoints_Request * data = NULL;

  if (size) {
    data = (san_msgs__srv__GetWaypoints_Request *)allocator.zero_allocate(size, sizeof(san_msgs__srv__GetWaypoints_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__srv__GetWaypoints_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__srv__GetWaypoints_Request__fini(&data[i - 1]);
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
san_msgs__srv__GetWaypoints_Request__Sequence__fini(san_msgs__srv__GetWaypoints_Request__Sequence * array)
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
      san_msgs__srv__GetWaypoints_Request__fini(&array->data[i]);
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

san_msgs__srv__GetWaypoints_Request__Sequence *
san_msgs__srv__GetWaypoints_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__GetWaypoints_Request__Sequence * array = (san_msgs__srv__GetWaypoints_Request__Sequence *)allocator.allocate(sizeof(san_msgs__srv__GetWaypoints_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__srv__GetWaypoints_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__srv__GetWaypoints_Request__Sequence__destroy(san_msgs__srv__GetWaypoints_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__srv__GetWaypoints_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__srv__GetWaypoints_Request__Sequence__are_equal(const san_msgs__srv__GetWaypoints_Request__Sequence * lhs, const san_msgs__srv__GetWaypoints_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__srv__GetWaypoints_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__srv__GetWaypoints_Request__Sequence__copy(
  const san_msgs__srv__GetWaypoints_Request__Sequence * input,
  san_msgs__srv__GetWaypoints_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__srv__GetWaypoints_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__srv__GetWaypoints_Request * data =
      (san_msgs__srv__GetWaypoints_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__srv__GetWaypoints_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__srv__GetWaypoints_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__srv__GetWaypoints_Request__copy(
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
// Member `waypoints`
#include "geometry_msgs/msg/detail/pose_array__functions.h"
// Member `node_path`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
san_msgs__srv__GetWaypoints_Response__init(san_msgs__srv__GetWaypoints_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    san_msgs__srv__GetWaypoints_Response__fini(msg);
    return false;
  }
  // waypoints
  if (!geometry_msgs__msg__PoseArray__init(&msg->waypoints)) {
    san_msgs__srv__GetWaypoints_Response__fini(msg);
    return false;
  }
  // node_path
  if (!rosidl_runtime_c__uint16__Sequence__init(&msg->node_path, 0)) {
    san_msgs__srv__GetWaypoints_Response__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__srv__GetWaypoints_Response__fini(san_msgs__srv__GetWaypoints_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // waypoints
  geometry_msgs__msg__PoseArray__fini(&msg->waypoints);
  // node_path
  rosidl_runtime_c__uint16__Sequence__fini(&msg->node_path);
}

bool
san_msgs__srv__GetWaypoints_Response__are_equal(const san_msgs__srv__GetWaypoints_Response * lhs, const san_msgs__srv__GetWaypoints_Response * rhs)
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
  // waypoints
  if (!geometry_msgs__msg__PoseArray__are_equal(
      &(lhs->waypoints), &(rhs->waypoints)))
  {
    return false;
  }
  // node_path
  if (!rosidl_runtime_c__uint16__Sequence__are_equal(
      &(lhs->node_path), &(rhs->node_path)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__srv__GetWaypoints_Response__copy(
  const san_msgs__srv__GetWaypoints_Response * input,
  san_msgs__srv__GetWaypoints_Response * output)
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
  // waypoints
  if (!geometry_msgs__msg__PoseArray__copy(
      &(input->waypoints), &(output->waypoints)))
  {
    return false;
  }
  // node_path
  if (!rosidl_runtime_c__uint16__Sequence__copy(
      &(input->node_path), &(output->node_path)))
  {
    return false;
  }
  return true;
}

san_msgs__srv__GetWaypoints_Response *
san_msgs__srv__GetWaypoints_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__GetWaypoints_Response * msg = (san_msgs__srv__GetWaypoints_Response *)allocator.allocate(sizeof(san_msgs__srv__GetWaypoints_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__srv__GetWaypoints_Response));
  bool success = san_msgs__srv__GetWaypoints_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__srv__GetWaypoints_Response__destroy(san_msgs__srv__GetWaypoints_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__srv__GetWaypoints_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__srv__GetWaypoints_Response__Sequence__init(san_msgs__srv__GetWaypoints_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__GetWaypoints_Response * data = NULL;

  if (size) {
    data = (san_msgs__srv__GetWaypoints_Response *)allocator.zero_allocate(size, sizeof(san_msgs__srv__GetWaypoints_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__srv__GetWaypoints_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__srv__GetWaypoints_Response__fini(&data[i - 1]);
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
san_msgs__srv__GetWaypoints_Response__Sequence__fini(san_msgs__srv__GetWaypoints_Response__Sequence * array)
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
      san_msgs__srv__GetWaypoints_Response__fini(&array->data[i]);
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

san_msgs__srv__GetWaypoints_Response__Sequence *
san_msgs__srv__GetWaypoints_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__GetWaypoints_Response__Sequence * array = (san_msgs__srv__GetWaypoints_Response__Sequence *)allocator.allocate(sizeof(san_msgs__srv__GetWaypoints_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__srv__GetWaypoints_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__srv__GetWaypoints_Response__Sequence__destroy(san_msgs__srv__GetWaypoints_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__srv__GetWaypoints_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__srv__GetWaypoints_Response__Sequence__are_equal(const san_msgs__srv__GetWaypoints_Response__Sequence * lhs, const san_msgs__srv__GetWaypoints_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__srv__GetWaypoints_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__srv__GetWaypoints_Response__Sequence__copy(
  const san_msgs__srv__GetWaypoints_Response__Sequence * input,
  san_msgs__srv__GetWaypoints_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__srv__GetWaypoints_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__srv__GetWaypoints_Response * data =
      (san_msgs__srv__GetWaypoints_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__srv__GetWaypoints_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__srv__GetWaypoints_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__srv__GetWaypoints_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
