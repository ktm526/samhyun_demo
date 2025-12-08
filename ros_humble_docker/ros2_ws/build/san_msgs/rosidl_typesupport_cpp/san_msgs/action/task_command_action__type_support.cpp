// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from san_msgs:action/TaskCommandAction.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "san_msgs/action/detail/task_command_action__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_Goal_type_support_ids_t;

static const _TaskCommandAction_Goal_type_support_ids_t _TaskCommandAction_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_Goal_type_support_symbol_names_t _TaskCommandAction_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_Goal)),
  }
};

typedef struct _TaskCommandAction_Goal_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_Goal_type_support_data_t;

static _TaskCommandAction_Goal_type_support_data_t _TaskCommandAction_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_Goal_message_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskCommandAction_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::action::TaskCommandAction_Goal>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_Goal)() {
  return get_message_type_support_handle<san_msgs::action::TaskCommandAction_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_Result_type_support_ids_t;

static const _TaskCommandAction_Result_type_support_ids_t _TaskCommandAction_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_Result_type_support_symbol_names_t _TaskCommandAction_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_Result)),
  }
};

typedef struct _TaskCommandAction_Result_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_Result_type_support_data_t;

static _TaskCommandAction_Result_type_support_data_t _TaskCommandAction_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_Result_message_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_Result_message_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_Result_message_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskCommandAction_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::action::TaskCommandAction_Result>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_Result)() {
  return get_message_type_support_handle<san_msgs::action::TaskCommandAction_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_Feedback_type_support_ids_t;

static const _TaskCommandAction_Feedback_type_support_ids_t _TaskCommandAction_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_Feedback_type_support_symbol_names_t _TaskCommandAction_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_Feedback)),
  }
};

typedef struct _TaskCommandAction_Feedback_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_Feedback_type_support_data_t;

static _TaskCommandAction_Feedback_type_support_data_t _TaskCommandAction_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_Feedback_message_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskCommandAction_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::action::TaskCommandAction_Feedback>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_Feedback)() {
  return get_message_type_support_handle<san_msgs::action::TaskCommandAction_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_SendGoal_Request_type_support_ids_t;

static const _TaskCommandAction_SendGoal_Request_type_support_ids_t _TaskCommandAction_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_SendGoal_Request_type_support_symbol_names_t _TaskCommandAction_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_SendGoal_Request)),
  }
};

typedef struct _TaskCommandAction_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_SendGoal_Request_type_support_data_t;

static _TaskCommandAction_SendGoal_Request_type_support_data_t _TaskCommandAction_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_SendGoal_Request_message_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskCommandAction_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::action::TaskCommandAction_SendGoal_Request>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_SendGoal_Request)() {
  return get_message_type_support_handle<san_msgs::action::TaskCommandAction_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_SendGoal_Response_type_support_ids_t;

static const _TaskCommandAction_SendGoal_Response_type_support_ids_t _TaskCommandAction_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_SendGoal_Response_type_support_symbol_names_t _TaskCommandAction_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_SendGoal_Response)),
  }
};

typedef struct _TaskCommandAction_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_SendGoal_Response_type_support_data_t;

static _TaskCommandAction_SendGoal_Response_type_support_data_t _TaskCommandAction_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_SendGoal_Response_message_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskCommandAction_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::action::TaskCommandAction_SendGoal_Response>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_SendGoal_Response)() {
  return get_message_type_support_handle<san_msgs::action::TaskCommandAction_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_SendGoal_type_support_ids_t;

static const _TaskCommandAction_SendGoal_type_support_ids_t _TaskCommandAction_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_SendGoal_type_support_symbol_names_t _TaskCommandAction_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_SendGoal)),
  }
};

typedef struct _TaskCommandAction_SendGoal_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_SendGoal_type_support_data_t;

static _TaskCommandAction_SendGoal_type_support_data_t _TaskCommandAction_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_SendGoal_service_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TaskCommandAction_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<san_msgs::action::TaskCommandAction_SendGoal>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<san_msgs::action::TaskCommandAction_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_GetResult_Request_type_support_ids_t;

