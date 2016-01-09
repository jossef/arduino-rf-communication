//Transmitter Code

#include <VirtualWire.h>

void setup()
{

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  vw_set_ptt_inverted(true); //

  vw_set_tx_pin(12);
  vw_setup(1000);
}

bool state = true;
char *controller;

void loop()
{

  if (state)
  {
    controller = "1";
    digitalWrite(13, HIGH);
  }
  else
  {
    controller = "0";
    digitalWrite(13, LOW);
  }
  
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx();

  delay(300);

  state = !state;
}
