#ifndef _ROS_kxr_controller_PressureControl_h
#define _ROS_kxr_controller_PressureControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kxr_controller
{

  class PressureControl : public ros::Msg
  {
    public:
      typedef uint16_t _board_idx_type;
      _board_idx_type board_idx;
      typedef float _start_pressure_type;
      _start_pressure_type start_pressure;
      typedef float _stop_pressure_type;
      _stop_pressure_type stop_pressure;
      typedef bool _release_type;
      _release_type release;

    PressureControl():
      board_idx(0),
      start_pressure(0),
      stop_pressure(0),
      release(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->board_idx >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->board_idx >> (8 * 1)) & 0xFF;
      offset += sizeof(this->board_idx);
      union {
        float real;
        uint32_t base;
      } u_start_pressure;
      u_start_pressure.real = this->start_pressure;
      *(outbuffer + offset + 0) = (u_start_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_start_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_start_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_pressure);
      union {
        float real;
        uint32_t base;
      } u_stop_pressure;
      u_stop_pressure.real = this->stop_pressure;
      *(outbuffer + offset + 0) = (u_stop_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stop_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stop_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stop_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_pressure);
      union {
        bool real;
        uint8_t base;
      } u_release;
      u_release.real = this->release;
      *(outbuffer + offset + 0) = (u_release.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->release);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->board_idx =  ((uint16_t) (*(inbuffer + offset)));
      this->board_idx |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->board_idx);
      union {
        float real;
        uint32_t base;
      } u_start_pressure;
      u_start_pressure.base = 0;
      u_start_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_start_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_start_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->start_pressure = u_start_pressure.real;
      offset += sizeof(this->start_pressure);
      union {
        float real;
        uint32_t base;
      } u_stop_pressure;
      u_stop_pressure.base = 0;
      u_stop_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stop_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stop_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stop_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stop_pressure = u_stop_pressure.real;
      offset += sizeof(this->stop_pressure);
      union {
        bool real;
        uint8_t base;
      } u_release;
      u_release.base = 0;
      u_release.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->release = u_release.real;
      offset += sizeof(this->release);
     return offset;
    }

    virtual const char * getType() override { return "kxr_controller/PressureControl"; };
    virtual const char * getMD5() override { return "61bcf3809e7f0e409628cc484675109d"; };

  };

}
#endif
