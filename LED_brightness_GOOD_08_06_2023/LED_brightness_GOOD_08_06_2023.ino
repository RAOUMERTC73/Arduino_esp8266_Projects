#define BLYNK_TEMPLATE_ID "TMPL6sTVx2PsK"
#define BLYNK_TEMPLATE_NAME "Home Automation System"
#define BLYNK_AUTH_TOKEN "wZD5yH4k8z3I9-3xIMEA6fOVE6vquafj"

#define BLYNK_PRINT Serial
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

int pinDHT11 = D0;
int Kfpin = D1;
int Kled = D2;
int Rfpin = D3;
int Rled1 = D4;
int Rled2 = D5;
int TVled1 = D6;
int TVled2 = D7;
int Wled = D8;


SimpleDHT11 dht11(pinDHT11);

 
char auth[] = BLYNK_AUTH_TOKEN;
 
char ssid[] = "HASEEB"; // Your Wifi Name
char pass[] = "karachi00201"; // Your Wifi Password
 
BLYNK_WRITE(V2){  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(Rled1,pinValue);
  //Blynk.virtualWrite(V0, pinValue);
  Serial.print("V2 Slider value is: ");
  Serial.println(pinValue);

}
BLYNK_WRITE(V3){  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(Rled2,pinValue);
  //Blynk.virtualWrite(V0, pinValue);
  Serial.print("V3 Slider value is: ");
  Serial.println(pinValue);

}
BLYNK_WRITE(V4){  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(Kled,pinValue);
  //Blynk.virtualWrite(V0, pinValue);
  Serial.print("V4 Slider value is: ");
  Serial.println(pinValue);

}
BLYNK_WRITE(V5){  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(TVled1,pinValue);
  //Blynk.virtualWrite(V0, pinValue);
  Serial.print("V5 Slider value is: ");
  Serial.println(pinValue);

}
BLYNK_WRITE(V6){  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(TVled2,pinValue);
  //Blynk.virtualWrite(V0, pinValue);
  Serial.print("V6 Slider value is: ");
  Serial.println(pinValue);

}
BLYNK_WRITE(V9){  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(Wled,pinValue);
  //Blynk.virtualWrite(V0, pinValue);
  Serial.print("V9 Slider value is: ");
  Serial.println(pinValue);

}
BLYNK_WRITE(V7){     // room fan   relay
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("V7 Slider value is: ");
  Serial.println(pinValue);
  if(pinValue == 1)
  {
    digitalWrite(Rfpin, LOW);
    Serial.println("Room Fan On, relay1");
  }
  if(pinValue == 0)
  {
    digitalWrite(Rfpin, HIGH);
    Serial.println("Room Fan Off, relay1"); 
  }

}
BLYNK_WRITE(V8){    //kitchen fan relay
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("V8 Slider value is: ");
  Serial.println(pinValue);
  if(pinValue == 1)
  {
    digitalWrite(Kfpin, LOW);
    Serial.println("Kitchen Fan On, relay2");
  }
  if(pinValue == 0)
  {
    digitalWrite(Kfpin, HIGH);
    Serial.println("kitchen Fan Off, relay2"); 
  }

}



void setup(){
  // Debug console
  Serial.begin(9600);
  pinMode(Kfpin,OUTPUT); 
  pinMode(Kled,OUTPUT);
  pinMode(Rfpin,OUTPUT);
  pinMode(Rled1,OUTPUT);
  pinMode(Rled2,OUTPUT);
  pinMode(TVled1,OUTPUT);
  pinMode(TVled2,OUTPUT);
  pinMode(Wled,OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  delay(500);
  Serial.println("DHT11 Humidity &    Temperature Sensor\n\n");
  delay(1000);

}

void loop(){  
  byte temperature = 0;
  byte humidity = 0;

  dht11.read(pinDHT11, &temperature, &humidity, NULL);
  Serial.print(" Temperature & Humidity : ");
  Serial.print((int)temperature); 
  Serial.print(" *C  "); 
  Serial.print((int)humidity); 
  Serial.println(" % H");
  // SEND the sensor data to blynk app
  Blynk.virtualWrite(V0,temperature);
  Blynk.virtualWrite(V1,humidity);


   if(temperature > 30 & humidity > 60 ){
     //   digitalWrite(Kfpin,LOW);
        Serial.println("on kitchen fan");
   }else{
       //s digitalWrite(Kfpin,HIGH);
        Serial.println("off kitchen fan");
   }

  delay(2000);
  
  Blynk.run();

}