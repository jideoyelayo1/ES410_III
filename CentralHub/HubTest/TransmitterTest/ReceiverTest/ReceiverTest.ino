#include <SPI.h>
#include <RH_RF95.h>
#include <stdio.h>
#define RFM95_CS 5
#define RFM95_RST 14
#define RFM95_INT 2
// Change to 434.0 or other frequency, must match RX's freq!
#define RF95_FREQ 434.0
// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);
// Blinky on receipt
#define LED 13
const int buttonPin = 21;
int buttonState = 0, SensorConnected = 0;
int SensorID = random(1, 99999);
float NReading = 37.5, PReading = 45.3, KReading = 98.3, TReading = 25.2, HReading = 95.3; //Test numbers
int NReading100 = NReading * 10, PReading100 = PReading * 10, KReading100 = KReading * 10, TReading100 = TReading * 10, HReading100 = HReading * 10;
char NString[5] = "", PString[5] = "", KString[5] = "", TString[5] = "", HString[5] = "";


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(RFM95_RST, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(RFM95_RST, HIGH);
  //while (!Serial);
  Serial.begin(9600);
  delay(100);
  Serial.println("Arduino LoRa RX Test!");
  // manual reset
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);
  while (!rf95.init()) {
    Serial.println("LoRa radio init failed");
    while (1)
      ;
  }
  Serial.println("LoRa radio init OK!");
  // Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, +13dbM
  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println("setFrequency failed");
    while (1)
      ;
  }
  Serial.print("Set Freq to: ");
  Serial.println(RF95_FREQ);
  // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
  // The default transmitter power is 13dBm, using PA_BOOST.
  // If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then
  // you can set transmitter powers from 5 to 23 dBm:
  rf95.setTxPower(23, false);

  itoa(NReading100, NString, 10);
  itoa(PReading100, PString, 10);
  itoa(KReading100, KString, 10);
  itoa(TReading100, TString, 10);
  itoa(HReading100, HString, 10);
  
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (rf95.available()) {
    // Should be a message for us now
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len)) {
      digitalWrite(LED, HIGH);
      RH_RF95::printBuffer("Received: ", buf, len);
      Serial.print("Got: ");
      Serial.println((char*)buf);
      Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);
      int SensorNum = atoi((char*)buf);
      delay(100);
      // Send a reply
      if (SensorNum == SensorID) {    
      //uint8_t data[] = "Sensor Number Received";
      rf95.send((uint8_t*)NString, sizeof(NString));
      rf95.waitPacketSent();
      Serial.println("Sensor number confirmed. Sending data...");
      delay(100);
      rf95.send((uint8_t*)PString, sizeof(PString));
      rf95.waitPacketSent();
      delay(100);
      rf95.send((uint8_t*)KString, sizeof(KString));
      rf95.waitPacketSent();
      delay(100);
      rf95.send((uint8_t*)TString, sizeof(TString));
      rf95.waitPacketSent();
      delay(100);
      rf95.send((uint8_t*)HString, sizeof(HString));
      rf95.waitPacketSent();
      }
      else if(buttonState == HIGH && SensorNum == 9999 && SensorConnected == 0){
      char SensorIDString[5];
      itoa(SensorID, SensorIDString, 10);
      rf95.send((uint8_t *)SensorIDString, sizeof(SensorIDString));
      rf95.waitPacketSent();
      Serial.println("Central Hub connected");
      SensorConnected = 1;
      }
      else{
        Serial.println("Incorrect Sensor Number");
      }
      digitalWrite(LED, LOW);
    } else {
      Serial.println("Receive failed");
    }
  }
}
