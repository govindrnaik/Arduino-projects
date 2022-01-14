#include<LiquidCrystal.h>
#include <time.h>

LiquidCrystal lcd(13,12,11,10,9,8);
void setup()
{
 lcd.begin(16, 2); 
   lcd.setCursor(0,0);          
  lcd.print("Time in Seconds:"); 
  Serial.begin(9600);
}
double i = 0;
double a = millis();
double c ;
void loop()
{
c = millis();
i = (c - a) / 1000;

  lcd.setCursor(2,1);           
  lcd.print(i); 
Serial.println(i);
  }
