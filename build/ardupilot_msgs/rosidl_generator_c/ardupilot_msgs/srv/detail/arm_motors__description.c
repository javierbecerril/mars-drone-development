// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ardupilot_msgs:srv/ArmMotors.idl
// generated code does not contain a copyright notice

#include "ardupilot_msgs/srv/detail/arm_motors__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ardupilot_msgs
const rosidl_type_hash_t *
ardupilot_msgs__srv__ArmMotors__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x99, 0x84, 0x9c, 0xee, 0x95, 0xea, 0x14, 0xf0,
      0x70, 0x3d, 0x48, 0x14, 0x34, 0xc6, 0x2a, 0xac,
      0x42, 0xee, 0xf5, 0xfb, 0xd9, 0x1e, 0x1d, 0xf4,
      0xe4, 0x80, 0xa9, 0x9c, 0x22, 0x77, 0x93, 0xb4,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ardupilot_msgs
const rosidl_type_hash_t *
ardupilot_msgs__srv__ArmMotors_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x59, 0xce, 0x3c, 0xb8, 0xb1, 0xb9, 0x60, 0x0e,
      0x88, 0xe7, 0x0c, 0xa2, 0x24, 0x12, 0x79, 0x52,
      0x42, 0xde, 0xc5, 0x9d, 0xab, 0xaa, 0x60, 0x08,
      0x3e, 0x23, 0xca, 0xd8, 0xdf, 0xac, 0xd8, 0x1e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ardupilot_msgs
const rosidl_type_hash_t *
ardupilot_msgs__srv__ArmMotors_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xca, 0xe5, 0xab, 0xb0, 0xec, 0x01, 0x2e, 0x2e,
      0x2e, 0x20, 0x98, 0xa1, 0x24, 0x2a, 0x08, 0x6b,
      0x95, 0xd9, 0xca, 0x6f, 0x3f, 0x77, 0xb4, 0xe1,
      0x89, 0x47, 0x0c, 0xd4, 0xb8, 0xd0, 0x6f, 0x94,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ardupilot_msgs
const rosidl_type_hash_t *
ardupilot_msgs__srv__ArmMotors_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x88, 0xea, 0x62, 0x8a, 0x53, 0xe9, 0xc7, 0x21,
      0x46, 0x4c, 0x02, 0xe2, 0x85, 0xb7, 0xc5, 0x1f,
      0x77, 0x20, 0x6f, 0x93, 0xfc, 0x3c, 0x41, 0xbe,
      0x74, 0xf2, 0x49, 0x20, 0x5c, 0x66, 0xf7, 0xd8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char ardupilot_msgs__srv__ArmMotors__TYPE_NAME[] = "ardupilot_msgs/srv/ArmMotors";
