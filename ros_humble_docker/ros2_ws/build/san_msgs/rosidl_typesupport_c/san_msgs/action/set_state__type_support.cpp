// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from san_msgs:action/SetState.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "san_msgs/action/detail/set_state__struct.h"
#include "san_msgs/action/detail/set_state__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_Goal_type_support_ids_t;

static const _SetState_Goal_type_support_ids_t _SetState_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_Goal_type_support_symbol_names_t _SetState_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_Goal)),
  }
};

typedef struct _SetState_Goal_type_support_data_t
{
  void * data[2];
} _SetState_Goal_type_support_data_t;

static _SetState_Goal_type_support_data_t _SetState_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_Goal_message_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_SetState_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_SetState_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetState_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_Goal)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_Result_type_support_ids_t;

static const _SetState_Result_type_support_ids_t _SetState_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_Result_type_support_symbol_names_t _SetState_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_Result)),
  }
};

typedef struct _SetState_Result_type_support_data_t
{
  void * data[2];
} _SetState_Result_type_support_data_t;

static _SetState_Result_type_support_data_t _SetState_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_Result_message_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_Result_message_typesupport_ids.typesupport_identifier[0],
  &_SetState_Result_message_typesupport_symbol_names.symbol_name[0],
  &_SetState_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetState_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_Result)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_Feedback_type_support_ids_t;

static const _SetState_Feedback_type_support_ids_t _SetState_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_Feedback_type_support_symbol_names_t _SetState_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_Feedback)),
  }
};

typedef struct _SetState_Feedback_type_support_data_t
{
  void * data[2];
} _SetState_Feedback_type_support_data_t;

static _SetState_Feedback_type_support_data_t _SetState_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_Feedback_message_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_SetState_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_SetState_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetState_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_Feedback)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_SendGoal_Request_type_support_ids_t;

static const _SetState_SendGoal_Request_type_support_ids_t _SetState_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_SendGoal_Request_type_support_symbol_names_t _SetState_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_SendGoal_Request)),
  }
};

typedef struct _SetState_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _SetState_SendGoal_Request_type_support_data_t;

static _SetState_SendGoal_Request_type_support_data_t _SetState_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_SendGoal_Request_message_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetState_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetState_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetState_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_SendGoal_Request)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_SendGoal_Response_type_support_ids_t;

static const _SetState_SendGoal_Response_type_support_ids_t _SetState_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_SendGoal_Response_type_support_symbol_names_t _SetState_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_SendGoal_Response)),
  }
};

typedef struct _SetState_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _SetState_SendGoal_Response_type_support_data_t;

static _SetState_SendGoal_Response_type_support_data_t _SetState_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_SendGoal_Response_message_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetState_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetState_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetState_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_SendGoal_Response)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_SendGoal_type_support_ids_t;

static const _SetState_SendGoal_type_support_ids_t _SetState_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_SendGoal_type_support_symbol_names_t _SetState_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_SendGoal)),
  }
};

typedef struct _SetState_SendGoal_type_support_data_t
{
  void * data[2];
} _SetState_SendGoal_type_support_data_t;

static _SetState_SendGoal_type_support_data_t _SetState_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_SendGoal_service_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_SetState_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_SetState_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetState_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_SendGoal)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_GetResult_Request_type_support_ids_t;

static const _SetState_GetResult_Request_type_support_ids_t _SetState_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_GetResult_Request_type_support_symbol_names_t _SetState_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_GetResult_Request)),
  }
};

typedef struct _SetState_GetResult_Request_type_support_data_t
{
  void * data[2];
} _SetState_GetResult_Request_type_support_data_t;

static _SetState_GetResult_Request_type_support_data_t _SetState_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_GetResult_Request_message_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetState_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetState_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetState_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_GetResult_Request)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_GetResult_Response_type_support_ids_t;

static const _SetState_GetResult_Response_type_support_ids_t _SetState_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_GetResult_Response_type_support_symbol_names_t _SetState_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_GetResult_Response)),
  }
};

typedef struct _SetState_GetResult_Response_type_support_data_t
{
  void * data[2];
} _SetState_GetResult_Response_type_support_data_t;

static _SetState_GetResult_Response_type_support_data_t _SetState_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_GetResult_Response_message_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetState_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetState_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetState_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_GetResult_Response)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_GetResult_type_support_ids_t;

static const _SetState_GetResult_type_support_ids_t _SetState_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_GetResult_type_support_symbol_names_t _SetState_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_GetResult)),
  }
};

typedef struct _SetState_GetResult_type_support_data_t
{
  void * data[2];
} _SetState_GetResult_type_support_data_t;

static _SetState_GetResult_type_support_data_t _SetState_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_GetResult_service_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_SetState_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_SetState_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetState_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_GetResult)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__struct.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetState_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetState_FeedbackMessage_type_support_ids_t;

static const _SetState_FeedbackMessage_type_support_ids_t _SetState_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetState_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetState_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetState_FeedbackMessage_type_support_symbol_names_t _SetState_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, san_msgs, action, SetState_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, san_msgs, action, SetState_FeedbackMessage)),
  }
};

typedef struct _SetState_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _SetState_FeedbackMessage_type_support_data_t;

static _SetState_FeedbackMessage_type_support_data_t _SetState_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetState_FeedbackMessage_message_typesupport_map = {
  2,
  "san_msgs",
  &_SetState_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_SetState_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_SetState_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetState_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetState_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace san_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, san_msgs, action, SetState_FeedbackMessage)() {
  return &::san_msgs::action::rosidl_typesupport_c::SetState_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "san_msgs/action/set_state.h"
// already included above
// #include "san_msgs/action/detail/set_state__type_support.h"

static rosidl_action_type_support_t _san_msgs__action__SetState__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, san_msgs, action, SetState)()
{
  // Thread-safe by always writing the same values to the static struct
  _san_msgs__action__SetState__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, san_msgs, action, SetState_SendGoal)();
  _san_msgs__action__SetState__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, san_msgs, action, SetState_GetResult)();
  _san_msgs__action__SetState__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _san_msgs__action__SetState__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, san_msgs, action, SetState_FeedbackMessage)();
  _san_msgs__action__SetState__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_san_msgs__action__SetState__typesupport_c;
}

#ifdef __cplusplus
}
#endif
