#include <DMXSerial.h>
#include <SoftwareSerial.h>

uint8_t dmxLevel[512];
String sendBuff;

SoftwareSerial mySerial(10, 11); // RX, TX
// Constants for demo program

void setup () {
  DMXSerial.init(DMXReceiver);
  
  mySerial.begin(9600);
}


void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  if (lastPacket < 5000) {
    for(int i = 0; i < 512; i++){
			int j = 0;
      if(dmxLevel[i] != DMXSerial.read(i + 1)){
        dmxLevel[i] = DMXSerial.read(i + 1);
				mySerial.write((byte*) dmxLevel, 512);
      }
    }
  }
}
