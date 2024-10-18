#include <Servo.h>  // サーボ制御のライブラリを読み込みます。

Servo servo1;  // 制御するサーボ名１～４を定義します。
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;


void setup() {
  servo1.attach(9);    // 7番ピンをサーボモーター1の制御ピンに設定
  servo2.attach(8);    // 8番ピンをサーボモーター2の制御ピンに設定
  servo3.attach(12);    // 9番ピンをサーボモーター3の制御ピンに設定
  servo4.attach(10);
  servo5.attach(7);
  servo6.attach(11);
}

void loop() {
  /* servo2 should be 83~124, servo1 should be 72~132*/
  // normal
  set(100, 80, 45);

  

  // happy
  //set(80, 90, 20);
  set(80, 90, 15);
  

  // sad
  //set(112, 76, 60);
  //set(112, 93, 47);
  //set(105, 90, 25); 
  set(120, 130, 10);
  //set(115, 110, 10);
  //set(112, 108, 35);

  // surprised
  //set(79, 104, 45);
  set(80, 90, 30);
  //set(110, 120, 30);

  

  // angry
  set(115, 110, 85);
  //set(80, 90, 80);
  //set(120, 130, 90);

}


void set(int angle1, int angle2, int angle3) {
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(207-angle1);
  servo5.write(199-angle2);
  servo6.write(174-angle3);
  delay(1000);
}
