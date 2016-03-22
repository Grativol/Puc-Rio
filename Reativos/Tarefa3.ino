
// Variáveis API///////////////////////////////////////////////////////
unsigned long timer1=0,timer2=0,timer1_marca=0,timer2_marca=0;
unsigned long timer1_flag=0, timer2_flag=0;
bool flag_button=0,flag_timer1=0,flag_timer2=0;
//////////////////////////////////////////////////////////////////////

void button_listen (int pin) // “pin” passado deve gerar notificações
{
  if(!flag_button)
    timer1_flag=millis();
    else
    {
      timer2_flag=millis();
      flag_button=!flag_button;
    }
    
   if(timer1_flag-timer2_flag>=250)
   {
     if( digitalRead(pin)==HIGH)
     {
       flag_button=!flag_button;
       button_changed(pin,1);
      
     }
   }
}

void timer_set (int ms) // timer deve expirar após “ms” milisegundos
{
  timer1=timer2=millis();
 
  if(timer1-timer1_marca>=ms)
  {
    timer_expired();
    timer1_marca=timer1;
    flag_timer1=1;
  }
   else
      if(timer2-timer2_marca>=ms)
      {
        timer_expired();
        timer2_marca=timer2;
        flag_timer2=1;
      }
}

void button_changed (int pin, int v)// notifica que “pin” mudou para “v”
{

}

void timer_expired(void)// notifica que o timer expirou
{

}
