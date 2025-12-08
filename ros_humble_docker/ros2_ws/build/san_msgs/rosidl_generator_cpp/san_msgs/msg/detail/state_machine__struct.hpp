// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:msg/StateMachine.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_
#define SAN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__san_msgs__msg__StateMachine __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__msg__StateMachine __declspec(deprecated)
#endif

namespace san_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StateMachine_
{
  using Type = StateMachine_<ContainerAllocator>;

  explicit StateMachine_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->status = 0;
    }
  }

  explicit StateMachine_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->status = 0;
    }
  }

  // field types and members
  using _state_type =
    uint8_t;
  _state_type state;
  using _status_type =
    uint8_t;
  _status_type status;

  // setters for named parameter idiom
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t INIT =
    0u;
  static constexpr uint8_t IDLE =
    16u;
  static constexpr uint8_t AUTO =
    32u;
  static constexpr uint8_t MANUAL =
    48u;
  static constexpr uint8_t DOCKING =
    64u;
  static constexpr uint8_t UNDOCKING =
    80u;
  static constexpr uint8_t CHARGING =
    96u;
  static constexpr uint8_t MANIPULATION =
    112u;
  static constexpr uint8_t EMERGENCY =
    128u;
  static constexpr uint8_t STOP =
    144u;
  static constexpr uint8_t RUNNING =
    0u;
  static constexpr uint8_t SUCCESS =
    1u;
  static constexpr uint8_t FAIL =
    2u;

  // pointer types
  using RawPtr =
    san_msgs::msg::StateMachine_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::msg::StateMachine_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::msg::StateMachine_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::msg::StateMachine_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::StateMachine_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::StateMachine_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::StateMachine_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::StateMachine_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::msg::StateMachine_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::msg::StateMachine_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__msg__StateMachine
    std::shared_ptr<san_msgs::msg::StateMachine_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__msg__StateMachine
    std::shared_ptr<san_msgs::msg::StateMachine_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateMachine_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateMachine_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateMachine_

// alias to use template instance with default allocator
using StateMachine =
  san_msgs::msg::StateMachine_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::INIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::AUTO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::MANUAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::DOCKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::UNDOCKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::CHARGING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::MANIPULATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::EMERGENCY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::RUNNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::SUCCESS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t StateMachine_<ContainerAllocator>::FAIL;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__STATE_MACHINE__STRUCT_HPP_
