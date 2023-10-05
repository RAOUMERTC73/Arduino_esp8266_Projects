#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int pbutton=7;
int count=0;

void setup(){
lcd.begin(16,2);
pinMode(pbutton, INPUT);
}

void loop(){
if (digitalRead(pbutton)==HIGH){
lcd.setCursor(0,0);
lcd.print(count++);
while(digitalRead(pbutton)==HIGH);
}

}

---------------------------------------------------

#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int pbutton=7;
int count=0;

void setup(){
lcd.begin(16,2);
pinMode(pbutton, INPUT);
}

void loop(){
if (digitalRead(pbutton)==HIGH){
lcd.setCursor(0,0);
lcd.print('button pressed");
}

}


