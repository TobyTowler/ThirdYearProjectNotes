// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robot_interfaces:msg/RobotSendCMD.idl
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
#include "robot_interfaces/msg/detail/robot_send_cmd__struct.h"
#include "robot_interfaces/msg/detail/robot_send_cmd__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robot_interfaces__msg__robot_send_cmd__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
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
    assert(strncmp("robot_interfaces.msg._robot_send_cmd.RobotSendCMD", full_classname_dest, 49) == 0);
  }
  robot_interfaces__msg__RobotSendCMD * ros_message = _ros_message;
  {  // cmd_chr
    PyObject * field = PyObject_GetAttrString(_pymsg, "cmd_chr");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cmd_chr = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // arg1
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg2
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg3
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg4
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg4");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg4 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg5
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg5");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg5 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg6
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg6");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg6 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg7
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg7");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg7 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg8
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg8");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg8 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg9
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg9");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg9 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg10
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg10");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg10 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg11
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg11");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg11 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg12
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg12");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg12 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg13
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg13");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg13 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arg14
    PyObject * field = PyObject_GetAttrString(_pymsg, "arg14");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->arg14 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robot_interfaces__msg__robot_send_cmd__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RobotSendCMD */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robot_interfaces.msg._robot_send_cmd");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RobotSendCMD");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robot_interfaces__msg__RobotSendCMD * ros_message = (robot_interfaces__msg__RobotSendCMD *)raw_ros_message;
  {  // cmd_chr
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cmd_chr);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cmd_chr", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg4
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg5
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg6
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg6);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg6", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg7
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg7);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg7", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg8
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg8);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg8", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg9
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg9);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg9", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg10
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg10);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg10", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg11
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg11);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg11", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg12
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg12);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg12", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg13
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg13);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg13", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arg14
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->arg14);
    {
      int rc = PyObject_SetAttrString(_pymessage, "arg14", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
