#Code for an anologue temperature sensor attached to the A0 pin.
int sensePin = A0; 

void setup() {
Serial.begin(9600);

}
void loop() {
int sensorVal = analogRead(sensePin);
double temp = (double)sensorVal / 1024;
temp *= 5;temp-=0.5;temp *=100;

Serial.print("Temperature: ");
Serial.print(temp);
Serial.print("\n");
delay(1000);
}