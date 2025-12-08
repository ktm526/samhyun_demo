// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:action/TaskCommandAction.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__STRUCT_HPP_
#define SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__STRUCT_HPP_

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
# define DEPRECATED__san_msgs__action__TaskCommandAction_Goal __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__action__TaskCommandAction_Goal __declspec(deprecated)
#endif

namespace san_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskCommandAction_Goal_
{
  using Type = TaskCommandAction_Goal_<ContainerAllocator>;

  explicit TaskCommandAction_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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

  explicit TaskCommandAction_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_Goal
    std::shared_ptr<san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_Goal
    std::shared_ptr<san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommandAction_Goal_ & other) const
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
  bool operator!=(const TaskCommandAction_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommandAction_Goal_

// alias to use template instance with default allocator
using TaskCommandAction_Goal =
  san_msgs::action::TaskCommandAction_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace san_msgs


#ifndef _WIN32
# define DEPRECATED__san_msgs__action__TaskCommandAction_Result __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__action__TaskCommandAction_Result __declspec(deprecated)
#endif

namespace san_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskCommandAction_Result_
{
  using Type = TaskCommandAction_Result_<ContainerAllocator>;

  explicit TaskCommandAction_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit TaskCommandAction_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    san_msgs::action::TaskCommandAction_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::action::TaskCommandAction_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_Result
    std::shared_ptr<san_msgs::action::TaskCommandAction_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_Result
    std::shared_ptr<san_msgs::action::TaskCommandAction_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommandAction_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommandAction_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommandAction_Result_

// alias to use template instance with default allocator
using TaskCommandAction_Result =
  san_msgs::action::TaskCommandAction_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace san_msgs


// Include directives for member types
// Member 'current_behavior'
#include "san_msgs/msg/detail/behavior__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__action__TaskCommandAction_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__action__TaskCommandAction_Feedback __declspec(deprecated)
#endif

namespace san_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskCommandAction_Feedback_
{
  using Type = TaskCommandAction_Feedback_<ContainerAllocator>;

  explicit TaskCommandAction_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_behavior(_init)
  {
    (void)_init;
  }

  explicit TaskCommandAction_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_behavior(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _current_behavior_type =
    san_msgs::msg::Behavior_<ContainerAllocator>;
  _current_behavior_type current_behavior;

  // setters for named parameter idiom
  Type & set__current_behavior(
    const san_msgs::msg::Behavior_<ContainerAllocator> & _arg)
  {
    this->current_behavior = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_Feedback
    std::shared_ptr<san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_Feedback
    std::shared_ptr<san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommandAction_Feedback_ & other) const
  {
    if (this->current_behavior != other.current_behavior) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommandAction_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommandAction_Feedback_

// alias to use template instance with default allocator
using TaskCommandAction_Feedback =
  san_msgs::action::TaskCommandAction_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace san_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "san_msgs/action/detail/task_command_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__action__TaskCommandAction_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__action__TaskCommandAction_SendGoal_Request __declspec(deprecated)
#endif

namespace san_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskCommandAction_SendGoal_Request_
{
  using Type = TaskCommandAction_SendGoal_Request_<ContainerAllocator>;

  explicit TaskCommandAction_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit TaskCommandAction_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const san_msgs::action::TaskCommandAction_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_SendGoal_Request
    std::shared_ptr<san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_SendGoal_Request
    std::shared_ptr<san_msgs::action::TaskCommandAction_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommandAction_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommandAction_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommandAction_SendGoal_Request_

// alias to use template instance with default allocator
using TaskCommandAction_SendGoal_Request =
  san_msgs::action::TaskCommandAction_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace san_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__action__TaskCommandAction_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__action__TaskCommandAction_SendGoal_Response __declspec(deprecated)
#endif

namespace san_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskCommandAction_SendGoal_Response_
{
  using Type = TaskCommandAction_SendGoal_Response_<ContainerAllocator>;

  explicit TaskCommandAction_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit TaskCommandAction_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_SendGoal_Response
    std::shared_ptr<san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_SendGoal_Response
    std::shared_ptr<san_msgs::action::TaskCommandAction_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommandAction_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommandAction_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommandAction_SendGoal_Response_

// alias to use template instance with default allocator
using TaskCommandAction_SendGoal_Response =
  san_msgs::action::TaskCommandAction_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace san_msgs

namespace san_msgs
{

namespace action
{

struct TaskCommandAction_SendGoal
{
  using Request = san_msgs::action::TaskCommandAction_SendGoal_Request;
  using Response = san_msgs::action::TaskCommandAction_SendGoal_Response;
};

}  // namespace action

}  // namespace san_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__action__TaskCommandAction_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__action__TaskCommandAction_GetResult_Request __declspec(deprecated)
#endif

namespace san_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskCommandAction_GetResult_Request_
{
  using Type = TaskCommandAction_GetResult_Request_<ContainerAllocator>;

  explicit TaskCommandAction_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit TaskCommandAction_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_GetResult_Request
    std::shared_ptr<san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_GetResult_Request
    std::shared_ptr<san_msgs::action::TaskCommandAction_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommandAction_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommandAction_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommandAction_GetResult_Request_

// alias to use template instance with default allocator
using TaskCommandAction_GetResult_Request =
  san_msgs::action::TaskCommandAction_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace san_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__action__TaskCommandAction_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__action__TaskCommandAction_GetResult_Response __declspec(deprecated)
#endif

namespace san_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskCommandAction_GetResult_Response_
{
  using Type = TaskCommandAction_GetResult_Response_<ContainerAllocator>;

  explicit TaskCommandAction_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit TaskCommandAction_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    san_msgs::action::TaskCommandAction_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const san_msgs::action::TaskCommandAction_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_GetResult_Response
    std::shared_ptr<san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_GetResult_Response
    std::shared_ptr<san_msgs::action::TaskCommandAction_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommandAction_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommandAction_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommandAction_GetResult_Response_

// alias to use template instance with default allocator
using TaskCommandAction_GetResult_Response =
  san_msgs::action::TaskCommandAction_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace san_msgs

namespace san_msgs
{

namespace action
{

struct TaskCommandAction_GetResult
{
  using Request = san_msgs::action::TaskCommandAction_GetResult_Request;
  using Response = san_msgs::action::TaskCommandAction_GetResult_Response;
};

}  // namespace action

}  // namespace san_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "san_msgs/action/detail/task_command_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__action__TaskCommandAction_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__action__TaskCommandAction_FeedbackMessage __declspec(deprecated)
#endif

namespace san_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TaskCommandAction_FeedbackMessage_
{
  using Type = TaskCommandAction_FeedbackMessage_<ContainerAllocator>;

  explicit TaskCommandAction_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit TaskCommandAction_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const san_msgs::action::TaskCommandAction_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_FeedbackMessage
    std::shared_ptr<san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__action__TaskCommandAction_FeedbackMessage
    std::shared_ptr<san_msgs::action::TaskCommandAction_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskCommandAction_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskCommandAction_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskCommandAction_FeedbackMessage_

// alias to use template instance with default allocator
using TaskCommandAction_FeedbackMessage =
  san_msgs::action::TaskCommandAction_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace san_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace san_msgs
{

namespace action
{

struct TaskCommandAction
{
  /// The goal message defined in the action definition.
  using Goal = san_msgs::action::TaskCommandAction_Goal;
  /// The result message defined in the action definition.
  using Result = san_msgs::action::TaskCommandAction_Result;
  /// The feedback message defined in the action definition.
  using Feedback = san_msgs::action::TaskCommandAction_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = san_msgs::action::TaskCommandAction_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = san_msgs::action::TaskCommandAction_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = san_msgs::action::TaskCommandAction_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct TaskCommandAction TaskCommandAction;

}  // namespace action

}  // namespace san_msgs

#endif  // SAN_MSGS__ACTION__DETAIL__TASK_COMMAND_ACTION__STRUCT_HPP_
