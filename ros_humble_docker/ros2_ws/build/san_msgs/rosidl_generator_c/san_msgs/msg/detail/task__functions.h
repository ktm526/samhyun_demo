// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from san_msgs:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__TASK__FUNCTIONS_H_
#define SAN_MSGS__MSG__DETAIL__TASK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "san_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "san_msgs/msg/detail/task__struct.h"

/// Initialize msg/Task message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * san_msgs__msg__Task
 * )) before or use
 * san_msgs__msg__Task__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
bool
san_msgs__msg__Task__init(san_msgs__msg__Task * msg);

/// Finalize msg/Task message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
void
san_msgs__msg__Task__fini(san_msgs__msg__Task * msg);

/// Create msg/Task message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * san_msgs__msg__Task__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
san_msgs__msg__Task *
san_msgs__msg__Task__create();

/// Destroy msg/Task message.
/**
 * It calls
 * san_msgs__msg__Task__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
void
san_msgs__msg__Task__destroy(san_msgs__msg__Task * msg);

/// Check for msg/Task message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
bool
san_msgs__msg__Task__are_equal(const san_msgs__msg__Task * lhs, const san_msgs__msg__Task * rhs);

/// Copy a msg/Task message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
bool
san_msgs__msg__Task__copy(
  const san_msgs__msg__Task * input,
  san_msgs__msg__Task * output);

/// Initialize array of msg/Task messages.
/**
 * It allocates the memory for the number of elements and calls
 * san_msgs__msg__Task__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
bool
san_msgs__msg__Task__Sequence__init(san_msgs__msg__Task__Sequence * array, size_t size);

/// Finalize array of msg/Task messages.
/**
 * It calls
 * san_msgs__msg__Task__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
void
san_msgs__msg__Task__Sequence__fini(san_msgs__msg__Task__Sequence * array);

/// Create array of msg/Task messages.
/**
 * It allocates the memory for the array and calls
 * san_msgs__msg__Task__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
san_msgs__msg__Task__Sequence *
san_msgs__msg__Task__Sequence__create(size_t size);

/// Destroy array of msg/Task messages.
/**
 * It calls
 * san_msgs__msg__Task__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
void
san_msgs__msg__Task__Sequence__destroy(san_msgs__msg__Task__Sequence * array);

/// Check for msg/Task message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
bool
san_msgs__msg__Task__Sequence__are_equal(const san_msgs__msg__Task__Sequence * lhs, const san_msgs__msg__Task__Sequence * rhs);

/// Copy an array of msg/Task messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_san_msgs
bool
san_msgs__msg__Task__Sequence__copy(
  const san_msgs__msg__Task__Sequence * input,
  san_msgs__msg__Task__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__MSG__DETAIL__TASK__FUNCTIONS_H_
