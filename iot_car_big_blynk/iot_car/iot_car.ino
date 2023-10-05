
// wifi controlled home automation using Blynk App & ESP8266
#define BLYNK_TEMPLATE_ID "TMPL6s_nR1_2M"
#define BLYNK_TEMPLATE_NAME "NodeMCU"
#define BLYNK_AUTH_TOKEN "j3Z6QIM4iAeIYHjLyM7E0vECcBUFw2qT"

#define BLYNK_PRINT Serial
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = BLYNK_AUTH_TOKEN;
 
char ssid[] = "HASEEB"; // Your Wifi Name
char pass[] = "karachi00201"; // Your Wifi Password
 
//in the below code, we have set all values reverse
//For value==1, digitalWrite is "LOW" as the realy module is active "LOW" to turn device ON.
//For value==0, digitalWrite is "HIGH" as Optocoupler based relay is turned OFF when HIGH Input is given
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D0, LOW); 
    Serial.println("Forward,relay1"); //Setting Digital PIN as LOW to turn ON Device if relay module is "active low"
    digitalWrite(D1, LOW);
    Serial.println("Forward,relay2");
  }
  if(value == 0)
  {
     digitalWrite(D0, HIGH);
     Serial.println("Forward,relay1,Stop");//Setting Digital PIN as HIGH to turn OFF Device if relay module is "active low"
     digitalWrite(D1, HIGH);  
     Serial.println("Forward,relay2,Stop");
  }
}
 
BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D2, LOW);
    Serial.println("Backward relay3");
    digitalWrite(D3, LOW);
    Serial.println("Backward relay4");
  }
  if(value == 0)
  {
    digitalWrite(D2, HIGH);
    Serial.println("Backward relay3,Stop");
    digitalWrite(D3, HIGH);
    Serial.println("Backward relay4,Stop");
  }
}
 
BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D4, LOW);
    Serial.println("START CAR, relay5");
  }
  if(value == 0)
  {
    digitalWrite(D4, HIGH);
    Serial.println("STOP CAR, relay5"); 
  }
}
 
BLYNK_WRITE(V4)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    //digitalWrite(D3, LOW);
   // Serial.println("LED ON");
  }
  if(value == 0)
  {
     //digitalWrite(D3, HIGH);
     //Serial.println("LED OFF");
  }
}
 
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT); //GPIO 16 (equivalent to PIN 16 of Arduino)
  pinMode(D1,OUTPUT); //GPIO 05 (equivalent to PIN 05 of Arduino)
  pinMode(D2,OUTPUT);//GPIO 04 (equivalent to PIN 16 of Arduino)
  pinMode(D3,OUTPUT);//GPIO 00 (equivalent to PIN 00 of Arduino)
  pinMode(D4,OUTPUT);
}
 
void loop()
{
  Blynk.run();
}