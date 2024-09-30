// #include <Arduino.h>
// #include <Servo.h>  // サーボ制御のライブラリを読み込みます。

// Servo servo1;  // 制御するサーボ名１～４を定義します。
// Servo servo2;
// Servo servo3;
// Servo servo4;
// Servo servo5;
// Servo servo6;


// void set(int angle1, int angle2, int angle3) {
//   servo1.write(angle1);
//   servo2.write(angle2);
//   servo3.write(angle3);
//   servo4.write(212-angle1);
//   servo5.write(184-angle2);
//   servo6.write(174-angle3);
//   delay(1000);
// }


// void setup() {
//   servo1.attach(7);    // 7番ピンをサーボモーター1の制御ピンに設定
//   servo2.attach(8);    // 8番ピンをサーボモーター2の制御ピンに設定
//   servo3.attach(9);    // 9番ピンをサーボモーター3の制御ピンに設定
//   servo4.attach(10);
//   servo5.attach(11);
//   servo6.attach(12);
// }

// void loop() {
//   /* servo2 should be 83~124, servo1 should be 72~132*/
//   // normal
//   set(100, 80, 45);



//   // happy
//   //set(80, 90, 20);
//   set(80, 90, 15);


//   // sad
//   //set(112, 76, 60);
//   //set(112, 93, 47);
//   //set(105, 90, 25);
//   set(120, 130, 10);
//   //set(115, 110, 10);
//   //set(112, 108, 35);

//   // surprised
//   //set(79, 104, 45);
//   set(80, 90, 30);
//   //set(110, 120, 30);



//   // angry
//   set(115, 110, 85);
//   //set(80, 90, 80);
//   //set(120, 130, 90);

// }


#include <Arduino.h>
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

void set(int angle1, int angle2, int angle3) {
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(212 - angle1);
  servo5.write(184 - angle2);
  servo6.write(174 - angle3);

}


void jointStateCallback(const sensor_msgs::JointState &msg) {
  // Assuming that msg.position is always of size 3 for our use case
  int angle1 = static_cast<int>(msg.position[0]); // Assume input is in degrees
  int angle2 = static_cast<int>(msg.position[1]); // Assume input is in degrees
  int angle3 = static_cast<int>(msg.position[2]); // Assume input is in degrees

  // Check if angles are within expected range
  if ((angle1 >= 83 && angle1 <= 124) && (angle2 >= 72 && angle2 <= 132) && (angle3 >= 0 && angle3 <= 180)) {
    set(angle1, angle2, angle3);
  } else {
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

  nh.getHardware()->setBaud(57600);
  nh.initNode();
  nh.subscribe(sub);

  Serial.begin(57600); // Debugging output
}

void loop() {
  nh.spinOnce();
  delay(10);
}
