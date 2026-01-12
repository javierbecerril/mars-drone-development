// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ardupilot_msgs:srv/ArmMotors.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ardupilot_msgs/srv/arm_motors.h"


#ifndef ARDUPILOT_MSGS__SRV__DETAIL__ARM_MOTORS__STRUCT_H_
#define ARDUPILOT_MSGS__SRV__DETAIL__ARM_MOTORS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ArmMotors in the package ardupilot_msgs.
typedef struct ardupilot_msgs__srv__ArmMotors_Request
{
  /// This service requests the vehicle to arm or disarm its motors.
  /// Set true to arm motors, false to disarm motors.
  bool arm;
} ardupilot_msgs__srv__ArmMotors_Request;

// Struct for a sequence of ardupilot_msgs__srv__ArmMotors_Request.
typedef struct ardupilot_msgs__srv__ArmMotors_Request__Sequence
{
  ardupilot_msgs__srv__ArmMotors_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ardupilot_msgs__srv__ArmMotors_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/ArmMotors in the package ardupilot_msgs.
typedef struct ardupilot_msgs__srv__ArmMotors_Response
{
  bool result;
} ardupilot_msgs__srv__ArmMotors_Response;

// Struct for a sequence of ardupilot_msgs__srv__ArmMotors_Response.
typedef struct ardupilot_msgs__srv__ArmMotors_Response__Sequence
{
  ardupilot_msgs__srv__ArmMotors_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ardupilot_msgs__srv__ArmMotors_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ardupilot_msgs__srv__ArmMotors_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ardupilot_msgs__srv__ArmMotors_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ArmMotors in the package ardupilot_msgs.
typedef struct ardupilot_msgs__srv__ArmMotors_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ardupilot_msgs__srv__ArmMotors_Request__Sequence request;
  ardupilot_msgs__srv__ArmMotors_Response__Sequence response;
} ardupilot_msgs__srv__ArmMotors_Event;

// Struct for a sequence of ardupilot_msgs__srv__ArmMotors_Event.
typedef struct ardupilot_msgs__srv__ArmMotors_Event__Sequence
{
  ardupilot_msgs__srv__ArmMotors_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ardupilot_msgs__srv__ArmMotors_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARDUPILOT_MSGS__SRV__DETAIL__ARM_MOTORS__STRUCT_H_
