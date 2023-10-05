//CODE (Bluetooth Car)  by umertc21073
#define m1 5
#define m2 6
#define m3 9   //declares pins
#define m4 10
#define led1f 11
#define led2f 12
#define led1b 7
#define led2b 8
#define horn 2
int Speed =204;   // 0-255 range ha motor ki speed chang kar na ki PWM pins par  
 
void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(led1f, OUTPUT);
  pinMode(led2f, OUTPUT);
  pinMode(led1b, OUTPUT);
  pinMode(led2b, OUTPUT);
  pinMode(horn, OUTPUT);
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
     analogWrite(m1, Speed);
     analogWrite(m2, LOW);
     analogWrite(m3, Speed);
     analogWrite(m4, LOW);
   }
   if(voice == "backward"||voice=="B")
    { Serial.println("Going Backward !");
      analogWrite(m1, LOW);
      analogWrite(m2, Speed);
      analogWrite(m3, LOW);
      analogWrite(m4, Speed);
   }
   if(voice == "left"||voice=="L")
    { Serial.print("Going left !");
      analogWrite(m1, LOW);
      analogWrite(m2, Speed);
      analogWrite(m3, Speed);
      analogWrite(m4,LOW);
   }
   if(voice == "right"||voice=="R")
    { Serial.println("Going right !");
      analogWrite(m1, Speed);
      analogWrite(m2, LOW);
      analogWrite(m3, LOW);
      analogWrite(m4, Speed);
   }
  else if(voice == "stop"||voice=="S")
   { Serial.println("Car Stop !!");
     digitalWrite(m1, LOW);
     digitalWrite(m2, LOW);
     digitalWrite(m3, LOW);
     digitalWrite(m4, LOW);
  }
  else if(voice == "l"||voice == "G"||voice == "forward left")
   {  // forward left
     Serial.println("Forward Left !");
     analogWrite(m1, LOW);
     analogWrite(m2, LOW);
     analogWrite(m3, Speed);
     analogWrite(m4, LOW);
    }
  else if(voice == "r"||voice == "I"||voice =="forward right")
   {  //forward right
     Serial.println("Forward Right !");
     analogWrite(m1, Speed);
     analogWrite(m2, LOW);
     analogWrite(m3, LOW);
     analogWrite(m4, LOW);
    }
  else if(voice == "m"||voice == "H"||voice == "backward left")
   {
       //backward left
     Serial.println("Backward Left !");
     analogWrite(m1, LOW);
     analogWrite(m2, LOW);
     analogWrite(m3, LOW);
     analogWrite(m4, Speed);
    }
  else if(voice == "n"||voice == "J"||voice == "backward right")
   {
      //backward right
     Serial.println("Backward Right !"); 
     analogWrite(m1, LOW);
     analogWrite(m2, Speed);
     analogWrite(m3, LOW);
     analogWrite(m4, LOW);
    }
  else if(voice == "V"||voice == "on"){Serial.println("HORN ON"); digitalWrite(horn,HIGH);}
  else if(voice == "v"||voice == "of"){Serial.println("HORN OFF"); digitalWrite(horn,LOW);}
  else if(voice == "W"||voice == "front light on")
   { Serial.println("FRONT LIGHT ON ");
     digitalWrite(led1f, HIGH);
     digitalWrite(led2f, HIGH);
    }
  else if(voice == "w"||voice == "front light off")
   { Serial.println("FRONT LIGHT OFF ");
     digitalWrite(led1f, LOW);
     digitalWrite(led2f, LOW);
    }
  else if(voice == "U"||voice == "back light on")
   { Serial.println("BACK LIGHT ON ");
     digitalWrite(led1b, HIGH);
     digitalWrite(led2b, HIGH);
    }
  else if(voice == "u"||voice == "back light off")
   { Serial.println("BACK LIGHT OFF ");
     digitalWrite(led1b, LOW);
     digitalWrite(led2b, LOW);
    }  
  else if(voice=="0"){Serial.println("Motor Speed = 100 range"); Speed = 100;}
  else if(voice=="1"){Serial.println("Motor Speed = 140 range"); Speed = 140;}
  else if(voice=="2"){Serial.println("Motor Speed = 153 range"); Speed = 153;}
  else if(voice=="3"){Serial.println("Motor Speed = 165 range"); Speed = 165;}
  else if(voice=="4"){Serial.println("Motor Speed = 178 range"); Speed = 178;}
  else if(voice=="5"){Serial.println("Motor Speed = 191 range"); Speed = 191;}
  else if(voice=="6"){Serial.println("Motor Speed = 204 range"); Speed = 204;}
  else if(voice=="7"){Serial.println("Motor Speed = 216 range"); Speed = 216;}
  else if(voice=="8"){Serial.println("Motor Speed = 228 range"); Speed = 228;}
  else if(voice=="9"){Serial.println("Motor Speed = 240 range"); Speed = 240;}
  else if(voice=="q"){Serial.println("Motor Speed = 255 range END !"); Speed = 255;}
  else if(voice =="Y"||voice == "X"||voice =="front and back light on")
   { Serial.println("Motor Speed = 204 && ALL Light ON ");
     Speed = 204; 
     digitalWrite(led1f, HIGH);
     digitalWrite(led2f, HIGH);
     digitalWrite(led1b, HIGH);
     digitalWrite(led2b, HIGH);
    }
  else if(voice == "y"||voice == "x"||voice =="front and back light off") 
   { Serial.println("Motor Speed = 204 && ALL Light oFF");
     Speed = 204;
     digitalWrite(led1f, LOW);
     digitalWrite(led2f, LOW);
     digitalWrite(led1b, LOW);
     digitalWrite(led2b, LOW);
    } 
    Serial.println("End");
} }


