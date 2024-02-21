#include <Arduino.h>
#include <esp_sleep.h>

void setup() {
  Serial.begin(115200);
  delay(1000); // 等待串口连接
  Serial.println("ESP32即将进入深度睡眠模式...");

  // 设置唤醒源为定时器，唤醒时间为10秒后
  esp_sleep_enable_timer_wakeup(10 * 1000000);
  esp_deep_sleep_start();
}

void loop() {
  // 在深度睡眠模式下，设备不执行loop()
}