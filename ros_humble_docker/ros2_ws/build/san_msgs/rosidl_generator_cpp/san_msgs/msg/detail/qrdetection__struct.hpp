// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from san_msgs:msg/Qrdetection.idl
// generated code does not contain a copyright notice

#ifndef SAN_MSGS__MSG__DETAIL__QRDETECTION__STRUCT_HPP_
#define SAN_MSGS__MSG__DETAIL__QRDETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'translation'
// Member 'rotation'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__san_msgs__msg__Qrdetection __attribute__((deprecated))
#else
# define DEPRECATED__san_msgs__msg__Qrdetection __declspec(deprecated)
#endif

namespace san_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Qrdetection_
{
  using Type = Qrdetection_<ContainerAllocator>;

  explicit Qrdetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : translation(_init),
    rotation(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cam_num = 0l;
      this->id = 0l;
    }
  }

  explicit Qrdetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : translation(_alloc, _init),
    rotation(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cam_num = 0l;
      this->id = 0l;
    }
  }

  // field types and members
  using _cam_num_type =
    int32_t;
  _cam_num_type cam_num;
  using _id_type =
    int32_t;
  _id_type id;
  using _translation_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _translation_type translation;
  using _rotation_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _rotation_type rotation;

  // setters for named parameter idiom
  Type & set__cam_num(
    const int32_t & _arg)
  {
    this->cam_num = _arg;
    return *this;
  }
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__translation(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->translation = _arg;
    return *this;
  }
  Type & set__rotation(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->rotation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    san_msgs::msg::Qrdetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const san_msgs::msg::Qrdetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<san_msgs::msg::Qrdetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<san_msgs::msg::Qrdetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::Qrdetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::Qrdetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      san_msgs::msg::Qrdetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<san_msgs::msg::Qrdetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<san_msgs::msg::Qrdetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<san_msgs::msg::Qrdetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__san_msgs__msg__Qrdetection
    std::shared_ptr<san_msgs::msg::Qrdetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__san_msgs__msg__Qrdetection
    std::shared_ptr<san_msgs::msg::Qrdetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Qrdetection_ & other) const
  {
    if (this->cam_num != other.cam_num) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->translation != other.translation) {
      return false;
    }
    if (this->rotation != other.rotation) {
      return false;
    }
    return true;
  }
  bool operator!=(const Qrdetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Qrdetection_

// alias to use template instance with default allocator
using Qrdetection =
  san_msgs::msg::Qrdetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace san_msgs

#endif  // SAN_MSGS__MSG__DETAIL__QRDETECTION__STRUCT_HPP_
