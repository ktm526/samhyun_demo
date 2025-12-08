// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:msg/BatteryStatus.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_
#define SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__san_msgs__msg__BatteryStatus __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__msg__BatteryStatus __declspec(deprecated)
#endif

namespace san_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BatteryStatus_
{
  using Type = BatteryStatus_<ContainerAllocator>;

  explicit BatteryStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->voltage_top = 0.0f;
      this->current_top = 0.0f;
      this->soc_top = 0.0f;
      this->soh_top = 0.0f;
      this->voltage = 0.0f;
      this->current = 0.0f;
      this->soc = 0.0f;
      this->soh = 0.0f;
      this->charge_relay = false;
      this->charging_jack_state = false;
      this->charging_state = false;
    }
  }

  explicit BatteryStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->voltage_top = 0.0f;
      this->current_top = 0.0f;
      this->soc_top = 0.0f;
      this->soh_top = 0.0f;
      this->voltage = 0.0f;
      this->current = 0.0f;
      this->soc = 0.0f;
      this->soh = 0.0f;
      this->charge_relay = false;
      this->charging_jack_state = false;
      this->charging_state = false;
    }
  }

  // field types and members
  using _voltage_top_type =
    float;
  _voltage_top_type voltage_top;
  using _current_top_type =
    float;
  _current_top_type current_top;
  using _soc_top_type =
    float;
  _soc_top_type soc_top;
  using _soh_top_type =
    float;
  _soh_top_type soh_top;
  using _voltage_type =
    float;
  _voltage_type voltage;
  using _current_type =
    float;
  _current_type current;
  using _soc_type =
    float;
  _soc_type soc;
  using _soh_type =
    float;
  _soh_type soh;
  using _charge_relay_type =
    bool;
  _charge_relay_type charge_relay;
  using _charging_jack_state_type =
    bool;
  _charging_jack_state_type charging_jack_state;
  using _charging_state_type =
    bool;
  _charging_state_type charging_state;

  // setters for named parameter idiom
  Type & set__voltage_top(
    const float & _arg)
  {
    this->voltage_top = _arg;
    return *this;
  }
  Type & set__current_top(
    const float & _arg)
  {
    this->current_top = _arg;
    return *this;
  }
  Type & set__soc_top(
    const float & _arg)
  {
    this->soc_top = _arg;
    return *this;
  }
  Type & set__soh_top(
    const float & _arg)
  {
    this->soh_top = _arg;
    return *this;
  }
  Type & set__voltage(
    const float & _arg)
  {
    this->voltage = _arg;
    return *this;
  }
  Type & set__current(
    const float & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__soc(
    const float & _arg)
  {
    this->soc = _arg;
    return *this;
  }
  Type & set__soh(
    const float & _arg)
  {
    this->soh = _arg;
    return *this;
  }
  Type & set__charge_relay(
    const bool & _arg)
  {
    this->charge_relay = _arg;
    return *this;
  }
  Type & set__charging_jack_state(
    const bool & _arg)
  {
    this->charging_jack_state = _arg;
    return *this;
  }
  Type & set__charging_state(
    const bool & _arg)
  {
    this->charging_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::msg::BatteryStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::msg::BatteryStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::msg::BatteryStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::msg::BatteryStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::BatteryStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::BatteryStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::BatteryStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::BatteryStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::msg::BatteryStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::msg::BatteryStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__msg__BatteryStatus
    std::shared_ptr<san_msgs::msg::BatteryStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__msg__BatteryStatus
    std::shared_ptr<san_msgs::msg::BatteryStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BatteryStatus_ & other) const
  {
    if (this->voltage_top != other.voltage_top) {
      return false;
    }
    if (this->current_top != other.current_top) {
      return false;
    }
    if (this->soc_top != other.soc_top) {
      return false;
    }
    if (this->soh_top != other.soh_top) {
      return false;
    }
    if (this->voltage != other.voltage) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->soc != other.soc) {
      return false;
    }
    if (this->soh != other.soh) {
      return false;
    }
    if (this->charge_relay != other.charge_relay) {
      return false;
    }
    if (this->charging_jack_state != other.charging_jack_state) {
      return false;
    }
    if (this->charging_state != other.charging_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const BatteryStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BatteryStatus_

// alias to use template instance with default allocator
using BatteryStatus =
  san_msgs::msg::BatteryStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__BATTERY_STATUS__STRUCT_HPP_
