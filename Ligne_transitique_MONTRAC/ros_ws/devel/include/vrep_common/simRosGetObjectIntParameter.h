// Generated by gencpp from file vrep_common/simRosGetObjectIntParameter.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSGETOBJECTINTPARAMETER_H
#define VREP_COMMON_MESSAGE_SIMROSGETOBJECTINTPARAMETER_H

#include <ros/service_traits.h>


#include <vrep_common/simRosGetObjectIntParameterRequest.h>
#include <vrep_common/simRosGetObjectIntParameterResponse.h>


namespace vrep_common
{

struct simRosGetObjectIntParameter
{

typedef simRosGetObjectIntParameterRequest Request;
typedef simRosGetObjectIntParameterResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct simRosGetObjectIntParameter
} // namespace vrep_common


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::vrep_common::simRosGetObjectIntParameter > {
  static const char* value()
  {
    return "8372aeda509849308ae25567cba4e30f";
  }

  static const char* value(const ::vrep_common::simRosGetObjectIntParameter&) { return value(); }
};

template<>
struct DataType< ::vrep_common::simRosGetObjectIntParameter > {
  static const char* value()
  {
    return "vrep_common/simRosGetObjectIntParameter";
  }

  static const char* value(const ::vrep_common::simRosGetObjectIntParameter&) { return value(); }
};


// service_traits::MD5Sum< ::vrep_common::simRosGetObjectIntParameterRequest> should match 
// service_traits::MD5Sum< ::vrep_common::simRosGetObjectIntParameter > 
template<>
struct MD5Sum< ::vrep_common::simRosGetObjectIntParameterRequest>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosGetObjectIntParameter >::value();
  }
  static const char* value(const ::vrep_common::simRosGetObjectIntParameterRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosGetObjectIntParameterRequest> should match 
// service_traits::DataType< ::vrep_common::simRosGetObjectIntParameter > 
template<>
struct DataType< ::vrep_common::simRosGetObjectIntParameterRequest>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosGetObjectIntParameter >::value();
  }
  static const char* value(const ::vrep_common::simRosGetObjectIntParameterRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::vrep_common::simRosGetObjectIntParameterResponse> should match 
// service_traits::MD5Sum< ::vrep_common::simRosGetObjectIntParameter > 
template<>
struct MD5Sum< ::vrep_common::simRosGetObjectIntParameterResponse>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosGetObjectIntParameter >::value();
  }
  static const char* value(const ::vrep_common::simRosGetObjectIntParameterResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosGetObjectIntParameterResponse> should match 
// service_traits::DataType< ::vrep_common::simRosGetObjectIntParameter > 
template<>
struct DataType< ::vrep_common::simRosGetObjectIntParameterResponse>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosGetObjectIntParameter >::value();
  }
  static const char* value(const ::vrep_common::simRosGetObjectIntParameterResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSGETOBJECTINTPARAMETER_H