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
다운로드 QR CODE
<a href="https://play.google.com/store/apps/details?id=io.ionic.i2rReactIoT">
    <img src="https://github.com/kdi6033/i2r-03/assets/37902752/4f55641c-9a50-4eda-8ada-3e0f6beb34c6" alt="다운로드 QR코드" width="200">
</a>
</br>
스마트폰에 어플 설치와 와이파이 연결을 보여줍니다. 그림을 크릭하세요  

# 프로토콜
[i2r 프로토콜에 기술한 내용 참조](https://github.com/kdi6033/i2r/blob/main/README.md#프로토콜)

<br>

[아두이노 소스프로그램 링크](https://github.com/kdi6033/i2r-03/tree/main/0%20Android%20App%20Program/board-i2r-03)  

[스마트폰 ionic 소스프로그램 링크](https://github.com/kdi6033/i2r-03/tree/main/0%20Android%20App%20Program)  

[nodeRed 소스프로그램 링크](https://github.com/kdi6033/i2r-03/blob/main/0%20Android%20App%20Program/nodered/nodered.json)  

[![21-3 안드로이드 어플 사용 블루투스 와이파이 MQTT 통신](https://img.youtube.com/vi/FT0muFM24xc/0.jpg)](https://youtu.be/FT0muFM24xc)    

 1) 4채널 릴레이  
4채널 릴레이가 탑재된 보드입니다. 릴레이 출력단에 A접점 B접점을 활용해 장치를 연결할 수 있습니다.
다양한 장치를 연결해서 손쉽게 원격제어 시스템을 구현해보세요. 모든 소스프로그램은 설명글 하단을 참조하세요.
릴레이에 연결된 ESP32핀은 왼쪽부터 각각 33 32 27 26 입니다.

1) AHT21 온습도 센서   
   ![AHT21](https://github.com/user-attachments/assets/70008ecd-99a8-40aa-878d-b948978d42f0)   
   ![AHT21 온습도 센서](https://github.com/kdi6033/i2r-03/assets/37902752/50d9bb01-52b8-4f5f-91c6-f7fc9e98609e)   
3) WiFi, BLE 통신  
ESP32가 탑재되어 WiFi, BLE 통신 가능합니다. WiFi 를 활용해 PC 및 스마트폰에서 4채널 릴레이를
원격제어 및 모니터링 가능합니다. 또한 AHT20 온습도 센서의 정보를 실시간 모니터링할 수 있습니다.
BLE 를 활용해 근거리 제어가 가능합니다. IoT와 관련해 다양하게 활용 가능합니다.
<img width="682" alt="i2r-03-pin" src="https://github.com/kdi6033/i2r-03/assets/37902752/c558899e-9352-4e33-ac75-f2c6198489b3">
<img width="290" alt="i2r-03 pin연결" src="https://github.com/kdi6033/i2r-03/assets/37902752/c6b66e41-fdee-4c61-b97e-6b73f4b7d3a7">

# 입력확인 배선
![i2r-03-입력배선](https://github.com/kdi6033/i2r-03/blob/main/%EC%9E%90%EB%A3%8C/i2r-03%20input%20%EB%B0%B0%EC%84%A0.png?raw=true)

# Input Output 아두이노 프로그램
입력과 출력, 온도, 습도를 측정하는 아두이노 기본 프로그램  
[아두이노 소스프로그램 링크](https://github.com/kdi6033/i2r-03/tree/main/1%20input%20ouput/in-out)  
[![Input Output 아두이노 프로그램](https://img.youtube.com/vi/CTg_foy56oA/0.jpg)](https://youtu.be/CTg_foy56oA)]  

# MQTT 통신 연결하기
아두이노로 mqtt 통신을 연결한다.
ArduinoJson.h 를 사용해 데이터 처리방법을 설명한다.
IoT MQTT Panel을 이용해 스마트폰으로 보드의 Relay를 제어 한다.
이 프로그램을 이용해 인터넷 상에서 원격으로 입력과 출력을 제어 할 수 있습니다.
[![MQTT 통신 연결하기](https://img.youtube.com/vi/u4NejCu5xnw/0.jpg)](https://youtu.be/u4NejCu5xnw)]  

