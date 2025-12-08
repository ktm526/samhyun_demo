// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:msg/Emergency.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__EMERGENCY__STRUCT_HPP_
#define SAN_MSGS__MSG__DETAIL__EMERGENCY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__san_msgs__msg__Emergency __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__msg__Emergency __declspec(deprecated)
#endif

namespace san_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Emergency_
{
  using Type = Emergency_<ContainerAllocator>;

  explicit Emergency_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->emergency = 0;
    }
  }

  explicit Emergency_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->emergency = 0;
    }
  }

  // field types and members
  using _emergency_type =
    uint8_t;
  _emergency_type emergency;

  // setters for named parameter idiom
  Type & set__emergency(
    const uint8_t & _arg)
  {
    this->emergency = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t PHYSICAL_LAYER =
    0u;
  static constexpr uint8_t OBSTACLE =
    1u;
  static constexpr uint8_t LOW_BATTERY =
    2u;
  static constexpr uint8_t REDOCKING =
    3u;

  // pointer types
  using RawPtr =
    san_msgs::msg::Emergency_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::msg::Emergency_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::msg::Emergency_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::msg::Emergency_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::Emergency_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::Emergency_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::Emergency_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::Emergency_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::msg::Emergency_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::msg::Emergency_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__msg__Emergency
    std::shared_ptr<san_msgs::msg::Emergency_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__msg__Emergency
    std::shared_ptr<san_msgs::msg::Emergency_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Emergency_ & other) const
  {
    if (this->emergency != other.emergency) {
      return false;
    }
    return true;
  }
  bool operator!=(const Emergency_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Emergency_

// alias to use template instance with default allocator
using Emergency =
  san_msgs::msg::Emergency_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Emergency_<ContainerAllocator>::PHYSICAL_LAYER;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Emergency_<ContainerAllocator>::OBSTACLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Emergency_<ContainerAllocator>::LOW_BATTERY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Emergency_<ContainerAllocator>::REDOCKING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__EMERGENCY__STRUCT_HPP_
