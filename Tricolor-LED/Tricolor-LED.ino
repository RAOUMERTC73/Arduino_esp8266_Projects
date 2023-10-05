void setup(){
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(4, INPUT);

}


void loop(){
if (digitalRead(4) == HIGH)
{

 digitalWrite(10, HIGH); 
 delay(100);
 digitalWrite(10, LOW);
 delay(100);

 digitalWrite(11, HIGH); 
 delay(100);
 digitalWrite(11, LOW);
 delay(100);

 digitalWrite(12, HIGH);
 delay(100);
 digitalWrite(12, LOW);
 delay(100);
}
}
