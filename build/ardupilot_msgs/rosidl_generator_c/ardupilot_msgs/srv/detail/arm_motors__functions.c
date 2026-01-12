// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ardupilot_msgs:srv/ArmMotors.idl
// generated code does not contain a copyright notice
#include "ardupilot_msgs/srv/detail/arm_motors__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
ardupilot_msgs__srv__ArmMotors_Request__init(ardupilot_msgs__srv__ArmMotors_Request * msg)
{
  if (!msg) {
    return false;
  }
  // arm
  return true;
}

void
ardupilot_msgs__srv__ArmMotors_Request__fini(ardupilot_msgs__srv__ArmMotors_Request * msg)
{
  if (!msg) {
    return;
  }
  // arm
}

bool
ardupilot_msgs__srv__ArmMotors_Request__are_equal(const ardupilot_msgs__srv__ArmMotors_Request * lhs, const ardupilot_msgs__srv__ArmMotors_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // arm
  if (lhs->arm != rhs->arm) {
    return false;
  }
  return true;
}

bool
ardupilot_msgs__srv__ArmMotors_Request__copy(
  const ardupilot_msgs__srv__ArmMotors_Request * input,
  ardupilot_msgs__srv__ArmMotors_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // arm
  output->arm = input->arm;
  return true;
}

