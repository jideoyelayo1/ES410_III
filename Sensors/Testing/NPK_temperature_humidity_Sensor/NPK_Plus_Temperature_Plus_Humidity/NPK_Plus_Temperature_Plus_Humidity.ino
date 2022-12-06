// Libraries 
#include <SoftwareSerial.h>
#include "DHT.h"

/*Pins being used*/

// Humidity and Temperature Pins
#define DHTPIN 4
#define DHTTYPE DHT11
// NPK Sensor Pins
#define RO 2
#define RE 8
#define DE 7
#define DI 3

// NPK sensor byteArrays
const byte nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};
byte values[11];

SoftwareSerial mod(RO,DI);
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
