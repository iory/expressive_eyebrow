#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperGrabResult_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperGrabResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pr2_gripper_sensor_msgs/PR2GripperGrabData.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperGrabResult : public ros::Msg
  {
    public:
      typedef pr2_gripper_sensor_msgs::PR2GripperGrabData _data_type;
      _data_type data;

    PR2GripperGrabResult():
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "pr2_gripper_sensor_msgs/PR2GripperGrabResult"; };
    virtual const char * getMD5() override { return "b4b68d48ac7d07bdb11b7f3badfa9266"; };

  };

}
#endif
