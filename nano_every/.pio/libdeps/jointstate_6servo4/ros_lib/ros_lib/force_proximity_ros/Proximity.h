#ifndef _ROS_force_proximity_ros_Proximity_h
#define _ROS_force_proximity_ros_Proximity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace force_proximity_ros
{

  class Proximity : public ros::Msg
  {
    public:
      typedef uint32_t _proximity_type;
      _proximity_type proximity;
      typedef uint32_t _average_type;
      _average_type average;
      typedef int32_t _fa2_type;
      _fa2_type fa2;
      typedef int32_t _fa2derivative_type;
      _fa2derivative_type fa2derivative;
      typedef const char* _mode_type;
      _mode_type mode;

    Proximity():
      proximity(0),
      average(0),
      fa2(0),
      fa2derivative(0),
      mode("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->proximity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->proximity >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->proximity >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->proximity >> (8 * 3)) & 0xFF;
      offset += sizeof(this->proximity);
      *(outbuffer + offset + 0) = (this->average >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->average >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->average >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->average >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average);
      union {
        int32_t real;
        uint32_t base;
      } u_fa2;
      u_fa2.real = this->fa2;
      *(outbuffer + offset + 0) = (u_fa2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fa2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fa2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fa2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fa2);
      union {
        int32_t real;
        uint32_t base;
      } u_fa2derivative;
      u_fa2derivative.real = this->fa2derivative;
      *(outbuffer + offset + 0) = (u_fa2derivative.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fa2derivative.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fa2derivative.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fa2derivative.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fa2derivative);
      uint32_t length_mode = strlen(this->mode);
      varToArr(outbuffer + offset, length_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->mode, length_mode);
      offset += length_mode;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->proximity =  ((uint32_t) (*(inbuffer + offset)));
      this->proximity |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->proximity |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->proximity |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->proximity);
      this->average =  ((uint32_t) (*(inbuffer + offset)));
      this->average |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->average |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->average |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->average);
      union {
        int32_t real;
        uint32_t base;
      } u_fa2;
      u_fa2.base = 0;
      u_fa2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fa2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fa2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fa2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fa2 = u_fa2.real;
      offset += sizeof(this->fa2);
      union {
        int32_t real;
        uint32_t base;
      } u_fa2derivative;
      u_fa2derivative.base = 0;
      u_fa2derivative.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fa2derivative.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fa2derivative.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fa2derivative.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fa2derivative = u_fa2derivative.real;
      offset += sizeof(this->fa2derivative);
      uint32_t length_mode;
      arrToVar(length_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mode-1]=0;
      this->mode = (char *)(inbuffer + offset-1);
      offset += length_mode;
     return offset;
    }

    virtual const char * getType() override { return "force_proximity_ros/Proximity"; };
    virtual const char * getMD5() override { return "aa18090486be182d277600cdd5484a7e"; };

  };

}
#endif
