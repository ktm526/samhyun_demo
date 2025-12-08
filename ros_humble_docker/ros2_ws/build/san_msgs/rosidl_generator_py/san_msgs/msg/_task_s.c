// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from san_msgs:msg/Task.idl
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
#include "san_msgs/msg/detail/task__struct.h"
#include "san_msgs/msg/detail/task__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool san_msgs__msg__task__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[24];
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
    assert(strncmp("san_msgs.msg._task.Task", full_classname_dest, 23) == 0);
  }
  san_msgs__msg__Task * ros_message = _ros_message;
  {  // task_load_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_load_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_load_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_unload_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_unload_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_unload_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_move_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_move_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_move_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_home_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_home_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_home_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_cancel_started
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_cancel_started");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_cancel_started = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_load_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_load_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_load_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_unload_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_unload_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_unload_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_move_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_move_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_move_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_home_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_home_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_home_completed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // task_cancel_completed
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_cancel_completed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->task_cancel_completed = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * san_msgs__msg__task__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Task */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("san_msgs.msg._task");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Task");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  san_msgs__msg__Task * ros_message = (san_msgs__msg__Task *)raw_ros_message;
  {  // task_load_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_load_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_load_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_unload_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_unload_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_unload_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_move_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_move_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_move_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_home_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_home_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_home_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_cancel_started
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_cancel_started ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_cancel_started", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_load_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_load_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_load_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_unload_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_unload_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_unload_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_move_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_move_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_move_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_home_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_home_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_home_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_cancel_completed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->task_cancel_completed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_cancel_completed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
