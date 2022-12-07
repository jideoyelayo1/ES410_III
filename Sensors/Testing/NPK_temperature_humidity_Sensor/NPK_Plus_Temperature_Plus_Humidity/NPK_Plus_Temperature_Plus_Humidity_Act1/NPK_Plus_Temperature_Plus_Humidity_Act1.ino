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
/* Address Code = AddC, Function Code = FunC, Effective number of bytes = ENoB,
 *  Nitrogen/Phosphorus/Potassium content = NPKC, CRC_L = CRCL, CRC_H = CRCH
 */

const byte nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xb5, 0xcc};
const byte phos[]  = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xe4, 0x0c};
const byte pota[]  = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};
byte values[11];

SoftwareSerial mod(RO,DI);
DHT dht(DHTPIN, DHTTYPE);

// text to be dislayed to serial
char text[100];
// readings array
float readings[] = { 0, 0, 0, 0, 0, 0};
// slide and LEDs
#define slidePin 5
#define LEDPin 6
int slideState = 0;
int slideCnt = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  mod.begin(9600);
  pinMode(RE, OUTPUT);  pinMode(DE, OUTPUT);
  dht.begin();
  pinMode(slidePin,INPUT);pinMode(LEDPin, OUTPUT);
}

void loop() {
  //PrintReadingsToSerial(); delay(2000);
  //GenerateReadingsAndDisplayToSerial();delay(2000);
  slideState = digitalRead(slidePin);
    if(slideState == HIGH){
      slideCnt++;
    }else slideCnt = 0;
    delay(10);
    
    if(slideCnt > 100){
      digitalWrite(LEDPin,HIGH);
      GenerateReadingsAndDisplayToSerial();delay(2000);
      digitalWrite(LEDPin,LOW);
      slideCnt = 0;}
  }


  
void GenerateReadingsAndDisplayToSerial(){
  Serial.println("Reading values...");
  GetReadings();
  sprintf(text, "NPK values\nN: %d, P: %d, K: %d\nTemperature: %d, Humidity: %d, HeatIndex: %d",
  (int)readings[0],(int)readings[1],(int)readings[2],(int)readings[3],(int)readings[4],(int)readings[5]);
  // sprintf can not handle floats so this is just to test the output
  Serial.println(text);
  Serial.println("------------------------------------------------");
  }
void GetReadings(){
  byte nitrogenValue,phosphorousValue,potassiumValue; 
  float temperature,humidity,heatIndex;
  nitrogenValue = GetNitrogen();delay(250);
  phosphorousValue = GetPhosphorous();delay(250);
  potassiumValue = GetPotassium();delay(250);
  temperature = Temperature(); humidity = Humidity(); heatIndex = HeatIndex(temperature,humidity);
  float out[] = { (float) nitrogenValue, (float) phosphorousValue,(float) potassiumValue, 
  (float) temperature, (float) humidity, (float) heatIndex};
  for(int i = 0; i < 6; i++) readings[i] = out[i];
  }
  
void PrintReadingsToSerial(){
  byte nitrogenValue,phosphorousValue,potassiumValue; 
  float temperature,humidity,heatIndex;
  nitrogenValue = GetNitrogen();delay(250);
  phosphorousValue = GetPhosphorous();delay(250);
  potassiumValue = GetPotassium();delay(250);
  temperature = Temperature(); humidity = Humidity();heatIndex = HeatIndex(temperature,humidity);
  Serial.println("------------------------------------------------------");
  Serial.print("Nitrogen: ");Serial.print(nitrogenValue); Serial.println(" mg/kg"); 
  Serial.print("Phosphorous: ");Serial.print(phosphorousValue); Serial.println(" mg/kg");
  Serial.print("Potassium: "); Serial.print(potassiumValue); Serial.println(" mg/kg");
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Heat Index: "); Serial.print(heatIndex); Serial.println(" C");
}
//NPK Calculations
byte GetNitrogen(){
  digitalWrite(DE,HIGH); digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(nitro,sizeof(nitro))==8){
    digitalWrite(DE,LOW); digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){values[i] = mod.read();}
  }return values[4];
}

byte GetPhosphorous(){
  digitalWrite(DE,HIGH); digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(phos,sizeof(phos))==8){
    digitalWrite(DE,LOW); digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){values[i] = mod.read();}
  }return values[4];
}

byte GetPotassium(){
  digitalWrite(DE,HIGH); digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(pota,sizeof(pota))==8){
    digitalWrite(DE,LOW); digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){values[i] = mod.read();}
  }return values[4];
}

// Humidity, Temperature and HeatIndex Calculation
float Humidity(){return dht.readHumidity();}
float Temperature(){return dht.readTemperature();}
float HeatIndex(float t, float h){return dht.computeHeatIndex(t, h, false);}
