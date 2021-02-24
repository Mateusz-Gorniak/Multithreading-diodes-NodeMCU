#include <Arduino.h>

#define pin0 16
#define pin1 5
#define pin2 4

//"delays" value
uint32_t Time1 = 1500;
uint32_t Time2 = 750;
uint32_t Time3 = 325;

uint32_t previous_millis1;
uint32_t previous_millis2;
uint32_t previous_millis3;

int presentTime; // the time returned by millis()

//function to change led state
void digitalToggle(uint8_t pin);

void setup()
{
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
  presentTime = millis();

  if ((presentTime - previous_millis1) >= Time1)
  {
    previous_millis1 = millis();
    digitalToggle(16);
  }
  if ((presentTime - previous_millis2) >= Time2)
  {
    previous_millis2 = millis();
    digitalToggle(5);
  }
  if ((presentTime - previous_millis3) >= Time3)
  {
    previous_millis3 = millis();
    digitalToggle(4);
  }
}
void digitalToggle(uint8_t pin)
{
  digitalWrite(pin, !digitalRead(pin));
}