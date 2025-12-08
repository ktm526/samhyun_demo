// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:srv/TaskCommand.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__SRV__DETAIL__TASK_COMMAND__STRUCT_HPP_
#define SAN_MSGS__SRV__DETAIL__TASK_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'waypoint_lists'
#include "geometry_msgs/msg/detail/pose_array__struct.hpp"
// Member 'target_goal'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__srv__TaskCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__srv__TaskCommand_Request __declspec(deprecated)
#endif

namespace san_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskCommand_Request_
{
  using Type = TaskCommand_Request_<ContainerAllocator>;

  explicit TaskCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : waypoint_lists(_init),
    target_goal(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mission = "";
      this->start_node = 0;
      this->goal_node = 0;
    }
  }

  explicit TaskCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mission(_alloc),
    waypoint_lists(_alloc, _init),
    target_goal(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mission = "";
      this->start_node = 0;
      this->goal_node = 0;
    }
  }

  // field types and members
  using _mission_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mission_type mission;
  using _start_node_type =
    uint16_t;
  _start_node_type start_node;
  using _goal_node_type =
    uint16_t;
  _goal_node_type goal_node;
  using _waypoint_lists_type =
    geometry_msgs::msg::PoseArray_<ContainerAllocator>;
  _waypoint_lists_type waypoint_lists;
  using _target_goal_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _target_goal_type target_goal;

  // setters for named parameter idiom
  Type & set__mission(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mission = _arg;
    return *this;
  }
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
  Type & set__waypoint_lists(
    const geometry_msgs::msg::PoseArray_<ContainerAllocator> & _arg)
  {
    this->waypoint_lists = _arg;
    return *this;
  }
  Type & set__target_goal(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->target_goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::srv::TaskCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::srv::TaskCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::srv::TaskCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::srv::TaskCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::TaskCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::TaskCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::TaskCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::TaskCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::srv::TaskCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::srv::TaskCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__srv__TaskCommand_Request
    std::shared_ptr<san_msgs::srv::TaskCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__srv__TaskCommand_Request
    std::shared_ptr<san_msgs::srv::TaskCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommand_Request_ & other) const
  {
    if (this->mission != other.mission) {
      return false;
    }
    if (this->start_node != other.start_node) {
      return false;
    }
    if (this->goal_node != other.goal_node) {
      return false;
    }
    if (this->waypoint_lists != other.waypoint_lists) {
      return false;
    }
    if (this->target_goal != other.target_goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommand_Request_

// alias to use template instance with default allocator
using TaskCommand_Request =
  san_msgs::srv::TaskCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace san_msgs


#ifndef _WIN32
# define DEPRECATED__san_msgs__srv__TaskCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__srv__TaskCommand_Response __declspec(deprecated)
#endif

namespace san_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskCommand_Response_
{
  using Type = TaskCommand_Response_<ContainerAllocator>;

  explicit TaskCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit TaskCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    san_msgs::srv::TaskCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::srv::TaskCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::srv::TaskCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::srv::TaskCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::TaskCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::TaskCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::srv::TaskCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::srv::TaskCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::srv::TaskCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::srv::TaskCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__srv__TaskCommand_Response
    std::shared_ptr<san_msgs::srv::TaskCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__srv__TaskCommand_Response
    std::shared_ptr<san_msgs::srv::TaskCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommand_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommand_Response_

// alias to use template instance with default allocator
using TaskCommand_Response =
  san_msgs::srv::TaskCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace san_msgs

namespace san_msgs
{

namespace srv
{

struct TaskCommand
{
  using Request = san_msgs::srv::TaskCommand_Request;
  using Response = san_msgs::srv::TaskCommand_Response;
};

}  // namespace srv

}  // namespace san_msgs

#endif  // SAN_MSGS__SRV__DETAIL__TASK_COMMAND__STRUCT_HPP_
