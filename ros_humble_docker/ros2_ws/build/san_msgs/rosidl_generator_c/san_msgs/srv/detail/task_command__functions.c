// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from san_msgs:srv/TaskCommand.idl
// generated code does not contain a copyright notice
#include "san_msgs/srv/detail/task_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `mission`
#include "rosidl_runtime_c/string_functions.h"
// Member `waypoint_lists`
#include "geometry_msgs/msg/detail/pose_array__functions.h"
// Member `target_goal`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
san_msgs__srv__TaskCommand_Request__init(san_msgs__srv__TaskCommand_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mission
  if (!rosidl_runtime_c__String__init(&msg->mission)) {
    san_msgs__srv__TaskCommand_Request__fini(msg);
    return false;
  }
  // start_node
  // goal_node
  // waypoint_lists
  if (!geometry_msgs__msg__PoseArray__init(&msg->waypoint_lists)) {
    san_msgs__srv__TaskCommand_Request__fini(msg);
    return false;
  }
  // target_goal
  if (!geometry_msgs__msg__PoseStamped__init(&msg->target_goal)) {
    san_msgs__srv__TaskCommand_Request__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__srv__TaskCommand_Request__fini(san_msgs__srv__TaskCommand_Request * msg)
{
  if (!msg) {
    return;
  }
  // mission
  rosidl_runtime_c__String__fini(&msg->mission);
  // start_node
  // goal_node
  // waypoint_lists
  geometry_msgs__msg__PoseArray__fini(&msg->waypoint_lists);
  // target_goal
  geometry_msgs__msg__PoseStamped__fini(&msg->target_goal);
}

bool
san_msgs__srv__TaskCommand_Request__are_equal(const san_msgs__srv__TaskCommand_Request * lhs, const san_msgs__srv__TaskCommand_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mission
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mission), &(rhs->mission)))
  {
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
  // waypoint_lists
  if (!geometry_msgs__msg__PoseArray__are_equal(
      &(lhs->waypoint_lists), &(rhs->waypoint_lists)))
  {
    return false;
  }
  // target_goal
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->target_goal), &(rhs->target_goal)))
  {
    return false;
  }
  return true;
}

bool
san_msgs__srv__TaskCommand_Request__copy(
  const san_msgs__srv__TaskCommand_Request * input,
  san_msgs__srv__TaskCommand_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mission
  if (!rosidl_runtime_c__String__copy(
      &(input->mission), &(output->mission)))
  {
    return false;
  }
  // start_node
  output->start_node = input->start_node;
  // goal_node
  output->goal_node = input->goal_node;
  // waypoint_lists
  if (!geometry_msgs__msg__PoseArray__copy(
      &(input->waypoint_lists), &(output->waypoint_lists)))
  {
    return false;
  }
  // target_goal
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->target_goal), &(output->target_goal)))
  {
    return false;
  }
  return true;
}

