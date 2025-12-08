// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__TASK__STRUCT_HPP_
#define SAN_MSGS__MSG__DETAIL__TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__san_msgs__msg__Task __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__msg__Task __declspec(deprecated)
#endif

namespace san_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Task_
{
  using Type = Task_<ContainerAllocator>;

  explicit Task_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_load_started = false;
      this->task_unload_started = false;
      this->task_move_started = false;
      this->task_home_started = false;
      this->task_cancel_started = false;
      this->task_load_completed = false;
      this->task_unload_completed = false;
      this->task_move_completed = false;
      this->task_home_completed = false;
      this->task_cancel_completed = false;
    }
  }

  explicit Task_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_load_started = false;
      this->task_unload_started = false;
      this->task_move_started = false;
      this->task_home_started = false;
      this->task_cancel_started = false;
      this->task_load_completed = false;
      this->task_unload_completed = false;
      this->task_move_completed = false;
      this->task_home_completed = false;
      this->task_cancel_completed = false;
    }
  }

  // field types and members
  using _task_load_started_type =
    bool;
  _task_load_started_type task_load_started;
  using _task_unload_started_type =
    bool;
  _task_unload_started_type task_unload_started;
  using _task_move_started_type =
    bool;
  _task_move_started_type task_move_started;
  using _task_home_started_type =
    bool;
  _task_home_started_type task_home_started;
  using _task_cancel_started_type =
    bool;
  _task_cancel_started_type task_cancel_started;
  using _task_load_completed_type =
    bool;
  _task_load_completed_type task_load_completed;
  using _task_unload_completed_type =
    bool;
  _task_unload_completed_type task_unload_completed;
  using _task_move_completed_type =
    bool;
  _task_move_completed_type task_move_completed;
  using _task_home_completed_type =
    bool;
  _task_home_completed_type task_home_completed;
  using _task_cancel_completed_type =
    bool;
  _task_cancel_completed_type task_cancel_completed;

  // setters for named parameter idiom
  Type & set__task_load_started(
    const bool & _arg)
  {
    this->task_load_started = _arg;
    return *this;
  }
  Type & set__task_unload_started(
    const bool & _arg)
  {
    this->task_unload_started = _arg;
    return *this;
  }
  Type & set__task_move_started(
    const bool & _arg)
  {
    this->task_move_started = _arg;
    return *this;
  }
  Type & set__task_home_started(
    const bool & _arg)
  {
    this->task_home_started = _arg;
    return *this;
  }
  Type & set__task_cancel_started(
    const bool & _arg)
  {
    this->task_cancel_started = _arg;
    return *this;
  }
  Type & set__task_load_completed(
    const bool & _arg)
  {
    this->task_load_completed = _arg;
    return *this;
  }
  Type & set__task_unload_completed(
    const bool & _arg)
  {
    this->task_unload_completed = _arg;
    return *this;
  }
  Type & set__task_move_completed(
    const bool & _arg)
  {
    this->task_move_completed = _arg;
    return *this;
  }
  Type & set__task_home_completed(
    const bool & _arg)
  {
    this->task_home_completed = _arg;
    return *this;
  }
  Type & set__task_cancel_completed(
    const bool & _arg)
  {
    this->task_cancel_completed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::msg::Task_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::msg::Task_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::msg::Task_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::msg::Task_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::Task_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::Task_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::Task_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::Task_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::msg::Task_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::msg::Task_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__msg__Task
    std::shared_ptr<san_msgs::msg::Task_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__msg__Task
    std::shared_ptr<san_msgs::msg::Task_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Task_ & other) const
  {
    if (this->task_load_started != other.task_load_started) {
      return false;
    }
    if (this->task_unload_started != other.task_unload_started) {
      return false;
    }
    if (this->task_move_started != other.task_move_started) {
      return false;
    }
    if (this->task_home_started != other.task_home_started) {
      return false;
    }
    if (this->task_cancel_started != other.task_cancel_started) {
      return false;
    }
    if (this->task_load_completed != other.task_load_completed) {
      return false;
    }
    if (this->task_unload_completed != other.task_unload_completed) {
      return false;
    }
    if (this->task_move_completed != other.task_move_completed) {
      return false;
    }
    if (this->task_home_completed != other.task_home_completed) {
      return false;
    }
    if (this->task_cancel_completed != other.task_cancel_completed) {
      return false;
    }
    return true;
  }
  bool operator!=(const Task_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Task_

// alias to use template instance with default allocator
using Task =
  san_msgs::msg::Task_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__TASK__STRUCT_HPP_
