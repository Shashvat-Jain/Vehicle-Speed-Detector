int ir1 = 2;
int ir2 = 3;

int T1;
int T2;
int T;
int flag = 0;

float distance = 0.15;
float Speed;

void setup() {
  attachInterrupt(digitalPinToInterrupt(ir1),ISR1,RISING);
  attachInterrupt(digitalPinToInterrupt(ir2),ISR2,FALLING);
  Serial.println("Car Over Speed Measurement");
  Serial.begin(9600);
}

void ISR1()
{
  T1 = millis(); 
  if (flag == 0) 
    {
      flag = 1;
    }
  else 
    {
      flag = 0;
    }
}

void ISR2()
{
  T2 = millis();
  if (flag == 0) 
    {
      flag = 1;
    }
  else 
    {
      flag = 0;
    }
}


void loop() 
{
  
  if (flag == 0){
  if(T1 > T2) 
  {
    T = T1 - T2;  
    Speed = (distance*1000)/T;
  }
  else if (T2 > T1) 
  {
    T = T2 - T1;  
    Speed = (distance*1000)/T;
  }
  else 
  {
    Speed = 0;
  }
  }
  
  if (Speed == 0) 
  { 
    Serial.println("No car detected");
    delay(1000);
  }
  else 
  { 
    Serial.print(Speed);
    Serial.println(" m/sec");
    if(Speed > 1)
    {
      Serial.println("Over Speeding car detected");
    }
    delay(1000);
    T1 = 0;
    T2 = 0;
  }
}
