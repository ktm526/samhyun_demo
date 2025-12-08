// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from san_msgs:srv/BuildMap.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__BUILD_MAP__STRUCT_H_
#define SAN_MSGS__SRV__DETAIL__BUILD_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'BUILD_MAP_UNKNOWN'.
enum
{
  san_msgs__srv__BuildMap_Request__BUILD_MAP_UNKNOWN = 0
};

/// Constant 'BUILD_MAP_START'.
enum
{
  san_msgs__srv__BuildMap_Request__BUILD_MAP_START = 1
};

/// Constant 'BUILD_MAP_CANCEL'.
enum
{
  san_msgs__srv__BuildMap_Request__BUILD_MAP_CANCEL = 2
};

/// Constant 'BUIDL_MAP_FINISH'.
enum
{
  san_msgs__srv__BuildMap_Request__BUIDL_MAP_FINISH = 3
};

// Include directives for member types
// Member 'map_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BuildMap in the package san_msgs.
typedef struct san_msgs__srv__BuildMap_Request
{
  /// Request
  uint8_t command;
  rosidl_runtime_c__String map_name;
} san_msgs__srv__BuildMap_Request;

// Struct for a sequence of san_msgs__srv__BuildMap_Request.
typedef struct san_msgs__srv__BuildMap_Request__Sequence
{
  san_msgs__srv__BuildMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__srv__BuildMap_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BuildMap in the package san_msgs.
typedef struct san_msgs__srv__BuildMap_Response
{
  bool success;
  rosidl_runtime_c__String message;
} san_msgs__srv__BuildMap_Response;

// Struct for a sequence of san_msgs__srv__BuildMap_Response.
typedef struct san_msgs__srv__BuildMap_Response__Sequence
{
  san_msgs__srv__BuildMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} san_msgs__srv__BuildMap_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SAN_MSGS__SRV__DETAIL__BUILD_MAP__STRUCT_H_
