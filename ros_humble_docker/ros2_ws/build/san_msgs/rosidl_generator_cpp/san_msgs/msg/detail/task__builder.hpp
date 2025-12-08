// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from san_msgs:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__TASK__BUILDER_HPP_
#define SAN_MSGS__MSG__DETAIL__TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "san_msgs/msg/detail/task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace san_msgs
{

namespace msg
{

namespace builder
{

class Init_Task_task_cancel_completed
{
public:
  explicit Init_Task_task_cancel_completed(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  ::san_msgs::msg::Task task_cancel_completed(::san_msgs::msg::Task::_task_cancel_completed_type arg)
  {
    msg_.task_cancel_completed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_home_completed
{
public:
  explicit Init_Task_task_home_completed(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_cancel_completed task_home_completed(::san_msgs::msg::Task::_task_home_completed_type arg)
  {
    msg_.task_home_completed = std::move(arg);
    return Init_Task_task_cancel_completed(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_move_completed
{
public:
  explicit Init_Task_task_move_completed(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_home_completed task_move_completed(::san_msgs::msg::Task::_task_move_completed_type arg)
  {
    msg_.task_move_completed = std::move(arg);
    return Init_Task_task_home_completed(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_unload_completed
{
public:
  explicit Init_Task_task_unload_completed(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_move_completed task_unload_completed(::san_msgs::msg::Task::_task_unload_completed_type arg)
  {
    msg_.task_unload_completed = std::move(arg);
    return Init_Task_task_move_completed(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_load_completed
{
public:
  explicit Init_Task_task_load_completed(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_unload_completed task_load_completed(::san_msgs::msg::Task::_task_load_completed_type arg)
  {
    msg_.task_load_completed = std::move(arg);
    return Init_Task_task_unload_completed(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_cancel_started
{
public:
  explicit Init_Task_task_cancel_started(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_load_completed task_cancel_started(::san_msgs::msg::Task::_task_cancel_started_type arg)
  {
    msg_.task_cancel_started = std::move(arg);
    return Init_Task_task_load_completed(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_home_started
{
public:
  explicit Init_Task_task_home_started(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_cancel_started task_home_started(::san_msgs::msg::Task::_task_home_started_type arg)
  {
    msg_.task_home_started = std::move(arg);
    return Init_Task_task_cancel_started(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_move_started
{
public:
  explicit Init_Task_task_move_started(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_home_started task_move_started(::san_msgs::msg::Task::_task_move_started_type arg)
  {
    msg_.task_move_started = std::move(arg);
    return Init_Task_task_home_started(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_unload_started
{
public:
  explicit Init_Task_task_unload_started(::san_msgs::msg::Task & msg)
  : msg_(msg)
  {}
  Init_Task_task_move_started task_unload_started(::san_msgs::msg::Task::_task_unload_started_type arg)
  {
    msg_.task_unload_started = std::move(arg);
    return Init_Task_task_move_started(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

class Init_Task_task_load_started
{
public:
  Init_Task_task_load_started()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Task_task_unload_started task_load_started(::san_msgs::msg::Task::_task_load_started_type arg)
  {
    msg_.task_load_started = std::move(arg);
    return Init_Task_task_unload_started(msg_);
  }

private:
  ::san_msgs::msg::Task msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::san_msgs::msg::Task>()
{
  return san_msgs::msg::builder::Init_Task_task_load_started();
}

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__TASK__BUILDER_HPP_
