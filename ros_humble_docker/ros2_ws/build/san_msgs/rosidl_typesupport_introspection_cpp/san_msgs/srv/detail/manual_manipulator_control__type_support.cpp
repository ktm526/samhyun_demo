// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from san_msgs:srv/ManualManipulatorControl.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "san_msgs/srv/detail/manual_manipulator_control__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace san_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ManualManipulatorControl_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) san_msgs::srv::ManualManipulatorControl_Request(_init);
}

void ManualManipulatorControl_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<san_msgs::srv::ManualManipulatorControl_Request *>(message_memory);
  typed_message->~ManualManipulatorControl_Request();
}

size_t size_function__ManualManipulatorControl_Request__position(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ManualManipulatorControl_Request__position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__ManualManipulatorControl_Request__position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__ManualManipulatorControl_Request__position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ManualManipulatorControl_Request__position(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ManualManipulatorControl_Request__position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ManualManipulatorControl_Request__position(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__ManualManipulatorControl_Request__position(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ManualManipulatorControl_Request_message_member_array[2] = {
  {
    "command",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs::srv::ManualManipulatorControl_Request, command),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs::srv::ManualManipulatorControl_Request, position),  // bytes offset in struct
    nullptr,  // default value
    size_function__ManualManipulatorControl_Request__position,  // size() function pointer
    get_const_function__ManualManipulatorControl_Request__position,  // get_const(index) function pointer
    get_function__ManualManipulatorControl_Request__position,  // get(index) function pointer
    fetch_function__ManualManipulatorControl_Request__position,  // fetch(index, &value) function pointer
    assign_function__ManualManipulatorControl_Request__position,  // assign(index, value) function pointer
    resize_function__ManualManipulatorControl_Request__position  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ManualManipulatorControl_Request_message_members = {
  "san_msgs::srv",  // message namespace
  "ManualManipulatorControl_Request",  // message name
  2,  // number of fields
  sizeof(san_msgs::srv::ManualManipulatorControl_Request),
  ManualManipulatorControl_Request_message_member_array,  // message members
  ManualManipulatorControl_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ManualManipulatorControl_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ManualManipulatorControl_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ManualManipulatorControl_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace san_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::srv::ManualManipulatorControl_Request>()
{
  return &::san_msgs::srv::rosidl_typesupport_introspection_cpp::ManualManipulatorControl_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, srv, ManualManipulatorControl_Request)() {
  return &::san_msgs::srv::rosidl_typesupport_introspection_cpp::ManualManipulatorControl_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "san_msgs/srv/detail/manual_manipulator_control__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace san_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ManualManipulatorControl_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) san_msgs::srv::ManualManipulatorControl_Response(_init);
}

void ManualManipulatorControl_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<san_msgs::srv::ManualManipulatorControl_Response *>(message_memory);
  typed_message->~ManualManipulatorControl_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ManualManipulatorControl_Response_message_member_array[1] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(san_msgs::srv::ManualManipulatorControl_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ManualManipulatorControl_Response_message_members = {
  "san_msgs::srv",  // message namespace
  "ManualManipulatorControl_Response",  // message name
  1,  // number of fields
  sizeof(san_msgs::srv::ManualManipulatorControl_Response),
  ManualManipulatorControl_Response_message_member_array,  // message members
  ManualManipulatorControl_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ManualManipulatorControl_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ManualManipulatorControl_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ManualManipulatorControl_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace san_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<san_msgs::srv::ManualManipulatorControl_Response>()
{
  return &::san_msgs::srv::rosidl_typesupport_introspection_cpp::ManualManipulatorControl_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, srv, ManualManipulatorControl_Response)() {
  return &::san_msgs::srv::rosidl_typesupport_introspection_cpp::ManualManipulatorControl_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "san_msgs/srv/detail/manual_manipulator_control__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace san_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ManualManipulatorControl_service_members = {
  "san_msgs::srv",  // service namespace
  "ManualManipulatorControl",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<san_msgs::srv::ManualManipulatorControl>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t ManualManipulatorControl_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ManualManipulatorControl_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace san_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<san_msgs::srv::ManualManipulatorControl>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::san_msgs::srv::rosidl_typesupport_introspection_cpp::ManualManipulatorControl_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::san_msgs::srv::ManualManipulatorControl_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::san_msgs::srv::ManualManipulatorControl_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, san_msgs, srv, ManualManipulatorControl)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<san_msgs::srv::ManualManipulatorControl>();
}

#ifdef __cplusplus
}
#endif
