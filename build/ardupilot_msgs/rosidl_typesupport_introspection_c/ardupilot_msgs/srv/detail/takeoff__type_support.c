// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ardupilot_msgs:srv/Takeoff.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ardupilot_msgs/srv/detail/takeoff__rosidl_typesupport_introspection_c.h"
#include "ardupilot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ardupilot_msgs/srv/detail/takeoff__functions.h"
#include "ardupilot_msgs/srv/detail/takeoff__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ardupilot_msgs__srv__Takeoff_Request__init(message_memory);
}

void ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_fini_function(void * message_memory)
{
  ardupilot_msgs__srv__Takeoff_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_member_array[1] = {
  {
    "alt",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ardupilot_msgs__srv__Takeoff_Request, alt),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_members = {
  "ardupilot_msgs__srv",  // message namespace
  "Takeoff_Request",  // message name
  1,  // number of fields
  sizeof(ardupilot_msgs__srv__Takeoff_Request),
  false,  // has_any_key_member_
  ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_member_array,  // message members
  ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_type_support_handle = {
  0,
  &ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_members,
  get_message_typesupport_handle_function,
  &ardupilot_msgs__srv__Takeoff_Request__get_type_hash,
  &ardupilot_msgs__srv__Takeoff_Request__get_type_description,
  &ardupilot_msgs__srv__Takeoff_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ardupilot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Request)() {
  if (!ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_type_support_handle.typesupport_identifier) {
    ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ardupilot_msgs/srv/detail/takeoff__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ardupilot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ardupilot_msgs/srv/detail/takeoff__functions.h"
// already included above
// #include "ardupilot_msgs/srv/detail/takeoff__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ardupilot_msgs__srv__Takeoff_Response__init(message_memory);
}

void ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_fini_function(void * message_memory)
{
  ardupilot_msgs__srv__Takeoff_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_member_array[1] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ardupilot_msgs__srv__Takeoff_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_members = {
  "ardupilot_msgs__srv",  // message namespace
  "Takeoff_Response",  // message name
  1,  // number of fields
  sizeof(ardupilot_msgs__srv__Takeoff_Response),
  false,  // has_any_key_member_
  ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_member_array,  // message members
  ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_type_support_handle = {
  0,
  &ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_members,
  get_message_typesupport_handle_function,
  &ardupilot_msgs__srv__Takeoff_Response__get_type_hash,
  &ardupilot_msgs__srv__Takeoff_Response__get_type_description,
  &ardupilot_msgs__srv__Takeoff_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ardupilot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Response)() {
  if (!ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_type_support_handle.typesupport_identifier) {
    ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ardupilot_msgs/srv/detail/takeoff__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ardupilot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ardupilot_msgs/srv/detail/takeoff__functions.h"
// already included above
// #include "ardupilot_msgs/srv/detail/takeoff__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "ardupilot_msgs/srv/takeoff.h"
// Member `request`
// Member `response`
// already included above
// #include "ardupilot_msgs/srv/detail/takeoff__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ardupilot_msgs__srv__Takeoff_Event__init(message_memory);
}

void ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_fini_function(void * message_memory)
{
  ardupilot_msgs__srv__Takeoff_Event__fini(message_memory);
}

size_t ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__size_function__Takeoff_Event__request(
  const void * untyped_member)
{
  const ardupilot_msgs__srv__Takeoff_Request__Sequence * member =
    (const ardupilot_msgs__srv__Takeoff_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_const_function__Takeoff_Event__request(
  const void * untyped_member, size_t index)
{
  const ardupilot_msgs__srv__Takeoff_Request__Sequence * member =
    (const ardupilot_msgs__srv__Takeoff_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_function__Takeoff_Event__request(
  void * untyped_member, size_t index)
{
  ardupilot_msgs__srv__Takeoff_Request__Sequence * member =
    (ardupilot_msgs__srv__Takeoff_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__fetch_function__Takeoff_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ardupilot_msgs__srv__Takeoff_Request * item =
    ((const ardupilot_msgs__srv__Takeoff_Request *)
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_const_function__Takeoff_Event__request(untyped_member, index));
  ardupilot_msgs__srv__Takeoff_Request * value =
    (ardupilot_msgs__srv__Takeoff_Request *)(untyped_value);
  *value = *item;
}

void ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__assign_function__Takeoff_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ardupilot_msgs__srv__Takeoff_Request * item =
    ((ardupilot_msgs__srv__Takeoff_Request *)
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_function__Takeoff_Event__request(untyped_member, index));
  const ardupilot_msgs__srv__Takeoff_Request * value =
    (const ardupilot_msgs__srv__Takeoff_Request *)(untyped_value);
  *item = *value;
}

bool ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__resize_function__Takeoff_Event__request(
  void * untyped_member, size_t size)
{
  ardupilot_msgs__srv__Takeoff_Request__Sequence * member =
    (ardupilot_msgs__srv__Takeoff_Request__Sequence *)(untyped_member);
  ardupilot_msgs__srv__Takeoff_Request__Sequence__fini(member);
  return ardupilot_msgs__srv__Takeoff_Request__Sequence__init(member, size);
}

size_t ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__size_function__Takeoff_Event__response(
  const void * untyped_member)
{
  const ardupilot_msgs__srv__Takeoff_Response__Sequence * member =
    (const ardupilot_msgs__srv__Takeoff_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_const_function__Takeoff_Event__response(
  const void * untyped_member, size_t index)
{
  const ardupilot_msgs__srv__Takeoff_Response__Sequence * member =
    (const ardupilot_msgs__srv__Takeoff_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_function__Takeoff_Event__response(
  void * untyped_member, size_t index)
{
  ardupilot_msgs__srv__Takeoff_Response__Sequence * member =
    (ardupilot_msgs__srv__Takeoff_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__fetch_function__Takeoff_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ardupilot_msgs__srv__Takeoff_Response * item =
    ((const ardupilot_msgs__srv__Takeoff_Response *)
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_const_function__Takeoff_Event__response(untyped_member, index));
  ardupilot_msgs__srv__Takeoff_Response * value =
    (ardupilot_msgs__srv__Takeoff_Response *)(untyped_value);
  *value = *item;
}

void ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__assign_function__Takeoff_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ardupilot_msgs__srv__Takeoff_Response * item =
    ((ardupilot_msgs__srv__Takeoff_Response *)
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_function__Takeoff_Event__response(untyped_member, index));
  const ardupilot_msgs__srv__Takeoff_Response * value =
    (const ardupilot_msgs__srv__Takeoff_Response *)(untyped_value);
  *item = *value;
}

bool ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__resize_function__Takeoff_Event__response(
  void * untyped_member, size_t size)
{
  ardupilot_msgs__srv__Takeoff_Response__Sequence * member =
    (ardupilot_msgs__srv__Takeoff_Response__Sequence *)(untyped_member);
  ardupilot_msgs__srv__Takeoff_Response__Sequence__fini(member);
  return ardupilot_msgs__srv__Takeoff_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ardupilot_msgs__srv__Takeoff_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(ardupilot_msgs__srv__Takeoff_Event, request),  // bytes offset in struct
    NULL,  // default value
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__size_function__Takeoff_Event__request,  // size() function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_const_function__Takeoff_Event__request,  // get_const(index) function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_function__Takeoff_Event__request,  // get(index) function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__fetch_function__Takeoff_Event__request,  // fetch(index, &value) function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__assign_function__Takeoff_Event__request,  // assign(index, value) function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__resize_function__Takeoff_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(ardupilot_msgs__srv__Takeoff_Event, response),  // bytes offset in struct
    NULL,  // default value
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__size_function__Takeoff_Event__response,  // size() function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_const_function__Takeoff_Event__response,  // get_const(index) function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__get_function__Takeoff_Event__response,  // get(index) function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__fetch_function__Takeoff_Event__response,  // fetch(index, &value) function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__assign_function__Takeoff_Event__response,  // assign(index, value) function pointer
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__resize_function__Takeoff_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_members = {
  "ardupilot_msgs__srv",  // message namespace
  "Takeoff_Event",  // message name
  3,  // number of fields
  sizeof(ardupilot_msgs__srv__Takeoff_Event),
  false,  // has_any_key_member_
  ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_member_array,  // message members
  ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_type_support_handle = {
  0,
  &ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_members,
  get_message_typesupport_handle_function,
  &ardupilot_msgs__srv__Takeoff_Event__get_type_hash,
  &ardupilot_msgs__srv__Takeoff_Event__get_type_description,
  &ardupilot_msgs__srv__Takeoff_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ardupilot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Event)() {
  ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Request)();
  ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Response)();
  if (!ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_type_support_handle.typesupport_identifier) {
    ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ardupilot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ardupilot_msgs/srv/detail/takeoff__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_service_members = {
  "ardupilot_msgs__srv",  // service namespace
  "Takeoff",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_Request_message_type_support_handle,
  NULL,  // response message
  // ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_Response_message_type_support_handle
  NULL  // event_message
  // ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_Response_message_type_support_handle
};


static rosidl_service_type_support_t ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_service_type_support_handle = {
  0,
  &ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_service_members,
  get_service_typesupport_handle_function,
  &ardupilot_msgs__srv__Takeoff_Request__rosidl_typesupport_introspection_c__Takeoff_Request_message_type_support_handle,
  &ardupilot_msgs__srv__Takeoff_Response__rosidl_typesupport_introspection_c__Takeoff_Response_message_type_support_handle,
  &ardupilot_msgs__srv__Takeoff_Event__rosidl_typesupport_introspection_c__Takeoff_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ardupilot_msgs,
    srv,
    Takeoff
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ardupilot_msgs,
    srv,
    Takeoff
  ),
  &ardupilot_msgs__srv__Takeoff__get_type_hash,
  &ardupilot_msgs__srv__Takeoff__get_type_description,
  &ardupilot_msgs__srv__Takeoff__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ardupilot_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff)(void) {
  if (!ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_service_type_support_handle.typesupport_identifier) {
    ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ardupilot_msgs, srv, Takeoff_Event)()->data;
  }

  return &ardupilot_msgs__srv__detail__takeoff__rosidl_typesupport_introspection_c__Takeoff_service_type_support_handle;
}
