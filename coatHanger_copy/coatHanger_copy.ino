//Displaying number of coat hangers on a rack
//Code written by Scott Faulkner on 06/05/2026

//Setting up LCD display
#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

//Declaring variables
int readPin=A0; 
float readVolts;
float resTotal;
float numItems;

void setup() {
  // put your setup code here, to run once:
pinMode(readPin,INPUT);
lcd.begin(16,2);
}

void loop() {
//Measuring remaining voltage after first resitor
readVolts=analogRead(readPin);

//Calculating total resistance
resTotal=(1023.*330.)/(1023-readVolts);

//Calculating the number of items
numItems=330./(resTotal-330);
if(resTotal>=0 && resTotal<=340){ //To avoid negative answers
  numItems=0;
}

//Displaying number of items on LCD screen
lcd.setCursor(0,0);
lcd.print("Number of items:");
lcd.setCursor(0,2);
lcd.print(round(numItems));
delay(900);
lcd.clear();
}
