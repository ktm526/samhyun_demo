// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:srv/BuildMap.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__BUILD_MAP__BUILDER_HPP_
#define SAN_MSGS__SRV__DETAIL__BUILD_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/srv/detail/build_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_BuildMap_Request_map_name
{
public:
  explicit Init_BuildMap_Request_map_name(::san_msgs::srv::BuildMap_Request & msg)
  : msg_(msg)
  {}
  ::san_msgs::srv::BuildMap_Request map_name(::san_msgs::srv::BuildMap_Request::_map_name_type arg)
  {
    msg_.map_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::BuildMap_Request msg_;
};

class Init_BuildMap_Request_command
{
public:
  Init_BuildMap_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BuildMap_Request_map_name command(::san_msgs::srv::BuildMap_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_BuildMap_Request_map_name(msg_);
  }

private:
  ::san_msgs::srv::BuildMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::BuildMap_Request>()
{
  return san_msgs::srv::builder::Init_BuildMap_Request_command();
}

}  // namespace san_msgs


namespace san_msgs
{

namespace srv
{

namespace builder
{

class Init_BuildMap_Response_message
{
public:
  explicit Init_BuildMap_Response_message(::san_msgs::srv::BuildMap_Response & msg)
  : msg_(msg)
  {}
  ::san_msgs::srv::BuildMap_Response message(::san_msgs::srv::BuildMap_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::srv::BuildMap_Response msg_;
};

class Init_BuildMap_Response_success
{
public:
  Init_BuildMap_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BuildMap_Response_message success(::san_msgs::srv::BuildMap_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_BuildMap_Response_message(msg_);
  }

private:
  ::san_msgs::srv::BuildMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::srv::BuildMap_Response>()
{
  return san_msgs::srv::builder::Init_BuildMap_Response_success();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__BUILD_MAP__BUILDER_HPP_
