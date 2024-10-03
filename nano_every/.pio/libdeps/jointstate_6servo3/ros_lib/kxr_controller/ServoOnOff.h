#ifndef _ROS_kxr_controller_ServoOnOff_h
#define _ROS_kxr_controller_ServoOnOff_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kxr_controller
{

  class ServoOnOff : public ros::Msg
  {
    public:
      uint32_t servo_on_states_length;
      typedef bool _servo_on_states_type;
      _servo_on_states_type st_servo_on_states;
      _servo_on_states_type * servo_on_states;

    ServoOnOff():
      servo_on_states_length(0), st_servo_on_states(), servo_on_states(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->servo_on_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->servo_on_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->servo_on_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->servo_on_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->servo_on_states_length);
      for( uint32_t i = 0; i < servo_on_states_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_servo_on_statesi;
      u_servo_on_statesi.real = this->servo_on_states[i];
      *(outbuffer + offset + 0) = (u_servo_on_statesi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->servo_on_states[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t servo_on_states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      servo_on_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      servo_on_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      servo_on_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->servo_on_states_length);
      if(servo_on_states_lengthT > servo_on_states_length)
        this->servo_on_states = (bool*)realloc(this->servo_on_states, servo_on_states_lengthT * sizeof(bool));
      servo_on_states_length = servo_on_states_lengthT;
      for( uint32_t i = 0; i < servo_on_states_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_servo_on_states;
      u_st_servo_on_states.base = 0;
      u_st_servo_on_states.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_servo_on_states = u_st_servo_on_states.real;
      offset += sizeof(this->st_servo_on_states);
        memcpy( &(this->servo_on_states[i]), &(this->st_servo_on_states), sizeof(bool));
      }
     return offset;
    }

    virtual const char * getType() override { return "kxr_controller/ServoOnOff"; };
    virtual const char * getMD5() override { return "c5cbb0a39492ce70b1ce96c6e485e6e5"; };

  };

}
#endif
