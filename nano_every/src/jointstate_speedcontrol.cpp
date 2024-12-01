#include <Arduino.h>
#include <Servo.h>
#include <ros.h>
#include <sensor_msgs/JointState.h>

// サーボオブジェクトの作成
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

ros::NodeHandle_<ArduinoHardware, 10, 10, 2048, 2048> nh;

float servo_now1 = 100;
float servo_now2 = 80;
float servo_now3 = 45;

int delay_time = 1500;

// サーボを指定された角度に移動させる関数
void moveServo(int angle1, int angle2, int angle3) {
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(227 - angle1);
  servo5.write(214 - angle2);
  servo6.write(179 - angle3);
}

// サーボを指定された角度に時間をかけて移動させる関数
void delayAndMoveServo(int delay_time, int angle1, int angle2, int angle3) {
  // 1回あたりの遅延時間を10ミリ秒に設定
  int steps = delay_time / 10;  // delay_time(ミリ秒) / 10ミリ秒
  float step_angle1 = ((float)angle1 - servo_now1) / steps;
  float step_angle2 = ((float)angle2 - servo_now2) / steps;
  float step_angle3 = ((float)angle3 - servo_now3) / steps;

  for (int i = 0; i < steps; i++) {
    servo_now1 += step_angle1;
    servo_now2 += step_angle2;
    servo_now3 += step_angle3;
    moveServo((int)servo_now1, (int)servo_now2, (int)servo_now3);
    delay(10);  // 10ミリ秒ごとに指令を送る
  }
}

// JointStateメッセージのコールバック関数
void jointStateCallback(const sensor_msgs::JointState &msg) {
  nh.loginfo("jointStateCallback called");

  if (msg.position_length >= 3) {
    int angle1 = static_cast<int>(msg.position[0]);
    int angle2 = static_cast<int>(msg.position[1]);
    int angle3 = static_cast<int>(msg.position[2]);

    if ((angle1 >= 83 && angle1 <= 124) && (angle2 >= 72 && angle2 <= 132) && (angle3 >= 0 && angle3 <= 180)) {
      delayAndMoveServo(delay_time, angle1, angle2, angle3);
    }
  } else {
    nh.loginfo("Insufficient data in position array.");
  }
  nh.loginfo("jointStateCallback end");
}

// ROSサブスクライバの設定
ros::Subscriber<sensor_msgs::JointState> sub("joint_states", &jointStateCallback);

// setup()関数
void setup() {
  // サーボのピンに接続
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(12);
  servo4.attach(10);
  servo5.attach(7);
  servo6.attach(11);

  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.subscribe(sub);

}

// loop()関数
void loop() {
  nh.spinOnce();
  delay(1);  // 1ミリ秒の遅延
}

