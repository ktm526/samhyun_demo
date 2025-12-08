// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from san_msgs:msg/BatteryStatus.idl
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
#include "san_msgs/msg/detail/battery_status__struct.h"
#include "san_msgs/msg/detail/battery_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool san_msgs__msg__battery_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
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
    assert(strncmp("san_msgs.msg._battery_status.BatteryStatus", full_classname_dest, 42) == 0);
  }
  san_msgs__msg__BatteryStatus * ros_message = _ros_message;
  {  // voltage_top
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage_top");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage_top = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_top
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_top");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_top = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // soc_top
    PyObject * field = PyObject_GetAttrString(_pymsg, "soc_top");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->soc_top = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // soh_top
    PyObject * field = PyObject_GetAttrString(_pymsg, "soh_top");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->soh_top = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current
    PyObject * field = PyObject_GetAttrString(_pymsg, "current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // soc
    PyObject * field = PyObject_GetAttrString(_pymsg, "soc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->soc = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // soh
    PyObject * field = PyObject_GetAttrString(_pymsg, "soh");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->soh = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // charge_relay
    PyObject * field = PyObject_GetAttrString(_pymsg, "charge_relay");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->charge_relay = (Py_True == field);
    Py_DECREF(field);
  }
  {  // charging_jack_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "charging_jack_state");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->charging_jack_state = (Py_True == field);
    Py_DECREF(field);
  }
  {  // charging_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "charging_state");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->charging_state = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * san_msgs__msg__battery_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BatteryStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("san_msgs.msg._battery_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BatteryStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  san_msgs__msg__BatteryStatus * ros_message = (san_msgs__msg__BatteryStatus *)raw_ros_message;
  {  // voltage_top
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage_top);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage_top", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_top
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_top);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_top", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // soc_top
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->soc_top);
    {
      int rc = PyObject_SetAttrString(_pymessage, "soc_top", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // soh_top
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->soh_top);
    {
      int rc = PyObject_SetAttrString(_pymessage, "soh_top", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // soc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->soc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "soc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // soh
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->soh);
    {
      int rc = PyObject_SetAttrString(_pymessage, "soh", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // charge_relay
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->charge_relay ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "charge_relay", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // charging_jack_state
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->charging_jack_state ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "charging_jack_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // charging_state
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->charging_state ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "charging_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
