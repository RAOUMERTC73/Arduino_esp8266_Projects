#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
 
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("First row");
lcd.setCursor(0,1);
lcd.print("second row");

}

void loop()
{

}
