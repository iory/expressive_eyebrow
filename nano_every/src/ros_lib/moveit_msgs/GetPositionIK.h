#ifndef _ROS_SERVICE_GetPositionIK_h
#define _ROS_SERVICE_GetPositionIK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/PositionIKRequest.h"

namespace moveit_msgs
{

static const char GETPOSITIONIK[] = "moveit_msgs/GetPositionIK";

  class GetPositionIKRequest : public ros::Msg
  {
    public:
      typedef moveit_msgs::PositionIKRequest _ik_request_type;
      _ik_request_type ik_request;

    GetPositionIKRequest():
      ik_request()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->ik_request.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->ik_request.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPOSITIONIK; };
    virtual const char * getMD5() override { return "a67dc7e99d15c1dca32a77c22bc2d93b"; };

  };

  class GetPositionIKResponse : public ros::Msg
  {
    public:
      typedef moveit_msgs::RobotState _solution_type;
      _solution_type solution;
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;

    GetPositionIKResponse():
      solution(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->solution.serialize(outbuffer + offset);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->solution.deserialize(inbuffer + offset);
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPOSITIONIK; };
    virtual const char * getMD5() override { return "ad50fe5fa0ddb482909be313121ea148"; };

  };

  class GetPositionIK {
    public:
    typedef GetPositionIKRequest Request;
    typedef GetPositionIKResponse Response;
  };

}
#endif
