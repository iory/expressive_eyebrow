#include <Servo.h>  // サーボ制御のライブラリを読み込みます。

Servo servo1;  // 制御するサーボ名１～４を定義します。
Servo servo2;
//Servo servo3;
//Servo servo4;

void setup() {
  servo1.attach(11); // ８番ピンの出力をサーボ制御用に宣言します。
  servo2.attach(12); // ９番ピン宣言。
  //servo3.attach(10); // １０番ピン宣言。
  //servo4.attach(11); // １１番ピン宣言。
}

void loop() {
  // Step.0 又は Step.5「中立位置／重心を戻す」
  // 90度（ニュートラル）
  //walk(90, 90, 90, 90);
  walk(0, 0);
  // Step.1「左足に重心を乗せる」
  /*walk(
    90,
    90,
    75, // 時計回り（今回は-15度）
    70  // 少し多めの時計回り（今回は-20度）
  );

  // Step.2「右足を前に出す」
  walk(
    105, // 反時計回り（今回は15度）
    105, // 反時計回り
    75,
    70
  );

  // Step.3「右足に重心を乗せる」
  // （１）重心を中央へ
  walk(
    105,
    105,
    90, // 中立位置
    90  // 中立位置
  );
  // （２） 重心を右脚へ
  walk(
    105,
    105,
    110, // 少し多めの反時計回り（今回は+20度）
    105  // 反時計回り（今回は+15度）
  );

  // Step.4「左足を前に出す」
  walk(
    90, // 時計回り（基準位置へ戻す）
    90, // 時計回り（基準位置へ戻す）
    110,
    105
  );
  */
  // Step.5　はループの先頭に戻る 
  //walk(0,180);

}

//void walk(int angle1, int angle2, int angle3, int angle4) {
void walk(int angle1, int angle2) {
  servo1.write(angle1);
  servo2.write(angle2);
  //servo3.write(angle3);
  //servo4.write(angle4);
  delay(800);
}