// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_interfaces:msg/RobotSendCMD.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/msg/detail/robot_send_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robot_interfaces__msg__RobotSendCMD__init(robot_interfaces__msg__RobotSendCMD * msg)
{
  if (!msg) {
    return false;
  }
  // cmd_chr
  msg->cmd_chr = 64;
  // arg1
  msg->arg1 = 0.0f;
  // arg2
  msg->arg2 = 0.0f;
  // arg3
  msg->arg3 = 0.0f;
  // arg4
  msg->arg4 = 0.0f;
  // arg5
  msg->arg5 = 0.0f;
  // arg6
  msg->arg6 = 0.0f;
  // arg7
  msg->arg7 = 0.0f;
  // arg8
  msg->arg8 = 0.0f;
  // arg9
  msg->arg9 = 0.0f;
  // arg10
  msg->arg10 = 0.0f;
  // arg11
  msg->arg11 = 0.0f;
  // arg12
  msg->arg12 = 0.0f;
  // arg13
  msg->arg13 = 0.0f;
  // arg14
  msg->arg14 = 0.0f;
  return true;
}

void
robot_interfaces__msg__RobotSendCMD__fini(robot_interfaces__msg__RobotSendCMD * msg)
{
  if (!msg) {
    return;
  }
  // cmd_chr
  // arg1
  // arg2
  // arg3
  // arg4
  // arg5
  // arg6
  // arg7
  // arg8
  // arg9
  // arg10
  // arg11
  // arg12
  // arg13
  // arg14
}

bool
robot_interfaces__msg__RobotSendCMD__are_equal(const robot_interfaces__msg__RobotSendCMD * lhs, const robot_interfaces__msg__RobotSendCMD * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd_chr
  if (lhs->cmd_chr != rhs->cmd_chr) {
    return false;
  }
  // arg1
  if (lhs->arg1 != rhs->arg1) {
    return false;
  }
  // arg2
  if (lhs->arg2 != rhs->arg2) {
    return false;
  }
  // arg3
  if (lhs->arg3 != rhs->arg3) {
    return false;
  }
  // arg4
  if (lhs->arg4 != rhs->arg4) {
    return false;
  }
  // arg5
  if (lhs->arg5 != rhs->arg5) {
    return false;
  }
  // arg6
  if (lhs->arg6 != rhs->arg6) {
    return false;
  }
  // arg7
  if (lhs->arg7 != rhs->arg7) {
    return false;
  }
  // arg8
  if (lhs->arg8 != rhs->arg8) {
    return false;
  }
  // arg9
  if (lhs->arg9 != rhs->arg9) {
    return false;
  }
  // arg10
  if (lhs->arg10 != rhs->arg10) {
    return false;
  }
  // arg11
  if (lhs->arg11 != rhs->arg11) {
    return false;
  }
  // arg12
  if (lhs->arg12 != rhs->arg12) {
    return false;
  }
  // arg13
  if (lhs->arg13 != rhs->arg13) {
    return false;
  }
  // arg14
  if (lhs->arg14 != rhs->arg14) {
    return false;
  }
  return true;
}

bool
robot_interfaces__msg__RobotSendCMD__copy(
  const robot_interfaces__msg__RobotSendCMD * input,
  robot_interfaces__msg__RobotSendCMD * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd_chr
  output->cmd_chr = input->cmd_chr;
  // arg1
  output->arg1 = input->arg1;
  // arg2
  output->arg2 = input->arg2;
  // arg3
  output->arg3 = input->arg3;
  // arg4
  output->arg4 = input->arg4;
  // arg5
  output->arg5 = input->arg5;
  // arg6
  output->arg6 = input->arg6;
  // arg7
  output->arg7 = input->arg7;
  // arg8
  output->arg8 = input->arg8;
  // arg9
  output->arg9 = input->arg9;
  // arg10
  output->arg10 = input->arg10;
  // arg11
  output->arg11 = input->arg11;
  // arg12
  output->arg12 = input->arg12;
  // arg13
  output->arg13 = input->arg13;
  // arg14
  output->arg14 = input->arg14;
  return true;
}

robot_interfaces__msg__RobotSendCMD *
robot_interfaces__msg__RobotSendCMD__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__RobotSendCMD * msg = (robot_interfaces__msg__RobotSendCMD *)allocator.allocate(sizeof(robot_interfaces__msg__RobotSendCMD), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_interfaces__msg__RobotSendCMD));
  bool success = robot_interfaces__msg__RobotSendCMD__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_interfaces__msg__RobotSendCMD__destroy(robot_interfaces__msg__RobotSendCMD * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_interfaces__msg__RobotSendCMD__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_interfaces__msg__RobotSendCMD__Sequence__init(robot_interfaces__msg__RobotSendCMD__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__RobotSendCMD * data = NULL;

  if (size) {
    data = (robot_interfaces__msg__RobotSendCMD *)allocator.zero_allocate(size, sizeof(robot_interfaces__msg__RobotSendCMD), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_interfaces__msg__RobotSendCMD__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_interfaces__msg__RobotSendCMD__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robot_interfaces__msg__RobotSendCMD__Sequence__fini(robot_interfaces__msg__RobotSendCMD__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robot_interfaces__msg__RobotSendCMD__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robot_interfaces__msg__RobotSendCMD__Sequence *
robot_interfaces__msg__RobotSendCMD__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_interfaces__msg__RobotSendCMD__Sequence * array = (robot_interfaces__msg__RobotSendCMD__Sequence *)allocator.allocate(sizeof(robot_interfaces__msg__RobotSendCMD__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_interfaces__msg__RobotSendCMD__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_interfaces__msg__RobotSendCMD__Sequence__destroy(robot_interfaces__msg__RobotSendCMD__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_interfaces__msg__RobotSendCMD__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_interfaces__msg__RobotSendCMD__Sequence__are_equal(const robot_interfaces__msg__RobotSendCMD__Sequence * lhs, const robot_interfaces__msg__RobotSendCMD__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_interfaces__msg__RobotSendCMD__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_interfaces__msg__RobotSendCMD__Sequence__copy(
  const robot_interfaces__msg__RobotSendCMD__Sequence * input,
  robot_interfaces__msg__RobotSendCMD__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_interfaces__msg__RobotSendCMD);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_interfaces__msg__RobotSendCMD * data =
      (robot_interfaces__msg__RobotSendCMD *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_interfaces__msg__RobotSendCMD__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_interfaces__msg__RobotSendCMD__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_interfaces__msg__RobotSendCMD__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
