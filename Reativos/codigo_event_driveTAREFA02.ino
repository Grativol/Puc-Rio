
// Variáveis API///////////////////////////////////////////////////////
unsigned long timer1 = 0, timer2 = 0, timer1_marca = 0, timer2_marca = 0;
unsigned long timer1_flag = 0, timer2_flag = 0;
bool flag_button = 0, stamp_2 = 0, flag = 0;
//////////////////////////////////////////////////////////////////////

#define BUTTON1 2
#define BUTTON2 3
#define LED 13

int vel_led = 2000;
int state_led = 0;
int pin1 = 0, pin2 = 0;

void button_listen (int pin) // “pin” passado deve gerar notificações
{
  if (!flag_button)
    timer1_flag = millis();
  else
  {
    timer2_flag = millis();
    flag_button = !flag_button;
  }

  if (timer1_flag - timer2_flag >= 150)
  {
    if ( digitalRead(pin) == HIGH)
    {
      flag_button = !flag_button;
      button_changed(pin, 1);

    }
  }
}

void timer_set (int ms) // timer deve expirar após “ms” milisegundos
{
  timer1 = timer2 = millis();

  if ( !stamp_2 )
  {
    if (timer1 - timer1_marca >= ms)
    {
      timer_expired();
      timer1_marca = timer1;
    }
  }
  else
  {
    if (timer2 - timer2_marca >= ms)
    {
      timer_expired();
      timer2_marca = timer2;
      flag = 1;
    }
  }
}
void button_changed (int pin, int v)// notifica que “pin” mudou para “v”
{
  if (pin == 2 && v == 1)
  {
    vel_led -= 250;
    pin1 = 1;
  }

  if (pin == 3 && v == 1)
  {
    vel_led += 250;
    pin2 = 1;
  }

  timer_set(500);
}

void timer_expired(void)// notifica que o timer expirou
{
  if (!flag)
  {
    state_led = !state_led;
    digitalWrite(LED, state_led);
  }
  else
  {
    pin1 = pin2 = 0;
    flag = 0;
    Serial.println("sim");
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  button_listen(2);
  timer_set(vel_led);
  button_listen(3);

  stamp_2 = 1;
  timer_set(500);
  stamp_2 = 0;

  if (pin1 && pin2)
    while (true)
      digitalWrite(LED, HIGH);




}
