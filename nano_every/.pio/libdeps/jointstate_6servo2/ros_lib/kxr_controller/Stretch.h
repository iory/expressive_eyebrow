#ifndef _ROS_kxr_controller_Stretch_h
#define _ROS_kxr_controller_Stretch_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kxr_controller
{

  class Stretch : public ros::Msg
  {
    public:
      uint32_t joint_names_length;
      typedef char* _joint_names_type;
      _joint_names_type st_joint_names;
      _joint_names_type * joint_names;
      uint32_t stretch_length;
      typedef int32_t _stretch_type;
      _stretch_type st_stretch;
      _stretch_type * stretch;

    Stretch():
      joint_names_length(0), st_joint_names(), joint_names(nullptr),
      stretch_length(0), st_stretch(), stretch(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      varToArr(outbuffer + offset, length_joint_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->stretch_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stretch_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stretch_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stretch_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stretch_length);
      for( uint32_t i = 0; i < stretch_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_stretchi;
      u_stretchi.real = this->stretch[i];
      *(outbuffer + offset + 0) = (u_stretchi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stretchi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stretchi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stretchi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stretch[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_names_length);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      joint_names_length = joint_names_lengthT;
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      arrToVar(length_st_joint_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint32_t stretch_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stretch_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stretch_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stretch_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stretch_length);
      if(stretch_lengthT > stretch_length)
        this->stretch = (int32_t*)realloc(this->stretch, stretch_lengthT * sizeof(int32_t));
      stretch_length = stretch_lengthT;
      for( uint32_t i = 0; i < stretch_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_stretch;
      u_st_stretch.base = 0;
      u_st_stretch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_stretch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_stretch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_stretch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_stretch = u_st_stretch.real;
      offset += sizeof(this->st_stretch);
        memcpy( &(this->stretch[i]), &(this->st_stretch), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "kxr_controller/Stretch"; };
    virtual const char * getMD5() override { return "9b2b730aeb11dca161b5a118a2171acb"; };

  };

}
#endif
