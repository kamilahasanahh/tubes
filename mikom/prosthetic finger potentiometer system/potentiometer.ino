#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#define sswitch 7

int value = 0;
Servo myservo;
int sudut;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setBacklight(HIGH);
  myservo.attach(9);
  pinMode(sswitch, INPUT);
 

}

void loop()
{
  value = digitalRead(sswitch);
  if( value == HIGH)
  {
   sudut = analogRead(A0);
   sudut = map(sudut, 0, 1023, 0, 180);
   myservo.write(sudut);
   lcd.setCursor(0,0); 
   lcd.print("Sudut Jari: "); 
   lcd.print(sudut);
   delay(10);
  }
  else
  {
   sudut = analogRead(A0);
   myservo.write(0);
  }
}
    
