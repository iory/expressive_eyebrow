#ifndef _ROS_google_chat_ros_SendMessageAction_h
#define _ROS_google_chat_ros_SendMessageAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "google_chat_ros/SendMessageActionGoal.h"
#include "google_chat_ros/SendMessageActionResult.h"
#include "google_chat_ros/SendMessageActionFeedback.h"

namespace google_chat_ros
{

  class SendMessageAction : public ros::Msg
  {
    public:
      typedef google_chat_ros::SendMessageActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef google_chat_ros::SendMessageActionResult _action_result_type;
      _action_result_type action_result;
      typedef google_chat_ros::SendMessageActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    SendMessageAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "google_chat_ros/SendMessageAction"; };
    virtual const char * getMD5() override { return "206fe2fbaf1767bb5cb3d3e00067dacb"; };

  };

}
#endif
