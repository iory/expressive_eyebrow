#ifndef _ROS_force_proximity_ros_ProximityStamped_h
#define _ROS_force_proximity_ros_ProximityStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "force_proximity_ros/Proximity.h"

namespace force_proximity_ros
{

  class ProximityStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef force_proximity_ros::Proximity _proximity_type;
      _proximity_type proximity;

    ProximityStamped():
      header(),
      proximity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->proximity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->proximity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "force_proximity_ros/ProximityStamped"; };
    virtual const char * getMD5() override { return "9fafbc0d999f1dfa74020a4d2b45b852"; };

  };

}
#endif
