// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:action/SetState.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__ACTION__DETAIL__SET_STATE__STRUCT_H_
#define SAN_MSGS__ACTION__DETAIL__SET_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/SetState in the package san_msgs.
typedef struct san_msgs__action__SetState_Goal
{
  uint8_t state;
  uint8_t status;
} san_msgs__action__SetState_Goal;

// Struct for a sequence of san_msgs__action__SetState_Goal.
typedef struct san_msgs__action__SetState_Goal__Sequence
{
  san_msgs__action__SetState_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__SetState_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/SetState in the package san_msgs.
typedef struct san_msgs__action__SetState_Result
{
  bool success;
  rosidl_runtime_c__String message;
} san_msgs__action__SetState_Result;

// Struct for a sequence of san_msgs__action__SetState_Result.
typedef struct san_msgs__action__SetState_Result__Sequence
{
  san_msgs__action__SetState_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__SetState_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/SetState in the package san_msgs.
typedef struct san_msgs__action__SetState_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} san_msgs__action__SetState_Feedback;

// Struct for a sequence of san_msgs__action__SetState_Feedback.
typedef struct san_msgs__action__SetState_Feedback__Sequence
{
  san_msgs__action__SetState_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__SetState_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "san_msgs/action/detail/set_state__struct.h"

/// Struct defined in action/SetState in the package san_msgs.
typedef struct san_msgs__action__SetState_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  san_msgs__action__SetState_Goal goal;
} san_msgs__action__SetState_SendGoal_Request;

// Struct for a sequence of san_msgs__action__SetState_SendGoal_Request.
typedef struct san_msgs__action__SetState_SendGoal_Request__Sequence
{
  san_msgs__action__SetState_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__SetState_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/SetState in the package san_msgs.
typedef struct san_msgs__action__SetState_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} san_msgs__action__SetState_SendGoal_Response;

// Struct for a sequence of san_msgs__action__SetState_SendGoal_Response.
typedef struct san_msgs__action__SetState_SendGoal_Response__Sequence
{
  san_msgs__action__SetState_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__SetState_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/SetState in the package san_msgs.
typedef struct san_msgs__action__SetState_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} san_msgs__action__SetState_GetResult_Request;

// Struct for a sequence of san_msgs__action__SetState_GetResult_Request.
typedef struct san_msgs__action__SetState_GetResult_Request__Sequence
{
  san_msgs__action__SetState_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__SetState_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"

/// Struct defined in action/SetState in the package san_msgs.
typedef struct san_msgs__action__SetState_GetResult_Response
{
  int8_t status;
  san_msgs__action__SetState_Result result;
} san_msgs__action__SetState_GetResult_Response;

// Struct for a sequence of san_msgs__action__SetState_GetResult_Response.
typedef struct san_msgs__action__SetState_GetResult_Response__Sequence
{
  san_msgs__action__SetState_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__SetState_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"

/// Struct defined in action/SetState in the package san_msgs.
typedef struct san_msgs__action__SetState_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  san_msgs__action__SetState_Feedback feedback;
} san_msgs__action__SetState_FeedbackMessage;

// Struct for a sequence of san_msgs__action__SetState_FeedbackMessage.
typedef struct san_msgs__action__SetState_FeedbackMessage__Sequence
{
  san_msgs__action__SetState_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__SetState_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__ACTION__DETAIL__SET_STATE__STRUCT_H_
