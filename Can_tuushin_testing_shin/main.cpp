#include <Arduino.h>
#include <CAN.h>
#include "tuushin.h"  // tuushin.hをインクルード

// setup関数: 初期設定を行う。CANバスの初期化と、送受信の設定を呼び出す
void setup() {
  Serial.begin(9600);  // シリアル通信開始
  while (!Serial);  // シリアル接続待機

  Serial.println("CAN Communication");

  // CANバスの初期化。500kbpsで動作を設定
  if (!CAN.begin(500E3)) {
    // CAN初期化に失敗した場合、エラーメッセージを表示して停止
    Serial.println("CANの初期化に失敗しました！");
    while (1);  // 永久ループで停止
  }

  // 受信と送信の初期化関数を呼び出し
  setupReceiver();
  setupSender();
}

// loop関数: 受信と送信を繰り返す
void loop() {
  // 受信処理を実行
  receivePacket();

  // 送信処理を実行
  sendPacket();

  delay(1000);  // 1秒の遅延
}
