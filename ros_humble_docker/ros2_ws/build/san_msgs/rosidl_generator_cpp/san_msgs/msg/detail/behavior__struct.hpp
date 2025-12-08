// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:msg/Behavior.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__BEHAVIOR__STRUCT_HPP_
#define SAN_MSGS__MSG__DETAIL__BEHAVIOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__san_msgs__msg__Behavior __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__msg__Behavior __declspec(deprecated)
#endif

namespace san_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Behavior_
{
  using Type = Behavior_<ContainerAllocator>;

  explicit Behavior_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->behavior_auto_started = false;
      this->behavior_slam_started = false;
      this->behavior_charge_started = false;
      this->behavior_docking_started = false;
      this->behavior_undocking_started = false;
      this->behavior_auto_completed = false;
      this->behavior_slam_completed = false;
      this->behavior_charge_completed = false;
      this->behavior_docking_completed = false;
      this->behavior_undocking_completed = false;
      this->behavior_auto_canceled = false;
      this->behavior_docking_canceled = false;
      this->behavior_manipulation_redocking_triggered = false;
      this->behavior_charging_redocking_triggered = false;
      this->behavior_manipulator_completed = false;
      this->behavior_manipulator_emergency_triggered = false;
      this->behavior_manual_mode_triggered = false;
    }
  }

  explicit Behavior_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->behavior_auto_started = false;
      this->behavior_slam_started = false;
      this->behavior_charge_started = false;
      this->behavior_docking_started = false;
      this->behavior_undocking_started = false;
      this->behavior_auto_completed = false;
      this->behavior_slam_completed = false;
      this->behavior_charge_completed = false;
      this->behavior_docking_completed = false;
      this->behavior_undocking_completed = false;
      this->behavior_auto_canceled = false;
      this->behavior_docking_canceled = false;
      this->behavior_manipulation_redocking_triggered = false;
      this->behavior_charging_redocking_triggered = false;
      this->behavior_manipulator_completed = false;
      this->behavior_manipulator_emergency_triggered = false;
      this->behavior_manual_mode_triggered = false;
    }
  }

  // field types and members
  using _behavior_auto_started_type =
    bool;
  _behavior_auto_started_type behavior_auto_started;
  using _behavior_slam_started_type =
    bool;
  _behavior_slam_started_type behavior_slam_started;
  using _behavior_charge_started_type =
    bool;
  _behavior_charge_started_type behavior_charge_started;
  using _behavior_docking_started_type =
    bool;
  _behavior_docking_started_type behavior_docking_started;
  using _behavior_undocking_started_type =
    bool;
  _behavior_undocking_started_type behavior_undocking_started;
  using _behavior_auto_completed_type =
    bool;
  _behavior_auto_completed_type behavior_auto_completed;
  using _behavior_slam_completed_type =
    bool;
  _behavior_slam_completed_type behavior_slam_completed;
  using _behavior_charge_completed_type =
    bool;
  _behavior_charge_completed_type behavior_charge_completed;
  using _behavior_docking_completed_type =
    bool;
  _behavior_docking_completed_type behavior_docking_completed;
  using _behavior_undocking_completed_type =
    bool;
  _behavior_undocking_completed_type behavior_undocking_completed;
  using _behavior_auto_canceled_type =
    bool;
  _behavior_auto_canceled_type behavior_auto_canceled;
  using _behavior_docking_canceled_type =
    bool;
  _behavior_docking_canceled_type behavior_docking_canceled;
  using _behavior_manipulation_redocking_triggered_type =
    bool;
  _behavior_manipulation_redocking_triggered_type behavior_manipulation_redocking_triggered;
  using _behavior_charging_redocking_triggered_type =
    bool;
  _behavior_charging_redocking_triggered_type behavior_charging_redocking_triggered;
  using _behavior_manipulator_completed_type =
    bool;
  _behavior_manipulator_completed_type behavior_manipulator_completed;
  using _behavior_manipulator_emergency_triggered_type =
    bool;
  _behavior_manipulator_emergency_triggered_type behavior_manipulator_emergency_triggered;
  using _behavior_manual_mode_triggered_type =
    bool;
  _behavior_manual_mode_triggered_type behavior_manual_mode_triggered;

  // setters for named parameter idiom
  Type & set__behavior_auto_started(
    const bool & _arg)
  {
    this->behavior_auto_started = _arg;
    return *this;
  }
  Type & set__behavior_slam_started(
    const bool & _arg)
  {
    this->behavior_slam_started = _arg;
    return *this;
  }
  Type & set__behavior_charge_started(
    const bool & _arg)
  {
    this->behavior_charge_started = _arg;
    return *this;
  }
  Type & set__behavior_docking_started(
    const bool & _arg)
  {
    this->behavior_docking_started = _arg;
    return *this;
  }
  Type & set__behavior_undocking_started(
    const bool & _arg)
  {
    this->behavior_undocking_started = _arg;
    return *this;
  }
  Type & set__behavior_auto_completed(
    const bool & _arg)
  {
    this->behavior_auto_completed = _arg;
    return *this;
  }
  Type & set__behavior_slam_completed(
    const bool & _arg)
  {
    this->behavior_slam_completed = _arg;
    return *this;
  }
  Type & set__behavior_charge_completed(
    const bool & _arg)
  {
    this->behavior_charge_completed = _arg;
    return *this;
  }
  Type & set__behavior_docking_completed(
    const bool & _arg)
  {
    this->behavior_docking_completed = _arg;
    return *this;
  }
  Type & set__behavior_undocking_completed(
    const bool & _arg)
  {
    this->behavior_undocking_completed = _arg;
    return *this;
  }
  Type & set__behavior_auto_canceled(
    const bool & _arg)
  {
    this->behavior_auto_canceled = _arg;
    return *this;
  }
  Type & set__behavior_docking_canceled(
    const bool & _arg)
  {
    this->behavior_docking_canceled = _arg;
    return *this;
  }
  Type & set__behavior_manipulation_redocking_triggered(
    const bool & _arg)
  {
    this->behavior_manipulation_redocking_triggered = _arg;
    return *this;
  }
  Type & set__behavior_charging_redocking_triggered(
    const bool & _arg)
  {
    this->behavior_charging_redocking_triggered = _arg;
    return *this;
  }
  Type & set__behavior_manipulator_completed(
    const bool & _arg)
  {
    this->behavior_manipulator_completed = _arg;
    return *this;
  }
  Type & set__behavior_manipulator_emergency_triggered(
    const bool & _arg)
  {
    this->behavior_manipulator_emergency_triggered = _arg;
    return *this;
  }
  Type & set__behavior_manual_mode_triggered(
    const bool & _arg)
  {
    this->behavior_manual_mode_triggered = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::msg::Behavior_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::msg::Behavior_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::msg::Behavior_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::msg::Behavior_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::Behavior_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::Behavior_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::Behavior_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::Behavior_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::msg::Behavior_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::msg::Behavior_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__msg__Behavior
    std::shared_ptr<san_msgs::msg::Behavior_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__msg__Behavior
    std::shared_ptr<san_msgs::msg::Behavior_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Behavior_ & other) const
  {
    if (this->behavior_auto_started != other.behavior_auto_started) {
      return false;
    }
    if (this->behavior_slam_started != other.behavior_slam_started) {
      return false;
    }
    if (this->behavior_charge_started != other.behavior_charge_started) {
      return false;
    }
    if (this->behavior_docking_started != other.behavior_docking_started) {
      return false;
    }
    if (this->behavior_undocking_started != other.behavior_undocking_started) {
      return false;
    }
    if (this->behavior_auto_completed != other.behavior_auto_completed) {
      return false;
    }
    if (this->behavior_slam_completed != other.behavior_slam_completed) {
      return false;
    }
    if (this->behavior_charge_completed != other.behavior_charge_completed) {
      return false;
    }
    if (this->behavior_docking_completed != other.behavior_docking_completed) {
      return false;
    }
    if (this->behavior_undocking_completed != other.behavior_undocking_completed) {
      return false;
    }
    if (this->behavior_auto_canceled != other.behavior_auto_canceled) {
      return false;
    }
    if (this->behavior_docking_canceled != other.behavior_docking_canceled) {
      return false;
    }
    if (this->behavior_manipulation_redocking_triggered != other.behavior_manipulation_redocking_triggered) {
      return false;
    }
    if (this->behavior_charging_redocking_triggered != other.behavior_charging_redocking_triggered) {
      return false;
    }
    if (this->behavior_manipulator_completed != other.behavior_manipulator_completed) {
      return false;
    }
    if (this->behavior_manipulator_emergency_triggered != other.behavior_manipulator_emergency_triggered) {
      return false;
    }
    if (this->behavior_manual_mode_triggered != other.behavior_manual_mode_triggered) {
      return false;
    }
    return true;
  }
  bool operator!=(const Behavior_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Behavior_

// alias to use template instance with default allocator
using Behavior =
  san_msgs::msg::Behavior_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__BEHAVIOR__STRUCT_HPP_
