// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:srv/GetWaypoints.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__STRUCT_HPP_
#define SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__san_msgs__srv__GetWaypoints_Request __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__srv__GetWaypoints_Request __declspec(deprecated)
#endif

namespace san_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetWaypoints_Request_
{
  using Type = GetWaypoints_Request_<ContainerAllocator>;

  explicit GetWaypoints_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_node = 0;
      this->goal_node = 0;
      this->node_file = "";
    }
  }

  explicit GetWaypoints_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : node_file(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start_node = 0;
      this->goal_node = 0;
      this->node_file = "";
    }
  }

  // field types and members
  using _start_node_type =
    uint16_t;
  _start_node_type start_node;
  using _goal_node_type =
    uint16_t;
  _goal_node_type goal_node;
  using _node_file_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_file_type node_file;

  // setters for named parameter idiom
  Type & set__start_node(
    const uint16_t & _arg)
  {
    this->start_node = _arg;
    return *this;
  }
  Type & set__goal_node(
    const uint16_t & _arg)
  {
    this->goal_node = _arg;
    return *this;
  }
  Type & set__node_file(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_file = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::srv::GetWaypoints_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::srv::GetWaypoints_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::srv::GetWaypoints_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::srv::GetWaypoints_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::GetWaypoints_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::GetWaypoints_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::GetWaypoints_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::GetWaypoints_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::srv::GetWaypoints_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::srv::GetWaypoints_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__srv__GetWaypoints_Request
    std::shared_ptr<san_msgs::srv::GetWaypoints_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__srv__GetWaypoints_Request
    std::shared_ptr<san_msgs::srv::GetWaypoints_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetWaypoints_Request_ & other) const
  {
    if (this->start_node != other.start_node) {
      return false;
    }
    if (this->goal_node != other.goal_node) {
      return false;
    }
    if (this->node_file != other.node_file) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetWaypoints_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetWaypoints_Request_

// alias to use template instance with default allocator
using GetWaypoints_Request =
  san_msgs::srv::GetWaypoints_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace san_msgs


// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/pose_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__srv__GetWaypoints_Response __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__srv__GetWaypoints_Response __declspec(deprecated)
#endif

namespace san_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetWaypoints_Response_
{
  using Type = GetWaypoints_Response_<ContainerAllocator>;

  explicit GetWaypoints_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : waypoints(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit GetWaypoints_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    waypoints(_alloc, _init)
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
  using _waypoints_type =
    geometry_msgs::msg::PoseArray_<ContainerAllocator>;
  _waypoints_type waypoints;
  using _node_path_type =
    std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>>;
  _node_path_type node_path;

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
  Type & set__waypoints(
    const geometry_msgs::msg::PoseArray_<ContainerAllocator> & _arg)
  {
    this->waypoints = _arg;
    return *this;
  }
  Type & set__node_path(
    const std::vector<uint16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint16_t>> & _arg)
  {
    this->node_path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::srv::GetWaypoints_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::srv::GetWaypoints_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::srv::GetWaypoints_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::srv::GetWaypoints_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::GetWaypoints_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::GetWaypoints_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::GetWaypoints_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::GetWaypoints_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::srv::GetWaypoints_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::srv::GetWaypoints_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__srv__GetWaypoints_Response
    std::shared_ptr<san_msgs::srv::GetWaypoints_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__srv__GetWaypoints_Response
    std::shared_ptr<san_msgs::srv::GetWaypoints_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetWaypoints_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->waypoints != other.waypoints) {
      return false;
    }
    if (this->node_path != other.node_path) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetWaypoints_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetWaypoints_Response_

// alias to use template instance with default allocator
using GetWaypoints_Response =
  san_msgs::srv::GetWaypoints_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace san_msgs

namespace san_msgs
{

namespace srv
{

struct GetWaypoints
{
  using Request = san_msgs::srv::GetWaypoints_Request;
  using Response = san_msgs::srv::GetWaypoints_Response;
};

}  // namespace srv

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__GET_WAYPOINTS__STRUCT_HPP_
