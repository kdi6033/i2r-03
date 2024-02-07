//tab2.page.ts
import { Component,NgZone, ChangeDetectorRef, OnDestroy, DoCheck } from '@angular/core';
import { Subscription } from 'rxjs';
import { GlobalService } from '../global.service';
import { Router } from '@angular/router';
import { ModalController,AlertController } from '@ionic/angular'; // Import ModalController here

interface Relay {
  isOn: boolean;
}
@Component({
  selector: 'app-tab2',
  templateUrl: 'tab2.page.html',
  styleUrls: ['tab2.page.scss']
})
export class Tab2Page implements OnDestroy, DoCheck {

  selectedAction: string = 'stop'; // 기본값 설정

  // 선택된 동작에 대한 로직
  performAction() {
    console.log(`선택된 동작: ${this.selectedAction}`);
    // 여기에 선택된 동작에 대한 처리 로직을 추가할 수 있습니다.
  }

  relayStates = [true, true, true, true];
  relays: Relay[] = [
    // Initialize this with your default values
    { isOn: false },
    { isOn: false },
    { isOn: false },
    { isOn: false }
    // ... add more relays as needed
  ];

  // 로그
  showMessageLog = false; // Flag to show/hide the message log
  messageLog: string[] = []; // Array to store the log of messages
  leds: boolean[] = new Array(4).fill(false);
  private subscription: Subscription;
  constructor(
    public globalService: GlobalService,
    private changeDetectorRef: ChangeDetectorRef,
    private ngZone: NgZone,
    public alertController: AlertController,
  ) {
    // Load message log from local storage
    this.messageLog = this.globalService.loadMessageLogFromLocalStorage();
    // MQTT 연결 상태 구독
    this.globalService.mqttConnection$.subscribe(isConnected => {
      this.onMQTTConnectionChange();
    });
    this.globalService.wifiData$.subscribe(() => {
      this.changeDetectorRef.detectChanges();
    });
    this.subscription = this.globalService.devIn$.subscribe((newIn) => {
      this.leds = newIn.map(value => value > 0);
      this.changeDetectorRef.detectChanges();
    });
    // RxJS 구독
    this.globalService.wifiData$.subscribe(data => {
      this.ngZone.run(() => {
        // 데이터 처리
        this.changeDetectorRef.detectChanges();
      });
    });
    // 앱 시작 시 MQTT 연결 상태 확인 및 연결 시도
    this.globalService.checkMQTTConnection();
  }

  onActionChange(value: number) {
    // this.globalService.dev.noSelect = value;
    this.globalService.sendData(4);
  }

  ngOnInit() {
    // MQTT 토픽 정보가 설정되어 있지만 BLE가 연결되지 않은 경우
    if (this.globalService.wifi.outTopic) {
      this.globalService.wifi.selectMqtt = true; // 실제 WiFi 선택 상태를 true로 설정
    } else{
      this.globalService.wifi.selectMqtt = false; // 실제 BLE 선택 상태를 true로 설정
    }
  }
  ngDoCheck(): void {
  }
  ngOnDestroy() {
    this.subscription.unsubscribe();
  }
// MQTT 연결 상태 변경 시 호출되는 메소드
onMQTTConnectionChange() {
  if (this.globalService.wifi.selectMqtt) {
    // MQTT 연결 상태가 활성화되면 연결 시도
    this.globalService.checkMQTTConnection();
  }
}
toggleRelay(event: MouseEvent, index: number): void {
  const button = event.target as Element; // Cast the target to Element

  const isOn = button.classList.contains('relay-on');
  const signal = button.nextElementSibling as HTMLElement;

  if (isOn) {
    button.classList.remove('relay-on');
    button.classList.add('relay-off');
    signal.classList.remove('signal-on');
    signal.classList.add('signal-off');
  } else {
    button.classList.remove('relay-off');
    button.classList.add('relay-on');
    signal.classList.remove('signal-off');
    signal.classList.add('signal-on');
  }

  this.relays[index].isOn = !this.relays[index].isOn;
  // Call sendDataToTab2 with the updated state
  this.sendDataToTab2(index, this.relays[index].isOn);
}

sendDataToTab2(no: number, value: boolean) {
  // GlobalService를 통해 Tab1Page의 sendData 함수를 호출합니다.
  this.globalService.dev.no = no;
  this.globalService.dev.value = value;
  this.globalService.sendData(2);
}

toggleMqttSelect() {
  console.log('와이파이 선택 상태:', this.globalService.wifi.selectMqtt);
  // 로컬 스토리지에 Wi-Fi 설정 저장
  //this.globalService.saveWifiSettingsToLocalStorage();
  this.globalService.loadMqttBrokerFromLocalStorage();
  console.log(this.globalService.wifi.mqttBroker);
  console.log(this.globalService.wifi.outTopic);
  console.log(this.globalService.wifi.inTopic);

  if (this.globalService.wifi.selectMqtt) {
    // MQTT가 활성화될 때
    this.globalService.startMQTTReconnect(); // 재연결 시작
  } else {
    // MQTT가 비활성화될 때
    this.globalService.stopMQTTReconnect(); // 재연결 중지
  }

  if(this.globalService.wifi.isConnectedMqtt)
    this.globalService.sendData(3);
  // 변경된 상태를 로컬 스토리지에 저장
  this.globalService.saveSelectMqttToLocalStorage();
}

get receivedMessage() {
  return this.globalService.receivedMessage;
}

}