static const _TaskCommandAction_GetResult_Request_type_support_ids_t _TaskCommandAction_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_GetResult_Request_type_support_symbol_names_t _TaskCommandAction_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_GetResult_Request)),
  }
};

typedef struct _TaskCommandAction_GetResult_Request_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_GetResult_Request_type_support_data_t;

static _TaskCommandAction_GetResult_Request_type_support_data_t _TaskCommandAction_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_GetResult_Request_message_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskCommandAction_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::action::TaskCommandAction_GetResult_Request>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_GetResult_Request)() {
  return get_message_type_support_handle<san_msgs::action::TaskCommandAction_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_GetResult_Response_type_support_ids_t;

static const _TaskCommandAction_GetResult_Response_type_support_ids_t _TaskCommandAction_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_GetResult_Response_type_support_symbol_names_t _TaskCommandAction_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_GetResult_Response)),
  }
};

typedef struct _TaskCommandAction_GetResult_Response_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_GetResult_Response_type_support_data_t;

static _TaskCommandAction_GetResult_Response_type_support_data_t _TaskCommandAction_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_GetResult_Response_message_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskCommandAction_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::action::TaskCommandAction_GetResult_Response>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_GetResult_Response)() {
  return get_message_type_support_handle<san_msgs::action::TaskCommandAction_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_GetResult_type_support_ids_t;

static const _TaskCommandAction_GetResult_type_support_ids_t _TaskCommandAction_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_GetResult_type_support_symbol_names_t _TaskCommandAction_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_GetResult)),
  }
};

typedef struct _TaskCommandAction_GetResult_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_GetResult_type_support_data_t;

static _TaskCommandAction_GetResult_type_support_data_t _TaskCommandAction_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_GetResult_service_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TaskCommandAction_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<san_msgs::action::TaskCommandAction_GetResult>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<san_msgs::action::TaskCommandAction_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _TaskCommandAction_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TaskCommandAction_FeedbackMessage_type_support_ids_t;

static const _TaskCommandAction_FeedbackMessage_type_support_ids_t _TaskCommandAction_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TaskCommandAction_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TaskCommandAction_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TaskCommandAction_FeedbackMessage_type_support_symbol_names_t _TaskCommandAction_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, san_msgs, action, TaskCommandAction_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, action, TaskCommandAction_FeedbackMessage)),
  }
};

typedef struct _TaskCommandAction_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _TaskCommandAction_FeedbackMessage_type_support_data_t;

static _TaskCommandAction_FeedbackMessage_type_support_data_t _TaskCommandAction_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TaskCommandAction_FeedbackMessage_message_typesupport_map = {
  2,
  "san_msgs",
  &_TaskCommandAction_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_TaskCommandAction_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_TaskCommandAction_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TaskCommandAction_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TaskCommandAction_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::action::TaskCommandAction_FeedbackMessage>()
{
  return &::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction_FeedbackMessage)() {
  return get_message_type_support_handle<san_msgs::action::TaskCommandAction_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace san_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t TaskCommandAction_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace san_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<san_msgs::action::TaskCommandAction>()
{
  using ::san_msgs::action::rosidl_typesupport_cpp::TaskCommandAction_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  TaskCommandAction_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::san_msgs::action::TaskCommandAction::Impl::SendGoalService>();
  TaskCommandAction_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::san_msgs::action::TaskCommandAction::Impl::GetResultService>();
  TaskCommandAction_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::san_msgs::action::TaskCommandAction::Impl::CancelGoalService>();
  TaskCommandAction_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::san_msgs::action::TaskCommandAction::Impl::FeedbackMessage>();
  TaskCommandAction_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::san_msgs::action::TaskCommandAction::Impl::GoalStatusMessage>();
  return &TaskCommandAction_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, san_msgs, action, TaskCommandAction)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<san_msgs::action::TaskCommandAction>();
}

#ifdef __cplusplus
}
#endif
