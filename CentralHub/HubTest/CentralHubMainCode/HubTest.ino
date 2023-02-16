#include "FS.h"

#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>

#include <SPI.h>
#include <RH_RF95.h>
#define RFM95_CS 5
#define RFM95_RST 14
#define RFM95_INT 25
// Change to 434.0 or other frequency, must match RX's freq!
#define RF95_FREQ 434
// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);


TFT_eSPI tft = TFT_eSPI();  // Invoke library

#define TFT_GREY 0x5AEB

#define LOOP_PERIOD 35 // Display updates every 35 ms

#define CALIBRATION_FILE "/TouchCalData1"
#define REPEAT_CAL false

float NReading[4] = {0}, PReading[4] = {0}, KReading[4] = {0}, TReading[4] = {0}, HReading[4] = {0};
//int SensorNum1 = 1, SensorNum2 = 2, SensorNum3 = 3, SensorNum4 = 4;
int DisplaySpiPin = 13, RFSpiPin = 5; // UPDATE WITH CORRECT PINS
int16_t packetnum = 0;  // packet counter, we increment per xmission
int NumberOfSensors = 0;
int SensorIDs[4] = {0}, SensorsUpdated[4]= {0};

#define REPEAT_CAL false


void SensorInfomationDisplay(float NReading[4], float PReading[4], float KReading[4], float TReading[4], float HReading[4], int NumberOfSensors, int SensorsUpdated[4]){ //Set the display to the infomation diplay

    int Line1_Y = 40;
    int Line1_X = 20, Line2_X = 40, Line3_X = 80, Line4_X = 130, Line5_X = 180, Line6_X = 230, Line7_X = 280;
    
    //Set SPI to update display
    //Pick SPI pins for RF and display and set high low accordingly.
    // SetSpiPin(true, DisplaySpiPin, RFSpiPin);

    //tft.fillScreen(TFT_BLACK); 

    if (NumberOfSensors>0){
      tft.setCursor(20, 160, 2);
      tft.println("Request data:");
      drawFrame(50,180);

      tft.setCursor(120, 160, 2);
      tft.println("Process data:");
      drawFrame(150,180);
    }

    tft.setCursor(230, 160, 2);
    tft.println("Add sensor:");

    tft.setCursor(80, 10, 2);
    tft.println("Soil Nutrient Readings");

    tft.setCursor(Line1_X, Line1_Y, 2);
    tft.println("Sensor");

    tft.setCursor(Line3_X, Line1_Y, 2);
    tft.println("N");

    tft.setCursor(Line4_X, Line1_Y, 2);
    tft.println("P");

    tft.setCursor(Line5_X, Line1_Y, 2);
    tft.println("K");

    tft.setCursor(Line6_X, Line1_Y, 2);
    tft.println("T");

    tft.setCursor(Line7_X, Line1_Y, 2);
    tft.println("H");

    if (NumberOfSensors>0){
        for(int i = 0; i < NumberOfSensors;i++){
          int Line_Y = 70 + 20*i;

          if (SensorsUpdated[i]==1){
            tft.setTextColor(TFT_GREEN);
          }
          else{
            tft.setTextColor(TFT_RED);
          }

          tft.setCursor(Line2_X, Line_Y, 2);
          tft.println(i+1);

          tft.setCursor(Line3_X, Line_Y, 2);  
          tft.println(NReading[i]); 

          tft.setCursor(Line4_X, Line_Y, 2);  
          tft.println(PReading[i]);   

          tft.setCursor(Line5_X, Line_Y, 2);  
          tft.println(KReading[i]);  

          tft.setCursor(Line6_X, Line_Y, 2);  
          tft.println(TReading[i]); 

          tft.setCursor(Line7_X, Line_Y, 2);  
          tft.println(HReading[i]);   

          tft.setTextColor(TFT_WHITE);
        }
    }
    else{
          tft.setCursor(Line1_X, 70, 2);
          tft.println("No Sensors connected");
    }

    drawFrame(250,180);    

    }

void RequestSensorData(int SensorNum[4],int SensorsUpdated[4], float NReading[4], float PReading[4], float KReading[4], float TReading[4], float HReading[4], int NumberOfSensors){ //Send out a request for data

  tft.fillScreen(TFT_BLACK); 
  tft.setCursor(120, 110, 2);
  tft.println("Requesting data...");

  for (int i = 0; i<NumberOfSensors;i++){
    char SensorString[20];
    itoa(SensorNum[i], SensorString, 10);

    Serial.println("Sending sensor data request");
    // Send a message to rf95_server
    Serial.print("Sending ");
    Serial.println(SensorString);
    Serial.println("Sending...");
    delay(10);
    rf95.send((uint8_t *)SensorString, 20);
    Serial.println("Waiting for packet to complete...");
    delay(10);
    rf95.waitPacketSent();
    // Now wait for a reply
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    Serial.println("Waiting for reply...");
    delay(10);


    int NInt = getData();
    NReading[i] = NInt > 0 ? (float)NInt/10 : NReading[i];
    int PInt = getData();
    PReading[i] = PInt > 0 ? (float)PInt/10 : PReading[i];
    int KInt = getData();
    KReading[i] = KInt > 0 ? (float)KInt/10 : KReading[i];
    int TInt = getData();
    TReading[i] = TInt > 0 ? (float)TInt/10 : TReading[i];
    int HInt = getData();
    HReading[i] = HInt > 0 ? (float)HInt/10 : HReading[i];

    SensorsUpdated[i] = (HInt > 0);
    tft.fillScreen(TFT_BLACK); 

  }
}

