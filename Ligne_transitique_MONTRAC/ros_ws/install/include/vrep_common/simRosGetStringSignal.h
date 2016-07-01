// Generated by gencpp from file vrep_common/simRosGetStringSignal.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSGETSTRINGSIGNAL_H
#define VREP_COMMON_MESSAGE_SIMROSGETSTRINGSIGNAL_H

#include <ros/service_traits.h>


#include <vrep_common/simRosGetStringSignalRequest.h>
#include <vrep_common/simRosGetStringSignalResponse.h>


namespace vrep_common
{

struct simRosGetStringSignal
{

typedef simRosGetStringSignalRequest Request;
typedef simRosGetStringSignalResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct simRosGetStringSignal
} // namespace vrep_common


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::vrep_common::simRosGetStringSignal > {
  static const char* value()
  {
    return "2404c94dd63ca66111460f0d88cb7f64";
  }

  static const char* value(const ::vrep_common::simRosGetStringSignal&) { return value(); }
};

template<>
struct DataType< ::vrep_common::simRosGetStringSignal > {
  static const char* value()
  {
    return "vrep_common/simRosGetStringSignal";
  }

  static const char* value(const ::vrep_common::simRosGetStringSignal&) { return value(); }
};


// service_traits::MD5Sum< ::vrep_common::simRosGetStringSignalRequest> should match 
// service_traits::MD5Sum< ::vrep_common::simRosGetStringSignal > 
template<>
struct MD5Sum< ::vrep_common::simRosGetStringSignalRequest>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosGetStringSignal >::value();
  }
  static const char* value(const ::vrep_common::simRosGetStringSignalRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosGetStringSignalRequest> should match 
// service_traits::DataType< ::vrep_common::simRosGetStringSignal > 
template<>
struct DataType< ::vrep_common::simRosGetStringSignalRequest>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosGetStringSignal >::value();
  }
  static const char* value(const ::vrep_common::simRosGetStringSignalRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::vrep_common::simRosGetStringSignalResponse> should match 
// service_traits::MD5Sum< ::vrep_common::simRosGetStringSignal > 
template<>
struct MD5Sum< ::vrep_common::simRosGetStringSignalResponse>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosGetStringSignal >::value();
  }
  static const char* value(const ::vrep_common::simRosGetStringSignalResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosGetStringSignalResponse> should match 
// service_traits::DataType< ::vrep_common::simRosGetStringSignal > 
template<>
struct DataType< ::vrep_common::simRosGetStringSignalResponse>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosGetStringSignal >::value();
  }
  static const char* value(const ::vrep_common::simRosGetStringSignalResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSGETSTRINGSIGNAL_H