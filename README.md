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

[아두이노 소스프로그램 링크](https://github.com/kdi6033/i2r-03/tree/main/0%20Source-Program-IoT/board-i2r-03)  

[AWS 아두이노 소스프로그램 링크](https://github.com/kdi6033/i2r-03/tree/main/0%20Source-Program-IoT/board-i2r-03-aws)  

[nodeRed 소스프로그램 링크](https://github.com/kdi6033/i2r/blob/main/0%20Source-Program-IOT/nodered-local.json)  

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

# CrowPanel Pico Display 3.5" HMI 모듈

[📌 판넬 사양은 다음 링크를 참조하세요](https://github.com/kdi6033/i2r#crowpanel-pico-display-35-hmi-%EB%AA%A8%EB%93%88)

[📥 i2r-03 보드 HMI 프로그램 다운로드](https://github.com/kdi6033/download/raw/main/i2r03/hmi-i2r03.zip)

<br>     
<details>
    <summary>💻 HMI 터치판넬 프로그램 </summary>

```c
// ✅ 여기에 C 코드 작성
//원본 2025.11.20
//on 연두색 0x32CD32 : off 회색 0xC0C0C0
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <Wire.h>
#include <ArduinoJson.h>
#include "lv_qrcode.hpp"
#include "qrcodegen.hpp"
#include "NotoSansKR_20.h"
#include "hardware/watchdog.h"

unsigned long lastSerialTime = 0;        // 마지막으로 Serial1 데이터를 받은 시각
const unsigned long serialTimeoutMs = 7000;  // 7초

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

// ★ 추가: on/off 공통 색상 매크로
#define onColor  lv_color_hex(0x32CD32)
#define offColor lv_color_hex(0xC0C0C0)

TFT_eSPI tft = TFT_eSPI();
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[SCREEN_WIDTH * SCREEN_HEIGHT / 10];

lv_obj_t* btn[4];
bool btnState[4] = {false};
lv_obj_t* in_led[4];   // 🔹 입력 상태 LED 4개 추가
String serialBuffer = "";

lv_obj_t* ssid_ta;
lv_obj_t* pw_ta;
lv_obj_t* email_ta;
lv_obj_t* connect_btn;  // ✅ 전역 선언
lv_obj_t* mqtt_ta;      // ✅ mqtt 입력도 전역 선언 가능
lv_obj_t* tab2; // ✅ 전역으로 이동
lv_obj_t* tab3; // 사용자 메뉴얼 탭
lv_obj_t* manual_btn;  // "사용법 보기" 버튼
lv_obj_t* qr_panel;    // QR 패널
lv_obj_t* bt_btn;   // ✅ 블루투스 버튼
lv_obj_t* fw_btn;   // ✅ 펌웨어 다운로드 버튼

lv_obj_t* wifi_icon;  // 와이파이 아이콘을 전역으로 선언
lv_obj_t* mqtt_icon; 
// ✅ 추가: 온도/습도 라벨
lv_obj_t* temp_label;
lv_obj_t* humi_label;

void send_bleboot() {
  JsonDocument doc;
  doc["c"] = "ti";
  doc["bleboot"] = 1;
  String json;
  serializeJson(doc, json);
  Serial1.println(json);
  Serial.println("[SEND] " + json);
}

void updateInputLedUI(uint8_t index, bool state) {
  if (index >= 4) return;
  lv_obj_set_style_bg_color(
    in_led[index],
    state ? onColor : offColor,  // 버튼과 같은 색
    LV_PART_MAIN
  );
}

void my_disp_flush(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p) {
  uint32_t w = area->x2 - area->x1 + 1;
  uint32_t h = area->y2 - area->y1 + 1;
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t*)&color_p->full, w * h, true);
  tft.endWrite();
  lv_disp_flush_ready(disp);
}

uint16_t touchX, touchY;
void my_touchpad_read(lv_indev_drv_t* indev_driver, lv_indev_data_t* data) {
  bool touched = tft.getTouch(&touchX, &touchY, 600);
  data->state = touched ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
  if (touched) {
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

void sendToggleCommand(uint8_t btnIndex, bool state) {
  JsonDocument doc;
  doc["c"] = "so";
  doc["n"] = btnIndex;
  doc["v"] = state ? 1 : 0;  // ✅ 0과 1로 명시적으로 전송
  String json;
  serializeJson(doc, json);
  Serial1.println(json);
  Serial.println("[SEND-toggle] " + json);
}

void updateButtonUI(uint8_t index, bool state) {
  //lv_obj_set_style_bg_color(btn[index], state ? lv_color_hex(0x32CD32) : lv_color_hex(0xC0C0C0), LV_PART_MAIN);
  lv_obj_set_style_bg_color(btn[index], state ? onColor : offColor, LV_PART_MAIN);
  lv_label_set_text(lv_obj_get_child(btn[index], 0), state ? "ON" : "OFF");
  lv_obj_center(lv_obj_get_child(btn[index], 0));
}

void btn_event_cb(lv_event_t* e) {
  uint8_t index = (uint32_t)lv_event_get_user_data(e);
  btnState[index] = !btnState[index];
  updateButtonUI(index, btnState[index]);
  sendToggleCommand(index, btnState[index]);
}

void add_footer_label(lv_obj_t* parent) {
  lv_obj_t* footer = lv_label_create(parent);
  lv_label_set_text(footer, "아이티알   http://i2r.link");
  lv_obj_set_style_text_font(footer, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_set_style_text_color(footer, lv_color_hex(0xF37A2D), LV_PART_MAIN);
  lv_obj_align(footer, LV_ALIGN_BOTTOM_RIGHT, -10, -10);
}

void create_tabs() {
  lv_obj_t* tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 50);
  lv_obj_set_style_text_font(lv_tabview_get_tab_btns(tabview), &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_t* tab1 = lv_tabview_add_tab(tabview, "제어판");
  tab2 = lv_tabview_add_tab(tabview, "크라우드연결");
  tab3 = lv_tabview_add_tab(tabview, "사용자 메뉴얼");
  //lv_obj_t* tab3 = lv_tabview_add_tab(tabview, "사용자 메뉴얼");

  // tab1 프로그램  ============================================================
  // 🔹 1) 입력 LED 4개 생성 (버튼 위에 위치)
  for (int i = 0; i < 4; i++) {
    in_led[i] = lv_obj_create(tab1);
    lv_obj_set_size(in_led[i], 40, 40);  // LED 크기
    // ✅ 원형 LED로 변경
    lv_obj_set_style_radius(in_led[i], LV_RADIUS_CIRCLE, LV_PART_MAIN);

    int xOffset = (i - 1.5) * 110;       // 버튼과 같은 X 배치 기준
    int yOffset = -150;                  // 버튼보다 더 위쪽에 배치
    //int yOffset = -120;                  // 버튼보다 더 위쪽에 배치
    lv_obj_align(in_led[i], LV_ALIGN_BOTTOM_MID, xOffset, yOffset);

    // 기본 색상: OFF (회색)
    lv_obj_set_style_bg_color(in_led[i], offColor, LV_PART_MAIN);
    lv_obj_set_style_border_width(in_led[i], 0, LV_PART_MAIN);

    // ✅ 여기부터 추가: LED 위에 0,1,2,3 글씨 표시
    lv_obj_t* led_label = lv_label_create(tab1);
    char text[2];
    snprintf(text, sizeof(text), "%d", i);        // "0", "1", "2", "3"
    lv_label_set_text(led_label, text);
    lv_obj_set_style_text_font(led_label, &NotoSansKR_20, LV_PART_MAIN);
    // ★ 글자 색상 파란색 적용
    lv_obj_set_style_text_color(led_label, lv_color_hex(0x007FFF), LV_PART_MAIN);
    // LED 기준으로 위쪽에 정렬
    lv_obj_align_to(led_label, in_led[i], LV_ALIGN_OUT_TOP_MID, 0, -5);
  }

  // 🔹 2) 버튼 4개 생성 (아래쪽 중앙에 가로로 배치)
  for (int i = 0; i < 4; i++) {   // 🔁 8 → 4
    btn[i] = lv_btn_create(tab1);
    lv_obj_set_size(btn[i], 100, 60);

    // 아래쪽 중앙 기준으로 가로로 나열
    int xOffset = (i - 1.5) * 110;  // -165, -55, 55, 165 정도 위치
    int yOffset = -70;              // 화면 아래에서 조금 위

    lv_obj_align(btn[i], LV_ALIGN_BOTTOM_MID, xOffset, yOffset);
    lv_obj_add_event_cb(btn[i], btn_event_cb, LV_EVENT_CLICKED, (void*)(uintptr_t)i);
    lv_obj_set_style_bg_color(btn[i], offColor, LV_PART_MAIN);

    lv_obj_t* label = lv_label_create(btn[i]);
    lv_label_set_text(label, "OFF");
    lv_obj_center(label);
  }

  // 와이파이 아이콘 추가
  wifi_icon = lv_label_create(tab1);
  lv_label_set_text(wifi_icon, LV_SYMBOL_WIFI);  // 와이파이 아이콘 lvgl 내장 아이콘
  lv_obj_set_style_text_font(wifi_icon, &lv_font_montserrat_20, LV_PART_MAIN); 
  lv_obj_set_style_text_color(wifi_icon, offColor, LV_PART_MAIN);  // 연두색으로 설정
  lv_obj_align(wifi_icon, LV_ALIGN_BOTTOM_LEFT, 20, -10);  // 아이콘 위치 조정

  //mqtt 아이콘
  mqtt_icon = lv_label_create(tab1);
  lv_label_set_text(mqtt_icon, LV_SYMBOL_REFRESH);  // 연결 아이콘
  lv_obj_set_style_text_font(mqtt_icon, &lv_font_montserrat_20, LV_PART_MAIN);  // 폰트 설정
  lv_obj_set_style_text_color(mqtt_icon, offColor, LV_PART_MAIN); 
  lv_obj_align(mqtt_icon, LV_ALIGN_BOTTOM_LEFT, 70, -10);  // 아이콘 위치 조정

  // ✅ 추가: 온도 라벨 (mqtt 아이콘 오른쪽)
  temp_label = lv_label_create(tab1);
  lv_label_set_text(temp_label, "온도: --.-°C");
  lv_obj_set_style_text_font(temp_label, &NotoSansKR_20, LV_PART_MAIN);
  //lv_obj_set_style_text_color(temp_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
  lv_obj_set_style_text_color(temp_label, lv_color_hex(0x007FFF), LV_PART_MAIN);
  lv_obj_align(temp_label, LV_ALIGN_BOTTOM_RIGHT, -120, -10); 

  // ✅ 추가: 습도 라벨 (온도 라벨 오른쪽)
  humi_label = lv_label_create(tab1);
  lv_label_set_text(humi_label, "습도: ---%");
  lv_obj_set_style_text_font(humi_label, &NotoSansKR_20, LV_PART_MAIN);
  //lv_obj_set_style_text_color(humi_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
  lv_obj_set_style_text_color(humi_label, lv_color_hex(0x007FFF), LV_PART_MAIN);
  //lv_obj_align_to(humi_label, temp_label, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
  lv_obj_align(humi_label, LV_ALIGN_BOTTOM_RIGHT, -10, -10); 

  //add_footer_label(tab1);

  // tab2 프로그램
  lv_obj_set_style_bg_color(tab2, lv_color_black(), LV_PART_MAIN);
  lv_obj_t* label2 = lv_label_create(tab2);
  lv_label_set_text(label2, "다음 정보를 입력하세요");
  lv_obj_set_style_text_font(label2, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_set_style_text_color(label2, lv_color_hex(0xA0A0A0), LV_PART_MAIN);
  lv_obj_align(label2, LV_ALIGN_TOP_MID, 0, 95);

  // ░▒▓ 박스 1: 와이파이 정보 ▓▒░
  lv_obj_t* wifi_row = lv_obj_create(tab2);
  lv_obj_set_size(wifi_row, 450, 100);
  lv_obj_set_pos(wifi_row, 10, -20);
  lv_obj_set_flex_flow(wifi_row, LV_FLEX_FLOW_ROW);
  lv_obj_set_style_bg_opa(wifi_row, LV_OPA_TRANSP, 0);
  lv_obj_set_style_border_width(wifi_row, 0, 0);
  lv_obj_set_style_pad_gap(wifi_row, 10, 0);

  ssid_ta = lv_textarea_create(wifi_row);
  lv_obj_set_width(ssid_ta, 200);
  lv_textarea_set_one_line(ssid_ta, true);
  lv_textarea_set_placeholder_text(ssid_ta, "와이파이 이름");
  lv_obj_set_style_text_font(ssid_ta, &NotoSansKR_20, LV_PART_MAIN);

  pw_ta = lv_textarea_create(wifi_row);
  lv_obj_set_width(pw_ta, 200);
  lv_textarea_set_one_line(pw_ta, true);
  lv_textarea_set_password_mode(pw_ta, true);
  lv_textarea_set_placeholder_text(pw_ta, "와이파이 비밀번호");
  lv_obj_set_style_text_font(pw_ta, &NotoSansKR_20, LV_PART_MAIN);

  // ░▒▓ 박스 2: 이메일 + MQTT ▓▒░
  lv_obj_t* email_row = lv_obj_create(tab2);
  lv_obj_set_size(email_row, 450, 60);
  lv_obj_set_pos(email_row, 10, 30);
  lv_obj_set_flex_flow(email_row, LV_FLEX_FLOW_ROW);
  lv_obj_set_style_bg_opa(email_row, LV_OPA_TRANSP, 0);
  lv_obj_set_style_border_width(email_row, 0, 0);
  lv_obj_set_style_pad_gap(email_row, 10, 0);

  email_ta = lv_textarea_create(email_row);
  lv_obj_set_width(email_ta, 200);
  lv_textarea_set_one_line(email_ta, true);
  lv_textarea_set_placeholder_text(email_ta, "이메일");
  lv_obj_set_style_text_font(email_ta, &NotoSansKR_20, LV_PART_MAIN);

  mqtt_ta = lv_textarea_create(email_row);
  lv_obj_set_width(mqtt_ta, 200);
  lv_textarea_set_one_line(mqtt_ta, true);
  lv_textarea_set_placeholder_text(mqtt_ta, "MQTT 주소");
  lv_textarea_set_text(mqtt_ta, "mqtt.i2r.link");  // ✅ 기본값 설정
  lv_obj_set_style_text_font(mqtt_ta, &NotoSansKR_20, LV_PART_MAIN);

  // 키보드
  lv_obj_t* kb = lv_keyboard_create(tab2);
  lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
  lv_obj_set_size(kb, 480, 120);
  lv_obj_align(kb, LV_ALIGN_BOTTOM_MID, 0, 0);

  // 키보드 이벤트
  auto kb_event_cb = [](lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* ta = lv_event_get_target(e);
    lv_obj_t* kb = (lv_obj_t*)lv_event_get_user_data(e);
    if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED) {
      lv_keyboard_set_textarea(kb, ta);
      lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(connect_btn, LV_OBJ_FLAG_HIDDEN);  // ✅ 버튼 숨김
    }
  };

  lv_obj_add_event_cb(ssid_ta, kb_event_cb, LV_EVENT_ALL, kb);
  lv_obj_add_event_cb(pw_ta, kb_event_cb, LV_EVENT_ALL, kb);
  lv_obj_add_event_cb(email_ta, kb_event_cb, LV_EVENT_ALL, kb);
  lv_obj_add_event_cb(mqtt_ta, kb_event_cb, LV_EVENT_ALL, kb);

  // manual_btn도 숨김 처리
  auto kb_event_cb_with_manual = [](lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* ta = lv_event_get_target(e);
    lv_obj_t* kb = (lv_obj_t*)lv_event_get_user_data(e);
    if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED) {
      lv_keyboard_set_textarea(kb, ta);
      lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(connect_btn, LV_OBJ_FLAG_HIDDEN);  // 연결 버튼 숨김
      lv_obj_add_flag(manual_btn, LV_OBJ_FLAG_HIDDEN);   // ✅ 사용법 버튼도 숨김
      if (bt_btn) lv_obj_add_flag(bt_btn, LV_OBJ_FLAG_HIDDEN);   // ✅ 추가
      if (fw_btn) lv_obj_add_flag(fw_btn, LV_OBJ_FLAG_HIDDEN);   // ✅ 추가
    }
  };
  lv_obj_add_event_cb(ssid_ta, kb_event_cb_with_manual, LV_EVENT_ALL, kb);
  lv_obj_add_event_cb(pw_ta, kb_event_cb_with_manual, LV_EVENT_ALL, kb);
  lv_obj_add_event_cb(email_ta, kb_event_cb_with_manual, LV_EVENT_ALL, kb);
  lv_obj_add_event_cb(mqtt_ta, kb_event_cb_with_manual, LV_EVENT_ALL, kb);

  lv_obj_add_event_cb(kb, [](lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* kb = lv_event_get_target(e);
    if (code == LV_EVENT_CANCEL || code == LV_EVENT_READY) {
      lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
      lv_keyboard_set_textarea(kb, NULL);
      lv_obj_clear_flag(connect_btn, LV_OBJ_FLAG_HIDDEN);  // ✅ 버튼 다시 표시
      lv_obj_clear_flag(manual_btn, LV_OBJ_FLAG_HIDDEN);   // ✅ 사용법 버튼도 다시 표시
      if (bt_btn) lv_obj_clear_flag(bt_btn, LV_OBJ_FLAG_HIDDEN); // ✅ 추가
      if (fw_btn) lv_obj_clear_flag(fw_btn, LV_OBJ_FLAG_HIDDEN); // ✅ 추가
    }
  }, LV_EVENT_ALL, NULL);

  // 연결 버튼
  connect_btn = lv_btn_create(tab2);
  lv_obj_set_size(connect_btn, 120, 40);
  lv_obj_align(connect_btn, LV_ALIGN_BOTTOM_MID, 0, -60);
  lv_obj_t* btn_label = lv_label_create(connect_btn);
  lv_label_set_text(btn_label, "연결");
  lv_obj_set_style_text_font(btn_label, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_center(btn_label);

  lv_obj_add_event_cb(connect_btn, [](lv_event_t* e) {
    const char* email = lv_textarea_get_text(email_ta);
    const char* ssid = lv_textarea_get_text(ssid_ta);
    const char* password = lv_textarea_get_text(pw_ta);
    const char* mqtt = lv_textarea_get_text(mqtt_ta);  // ✅ 추가
    JsonDocument doc;
    doc["c"] = "si";
    doc["e"] = email;
    doc["ssid"] = ssid;
    doc["password"] = password;
    doc["mqttBroker"] = mqtt;  // ✅ 추가
    String json;
    serializeJson(doc, json);
    Serial1.println(json);
    //Serial.println("[SEND] " + json);
  }, LV_EVENT_CLICKED, NULL);

  // "사용법 보기" 버튼 추가
  manual_btn = lv_btn_create(tab2);
  lv_obj_set_size(manual_btn, 120, 40);
  lv_obj_align(manual_btn, LV_ALIGN_BOTTOM_MID, -140, -10);  // "연결" 왼쪽에 위치
  lv_obj_t* manual_label = lv_label_create(manual_btn);
  lv_label_set_text(manual_label, "사용법 보기");
  lv_obj_set_style_text_font(manual_label, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_center(manual_label);

  //"사용법 보기" 버튼 이벤트 연결
  lv_obj_add_event_cb(manual_btn, [](lv_event_t* e) {
    show_qr_panel("https://youtu.be/eMnKAh1EjlE", tab2);  // ✅ 통합 함수 호출
  }, LV_EVENT_CLICKED, NULL);

  // Bluetooth 버튼 (연결 버튼 오른쪽)
  bt_btn = lv_btn_create(tab2);
  lv_obj_set_size(bt_btn, 120, 40);
  lv_obj_align(bt_btn, LV_ALIGN_BOTTOM_MID, 140, -10);  // ✅ 오른쪽에 배치
  lv_obj_t* bt_label = lv_label_create(bt_btn);
  lv_label_set_text(bt_label, "블루투스");
  lv_obj_set_style_text_font(bt_label, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_center(bt_label);

  // 클릭 시 bleboot 패킷 전송
  lv_obj_add_event_cb(bt_btn, [](lv_event_t* e) {
    send_bleboot();     // ✅ { "c":"ti", "bleboot": 1 } 전송
  }, LV_EVENT_CLICKED, NULL);

  // ⚙️ "Firmware Download" 버튼 (연결 버튼 위에 배치)
  fw_btn = lv_btn_create(tab2);
  lv_obj_set_size(fw_btn, 120, 40);
  lv_obj_align(fw_btn, LV_ALIGN_BOTTOM_MID, 0, -10);  // ✅ "연결"(-10) 위로 50px 정도 위
  lv_obj_t* fw_label = lv_label_create(fw_btn);
  lv_label_set_text(fw_label, "펌웨어설치");
  lv_obj_set_style_text_font(fw_label, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_center(fw_label);

  // 클릭 시 {"c":"df","f":"i2r-03-hmi.ino.bin"} 전송
  lv_obj_add_event_cb(fw_btn, [](lv_event_t* e) {
    JsonDocument doc;
    doc["c"] = "df";
    doc["f"] = "i2r-03-hmi.ino.bin";
    String json;
    serializeJson(doc, json);
    Serial1.println(json);
    //Serial.println("[SEND] " + json);
  }, LV_EVENT_CLICKED, NULL);

  //tab3 작성
  // "크라우드 로그인" 라벨
  lv_obj_t* cloud_link_label = lv_label_create(tab3);
  lv_label_set_text(cloud_link_label, "기기연결, 크라우드 로그인");
  lv_obj_set_style_text_font(cloud_link_label, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_set_style_text_color(cloud_link_label, lv_color_hex(0x007FFF), LV_PART_MAIN);
  lv_obj_align(cloud_link_label, LV_ALIGN_TOP_LEFT, 0, 10);
  lv_obj_add_flag(cloud_link_label, LV_OBJ_FLAG_CLICKABLE);  // ✅ 이벤트 처리
  // ""기기연결, 크라우드 로그인" 라벨 이벤트
  lv_obj_add_event_cb(cloud_link_label, [](lv_event_t* e) {
    show_qr_panel("https://youtu.be/o17IrUawetg", tab3);
  }, LV_EVENT_CLICKED, NULL);

  // "타이머 설정" 라벨 추가
  lv_obj_t* app_link_label1 = lv_label_create(tab3);
  lv_label_set_text(app_link_label1, "타이머 설정");
  lv_obj_set_style_text_font(app_link_label1, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_set_style_text_color(app_link_label1, lv_color_hex(0x007FFF), LV_PART_MAIN);
  lv_obj_align(app_link_label1, LV_ALIGN_TOP_LEFT, 0, 50);
  lv_obj_add_flag(app_link_label1, LV_OBJ_FLAG_CLICKABLE);
  // "타이머 설정" Play Store QR 표시
  lv_obj_add_event_cb(app_link_label1, [](lv_event_t* e) {
    show_qr_panel("https://youtu.be/hlbH4OiEDu4", tab3);
  }, LV_EVENT_CLICKED, NULL);

  // "입력 트리거 설정" 라벨 추가
  lv_obj_t* app_link_label2 = lv_label_create(tab3);
  lv_label_set_text(app_link_label2, "입력 트리거 설정");
  lv_obj_set_style_text_font(app_link_label2, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_set_style_text_color(app_link_label2, lv_color_hex(0x007FFF), LV_PART_MAIN);
  lv_obj_align(app_link_label2, LV_ALIGN_TOP_LEFT, 0, 90);
  lv_obj_add_flag(app_link_label2, LV_OBJ_FLAG_CLICKABLE);
  // "입력 트리거 설정" Play Store QR 표시
  lv_obj_add_event_cb(app_link_label2, [](lv_event_t* e) {
    show_qr_panel("https://youtu.be/e6tqkVcQ8n0", tab3);
  }, LV_EVENT_CLICKED, NULL);

  // "센서 트리거 설정" 라벨 추가
  lv_obj_t* app_link_label3 = lv_label_create(tab3);
  lv_label_set_text(app_link_label3, "센서 트리거 설정");
  lv_obj_set_style_text_font(app_link_label3, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_set_style_text_color(app_link_label3, lv_color_hex(0x007FFF), LV_PART_MAIN);
  lv_obj_align(app_link_label3, LV_ALIGN_TOP_LEFT, 0, 130);
  lv_obj_add_flag(app_link_label3, LV_OBJ_FLAG_CLICKABLE);
  // "센서 트리거 설정" Play Store QR 표시
  lv_obj_add_event_cb(app_link_label3, [](lv_event_t* e) {
    show_qr_panel("https://youtu.be/hOzujluNKDU", tab3);
  }, LV_EVENT_CLICKED, NULL);
  
  // "제품 사용설명서" 라벨 추가
  lv_obj_t* manual_link_label = lv_label_create(tab3);
  lv_label_set_text(manual_link_label, "제품 사용설명서");
  lv_obj_set_style_text_font(manual_link_label, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_set_style_text_color(manual_link_label, lv_color_hex(0x007FFF), LV_PART_MAIN);
  lv_obj_align(manual_link_label, LV_ALIGN_TOP_LEFT, 0, 170);
  lv_obj_add_flag(manual_link_label, LV_OBJ_FLAG_CLICKABLE);
  // 라벨 클릭 시 GitHub 링크 QR 코드 표시
  lv_obj_add_event_cb(manual_link_label, [](lv_event_t* e) {
    show_qr_panel("https://github.com/kdi6033/i2r-03",tab3);
    //show_qr_panel("https://github.com/kdi6033/i2r-04/blob/main/README.md#i2r-04-motor",tab3);
  }, LV_EVENT_CLICKED, NULL);

  add_footer_label(tab3);
}

// ✅ 공통 QR 패널 함수 (두 기능 통합)
void show_qr_panel(const char* url, lv_obj_t* parent) {
  qr_panel = lv_obj_create(parent);
  lv_obj_set_size(qr_panel, 480, 320);
  lv_obj_center(qr_panel);
  lv_obj_set_style_bg_color(qr_panel, lv_color_white(), LV_PART_MAIN);

  lv_obj_t* qr = lv_qrcode_create(qr_panel, 160, lv_color_white(), lv_color_black());
  lv_qrcode_update(qr, url, strlen(url));
  lv_obj_align(qr, LV_ALIGN_CENTER, 0, -20);

  lv_obj_t* close_btn = lv_btn_create(qr_panel);
  lv_obj_set_size(close_btn, 100, 40);
  lv_obj_align(close_btn, LV_ALIGN_BOTTOM_MID, 0, -10);
  lv_obj_t* close_label = lv_label_create(close_btn);
  lv_label_set_text(close_label, "닫기");
  lv_obj_set_style_text_font(close_label, &NotoSansKR_20, LV_PART_MAIN);
  lv_obj_center(close_label);

  lv_obj_add_event_cb(close_btn, [](lv_event_t* e) {
    lv_obj_del(qr_panel);
    qr_panel = NULL;
  }, LV_EVENT_CLICKED, NULL);
}

void setup() {
  delay(2000);
  Serial.begin(115200);
  Serial1.setTX(0); Serial1.setRX(1);
  Serial1.begin(9600);

  // ✅ 부팅 직후 수신 보드가 첫 줄은 버리도록, 의미 없는 INIT 한 줄 전송
  delay(100);
  Serial1.println("INIT");

  // 🔥 부팅 직후 기준 시각 저장 (7초 타이머 시작)
  lastSerialTime = millis();

  Wire.setSDA(20); Wire.setSCL(21); Wire.begin();

  tft.begin(); tft.setRotation(1);
  uint16_t calData[5] = {192, 3590, 335, 3362, 1};
  tft.setTouch(calData);
  tft.fillScreen(TFT_BLACK);

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf1, NULL, SCREEN_WIDTH * SCREEN_HEIGHT / 10);
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = SCREEN_WIDTH;
  disp_drv.ver_res = SCREEN_HEIGHT;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  create_tabs();
}

void loop() {
  lv_timer_handler();
  delay(5);

  /*
  if (millis() - lastLightSendTime >= 3000) {
    int lux = 20;
    JsonDocument doc;
    doc["c"] = "ti";
    doc["light"] = lux;
    String json;
    serializeJson(doc, json);
    Serial1.println(json);
    //Serial.println(json);
    lastLightSendTime = millis();
  }
  */

  // 1) 수신 처리 루프
  while (Serial1.available()) {
    char c = Serial1.read();

    // 🔥 한 글자라도 들어오면 "마지막 수신 시각" 갱신
    lastSerialTime = millis();

    if (c == '\n') {
      serialBuffer.trim();
      if (serialBuffer.length() > 0) {
        parseJSONPayload((byte*)serialBuffer.c_str(), serialBuffer.length());
      }
      serialBuffer = "";
    } else {
      serialBuffer += c;
    }
  }

  // 2) 수신이 전혀 없는 시간이 7초를 넘으면 리셋
  if (millis() - lastSerialTime > serialTimeoutMs) {
    Serial.print("❗ 7초 동안 Serial1 수신 없음 → RP2040 강제 리셋, 경과(ms): ");
    Serial.println(millis() - lastSerialTime);

    delay(50);
    watchdog_enable(1, 1);   // 1ms 후 리셋
    while (true) {}          // 워치독이 리셋할 때까지 대기
  }

}

void parseJSONPayload(byte* payload, unsigned int length) {
  Serial.println((const char*)payload);
  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, payload, length);
  if (error) {
    Serial.println("❗ JSON 파싱 오류");
    Serial.println(error.c_str());  // 오류 내용까지 출력
    return;
  }

  if (doc["c"] == "ti") {
    JsonArray outArray = doc["out"];
    for (int i = 0; i < 4 && i < outArray.size(); i++) {
      btnState[i] = outArray[i];
      updateButtonUI(i, btnState[i]);
    }
  }

  // 🔹 새로 추가: in 배열에 따른 입력 LED 상태 표시
  JsonArray inArray = doc["in"];
  if (!inArray.isNull()) {
    for (int i = 0; i < 4 && i < inArray.size(); i++) {
      bool inState = inArray[i];
      updateInputLedUI(i, inState);   // 0 → 주황 / 1 → 파란색
    }
  }

  // "wifi" 값에 따라 아이콘 색상 변경
  bool wifiStatus = doc["wifi"] | false;  // "wifi"가 true이면 연두색, false이면 빨간색
  //updateWifiIcon(wifiStatus);
  if (wifiStatus) {
    // Wi-Fi 연결됨 (연두색)
    lv_obj_set_style_text_color(wifi_icon, onColor, LV_PART_MAIN);  // 연두색
  } else {
    // Wi-Fi 연결 안됨 (회색)
    lv_obj_set_style_text_color(wifi_icon, offColor, LV_PART_MAIN);  // 회색
  }

  // "mqtt" 값에 따라 MQTT 아이콘 색상 변경
  bool mqttStatus = doc["mqtt"] | false;  // "mqtt"가 true이면 연두색, false이면 회색
  if (mqttStatus) {
    // MQTT 연결됨 (연두색)
    lv_obj_set_style_text_color(mqtt_icon, onColor, LV_PART_MAIN);  // 연두색
  } else {
    // MQTT 연결 안됨 (회색)
    lv_obj_set_style_text_color(mqtt_icon, offColor, LV_PART_MAIN);  // 회색
  }

  // ✅ 추가: 온도/습도 텍스트 갱신
  if (!doc["temp"].isNull()) {
    char buf[20];
    float temp = doc["temp"].as<float>();
    snprintf(buf, sizeof(buf), "온도: %.1f°C", temp);
    lv_label_set_text(temp_label, buf);
    // 위치가 깨졌다면 다시 정렬
    lv_obj_align(temp_label, LV_ALIGN_BOTTOM_RIGHT, -120, -10);
  }

  if (!doc["humi"].isNull()) {
    char buf[20];
    float humi = doc["humi"].as<float>();
    snprintf(buf, sizeof(buf), "습도: %.0f%%", humi);
    //snprintf(buf, sizeof(buf), LV_SYMBOL_TINT " %.0f%%", humi);
    lv_label_set_text(humi_label, buf);
    // 위치 유지
    lv_obj_align(humi_label, LV_ALIGN_BOTTOM_RIGHT, -10, -10);
  }
  
}

```
</details>
