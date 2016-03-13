#define LED 13
#define BUT 2

int time1,time2=0;
int flag=0;
int led_status=1;

void setup() 
{
  pinMode(LED,OUTPUT);
  pinMode(BUT,INPUT);
  
  digitalWrite(LED,led_status);
}

void loop()
{
  time1=millis();
  int state= digitalRead(BUT);
  
  if(!flag)
  {
    if(time1-time2==1000)
    {
      led_status=!led_status;
      digitalWrite(LED,led_status);
      time2=time1;
    }
  }
    
  if(state)
    flag=1;


}
