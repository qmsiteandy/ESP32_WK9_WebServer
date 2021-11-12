#include "WiFi.h"
void setup(){
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);//設定為STA工作站模式
    WiFi.disconnect();//斷線（初始化的意思）
    delay(100);
    Serial.println("Setup done");
}

void loop(){
    Serial.println("scan start");
    int wifiCount = WiFi.scanNetworks();//掃描網路，並將掃描到的網路數量存入
    Serial.println("scan done");
    if (wifiCount == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(wifiCount);
        Serial.println(" networks found");
        for (int i = 0; i < wifiCount; ++i) {
            //顯示無線網路SSID, RSSI, 加密
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.println(WiFi.SSID(i));
            delay(10);
        }
    }
    Serial.println("");
    //等候五秒後，重新掃描
    delay(5000);
}
