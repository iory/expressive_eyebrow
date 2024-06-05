#include <Servo.h>  // サーボ制御のライブラリを読み込みます。

Servo servo1;  // 制御するサーボ名１～４を定義します。
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;


void setup() {
  servo1.attach(10);    // 7番ピンをサーボモーター1の制御ピンに設定
  servo2.attach(11);    // 8番ピンをサーボモーター2の制御ピンに設定
  servo3.attach(12);    // 9番ピンをサーボモーター3の制御ピンに設定
  servo4.attach(7);
  servo5.attach(8);
  servo6.attach(9);
}

void loop() {
  // normal
  set(100, 82, 57);

  // happy
  set(80, 90, 23);

  // sad
  //set(112, 76, 60);
  //set(112, 93, 47);
  set(105, 90, 25); 
  //set(112, 108, 35);

  // surprised
  set(79, 104, 25);

  // angry
  set(112, 108, 85);

}


void set(int angle1, int angle2, int angle3) {
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(212-angle1);
  servo5.write(184-angle2);
  servo6.write(183-angle3);
  delay(1000);
}
