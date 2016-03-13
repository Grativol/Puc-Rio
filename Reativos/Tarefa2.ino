#define LED 13
#define BUT1 2
#define BUT2 3


int time1,time2,time3=0;
int flag=0;
int led_status=1;
int time_stamp=2000;
int state1=0;

void setup() 
{
  Serial.begin(9800);
  pinMode(LED,OUTPUT);
  pinMode(BUT1,INPUT);
  pinMode(BUT2,INPUT);
  
  digitalWrite(LED,led_status);
}

void loop()
{
  time1=millis();
  if(!flag)
  {
    if(time1-time2==time_stamp)
    {
      led_status=!led_status;
      digitalWrite(LED,led_status);
      Serial.println(time1-time2);
      
      time2=time1;
    }
  }
   
  if(digitalRead(BUT1)&& (time1-time3>500))
  {
    time_stamp/=2;
    time3=time1;
    time2=time1;
    Serial.println(time_stamp);
  }
  
  if(digitalRead(BUT2)&& (time1-time3>500))
  {
    time_stamp*=2;
    time3=time1;
    time2=time1;
    Serial.println(time_stamp);
  }
  
  if(digitalRead(BUT2)&& digitalRead(BUT1) && ((time1-time3<500) ||(time1-time2<500) ) )
    while(true)
      digitalWrite(LED,HIGH);
      
  
}
