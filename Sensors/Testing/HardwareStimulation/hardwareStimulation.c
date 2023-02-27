#include <LiquidCrystal.h>
// Connect LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define sensorPin A0

// Create variables to calculate the average moisture level
int moistureArray[100];
int idx = 0;

// Set up the LED display
void setupLED(){
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print("MoistLvL:");
}

// Calculate the average moisture level
long get_moisture_avg(){
long sum = 0;
  for(int i = 0; i < 100;i++)
    sum+=moistureArray[i];
  Serial.print(sum);
  Serial.print(" = ");
  Serial.println((int)sum);
  return sum;
}

// Get current moisture level and add it to array
void check_moisture(){
  digitalWrite(A0, HIGH);
  delay(1);
  moistureArray[idx%100] = analogRead(A1);
  digitalWrite(A0, LOW);
  idx++;
}

// Get current temperature value
float check_temperature(){
  int reading = analogRead(sensorPin);
  float voltage = reading * (5000 / 1024.0);
  float temperature = (voltage - 500) / 10;
  //Serial.println(temperature);
  return temperature;
}

// Set up MCU
void setup() {
  Serial.begin(9600);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
  setupLED();
}

// refreshes the LCD every 200 milliseconds and takes moisture recoding every 10 milliseconds
void loop() {  
  
  check_moisture();
  
  if(idx > 100){
  lcd.setCursor(12, 0);
  float temperature = check_temperature();
  lcd.print(temperature);
  
  lcd.setCursor(9, 1);
  int moisture_level = get_moisture_avg();
  lcd.print(moisture_level); 
  
  idx = 0;
  }
}
 