static char ardupilot_msgs__srv__ArmMotors_Event__TYPE_NAME[] = "ardupilot_msgs/srv/ArmMotors_Event";
static char ardupilot_msgs__srv__ArmMotors_Request__TYPE_NAME[] = "ardupilot_msgs/srv/ArmMotors_Request";
static char ardupilot_msgs__srv__ArmMotors_Response__TYPE_NAME[] = "ardupilot_msgs/srv/ArmMotors_Response";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char ardupilot_msgs__srv__ArmMotors__FIELD_NAME__request_message[] = "request_message";
static char ardupilot_msgs__srv__ArmMotors__FIELD_NAME__response_message[] = "response_message";
static char ardupilot_msgs__srv__ArmMotors__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field ardupilot_msgs__srv__ArmMotors__FIELDS[] = {
  {
    {ardupilot_msgs__srv__ArmMotors__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ardupilot_msgs__srv__ArmMotors_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {ardupilot_msgs__srv__ArmMotors__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ardupilot_msgs__srv__ArmMotors_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {ardupilot_msgs__srv__ArmMotors__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ardupilot_msgs__srv__ArmMotors_Event__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ardupilot_msgs__srv__ArmMotors__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {ardupilot_msgs__srv__ArmMotors_Event__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {ardupilot_msgs__srv__ArmMotors_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {ardupilot_msgs__srv__ArmMotors_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ardupilot_msgs__srv__ArmMotors__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ardupilot_msgs__srv__ArmMotors__TYPE_NAME, 28, 28},
      {ardupilot_msgs__srv__ArmMotors__FIELDS, 3, 3},
    },
    {ardupilot_msgs__srv__ArmMotors__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = ardupilot_msgs__srv__ArmMotors_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = ardupilot_msgs__srv__ArmMotors_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = ardupilot_msgs__srv__ArmMotors_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ardupilot_msgs__srv__ArmMotors_Request__FIELD_NAME__arm[] = "arm";

static rosidl_runtime_c__type_description__Field ardupilot_msgs__srv__ArmMotors_Request__FIELDS[] = {
  {
    {ardupilot_msgs__srv__ArmMotors_Request__FIELD_NAME__arm, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ardupilot_msgs__srv__ArmMotors_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ardupilot_msgs__srv__ArmMotors_Request__TYPE_NAME, 36, 36},
      {ardupilot_msgs__srv__ArmMotors_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ardupilot_msgs__srv__ArmMotors_Response__FIELD_NAME__result[] = "result";

static rosidl_runtime_c__type_description__Field ardupilot_msgs__srv__ArmMotors_Response__FIELDS[] = {
  {
    {ardupilot_msgs__srv__ArmMotors_Response__FIELD_NAME__result, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ardupilot_msgs__srv__ArmMotors_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ardupilot_msgs__srv__ArmMotors_Response__TYPE_NAME, 37, 37},
      {ardupilot_msgs__srv__ArmMotors_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ardupilot_msgs__srv__ArmMotors_Event__FIELD_NAME__info[] = "info";
static char ardupilot_msgs__srv__ArmMotors_Event__FIELD_NAME__request[] = "request";
static char ardupilot_msgs__srv__ArmMotors_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field ardupilot_msgs__srv__ArmMotors_Event__FIELDS[] = {
  {
    {ardupilot_msgs__srv__ArmMotors_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {ardupilot_msgs__srv__ArmMotors_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ardupilot_msgs__srv__ArmMotors_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {ardupilot_msgs__srv__ArmMotors_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ardupilot_msgs__srv__ArmMotors_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ardupilot_msgs__srv__ArmMotors_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {ardupilot_msgs__srv__ArmMotors_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {ardupilot_msgs__srv__ArmMotors_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ardupilot_msgs__srv__ArmMotors_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ardupilot_msgs__srv__ArmMotors_Event__TYPE_NAME, 34, 34},
      {ardupilot_msgs__srv__ArmMotors_Event__FIELDS, 3, 3},
    },
    {ardupilot_msgs__srv__ArmMotors_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    description.referenced_type_descriptions.data[0].fields = ardupilot_msgs__srv__ArmMotors_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = ardupilot_msgs__srv__ArmMotors_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "\n"
  "# This service requests the vehicle to arm or disarm its motors.\n"
  "\n"
  "# Set true to arm motors, false to disarm motors.\n"
  "bool arm\n"
  "---\n"
  "# True if arming/disarming request for motors was successful , false otherwise. \n"
  "bool result";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ardupilot_msgs__srv__ArmMotors__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ardupilot_msgs__srv__ArmMotors__TYPE_NAME, 28, 28},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 223, 223},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ardupilot_msgs__srv__ArmMotors_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ardupilot_msgs__srv__ArmMotors_Request__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ardupilot_msgs__srv__ArmMotors_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ardupilot_msgs__srv__ArmMotors_Response__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ardupilot_msgs__srv__ArmMotors_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ardupilot_msgs__srv__ArmMotors_Event__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ardupilot_msgs__srv__ArmMotors__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ardupilot_msgs__srv__ArmMotors__get_individual_type_description_source(NULL),
    sources[1] = *ardupilot_msgs__srv__ArmMotors_Event__get_individual_type_description_source(NULL);
    sources[2] = *ardupilot_msgs__srv__ArmMotors_Request__get_individual_type_description_source(NULL);
    sources[3] = *ardupilot_msgs__srv__ArmMotors_Response__get_individual_type_description_source(NULL);
    sources[4] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ardupilot_msgs__srv__ArmMotors_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ardupilot_msgs__srv__ArmMotors_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ardupilot_msgs__srv__ArmMotors_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ardupilot_msgs__srv__ArmMotors_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ardupilot_msgs__srv__ArmMotors_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ardupilot_msgs__srv__ArmMotors_Event__get_individual_type_description_source(NULL),
    sources[1] = *ardupilot_msgs__srv__ArmMotors_Request__get_individual_type_description_source(NULL);
    sources[2] = *ardupilot_msgs__srv__ArmMotors_Response__get_individual_type_description_source(NULL);
    sources[3] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
