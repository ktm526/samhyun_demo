// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:action/MarkerDocking.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__ACTION__DETAIL__MARKER_DOCKING__STRUCT_H_
#define SAN_MSGS__ACTION__DETAIL__MARKER_DOCKING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'camera_mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/MarkerDocking in the package san_msgs.
typedef struct san_msgs__action__MarkerDocking_Goal
{
  rosidl_runtime_c__String camera_mode;
  float marker_gap;
  int32_t marker_id;
} san_msgs__action__MarkerDocking_Goal;

// Struct for a sequence of san_msgs__action__MarkerDocking_Goal.
typedef struct san_msgs__action__MarkerDocking_Goal__Sequence
{
  san_msgs__action__MarkerDocking_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__MarkerDocking_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/MarkerDocking in the package san_msgs.
typedef struct san_msgs__action__MarkerDocking_Result
{
  bool success;
} san_msgs__action__MarkerDocking_Result;

// Struct for a sequence of san_msgs__action__MarkerDocking_Result.
typedef struct san_msgs__action__MarkerDocking_Result__Sequence
{
  san_msgs__action__MarkerDocking_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__MarkerDocking_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/MarkerDocking in the package san_msgs.
typedef struct san_msgs__action__MarkerDocking_Feedback
{
  int8_t step;
} san_msgs__action__MarkerDocking_Feedback;

// Struct for a sequence of san_msgs__action__MarkerDocking_Feedback.
typedef struct san_msgs__action__MarkerDocking_Feedback__Sequence
{
  san_msgs__action__MarkerDocking_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__MarkerDocking_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "san_msgs/action/detail/marker_docking__struct.h"

/// Struct defined in action/MarkerDocking in the package san_msgs.
typedef struct san_msgs__action__MarkerDocking_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  san_msgs__action__MarkerDocking_Goal goal;
} san_msgs__action__MarkerDocking_SendGoal_Request;

// Struct for a sequence of san_msgs__action__MarkerDocking_SendGoal_Request.
typedef struct san_msgs__action__MarkerDocking_SendGoal_Request__Sequence
{
  san_msgs__action__MarkerDocking_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__MarkerDocking_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MarkerDocking in the package san_msgs.
typedef struct san_msgs__action__MarkerDocking_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} san_msgs__action__MarkerDocking_SendGoal_Response;

// Struct for a sequence of san_msgs__action__MarkerDocking_SendGoal_Response.
typedef struct san_msgs__action__MarkerDocking_SendGoal_Response__Sequence
{
  san_msgs__action__MarkerDocking_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__MarkerDocking_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MarkerDocking in the package san_msgs.
typedef struct san_msgs__action__MarkerDocking_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} san_msgs__action__MarkerDocking_GetResult_Request;

// Struct for a sequence of san_msgs__action__MarkerDocking_GetResult_Request.
typedef struct san_msgs__action__MarkerDocking_GetResult_Request__Sequence
{
  san_msgs__action__MarkerDocking_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__MarkerDocking_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "san_msgs/action/detail/marker_docking__struct.h"

/// Struct defined in action/MarkerDocking in the package san_msgs.
typedef struct san_msgs__action__MarkerDocking_GetResult_Response
{
  int8_t status;
  san_msgs__action__MarkerDocking_Result result;
} san_msgs__action__MarkerDocking_GetResult_Response;

// Struct for a sequence of san_msgs__action__MarkerDocking_GetResult_Response.
typedef struct san_msgs__action__MarkerDocking_GetResult_Response__Sequence
{
  san_msgs__action__MarkerDocking_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__MarkerDocking_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "san_msgs/action/detail/marker_docking__struct.h"

/// Struct defined in action/MarkerDocking in the package san_msgs.
typedef struct san_msgs__action__MarkerDocking_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  san_msgs__action__MarkerDocking_Feedback feedback;
} san_msgs__action__MarkerDocking_FeedbackMessage;

// Struct for a sequence of san_msgs__action__MarkerDocking_FeedbackMessage.
typedef struct san_msgs__action__MarkerDocking_FeedbackMessage__Sequence
{
  san_msgs__action__MarkerDocking_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__action__MarkerDocking_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__ACTION__DETAIL__MARKER_DOCKING__STRUCT_H_
