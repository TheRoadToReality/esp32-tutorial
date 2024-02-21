#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// 定义串口引脚
const int serialPin = 1;  // 根据实际情况修改

// 定义任务句柄
TaskHandle_t task1Handle, task2Handle;

void task1(void *pvParameters) {
    int value = 1;
    while (1) {
        Serial.print(value);
        Serial.println();
        vTaskDelay(pdMS_TO_TICKS(1000));  // 每秒发送一次
        value += 3;
    }
}

void task2(void *pvParameters) {
    int value = 2;
    while (1) {
        Serial.print(value);
        Serial.println();
        vTaskDelay(pdMS_TO_TICKS(1000));  // 每秒发送一次
        value += 1;
    }
}

void setup() {
    Serial.begin(115200);
    
    // 创建任务
    xTaskCreate(task1, "Task1", 10000, NULL, 1, &task1Handle);
    xTaskCreate(task2, "Task2", 10000, NULL, 1, &task2Handle);
}

void loop() {
    // 空循环，Arduino框架需要有loop函数
}
