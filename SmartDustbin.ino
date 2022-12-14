#include<Servo.h>
#include<LiquidCrystal_I2C.h>
Servo servoMain; 

LiquidCrystal_I2C lcd(0x27,16,2);
int trigpin = 9;
int echopin = 8;
int distance;
float duration;
float cm;
int distance1=0;

int trig = 4;
int echo = 5;
int green = 10;
int yellow = 11;
int red = 12;


void setup()
{

lcd.init();
lcd.backlight();
servoMain.attach(7); //
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(trig, OUTPUT);
pinMode(green, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(red, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
}

void loop()
{
digitalWrite(trig, HIGH);
delay(1);
digitalWrite(trig, LOW);
int duration1 = pulseIn(echo, HIGH);
distance1 = duration1/80.82;

 

digitalWrite(trigpin, LOW);
delay(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration = pulseIn(echopin, HIGH);
cm = (duration/58.82);
distance = cm;


lcd.setCursor(4,0);
lcd.print("Welcome to");
lcd.setCursor(2, 1);
lcd.print("SMART DUSTBIN");


if(distance<30) { 
  lcd.clear();
  lcd.setCursor(0,0);
   lcd.print("lid is opening");
  
  if (distance1 < 199 and distance1 > 10){
     lcd.setCursor(0, 1);
      lcd.print("Waste Level 1");
  }


  else if (distance1 < 10 && distance1 >3){
     lcd.setCursor(0,1);
           lcd.print("Waste Level 2");
    }


    else if(distance1<3){

      lcd.setCursor(0,1);
           lcd.print("Waste Level 3");
    }
  
  servoMain.write(180);  delay(3000);

  lcd.clear();


 } else
 { servoMain.write(0); delay(50); } }