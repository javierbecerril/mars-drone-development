// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ardupilot_msgs:srv/Takeoff.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ardupilot_msgs/srv/takeoff.hpp"


#ifndef ARDUPILOT_MSGS__SRV__DETAIL__TAKEOFF__BUILDER_HPP_
#define ARDUPILOT_MSGS__SRV__DETAIL__TAKEOFF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ardupilot_msgs/srv/detail/takeoff__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ardupilot_msgs
{

namespace srv
{

namespace builder
{

class Init_Takeoff_Request_alt
{
public:
  Init_Takeoff_Request_alt()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ardupilot_msgs::srv::Takeoff_Request alt(::ardupilot_msgs::srv::Takeoff_Request::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ardupilot_msgs::srv::Takeoff_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ardupilot_msgs::srv::Takeoff_Request>()
{
  return ardupilot_msgs::srv::builder::Init_Takeoff_Request_alt();
}

}  // namespace ardupilot_msgs


namespace ardupilot_msgs
{

namespace srv
{

namespace builder
{

class Init_Takeoff_Response_status
{
public:
  Init_Takeoff_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ardupilot_msgs::srv::Takeoff_Response status(::ardupilot_msgs::srv::Takeoff_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ardupilot_msgs::srv::Takeoff_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ardupilot_msgs::srv::Takeoff_Response>()
{
  return ardupilot_msgs::srv::builder::Init_Takeoff_Response_status();
}

}  // namespace ardupilot_msgs


namespace ardupilot_msgs
{

namespace srv
{

namespace builder
{

class Init_Takeoff_Event_response
{
public:
  explicit Init_Takeoff_Event_response(::ardupilot_msgs::srv::Takeoff_Event & msg)
  : msg_(msg)
  {}
  ::ardupilot_msgs::srv::Takeoff_Event response(::ardupilot_msgs::srv::Takeoff_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ardupilot_msgs::srv::Takeoff_Event msg_;
};

class Init_Takeoff_Event_request
{
public:
  explicit Init_Takeoff_Event_request(::ardupilot_msgs::srv::Takeoff_Event & msg)
  : msg_(msg)
  {}
  Init_Takeoff_Event_response request(::ardupilot_msgs::srv::Takeoff_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Takeoff_Event_response(msg_);
  }

private:
  ::ardupilot_msgs::srv::Takeoff_Event msg_;
};

class Init_Takeoff_Event_info
{
public:
  Init_Takeoff_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Takeoff_Event_request info(::ardupilot_msgs::srv::Takeoff_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Takeoff_Event_request(msg_);
  }

private:
  ::ardupilot_msgs::srv::Takeoff_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ardupilot_msgs::srv::Takeoff_Event>()
{
  return ardupilot_msgs::srv::builder::Init_Takeoff_Event_info();
}

}  // namespace ardupilot_msgs

#endif  // ARDUPILOT_MSGS__SRV__DETAIL__TAKEOFF__BUILDER_HPP_
