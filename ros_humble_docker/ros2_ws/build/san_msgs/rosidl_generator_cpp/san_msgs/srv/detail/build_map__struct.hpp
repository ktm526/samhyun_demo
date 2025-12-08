// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:srv/BuildMap.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__BUILD_MAP__STRUCT_HPP_
#define SAN_MSGS__SRV__DETAIL__BUILD_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__san_msgs__srv__BuildMap_Request __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__srv__BuildMap_Request __declspec(deprecated)
#endif

namespace san_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BuildMap_Request_
{
  using Type = BuildMap_Request_<ContainerAllocator>;

  explicit BuildMap_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->map_name = "";
    }
  }

  explicit BuildMap_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : map_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->map_name = "";
    }
  }

  // field types and members
  using _command_type =
    uint8_t;
  _command_type command;
  using _map_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _map_name_type map_name;

  // setters for named parameter idiom
  Type & set__command(
    const uint8_t & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__map_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->map_name = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t BUILD_MAP_UNKNOWN =
    0u;
  static constexpr uint8_t BUILD_MAP_START =
    1u;
  static constexpr uint8_t BUILD_MAP_CANCEL =
    2u;
  static constexpr uint8_t BUIDL_MAP_FINISH =
    3u;

  // pointer types
  using RawPtr =
    san_msgs::srv::BuildMap_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::srv::BuildMap_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::srv::BuildMap_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::srv::BuildMap_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::BuildMap_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::BuildMap_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::BuildMap_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::BuildMap_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::srv::BuildMap_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::srv::BuildMap_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__srv__BuildMap_Request
    std::shared_ptr<san_msgs::srv::BuildMap_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__srv__BuildMap_Request
    std::shared_ptr<san_msgs::srv::BuildMap_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BuildMap_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->map_name != other.map_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const BuildMap_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BuildMap_Request_

// alias to use template instance with default allocator
using BuildMap_Request =
  san_msgs::srv::BuildMap_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BuildMap_Request_<ContainerAllocator>::BUILD_MAP_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BuildMap_Request_<ContainerAllocator>::BUILD_MAP_START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BuildMap_Request_<ContainerAllocator>::BUILD_MAP_CANCEL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BuildMap_Request_<ContainerAllocator>::BUIDL_MAP_FINISH;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace san_msgs


#ifndef _WIN32
# define DEPRECATED__san_msgs__srv__BuildMap_Response __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__srv__BuildMap_Response __declspec(deprecated)
#endif

namespace san_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BuildMap_Response_
{
  using Type = BuildMap_Response_<ContainerAllocator>;

  explicit BuildMap_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit BuildMap_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::srv::BuildMap_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::srv::BuildMap_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::srv::BuildMap_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::srv::BuildMap_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::BuildMap_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::BuildMap_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::BuildMap_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::BuildMap_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::srv::BuildMap_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::srv::BuildMap_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__srv__BuildMap_Response
    std::shared_ptr<san_msgs::srv::BuildMap_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__srv__BuildMap_Response
    std::shared_ptr<san_msgs::srv::BuildMap_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BuildMap_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const BuildMap_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BuildMap_Response_

// alias to use template instance with default allocator
using BuildMap_Response =
  san_msgs::srv::BuildMap_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace san_msgs

namespace san_msgs
{

namespace srv
{

struct BuildMap
{
  using Request = san_msgs::srv::BuildMap_Request;
  using Response = san_msgs::srv::BuildMap_Response;
};

}  // namespace srv

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__BUILD_MAP__STRUCT_HPP_
