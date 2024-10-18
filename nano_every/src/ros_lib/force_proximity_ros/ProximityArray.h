#ifndef _ROS_force_proximity_ros_ProximityArray_h
#define _ROS_force_proximity_ros_ProximityArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "force_proximity_ros/Proximity.h"

namespace force_proximity_ros
{

  class ProximityArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t proximities_length;
      typedef force_proximity_ros::Proximity _proximities_type;
      _proximities_type st_proximities;
      _proximities_type * proximities;

    ProximityArray():
      header(),
      proximities_length(0), st_proximities(), proximities(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->proximities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->proximities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->proximities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->proximities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->proximities_length);
      for( uint32_t i = 0; i < proximities_length; i++){
      offset += this->proximities[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t proximities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      proximities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      proximities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      proximities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->proximities_length);
      if(proximities_lengthT > proximities_length)
        this->proximities = (force_proximity_ros::Proximity*)realloc(this->proximities, proximities_lengthT * sizeof(force_proximity_ros::Proximity));
      proximities_length = proximities_lengthT;
      for( uint32_t i = 0; i < proximities_length; i++){
      offset += this->st_proximities.deserialize(inbuffer + offset);
        memcpy( &(this->proximities[i]), &(this->st_proximities), sizeof(force_proximity_ros::Proximity));
      }
     return offset;
    }

    virtual const char * getType() override { return "force_proximity_ros/ProximityArray"; };
    virtual const char * getMD5() override { return "7876a44a9d6b13ed0837551cc918bda1"; };

  };

}
#endif
