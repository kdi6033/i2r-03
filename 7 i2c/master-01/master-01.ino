#include <Wire.h>
#include <Adafruit_AHTX0.h>

#define I2C_SLAVE_ADDR 0x01
#define SCL_PIN 22
#define SDA_PIN 21

Adafruit_AHTX0 aht;

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.begin(115200);

  // AHT10 센서 초기화
  if (!aht.begin()) {
    Serial.println("Failed to find AHT10/AHT20 chip");
    while (1) { delay(10); }
  }
  Serial.println("AHT10/AHT20 found");
}

void loop() {
  // 온도 및 습도 측정
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.print(" degrees C, Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println("%");

  Wire.beginTransmission(I2C_SLAVE_ADDR);
  Wire.write("Hello, Slave!");
  Wire.endTransmission();
  delay(1000);

  Wire.requestFrom(I2C_SLAVE_ADDR, 13); //슬레이브(1)에 13byte 요청
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
  delay(1000);
}
