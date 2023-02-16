
#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>

#define TFT_GREY 0x5AEB // New colour

TFT_eSPI tft = TFT_eSPI();  // Invoke library

#define TFT_GREY 0x5AEB

#define LOOP_PERIOD 35 // Display updates every 35 ms

float NReading = 0, PReading = 0, KReading = 0;
//int SensorNum1 = 1, SensorNum2 = 2, SensorNum3 = 3, SensorNum4 = 4;
int DisplaySpiPin = 13, RFSpiPin = 14; // UPDATE WITH CORRECT PINS


void SensorInfomationDisplay(float NReading, float PReading, float KReading,  int RFSpiPin, int DisplaySpiPin){ //Set the display to the infomation diplay


    int Line1_Y = 40, Line2_Y = 70, Line3_Y = 110, Line4_Y = 150, Line5_Y = 190;
    int Line1_X = 20, Line2_X = 40, Line3_X = 80, Line4_X = 130, Line5_X = 180;
    
    //Set SPI to update display
    //Pick SPI pins for RF and display and set high low accordingly.
    SetSpiPin(true, DisplaySpiPin, RFSpiPin);

    tft.fillScreen(TFT_BLACK); 

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

    tft.setCursor(Line2_X, Line2_Y, 2);
    tft.println("1");

    tft.setCursor(Line2_X, Line3_Y, 2);
    tft.println("2");

    tft.setCursor(Line2_X, Line4_Y, 2);
    tft.println("3");

    tft.setCursor(Line2_X, Line5_Y, 2);
    tft.println("4");
    
    tft.setCursor(Line3_X, Line2_Y, 2);
    tft.println(NReading);
    
    tft.setCursor(Line4_X, Line2_Y, 2);
    tft.println(PReading);

    tft.setCursor(Line5_X, Line2_Y, 2);
    tft.println(KReading);

    }





void RequestSensorData(){ //Send out a request for data

}

void ReceiveSensorData(){ // If a response is receive, accept data and assign it to correct variables.
    
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

void setup(void) {
  tft.init();
  tft.setRotation(2);
  pinMode(DisplaySpiPin, OUTPUT);  
  pinMode(RFSpiPin, OUTPUT);  
  Serial.begin(57600); // For debug
  tft.fillScreen(TFT_BLACK);
}

void loop(){   
    NReading = NReading + 1;
    PReading = PReading + 0.5;
    KReading = KReading + 0.1;
    SensorInfomationDisplay(NReading, PReading, KReading, RFSpiPin, DisplaySpiPin);
    ReceiveSensorData();
    delay(10000);
}


