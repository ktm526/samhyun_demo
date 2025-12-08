// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:srv/SlamMode.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__SLAM_MODE__STRUCT_HPP_
#define SAN_MSGS__SRV__DETAIL__SLAM_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__san_msgs__srv__SlamMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__srv__SlamMode_Request __declspec(deprecated)
#endif

namespace san_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SlamMode_Request_
{
  using Type = SlamMode_Request_<ContainerAllocator>;

  explicit SlamMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->slam_start = false;
    }
  }

  explicit SlamMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->slam_start = false;
    }
  }

  // field types and members
  using _slam_start_type =
    bool;
  _slam_start_type slam_start;

  // setters for named parameter idiom
  Type & set__slam_start(
    const bool & _arg)
  {
    this->slam_start = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::srv::SlamMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::srv::SlamMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::srv::SlamMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::srv::SlamMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::SlamMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::SlamMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::SlamMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::SlamMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::srv::SlamMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::srv::SlamMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__srv__SlamMode_Request
    std::shared_ptr<san_msgs::srv::SlamMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__srv__SlamMode_Request
    std::shared_ptr<san_msgs::srv::SlamMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SlamMode_Request_ & other) const
  {
    if (this->slam_start != other.slam_start) {
      return false;
    }
    return true;
  }
  bool operator!=(const SlamMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SlamMode_Request_

// alias to use template instance with default allocator
using SlamMode_Request =
  san_msgs::srv::SlamMode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace san_msgs


#ifndef _WIN32
# define DEPRECATED__san_msgs__srv__SlamMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__srv__SlamMode_Response __declspec(deprecated)
#endif

namespace san_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SlamMode_Response_
{
  using Type = SlamMode_Response_<ContainerAllocator>;

  explicit SlamMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SlamMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    san_msgs::srv::SlamMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::srv::SlamMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::srv::SlamMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::srv::SlamMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::SlamMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::SlamMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::SlamMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::SlamMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::srv::SlamMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::srv::SlamMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__srv__SlamMode_Response
    std::shared_ptr<san_msgs::srv::SlamMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__srv__SlamMode_Response
    std::shared_ptr<san_msgs::srv::SlamMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SlamMode_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SlamMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SlamMode_Response_

// alias to use template instance with default allocator
using SlamMode_Response =
  san_msgs::srv::SlamMode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace san_msgs

namespace san_msgs
{

namespace srv
{

struct SlamMode
{
  using Request = san_msgs::srv::SlamMode_Request;
  using Response = san_msgs::srv::SlamMode_Response;
};

}  // namespace srv

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__SLAM_MODE__STRUCT_HPP_
