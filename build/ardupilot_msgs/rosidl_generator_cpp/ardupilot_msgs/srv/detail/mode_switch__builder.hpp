// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ardupilot_msgs:srv/ModeSwitch.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ardupilot_msgs/srv/mode_switch.hpp"


#ifndef ARDUPILOT_MSGS__SRV__DETAIL__MODE_SWITCH__BUILDER_HPP_
#define ARDUPILOT_MSGS__SRV__DETAIL__MODE_SWITCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ardupilot_msgs/srv/detail/mode_switch__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ardupilot_msgs
{

namespace srv
{

namespace builder
{

class Init_ModeSwitch_Request_mode
{
public:
  Init_ModeSwitch_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ardupilot_msgs::srv::ModeSwitch_Request mode(::ardupilot_msgs::srv::ModeSwitch_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ardupilot_msgs::srv::ModeSwitch_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ardupilot_msgs::srv::ModeSwitch_Request>()
{
  return ardupilot_msgs::srv::builder::Init_ModeSwitch_Request_mode();
}

}  // namespace ardupilot_msgs


namespace ardupilot_msgs
{

namespace srv
{

namespace builder
{

class Init_ModeSwitch_Response_curr_mode
{
public:
  explicit Init_ModeSwitch_Response_curr_mode(::ardupilot_msgs::srv::ModeSwitch_Response & msg)
  : msg_(msg)
  {}
  ::ardupilot_msgs::srv::ModeSwitch_Response curr_mode(::ardupilot_msgs::srv::ModeSwitch_Response::_curr_mode_type arg)
  {
    msg_.curr_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ardupilot_msgs::srv::ModeSwitch_Response msg_;
};

class Init_ModeSwitch_Response_status
{
public:
  Init_ModeSwitch_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModeSwitch_Response_curr_mode status(::ardupilot_msgs::srv::ModeSwitch_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ModeSwitch_Response_curr_mode(msg_);
  }

private:
  ::ardupilot_msgs::srv::ModeSwitch_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ardupilot_msgs::srv::ModeSwitch_Response>()
{
  return ardupilot_msgs::srv::builder::Init_ModeSwitch_Response_status();
}

}  // namespace ardupilot_msgs


namespace ardupilot_msgs
{

namespace srv
{

namespace builder
{

class Init_ModeSwitch_Event_response
{
public:
  explicit Init_ModeSwitch_Event_response(::ardupilot_msgs::srv::ModeSwitch_Event & msg)
  : msg_(msg)
  {}
  ::ardupilot_msgs::srv::ModeSwitch_Event response(::ardupilot_msgs::srv::ModeSwitch_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ardupilot_msgs::srv::ModeSwitch_Event msg_;
};

class Init_ModeSwitch_Event_request
{
public:
  explicit Init_ModeSwitch_Event_request(::ardupilot_msgs::srv::ModeSwitch_Event & msg)
  : msg_(msg)
  {}
  Init_ModeSwitch_Event_response request(::ardupilot_msgs::srv::ModeSwitch_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ModeSwitch_Event_response(msg_);
  }

private:
  ::ardupilot_msgs::srv::ModeSwitch_Event msg_;
};

class Init_ModeSwitch_Event_info
{
public:
  Init_ModeSwitch_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModeSwitch_Event_request info(::ardupilot_msgs::srv::ModeSwitch_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ModeSwitch_Event_request(msg_);
  }

private:
  ::ardupilot_msgs::srv::ModeSwitch_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ardupilot_msgs::srv::ModeSwitch_Event>()
{
  return ardupilot_msgs::srv::builder::Init_ModeSwitch_Event_info();
}

}  // namespace ardupilot_msgs

#endif  // ARDUPILOT_MSGS__SRV__DETAIL__MODE_SWITCH__BUILDER_HPP_
