

#include <NewPing.h>
#include <LiquidCrystal.h> 
#include <Servo.h>
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
int counter=0;
int hello=0;
int dist=0;

#define TRIGGER_PIN  8
#define ECHO_PIN     10
#define MAX_DISTANCE 100

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo Servo1;

void setup() {
  Serial.begin(9600);
  delay(50);
  pinMode(9, OUTPUT);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A3,OUTPUT);
  Servo1.attach(A1);
}

void loop(){
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(500);    
 
  if (sensorValue>900){
    if (hello==0){
      Servo1.write(0);
    hello=1;
    }
   
   run();
  }
}
void run() {

dist= sonar.ping_cm();
Serial.print(dist);
Serial.println ("cm");
while(dist>0 and dist<5)
  {
    digitalWrite(13,HIGH);
    delay(2000);
  tone(9, 329.63, 300);
  delay(350);
  // play d4# 
  tone(9, 311.13, 300);
  delay(350);
  // play e4
  tone(9, 329.63, 300);
  delay(350);
  // play d4# 
  tone( 9,311.13, 300);
  delay(350);
  // play e4
  tone(9, 329.63, 300);
  delay(350);
  // play b3
  tone( 9, 246.94, 300);
  delay(400);
  // play d4
  tone(9, 293.66,300);
  delay(400);
  // play c4
  tone(9, 261.63,300);
  delay(400);
  // play a3
  tone(9, 220, 900);
  delay(2000);
  digitalWrite(A5,HIGH);
digitalWrite(A4,HIGH);
digitalWrite(A3,HIGH);
 delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Thank you !!!!");
   
  lcd.setCursor(0, 1);
  lcd.print("MDM FONG <3 ;)");
if (counter==0){
    Servo1.write(90);
    counter=1;
    }
  delay(1000);
  dist= sonar.ping_cm();
 
  
  }
  
  digitalWrite(9, LOW);
  delay(300);

}