san_msgs__srv__TaskCommand_Request *
san_msgs__srv__TaskCommand_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__TaskCommand_Request * msg = (san_msgs__srv__TaskCommand_Request *)allocator.allocate(sizeof(san_msgs__srv__TaskCommand_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__srv__TaskCommand_Request));
  bool success = san_msgs__srv__TaskCommand_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__srv__TaskCommand_Request__destroy(san_msgs__srv__TaskCommand_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__srv__TaskCommand_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__srv__TaskCommand_Request__Sequence__init(san_msgs__srv__TaskCommand_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__TaskCommand_Request * data = NULL;

  if (size) {
    data = (san_msgs__srv__TaskCommand_Request *)allocator.zero_allocate(size, sizeof(san_msgs__srv__TaskCommand_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__srv__TaskCommand_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__srv__TaskCommand_Request__fini(&data[i - 1]);
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
san_msgs__srv__TaskCommand_Request__Sequence__fini(san_msgs__srv__TaskCommand_Request__Sequence * array)
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
      san_msgs__srv__TaskCommand_Request__fini(&array->data[i]);
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

san_msgs__srv__TaskCommand_Request__Sequence *
san_msgs__srv__TaskCommand_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__TaskCommand_Request__Sequence * array = (san_msgs__srv__TaskCommand_Request__Sequence *)allocator.allocate(sizeof(san_msgs__srv__TaskCommand_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__srv__TaskCommand_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__srv__TaskCommand_Request__Sequence__destroy(san_msgs__srv__TaskCommand_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__srv__TaskCommand_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__srv__TaskCommand_Request__Sequence__are_equal(const san_msgs__srv__TaskCommand_Request__Sequence * lhs, const san_msgs__srv__TaskCommand_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__srv__TaskCommand_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__srv__TaskCommand_Request__Sequence__copy(
  const san_msgs__srv__TaskCommand_Request__Sequence * input,
  san_msgs__srv__TaskCommand_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__srv__TaskCommand_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__srv__TaskCommand_Request * data =
      (san_msgs__srv__TaskCommand_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__srv__TaskCommand_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__srv__TaskCommand_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__srv__TaskCommand_Request__copy(
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
san_msgs__srv__TaskCommand_Response__init(san_msgs__srv__TaskCommand_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    san_msgs__srv__TaskCommand_Response__fini(msg);
    return false;
  }
  return true;
}

void
san_msgs__srv__TaskCommand_Response__fini(san_msgs__srv__TaskCommand_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
san_msgs__srv__TaskCommand_Response__are_equal(const san_msgs__srv__TaskCommand_Response * lhs, const san_msgs__srv__TaskCommand_Response * rhs)
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
san_msgs__srv__TaskCommand_Response__copy(
  const san_msgs__srv__TaskCommand_Response * input,
  san_msgs__srv__TaskCommand_Response * output)
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

san_msgs__srv__TaskCommand_Response *
san_msgs__srv__TaskCommand_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__TaskCommand_Response * msg = (san_msgs__srv__TaskCommand_Response *)allocator.allocate(sizeof(san_msgs__srv__TaskCommand_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(san_msgs__srv__TaskCommand_Response));
  bool success = san_msgs__srv__TaskCommand_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
san_msgs__srv__TaskCommand_Response__destroy(san_msgs__srv__TaskCommand_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    san_msgs__srv__TaskCommand_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
san_msgs__srv__TaskCommand_Response__Sequence__init(san_msgs__srv__TaskCommand_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__TaskCommand_Response * data = NULL;

  if (size) {
    data = (san_msgs__srv__TaskCommand_Response *)allocator.zero_allocate(size, sizeof(san_msgs__srv__TaskCommand_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = san_msgs__srv__TaskCommand_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        san_msgs__srv__TaskCommand_Response__fini(&data[i - 1]);
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
san_msgs__srv__TaskCommand_Response__Sequence__fini(san_msgs__srv__TaskCommand_Response__Sequence * array)
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
      san_msgs__srv__TaskCommand_Response__fini(&array->data[i]);
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

san_msgs__srv__TaskCommand_Response__Sequence *
san_msgs__srv__TaskCommand_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  san_msgs__srv__TaskCommand_Response__Sequence * array = (san_msgs__srv__TaskCommand_Response__Sequence *)allocator.allocate(sizeof(san_msgs__srv__TaskCommand_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = san_msgs__srv__TaskCommand_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
san_msgs__srv__TaskCommand_Response__Sequence__destroy(san_msgs__srv__TaskCommand_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    san_msgs__srv__TaskCommand_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
san_msgs__srv__TaskCommand_Response__Sequence__are_equal(const san_msgs__srv__TaskCommand_Response__Sequence * lhs, const san_msgs__srv__TaskCommand_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!san_msgs__srv__TaskCommand_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
san_msgs__srv__TaskCommand_Response__Sequence__copy(
  const san_msgs__srv__TaskCommand_Response__Sequence * input,
  san_msgs__srv__TaskCommand_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(san_msgs__srv__TaskCommand_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    san_msgs__srv__TaskCommand_Response * data =
      (san_msgs__srv__TaskCommand_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!san_msgs__srv__TaskCommand_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          san_msgs__srv__TaskCommand_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!san_msgs__srv__TaskCommand_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