ardupilot_msgs__srv__ArmMotors_Request *
ardupilot_msgs__srv__ArmMotors_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Request * msg = (ardupilot_msgs__srv__ArmMotors_Request *)allocator.allocate(sizeof(ardupilot_msgs__srv__ArmMotors_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ardupilot_msgs__srv__ArmMotors_Request));
  bool success = ardupilot_msgs__srv__ArmMotors_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ardupilot_msgs__srv__ArmMotors_Request__destroy(ardupilot_msgs__srv__ArmMotors_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ardupilot_msgs__srv__ArmMotors_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ardupilot_msgs__srv__ArmMotors_Request__Sequence__init(ardupilot_msgs__srv__ArmMotors_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Request * data = NULL;

  if (size) {
    data = (ardupilot_msgs__srv__ArmMotors_Request *)allocator.zero_allocate(size, sizeof(ardupilot_msgs__srv__ArmMotors_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ardupilot_msgs__srv__ArmMotors_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ardupilot_msgs__srv__ArmMotors_Request__fini(&data[i - 1]);
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
ardupilot_msgs__srv__ArmMotors_Request__Sequence__fini(ardupilot_msgs__srv__ArmMotors_Request__Sequence * array)
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
      ardupilot_msgs__srv__ArmMotors_Request__fini(&array->data[i]);
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

ardupilot_msgs__srv__ArmMotors_Request__Sequence *
ardupilot_msgs__srv__ArmMotors_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Request__Sequence * array = (ardupilot_msgs__srv__ArmMotors_Request__Sequence *)allocator.allocate(sizeof(ardupilot_msgs__srv__ArmMotors_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ardupilot_msgs__srv__ArmMotors_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ardupilot_msgs__srv__ArmMotors_Request__Sequence__destroy(ardupilot_msgs__srv__ArmMotors_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ardupilot_msgs__srv__ArmMotors_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ardupilot_msgs__srv__ArmMotors_Request__Sequence__are_equal(const ardupilot_msgs__srv__ArmMotors_Request__Sequence * lhs, const ardupilot_msgs__srv__ArmMotors_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ardupilot_msgs__srv__ArmMotors_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ardupilot_msgs__srv__ArmMotors_Request__Sequence__copy(
  const ardupilot_msgs__srv__ArmMotors_Request__Sequence * input,
  ardupilot_msgs__srv__ArmMotors_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ardupilot_msgs__srv__ArmMotors_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ardupilot_msgs__srv__ArmMotors_Request * data =
      (ardupilot_msgs__srv__ArmMotors_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ardupilot_msgs__srv__ArmMotors_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ardupilot_msgs__srv__ArmMotors_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ardupilot_msgs__srv__ArmMotors_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
ardupilot_msgs__srv__ArmMotors_Response__init(ardupilot_msgs__srv__ArmMotors_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
ardupilot_msgs__srv__ArmMotors_Response__fini(ardupilot_msgs__srv__ArmMotors_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
ardupilot_msgs__srv__ArmMotors_Response__are_equal(const ardupilot_msgs__srv__ArmMotors_Response * lhs, const ardupilot_msgs__srv__ArmMotors_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
ardupilot_msgs__srv__ArmMotors_Response__copy(
  const ardupilot_msgs__srv__ArmMotors_Response * input,
  ardupilot_msgs__srv__ArmMotors_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

ardupilot_msgs__srv__ArmMotors_Response *
ardupilot_msgs__srv__ArmMotors_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Response * msg = (ardupilot_msgs__srv__ArmMotors_Response *)allocator.allocate(sizeof(ardupilot_msgs__srv__ArmMotors_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ardupilot_msgs__srv__ArmMotors_Response));
  bool success = ardupilot_msgs__srv__ArmMotors_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ardupilot_msgs__srv__ArmMotors_Response__destroy(ardupilot_msgs__srv__ArmMotors_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ardupilot_msgs__srv__ArmMotors_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ardupilot_msgs__srv__ArmMotors_Response__Sequence__init(ardupilot_msgs__srv__ArmMotors_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Response * data = NULL;

  if (size) {
    data = (ardupilot_msgs__srv__ArmMotors_Response *)allocator.zero_allocate(size, sizeof(ardupilot_msgs__srv__ArmMotors_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ardupilot_msgs__srv__ArmMotors_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ardupilot_msgs__srv__ArmMotors_Response__fini(&data[i - 1]);
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
ardupilot_msgs__srv__ArmMotors_Response__Sequence__fini(ardupilot_msgs__srv__ArmMotors_Response__Sequence * array)
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
      ardupilot_msgs__srv__ArmMotors_Response__fini(&array->data[i]);
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

ardupilot_msgs__srv__ArmMotors_Response__Sequence *
ardupilot_msgs__srv__ArmMotors_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Response__Sequence * array = (ardupilot_msgs__srv__ArmMotors_Response__Sequence *)allocator.allocate(sizeof(ardupilot_msgs__srv__ArmMotors_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ardupilot_msgs__srv__ArmMotors_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ardupilot_msgs__srv__ArmMotors_Response__Sequence__destroy(ardupilot_msgs__srv__ArmMotors_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ardupilot_msgs__srv__ArmMotors_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ardupilot_msgs__srv__ArmMotors_Response__Sequence__are_equal(const ardupilot_msgs__srv__ArmMotors_Response__Sequence * lhs, const ardupilot_msgs__srv__ArmMotors_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ardupilot_msgs__srv__ArmMotors_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ardupilot_msgs__srv__ArmMotors_Response__Sequence__copy(
  const ardupilot_msgs__srv__ArmMotors_Response__Sequence * input,
  ardupilot_msgs__srv__ArmMotors_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ardupilot_msgs__srv__ArmMotors_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ardupilot_msgs__srv__ArmMotors_Response * data =
      (ardupilot_msgs__srv__ArmMotors_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ardupilot_msgs__srv__ArmMotors_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ardupilot_msgs__srv__ArmMotors_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ardupilot_msgs__srv__ArmMotors_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "ardupilot_msgs/srv/detail/arm_motors__functions.h"

bool
ardupilot_msgs__srv__ArmMotors_Event__init(ardupilot_msgs__srv__ArmMotors_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    ardupilot_msgs__srv__ArmMotors_Event__fini(msg);
    return false;
  }
  // request
  if (!ardupilot_msgs__srv__ArmMotors_Request__Sequence__init(&msg->request, 0)) {
    ardupilot_msgs__srv__ArmMotors_Event__fini(msg);
    return false;
  }
  // response
  if (!ardupilot_msgs__srv__ArmMotors_Response__Sequence__init(&msg->response, 0)) {
    ardupilot_msgs__srv__ArmMotors_Event__fini(msg);
    return false;
  }
  return true;
}

void
ardupilot_msgs__srv__ArmMotors_Event__fini(ardupilot_msgs__srv__ArmMotors_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  ardupilot_msgs__srv__ArmMotors_Request__Sequence__fini(&msg->request);
  // response
  ardupilot_msgs__srv__ArmMotors_Response__Sequence__fini(&msg->response);
}

bool
ardupilot_msgs__srv__ArmMotors_Event__are_equal(const ardupilot_msgs__srv__ArmMotors_Event * lhs, const ardupilot_msgs__srv__ArmMotors_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!ardupilot_msgs__srv__ArmMotors_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!ardupilot_msgs__srv__ArmMotors_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
ardupilot_msgs__srv__ArmMotors_Event__copy(
  const ardupilot_msgs__srv__ArmMotors_Event * input,
  ardupilot_msgs__srv__ArmMotors_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!ardupilot_msgs__srv__ArmMotors_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!ardupilot_msgs__srv__ArmMotors_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

ardupilot_msgs__srv__ArmMotors_Event *
ardupilot_msgs__srv__ArmMotors_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Event * msg = (ardupilot_msgs__srv__ArmMotors_Event *)allocator.allocate(sizeof(ardupilot_msgs__srv__ArmMotors_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ardupilot_msgs__srv__ArmMotors_Event));
  bool success = ardupilot_msgs__srv__ArmMotors_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ardupilot_msgs__srv__ArmMotors_Event__destroy(ardupilot_msgs__srv__ArmMotors_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ardupilot_msgs__srv__ArmMotors_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ardupilot_msgs__srv__ArmMotors_Event__Sequence__init(ardupilot_msgs__srv__ArmMotors_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Event * data = NULL;

  if (size) {
    data = (ardupilot_msgs__srv__ArmMotors_Event *)allocator.zero_allocate(size, sizeof(ardupilot_msgs__srv__ArmMotors_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ardupilot_msgs__srv__ArmMotors_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ardupilot_msgs__srv__ArmMotors_Event__fini(&data[i - 1]);
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
ardupilot_msgs__srv__ArmMotors_Event__Sequence__fini(ardupilot_msgs__srv__ArmMotors_Event__Sequence * array)
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
      ardupilot_msgs__srv__ArmMotors_Event__fini(&array->data[i]);
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

ardupilot_msgs__srv__ArmMotors_Event__Sequence *
ardupilot_msgs__srv__ArmMotors_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__srv__ArmMotors_Event__Sequence * array = (ardupilot_msgs__srv__ArmMotors_Event__Sequence *)allocator.allocate(sizeof(ardupilot_msgs__srv__ArmMotors_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ardupilot_msgs__srv__ArmMotors_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ardupilot_msgs__srv__ArmMotors_Event__Sequence__destroy(ardupilot_msgs__srv__ArmMotors_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ardupilot_msgs__srv__ArmMotors_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ardupilot_msgs__srv__ArmMotors_Event__Sequence__are_equal(const ardupilot_msgs__srv__ArmMotors_Event__Sequence * lhs, const ardupilot_msgs__srv__ArmMotors_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ardupilot_msgs__srv__ArmMotors_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ardupilot_msgs__srv__ArmMotors_Event__Sequence__copy(
  const ardupilot_msgs__srv__ArmMotors_Event__Sequence * input,
  ardupilot_msgs__srv__ArmMotors_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ardupilot_msgs__srv__ArmMotors_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ardupilot_msgs__srv__ArmMotors_Event * data =
      (ardupilot_msgs__srv__ArmMotors_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ardupilot_msgs__srv__ArmMotors_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ardupilot_msgs__srv__ArmMotors_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ardupilot_msgs__srv__ArmMotors_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
