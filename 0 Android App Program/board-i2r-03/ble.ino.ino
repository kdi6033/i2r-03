/* 블루투스 함수 ===============================================*/
// 받은 order의 리턴정보는 100을 더한다.
void writeToBle(int order) {
  // Create a JSON object
  DynamicJsonDocument responseDoc(1024);
  // Serialize JSON object to string
  String responseString;
  serializeJson(responseDoc, responseString);

  if(order == 0) {
    responseString = "프로그램 다운로드";
  }
  else if(order == 2) {
    responseString = dev.sendData;
  }
  else if (order == 101) {
    responseString = dev.sendData;
  }
  // Convert String to std::string to be able to send via BLE
  std::string response(responseString.c_str());

  // Send the JSON string over BLE
  if (pCharacteristic) {
    pCharacteristic->setValue(response);
    pCharacteristic->notify(); // If notification enabled
  }
}

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      wifi.isConnected = true; // Set the isConnected flag to true on connection
      Serial.println("Device connected");
      ble.isConnected = true;
      wifi.selectMqtt = false;
      event = 1;
    }

    void onDisconnect(BLEServer* pServer) {
      wifi.isConnected = false; // Set the isConnected flag to false on disconnection
      Serial.println("Device disconnected");
      ble.isConnected = false;
      wifi.selectMqtt = true;
      BLEDevice::startAdvertising();  // Start advertising again after disconnect
    }
};


// 전송된 문자를 받는다.
class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string value = pCharacteristic->getValue();
      if (value.length() > 0) {
        Serial.println("Received on BLE:");
        for (int i = 0; i < value.length(); i++) {
          Serial.print(value[i]);
        }
        Serial.println();
        // std::string을 byte*로 변환
        parseJSONPayload((byte*)value.c_str(),value.length());
      }
    }
};

void setupBLE() {
  BLEDevice::init("i2r-03-IoT PLC");
  BLEServer *pServer = BLEDevice::createServer();

  // Set server callbacks
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(ble.service_uuid);
  pCharacteristic = pService->createCharacteristic(
                                         ble.characteristic_uuid,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
  pCharacteristic->setValue(""); // 초기 값 설정
  pCharacteristic->setValue(std::string(200, ' ')); // 최대 길이를 200으로 설정

  pCharacteristic->setCallbacks(new MyCallbacks());
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(ble.service_uuid);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("BLE service started");
}

void readBleMacAddress() {
  // BLE 디바이스에서 MAC 주소를 가져옵니다.
  BLEAddress bleAddress = BLEDevice::getAddress();
  // MAC 주소를 String 타입으로 변환합니다.
  dev.mac = bleAddress.toString().c_str();
  // MAC 주소를 모두 대문자로 변환합니다.
  dev.mac.toUpperCase();
  // BLE MAC 주소를 기반으로 하는 MQTT 토픽 설정
  snprintf(wifi.outTopic, sizeof(wifi.outTopic), "i2r/EasyPLC/%s/out", dev.mac.c_str());
  snprintf(wifi.inTopic, sizeof(wifi.inTopic), "i2r/EasyPLC/%s/in", dev.mac.c_str());

  // 시리얼 모니터에 BLE MAC 주소 및 MQTT 토픽을 출력합니다.
  Serial.printf("BLE MAC Address: %s, Out Topic: %s, In Topic: %s\n", dev.mac.c_str(), wifi.outTopic, wifi.inTopic);
}

/* 블루투스 함수 ===============================================*/
