#include <WiFi.h>
#include <Wire.h>
#include <WiFiUdp.h>
#include <time.h>

const char* ssid = "i2r";
const char* password = "00000000";
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 32400;  // 한국 시간대 (UTC+9)
const int daylightOffset_sec = 0;  // 한국은 일광 절약 시간제를 적용하지 않습니다.

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;     
const long interval = 1000;  
char msg[200];
WiFiUDP ntpUDP;

void bootWifiStation();
void doTick();
void setup();

const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  bootWifiStation();
}

void bootWifiStation() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  doTick();
}

void doTick() {
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)){
        Serial.println("시간을 얻는데 실패하였습니다");
        return;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  }
}
