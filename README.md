# i2r-03
WiFi Bluetooth PLC (4채널 릴레이, 온습도센서, ESP32) KC인증
![i2r-03-포트설명](https://github.com/kdi6033/i2r-03/assets/37902752/a6df72d2-0707-48f0-93b9-484a90149bba)
# 사양
- 정격전압 : 5V DC, 보드내에서는 5V로 설계했습니다.  
- 입력전압 : 7-30V DC Free Volt, 7-30V 사이 전압을 공급하면 레귤레이터에서 5V 로 전원을 공급합니다.  
- 작동온도 : -40 ℃ - 85 ℃  
- 입력 : 4개, com에 0V 또는 입력전압을 연결하고 입력 단자에 공급되는 전압에 따라 동작 합니다.  
- 출력 : 1개는 30A 250VAC/30VDC  
- 3개는 10A VAC, 10A VDC, 10A 125VAC, 10A 28VDC  
- 통신: WIFI 802.11 b / g / n (802.11n에서 최대 150Mbps) 및 Bluetooth 4.2 BR / EDR + BLE  
- 와이파이는 2.4G에 연결하세요. 5G는 동작하지 않습니다.  
- RS232 통신 : 보드내에 TTL Level의 rx, tx 단자가 있습니다.  
- 온습도 센서 : 모델 : AHT21, 습도 측정 범위: 0-100% RH, 온도 범위: -40 'C-120 'C, 습도 정확도 범위: 10% RH에서 95% RH, 습도 히스테리: ± 1% RH, 측정 시간: 50ms, 응답 시간: 5 초, 커뮤니케이션: I2C

# "Play 스토어" 에서 어플을 다운로드 하세요 프로그램 하지 않아도 원격으로 모니터링/제어 할 수 있습니다.  
그림을 크릭하세요  
[![Video Label]![21-3 안드로이드 어플 사용 블루투스 와이파이 MQTT 통신](https://github.com/kdi6033/i2r-03/assets/37902752/4d97b216-06a0-4601-bed9-37c0e841eae0)
(http://img.youtube.com/vi/59USvjy2toI/0.jpg)](https://youtu.be/FT0muFM24xc)
   
<iframe width="560" height="315" src="https://youtu.be/FT0muFM24xc" frameborder="0" allowfullscreen></iframe>

1) 4채널 릴레이  
4채널 릴레이가 탑재된 보드입니다. 릴레이 출력단에 A접점 B접점을 활용해 장치를 연결할 수 있습니다.
다양한 장치를 연결해서 손쉽게 원격제어 시스템을 구현해보세요. 모든 소스프로그램은 설명글 하단을 참조하세요.
릴레이에 연결된 ESP32핀은 왼쪽부터 각각 33 32 27 26 입니다.

2) AHT21 온습도 센서  
   ![AHT21 온습도 센서](https://github.com/kdi6033/i2r-03/assets/37902752/50d9bb01-52b8-4f5f-91c6-f7fc9e98609e)
3) WiFi, BLE 통신  
ESP32가 탑재되어 WiFi, BLE 통신 가능합니다. WiFi 를 활용해 PC 및 스마트폰에서 4채널 릴레이를
원격제어 및 모니터링 가능합니다. 또한 AHT20 온습도 센서의 정보를 실시간 모니터링할 수 있습니다.
BLE 를 활용해 근거리 제어가 가능합니다. IoT와 관련해 다양하게 활용 가능합니다.
