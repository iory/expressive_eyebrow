#include <Servo.h>

Servo servo1;  // サーボモーター1を制御するためのオブジェクト
Servo servo2;  // サーボモーター2を制御するためのオブジェクト
Servo servo3;  // サーボモーター3を制御するためのオブジェクト
Servo servo4;
Servo servo5;
Servo servo6;

int potPin = A0;  // ポテンショメータの接続ピン（アナログ入力）
int currentServo = 1;  // 現在制御中のサーボモーター
unsigned long previousMillis = 0;  // 前回の切り替え時間

const long interval = 10000;  // 切り替えの間隔（10秒）

void setup() {
  Serial.begin(9600);  // シリアルポートを9600bpsで開始
  servo1.attach(7);    // 7番ピンをサーボモーター1の制御ピンに設定
  servo2.attach(8);    // 8番ピンをサーボモーター2の制御ピンに設定
  servo3.attach(9);    // 9番ピンをサーボモーター3の制御ピンに設定
  servo4.attach(10);
  servo5.attach(11);
  servo6.attach(12);
}

void loop() {
  unsigned long currentMillis = millis();  // 現在の時間を取得

  // 10秒ごとに制御するサーボを切り替える
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    currentServo++;
   
    Serial.print("現在の制御対象サーボ: ");
    Serial.println(currentServo);
    
    if (currentServo > 3) {
      // 全てのサーボモーターを制御した後、無限ループに入りプログラムを停止
      while (true) {
        // 何もしない
      }
    }
  }

  // ポテンショメータの値を読み取り、サーボの角度に変換
  int potValue = analogRead(potPin);  // ポテンショメータの値を読み取る
  int angle = map(potValue, 0, 1023, 0, 180);  // ポテンショメータの値を0〜180度にマッピング

  // 現在の制御対象サーボに角度を設定
  switch (currentServo) {
    case 1:
      servo1.write(angle);
      servo4.write(212-angle);
      break;
    case 2:
      servo2.write(angle);
      servo5.write(184-angle);
      break;
    case 3:
      servo3.write(angle);
      servo6.write(180-angle);
      break;
  }

  // 現在のサーボの角度をシリアルモニタに出力
  Serial.print("サーボ");
  Serial.print(currentServo);
  Serial.print("の角度: ");
  Serial.println(angle);

  delay(100);  // 少し待機
}
