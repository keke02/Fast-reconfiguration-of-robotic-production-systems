// Generated by gencpp from file vrep_common/simRosSetJointTargetPosition.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSSETJOINTTARGETPOSITION_H
#define VREP_COMMON_MESSAGE_SIMROSSETJOINTTARGETPOSITION_H

#include <ros/service_traits.h>


#include <vrep_common/simRosSetJointTargetPositionRequest.h>
#include <vrep_common/simRosSetJointTargetPositionResponse.h>


namespace vrep_common
{

struct simRosSetJointTargetPosition
{

typedef simRosSetJointTargetPositionRequest Request;
typedef simRosSetJointTargetPositionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct simRosSetJointTargetPosition
} // namespace vrep_common


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::vrep_common::simRosSetJointTargetPosition > {
  static const char* value()
  {
    return "b23bfbd3cc670ebc2b50d027597762b2";
  }

  static const char* value(const ::vrep_common::simRosSetJointTargetPosition&) { return value(); }
};

template<>
struct DataType< ::vrep_common::simRosSetJointTargetPosition > {
  static const char* value()
  {
    return "vrep_common/simRosSetJointTargetPosition";
  }

  static const char* value(const ::vrep_common::simRosSetJointTargetPosition&) { return value(); }
};


// service_traits::MD5Sum< ::vrep_common::simRosSetJointTargetPositionRequest> should match 
// service_traits::MD5Sum< ::vrep_common::simRosSetJointTargetPosition > 
template<>
struct MD5Sum< ::vrep_common::simRosSetJointTargetPositionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosSetJointTargetPosition >::value();
  }
  static const char* value(const ::vrep_common::simRosSetJointTargetPositionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosSetJointTargetPositionRequest> should match 
// service_traits::DataType< ::vrep_common::simRosSetJointTargetPosition > 
template<>
struct DataType< ::vrep_common::simRosSetJointTargetPositionRequest>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosSetJointTargetPosition >::value();
  }
  static const char* value(const ::vrep_common::simRosSetJointTargetPositionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::vrep_common::simRosSetJointTargetPositionResponse> should match 
// service_traits::MD5Sum< ::vrep_common::simRosSetJointTargetPosition > 
template<>
struct MD5Sum< ::vrep_common::simRosSetJointTargetPositionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosSetJointTargetPosition >::value();
  }
  static const char* value(const ::vrep_common::simRosSetJointTargetPositionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosSetJointTargetPositionResponse> should match 
// service_traits::DataType< ::vrep_common::simRosSetJointTargetPosition > 
template<>
struct DataType< ::vrep_common::simRosSetJointTargetPositionResponse>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosSetJointTargetPosition >::value();
  }
  static const char* value(const ::vrep_common::simRosSetJointTargetPositionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSSETJOINTTARGETPOSITION_H