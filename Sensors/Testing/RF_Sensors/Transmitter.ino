Include relevant libraries 
#include <SPI.h> 
#include <Wire.h> 
#include <stdio.h> 
#include <RH_RF95.h> 
#include <Adafruit_MPL3115A2.h> 

//Assign pins
#define RFM95_CS 10 
#define RFM95_RST 9 
#define RFM95_INT 2 

//Define frequency 
#define RF95_FREQ 433.0 

//Instantiate radio object with custom pin numbers and Adafruit sensor
RH_RF95 rf95(RFM95_CS, RFM95_INT); 
Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

void setup()
{
pinMode(RFM95_RST, OUTPUT); 
digitalWrite(RFM95_RST, HIGH);

while (!Serial); 
Serial.begin(9600); 
delay(100); 
Serial.println("Temperature, Air Pressure & Altitude Readings"); 

//Manually reset the radio
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

int16_t packetnum = 0; //Define packet counter: incremented per transmission

void loop()
{
if (! baro.begin()) {
    Serial.println("Couldnt find sensor");
    return;
  }
  
  //Collect and print pressure, altitude and temperature readings
  float pressure = baro.getPressure();
  Serial.print("Air Pressure = "); Serial.print(pressure); Serial.println(" Pa");
  float altitude = baro.getAltitude();
  Serial.print("Altitude = "); Serial.print(altitude); Serial.println(" m");
  float temperature = baro.getTemperature();
  Serial.print("Temperature = "); Serial.print(temperature); Serial.println(" °C");

  //Convert float values to character arrays contained in 'P', 'A' and 'T'
  char P[10];
  char A[10];
  char T[10];
  dtostrf(pressure, 7,2, P);
  dtostrf(altitude, 7,2, A);
  dtostrf(temperature, 4,2, T);

  //Create character array called data containing readings 
 char data[80];
 sprintf(data, "Air Pressure = %s Pa \nAltitude = %s m \nTemperature = %s °C", P, A, T);

Serial.println("Sending to receiver");

//Transmit data to receiver 
rf95.send((uint8_t*)data, sizeof(data));
delay(10);
rf95.waitPacketSent();

// Wait for a reply
uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
uint8_t len = sizeof(buf);
delay(10);
if (rf95.waitAvailableTimeout(1000))
{
  
// Should be a reply message; print reply
if (rf95.recv(buf, &len))
{
Serial.print("Message from receiver: ");
Serial.println((char*)buf);

//Print RSSI value
Serial.print("RSSI: ");
Serial.println( rf95.lastRssi(), DEC);

}
else
{
Serial.println("Receive failed");
}
}
else
{
Serial.println("Could not reach receiver");
}
delay(1000);
}
