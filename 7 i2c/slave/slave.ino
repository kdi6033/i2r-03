#include <Wire.h>

#define I2C_SLAVE_ADDR 0x01
#define SCL_PIN 22
#define SDA_PIN 21
String message = "";

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read();
    message += c;
  }
  Serial.print("Received: ");
  Serial.println(message);
  message="";
}

void requestEvent() {
  Wire.write("Hello, Master!");
}

void setup() {
  Wire.begin(I2C_SLAVE_ADDR);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(115200);
}

void loop() {
  delay(100);
}
