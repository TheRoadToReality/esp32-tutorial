// #include <Arduino.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>

// // 定义串口引脚
// const int serialPin = 1;  // 根据实际情况修改

// // 定义任务句柄
// TaskHandle_t task1Handle, task2Handle;

// void task1(void *pvParameters) {
//     int value = 1;
//     while (1) {
//         Serial.print(value);
//         Serial.println();
//         vTaskDelay(pdMS_TO_TICKS(1000));  // 每秒发送一次
//         value += 3;
//     }
// }

// void task2(void *pvParameters) {
//     int value = 2;
//     while (1) {
//         Serial.print(value);
//         Serial.println();
//         vTaskDelay(pdMS_TO_TICKS(1000));  // 每秒发送一次
//         value += 1;
//     }
// }

// void setup() {
//     Serial.begin(115200);
    
//     // 创建任务
//     xTaskCreate(task1, "Task1", 10000, NULL, 1, &task1Handle);
//     xTaskCreate(task2, "Task2", 10000, NULL, 1, &task2Handle);
// }

// void loop() {
//     // 空循环，Arduino框架需要有loop函数
// }
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// 定义BLE服务和特征值的UUID
#define SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID "abcdef12-3456-7890-1234-56789abcdef0"

void setup() {
 Serial.begin(115200);

 BLEDevice::init("ESP32_BLE");
 BLEServer *pServer = BLEDevice::createServer();
 BLEService *pService = pServer->createService(SERVICE_UUID);
 BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                        CHARACTERISTIC_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_WRITE
                                      );

 pCharacteristic->setValue("Hello World");
 pService->start();
 BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
 pAdvertising->addServiceUUID(SERVICE_UUID);
 pAdvertising->setScanResponse(true);
 pAdvertising->setMinPreferred(0x06);  // 函数间隔，该值越小功耗越高
 pAdvertising->setMinPreferred(0x12);
 BLEDevice::startAdvertising();
 Serial.println("BLE服务已启动");
}

void loop() {
 // 这里不需要做任何事情
}