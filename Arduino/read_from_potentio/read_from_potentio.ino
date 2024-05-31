#include <Servo.h>

Servo servo1;  // サーボモーターを制御するためのオブジェクトを作成
int potPin = A0;  // ポテンショメータの接続ピン（アナログ入力）

void setup() {
   Serial.begin(9600);  // 9600bpsでシリアルポートを開く
   servo1.attach(7);    // 7番ピンをサーボモーターの制御ピンに設定
}

void loop() {
  int potValue = analogRead(potPin);  // ポテンショメータの値を読み取る
  int angle = map(potValue, 0, 1023, 0, 180);  // ポテンショメータの値を0〜180度にマッピング
  servo1.write(angle);  // サーボモーターの角度を設定

  // サーボモーターの角度をシリアルモニタに出力
  char s[80];
  sprintf(s, "servo1 angle = %d", angle);
  Serial.println(s);

  delay(100);  // 少し待機して次のループへ
}

