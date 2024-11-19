#ifndef TUUSHIN_H
#define TUUSHIN_H

// 関数宣言
void setupReceiver();  // 受信の初期設定
void setupSender();    // 送信の初期設定
void sendPacket();     // CANメッセージの送信
void receivePacket();  // CANメッセージの受信

#endif
