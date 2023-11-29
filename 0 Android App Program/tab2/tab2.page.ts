//tab2.page.ts
import { Component, ChangeDetectorRef, OnDestroy } from '@angular/core';
import { Subscription } from 'rxjs';
import { GlobalService } from '../global.service';
import { NgZone } from '@angular/core';

@Component({
  selector: 'app-tab2',
  templateUrl: 'tab2.page.html',
  styleUrls: ['tab2.page.scss']
})
export class Tab2Page implements OnDestroy {
  //receivedMessage: string = ''; // 수신된 메시지를 저장하기 위해 빈 문자열로 초기화합니다.,
  //leds: any[] = [];
  leds: boolean[] = new Array(8).fill(false);
  private subscription: Subscription;

  constructor(public globalService: GlobalService, private changeDetectorRef: ChangeDetectorRef,private ngZone: NgZone) {
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
  }

  ngOnDestroy() {
    this.subscription.unsubscribe();
  }

  sendDataToTab2(no: number, value: boolean) {
    // GlobalService를 통해 Tab1Page의 sendData 함수를 호출합니다.
    this.globalService.dev.no = no;
    this.globalService.dev.value = value;
    this.globalService.sendData(2);
  }

  /*
  toggleMqttSelect() {
    // selectMqtt 값이 변경되었을 때 필요한 로직을 여기에 작성합니다.
    // 예: GlobalService의 wifi 객체 업데이트
    //this.globalService.wifi.selectMqtt = !this.globalService.wifi.selectMqtt;
    console.log('와이파이 선택 상태:', this.globalService.wifi.selectMqtt);
    this.globalService.sendData(3);
    //this.globalService.wifiUseChanged();
  }
  */

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

