#include <DMXSerial.h>
//#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
byte dmxLevel[512];

//SoftwareSerial mySerial(10, 11); // RX, TX
AltSoftSerial mySerial; //RX 8 TX 9

void setup () {
  DMXSerial.init(DMXReceiver);
  
  mySerial.begin(9600); // ソフトウェアシリアルの初期化
}


void loop() {
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  if (lastPacket < 5000) {
    for(byte  i = 0; i < 512; i++){
      if(dmxLevel[i] != DMXSerial.read(i + 1)){
//        mySerial.println(DMXSerial.read(i));
        
        dmxLevel[i] = DMXSerial.read(i + 1);
        mySerial.print(i+1);
        mySerial.print(":");
        mySerial.println(dmxLevel[i]);
      }
    }
  }
  delay(2);
}
