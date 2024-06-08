#include <Servo.h>  // サーボ制御のライブラリを読み込みます。
#include <ros.h>
#include <std_msgs/Int32MultiArray.h>

Servo servo1;  // 制御するサーボ名１～６を定義します。
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

ros::NodeHandle nh;

// Define the callback function to handle incoming messages
void eyebrowAngleCallback(const std_msgs::Int32MultiArray &msg) {
  if (msg.data_length == 3) {
    int angle1 = msg.data[0];
    int angle2 = msg.data[1];
    int angle3 = msg.data[2];
    /*Serial.print("Received eyebrow_angle: ");
    Serial.print(angle1);
    Serial.print(", ");
    Serial.print(angle2);
    Serial.print(", ");
    Serial.println(angle3);*/  //ターミナル側に出すべき
    if (angle1 < 83 || angle1 > 124 || angle2 < 72 || angle2 > 132){
      //Serial.print("inappropriate angle!");  //ターミナル側に出すべき
    }else{
      set(angle1, angle2, angle3);
    }
  }
}

// Create a subscriber object
ros::Subscriber<std_msgs::Int32MultiArray> sub("eyebrow_angle", &eyebrowAngleCallback);

void setup() {
  servo1.attach(7);    // 7番ピンをサーボモーター1の制御ピンに設定
  servo2.attach(8);    // 8番ピンをサーボモーター2の制御ピンに設定
  servo3.attach(9);    // 9番ピンをサーボモーター3の制御ピンに設定
  servo4.attach(10);
  servo5.attach(11);
  servo6.attach(12);

  nh.initNode();
  nh.getHardware()->setBaud(57600);
  nh.subscribe(sub);
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
  delay(1000);
}

