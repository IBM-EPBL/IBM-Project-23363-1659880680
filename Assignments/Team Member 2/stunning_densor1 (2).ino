int trig=2;
int echo=3;

void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(2,INPUT);
  pinMode(12,OUTPUT);
}

void loop()
{
  //PIR Motion Sensor
   int motion=digitalRead(2);
   Serial.print("Position is :");
   Serial.println(motion);   

  //LED ON
  if(motion==1)
  {
    digitalWrite(12,HIGH);
  }
  
  //Buzzer For ultrasonic Sensor
  if(motion==100)
  {
  for(int i=0; i<=30000; i=i+100)
  {
  tone(12,i);
  delay(1000);
  noTone(12);
  delay(1000);
  }
  }
  
    //Temperate Sensor
  double a= analogRead(A2);
  double tem=(((a/1024)*5)-0.5)*100;
  Serial.print("Temp Value: ");
  Serial.println(tem);
  delay(1000);
  
  
  //LED ON
  if(tem>=100)
  {
    digitalWrite(12,HIGH);
  }
  
  //Buzzer for Temperature Sensor
  if(tem>=100)
  {
  for(int i=0; i<=30000; i=i+10)
  {
  tone(12,i);
  delay(1000);
  noTone(12);
  delay(1000);
  }
  }

   //LED OFF
  if(tem<100)
  {
    digitalWrite(12,LOW);
  }
}