int getData(){
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    int count = 0;    
    while (count<2000000){
    if (rf95.recv(buf, &len)) {
      Serial.print("Got data: ");
      Serial.println((char *)buf);
      return atoi((char *)buf);
     }
     else{
       count++;
     }
  }
    Serial.println("No Data...");
    return 0;
}

int addSensor(int NumberOfSensors, int SensorIDs[4]){ // Connect the central hub to a new sensor
  tft.fillScreen(TFT_BLACK); 
  tft.setCursor(20, 110, 2);
  tft.println("Hold the connect button on the sensor now.");

  int ConnectCode = 9999;
  char ConnectString[4];
  itoa(ConnectCode, ConnectString, 10);

  Serial.println("Attempting to find a new sensor...");
  // Send a message to rf95_server
  Serial.print("Sending ");
  Serial.println(ConnectString);
  Serial.println("Sending...");

  for (int i = 0; i<10; i++){
    delay(10);
    rf95.send((uint8_t *)ConnectString, 20);
    delay(10);
    rf95.waitPacketSent();
    // Now wait for a reply
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);

    if (rf95.waitAvailableTimeout(2000)) {
      // Should be a reply message for us now
      if (rf95.recv(buf, &len)) {
        Serial.print("Got reply: ");
        Serial.println((char *)buf);
        SensorIDs[NumberOfSensors] = atoi((char*)buf);
        NumberOfSensors++;
        tft.fillScreen(TFT_BLACK); 
        tft.setCursor(120, 80, 2);
        tft.println("Sensor connected");
        tft.setCursor(125, 110, 2);
        tft.println("This is sensor: ");
        tft.setCursor(165, 140, 2);
        tft.println(NumberOfSensors); 
        Serial.println("Sensor Added");
        Serial.println(NumberOfSensors);
        Serial.println(SensorIDs[NumberOfSensors-1]);
        delay(10000); 
        tft.fillScreen(TFT_BLACK);    
        return NumberOfSensors;
      } else {
        Serial.println("Receive failed");
      }
    } else {
      Serial.println("Still searching for sensor");
      Serial.print("Test Number: ");
      Serial.println(i);      
    }
  }
  Serial.println("Unable to find any sensor");
  tft.fillScreen(TFT_BLACK); 
  tft.setCursor(90, 110, 2);
  tft.println("Unable to find any sensor");
  delay(3000);  
  tft.fillScreen(TFT_BLACK); 
  return NumberOfSensors;
}

void ProcessData(){

  tft.fillScreen(TFT_BLACK); 
  tft.setCursor(120, 110, 2);
  tft.println("Processing data...");
  delay(5000);
  tft.fillScreen(TFT_BLACK); 

}

void SetSpiPin(bool SetPin, int RFSpiPin, int DisplaySpiPin){ // SetPin == 1 enables display, 0 == RF.
  if (SetPin == 1){
    digitalWrite(RFSpiPin, HIGH);
    delay(100);
    digitalWrite(DisplaySpiPin, LOW);
  }
  else{
    digitalWrite(DisplaySpiPin, HIGH);
    delay(100);
    digitalWrite(RFSpiPin, LOW);
  }
}

void drawFrame(int x, int y)
{
  tft.drawRect(x, y, 50, 50, TFT_RED);
}

void setup(void) {
  Serial.begin(9600); // For debug
  
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
  delay(100);

    Serial.println("Arduino LoRa TX Test!");
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

  //LCD Setup!
  tft.init();
 
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  touch_calibrate();
  tft.fillScreen(TFT_BLACK);
}

void loop(){   
  SensorInfomationDisplay(NReading, PReading, KReading, TReading, HReading, NumberOfSensors, SensorsUpdated);

  uint16_t x, y;
  tft.getTouch(&x, &y);

  if (y>180 && y<235 && x>40 && x<100){
    if(NumberOfSensors>0 && NumberOfSensors<4){    
      RequestSensorData(SensorIDs, SensorsUpdated, NReading, PReading, KReading, TReading, HReading, NumberOfSensors); //Send out a request for data
    }
    else{
      Serial.println("No Sensors Connected or full");
    }
  }

  if (y>180 && y<235 && x>250 && x<300){
    //ProcessData(); //Send out a request for data
    NumberOfSensors = addSensor(NumberOfSensors, SensorIDs);
  }

  if (y>180 && y<235 && x>140 && x<200){
    ProcessData(); //Send out a request for data
  }

  // Serial.println(x);
  // Serial.println(y);
    // ReceiveSensorData();
  delay(250);
}

void touch_calibrate()
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // check file system exists
  if (!SPIFFS.begin()) {
    Serial.println("Formating file system");
    SPIFFS.format();
    SPIFFS.begin();
  }

  // check if calibration file exists and size is correct
  if (SPIFFS.exists(CALIBRATION_FILE)) {
    if (REPEAT_CAL)
    {
      // Delete if we want to re-calibrate
      SPIFFS.remove(CALIBRATION_FILE);
    }
    else
    {
      File f = SPIFFS.open(CALIBRATION_FILE, "r");
      if (f) {
        if (f.readBytes((char *)calData, 14) == 14)
          calDataOK = 1;
        f.close();
      }
    }
  }

  if (calDataOK && !REPEAT_CAL) {
    // calibration data valid
    tft.setTouch(calData);
  } else {
    // data not valid so recalibrate
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(20, 0);
    tft.setTextFont(2);
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.println("Touch corners as indicated");

    tft.setTextFont(1);
    tft.println();

    if (REPEAT_CAL) {
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.println("Set REPEAT_CAL to false to stop this running again!");
    }

    tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.println("Calibration complete!");

    // store data
    File f = SPIFFS.open(CALIBRATION_FILE, "w");
    if (f) {
      f.write((const unsigned char *)calData, 14);
      f.close();
    }
  }
}


