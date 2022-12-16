Include relevant libraries 
#include <SPI.h> //Include SPI library 
#include <RH_RF95.h> //Include radio library
#include <Wire.h> //Include Wire library

//Assign pins
#define RFM95_CS 10
#define RFM95_RST 9
#define RFM95_INT 2

//Define frequency 
#define RF95_FREQ 433.0

//Instantiate radio object with custom pin numbers
RH_RF95 rf95(RFM95_CS, RFM95_INT);

// Blink on receipt
#define LED 13


void setup()
{
pinMode(LED, OUTPUT); 
pinMode(RFM95_RST, OUTPUT); 
digitalWrite(RFM95_RST, HIGH); 

while (!Serial); 
Serial.begin(9600); 
delay(100);
Serial.println("Temperature, Air Pressure & Altitude Readings");

//Manual reset the radio
digitalWrite(RFM95_RST, LOW); 
delay(10);
digitalWrite(RFM95_RST, HIGH); 
delay(10);

//Initialise library 
while (!rf95.init()) {
Serial.println("LoRa radio initialization failed");
while (1);
}
Serial.println("LoRa radio initialization successful");

// Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
// The default transmitter power is 13dBm, using PA_BOOST.

//Set frequency to 433MHz
if (!rf95.setFrequency(RF95_FREQ)) {
Serial.println("setFrequency failed");
while (1);
}
Serial.print("Set Frequency: "); Serial.println(RF95_FREQ);


//Set transmitter power to 23 dBm
rf95.setTxPower(23, false);
}

void loop()
{
if (rf95.available())
{
//Receive and print message from transmitter
uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
uint8_t len = sizeof(buf);

if (rf95.recv(buf, &len))
{
digitalWrite(LED, HIGH);
Serial.print("Data received: \n");
Serial.println((char*)buf);

//Print RSSI value
Serial.print("RSSI: ");
Serial.println(rf95.lastRssi(), DEC);

// Send a reply
uint8_t data[] = "Data received";
rf95.send(data, sizeof(data));
rf95.waitPacketSent();

digitalWrite(LED, LOW);
}
else
{
Serial.println("Receive failed");
}
}
}
