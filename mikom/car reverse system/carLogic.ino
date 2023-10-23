#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
long duration;
int distanceCm;

void setup() {
Serial.begin(9600);
lcd.begin(16,2);
lcd.init();
lcd.setBacklight(HIGH);
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;

lcd.setCursor(0,0); 
lcd.print("Distance: "); 
lcd.print(distanceCm); 
lcd.print(" cm");
delay(10);
  
if(distanceCm <= 300){
    digitalWrite(buzzer, HIGH);
    delay(10);
  }
  else {
    digitalWrite (buzzer, LOW);
    delay(10);
  }
}
