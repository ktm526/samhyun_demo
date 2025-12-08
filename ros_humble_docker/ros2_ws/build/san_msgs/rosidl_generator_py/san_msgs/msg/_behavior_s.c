// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from san_msgs:msg/Behavior.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "san_msgs/msg/detail/behavior__struct.h"
#include "san_msgs/msg/detail/behavior__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool san_msgs__msg__behavior__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[32];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("san_msgs.msg._behavior.Behavior", full_classname_dest, 31) == 0);
  }
  san_msgs__msg__Behavior * ros_message = _ros_message;
  {  // behavior_auto_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_auto_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_auto_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_slam_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_slam_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_slam_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_charge_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_charge_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_charge_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_docking_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_docking_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_docking_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_undocking_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_undocking_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_undocking_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_auto_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_auto_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_auto_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_slam_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_slam_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_slam_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_charge_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_charge_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_charge_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_docking_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_docking_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_docking_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_undocking_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_undocking_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_undocking_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_auto_canceled
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_auto_canceled");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_auto_canceled = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_docking_canceled
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_docking_canceled");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_docking_canceled = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_manipulation_redocking_triggered
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_manipulation_redocking_triggered");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_manipulation_redocking_triggered = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_charging_redocking_triggered
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_charging_redocking_triggered");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_charging_redocking_triggered = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_manipulator_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_manipulator_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_manipulator_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_manipulator_emergency_triggered
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_manipulator_emergency_triggered");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_manipulator_emergency_triggered = (Py_True == field);
    Py_DECREF(field);
  }
  {  // behavior_manual_mode_triggered
    PyObject * field = PyObject_GetAttrString(_pymsg, "behavior_manual_mode_triggered");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->behavior_manual_mode_triggered = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * san_msgs__msg__behavior__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Behavior */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("san_msgs.msg._behavior");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Behavior");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  san_msgs__msg__Behavior * ros_message = (san_msgs__msg__Behavior *)raw_ros_message;
  {  // behavior_auto_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_auto_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_auto_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_slam_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_slam_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_slam_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_charge_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_charge_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_charge_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_docking_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_docking_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_docking_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_undocking_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_undocking_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_undocking_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_auto_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_auto_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_auto_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_slam_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_slam_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_slam_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_charge_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_charge_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_charge_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_docking_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_docking_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_docking_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_undocking_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_undocking_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_undocking_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_auto_canceled
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_auto_canceled ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_auto_canceled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_docking_canceled
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_docking_canceled ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_docking_canceled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_manipulation_redocking_triggered
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_manipulation_redocking_triggered ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_manipulation_redocking_triggered", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_charging_redocking_triggered
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_charging_redocking_triggered ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_charging_redocking_triggered", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_manipulator_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_manipulator_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_manipulator_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_manipulator_emergency_triggered
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_manipulator_emergency_triggered ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_manipulator_emergency_triggered", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // behavior_manual_mode_triggered
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->behavior_manual_mode_triggered ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "behavior_manual_mode_triggered", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
