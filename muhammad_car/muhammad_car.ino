//CODE (Bluetooth Car)  by umertc21073
#define m1 D0
#define m2 D1
#define m3 D2   //declares pins
#define m4 D3

 
void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
 
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()> 0 )
  {
  String voice = Serial.readString();
  Serial.println("MESSAGE FROM THE PHONE :" +voice);
  if(voice == "forward"||voice=="F")
   { Serial.println("Going forward !");
     digitalWrite(m1, LOW); 
     Serial.println("Forward,relay1  on"); 
     digitalWrite(m2, LOW);
     Serial.println("Forward,relay2  on");
     digitalWrite(m3, HIGH);
     Serial.println("Backward relay3, off");
     digitalWrite(m4, HIGH);
     Serial.println("Backward relay4,off");
   }
    if(voice == "backward"||voice=="B")
    { Serial.println("Going Backward !");
      digitalWrite(m3, LOW);
      Serial.println("Backward relay3  on");
      digitalWrite(m4, LOW);
      Serial.println("Backward relay4  on");
      digitalWrite(m1, HIGH);
      Serial.println("Forward,relay1,off");
      digitalWrite(m2, HIGH);  
      Serial.println("Forward,relay2,off");
   }
  else if(voice == "stop"||voice=="S")
   { Serial.println("Car Stop !!");
     digitalWrite(m1, HIGH);
     Serial.println("Forward,relay1,Stop");//Setting Digital PIN as HIGH to turn OFF Device if relay module is "active low"
     digitalWrite(m2, HIGH);  
     Serial.println("Forward,relay2,Stop");
     digitalWrite(m3, HIGH);
     Serial.println("Backward relay3,Stop");
     digitalWrite(m4, HIGH);
     Serial.println("Backward relay4,Stop");
  }
  
    Serial.println("End");
}

 }


