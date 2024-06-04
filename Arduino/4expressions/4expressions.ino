#include <Servo.h>  // サーボ制御のライブラリを読み込みます。

Servo servo1;  // 制御するサーボ名１～４を定義します。
Servo servo2;
Servo servo3;
//Servo servo4;

void setup() {
  servo1.attach(7);
  servo2.attach(8); // ８番ピンの出力をサーボ制御用に宣言します。
  servo3.attach(9); // ９番ピン宣言。
  //servo3.attach(10); // １０番ピン宣言。
  //servo4.attach(11); // １１番ピン宣言。
}

void loop() {
  // normal
  set(106, 82, 57);

  // happy
  set(80, 90, 23);

  // sad
  //set(112, 76, 60);
  //set(112, 93, 47);
  set(112, 93, 25); 
  //set(112, 108, 35);

  // surprised
  set(79, 104, 25);

  // angry
  set(112, 108, 85);

}

//void walk(int angle1, int angle2, int angle3, int angle4) {
void set(int angle1, int angle2, int angle3) {
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  //servo3.write(angle3);
  //servo4.write(angle4);
  delay(3000);
}
