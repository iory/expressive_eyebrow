#include <Servo.h>
#include <ros.h>
#include <sensor_msgs/JointState.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

ros::NodeHandle nh;

void jointStateCallback(const sensor_msgs::JointState &msg) {
  // Assuming that msg.position is always of size 3 for our use case
  int angle1 = static_cast<int>(msg.position[0]); // Assume input is in degrees
  int angle2 = static_cast<int>(msg.position[1]); // Assume input is in degrees
  int angle3 = static_cast<int>(msg.position[2]); // Assume input is in degrees
    
  // Check if angles are within expected range
  if ((angle1 >= 83 && angle1 <= 124) && (angle2 >= 72 && angle2 <= 132) && (angle3 >= 0 && angle3 <= 180)) {
    Serial.print("Received joint_states: ");
    Serial.print(angle1);
    Serial.print(", ");
    Serial.print(angle2);
    Serial.print(", ");
    Serial.println(angle3);
    set(angle1, angle2, angle3);
  } else {
    Serial.println("Received out of range joint_states");
  }
}

ros::Subscriber<sensor_msgs::JointState> sub("joint_states", &jointStateCallback);

void setup() {
  servo1.attach(7);
  servo2.attach(8);
  servo3.attach(9);
  servo4.attach(10);
  servo5.attach(11);
  servo6.attach(12);

  nh.initNode();
  nh.getHardware()->setBaud(57600);
  nh.subscribe(sub);

  Serial.begin(57600); // Debugging output
}

void loop() {
  nh.spinOnce();
  delay(10);
}

void set(int angle1, int angle2, int angle3) {
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(212 - angle1);
  servo5.write(184 - angle2);
  servo6.write(174 - angle3);
}

