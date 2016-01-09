//Reciever Code

#include <VirtualWire.h>

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(1000);  // Bits per sec
  vw_rx_start();
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    if (buf[0] == '1') {
      digitalWrite(13, 1);
    }
    if (buf[0] == '0') {
      digitalWrite(13, 0);
    }
  }
}
