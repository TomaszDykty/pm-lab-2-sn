

/*
//231
#include <Arduino.h>
volatile int state = LOW;
void myISR();

int main() {
 init();  
 pinMode(12, OUTPUT); 
 pinMode(13, OUTPUT); 
 attachInterrupt(0, myISR, CHANGE);
  sei();  
  while (1) 
  {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  }
}

void myISR() {
 state = !state;
 digitalWrite(12, state);
}
*/
//232
#include <Arduino.h>
volatile int state = LOW;

int main() {
  init();
  DDRB |= B00110000;
  PORTD |= (1 << PORTD2);
  EICRA |= (1 << ISC00);
  EIMSK |= (1 << INT0);
  sei();
  while (1) {
      PORTB |= (1<< PORTB5);
    delay(500);
       PORTB &= !(1<< PORTB5);
    delay(500);

  }
}

ISR(INTO_vect){
  state = !state;
  digitalWrite(12, state);
}








/*
//224
#inculde <avr/io.h>
uint8_t button;
bool state = true;
void togglePinD13 (bool *state)
{
  PORTB = (*state << 5);
  *state = !(*state);
}
void delay()
{
  for (uint32_t j = 0x1FFFF; j > 0 ; j--)
  {  
    __asm__ __volatile__("nop");
  }
}
int main()
{
  DDRB &= !(1 << 0);
  DDRB |= (1 << 5);
  while (1)
  {
    button = (PINB & (1<<PINB0));
    if (button == 0)
    {
      togglePinD13(&state);
    }
    else
    {
        delay();
    }
    
    
  }
  
}

*/


/*
//223 nie wgrane
#inculde <avr/io.h>

uint8_t ledState[] = {0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x18, 0x3C, 0x7E};
uint8_t *pLedState = ledState ;
bool state = true;
void togglePinD13(bool *state)
{
  PORTB = (*state << 5);
  *state = !(*state);
}
void delay()
{
  for (uint32_t j = 0x2FFFF; j > 0 ; j--)
  {  
    __asm__ __volatile__("nop");
  }
}

int main()
{
 DDRB |= (1 << 5);
  DDRD |= 0xFF;
  while(1)
  {
    togglePinD13(&state);
    delay();
    for (uint8_t i = 0; i < sizeof(ledState) ; i++)
    {
      PORTD = ledState[i];
      delay();
    }
    pLedState = ledState;

    for (uint8_t i = 0; i < sizeof(ledState) ; i++)
    {
      PORTD = *pLedState;
      pLedState++;
      delay();
    }



  }

}

*/












/*
//222
 #include <avr/io.h>
#define LED_LENGTH 8
int main()
{
  
  DDRD |= 0XFF;
  while (1)
  {
      for (uint8_t i = 0;i <LED_LENGTH; i++)
      {
         PORTD = (1 << i); 
        for (uint8_t j = 0x1FFFF; j > 0 ; j--)
        {
          
          __asm__ __volatile__("nop");
        
        
        }

      }
      for (uint8_t i = 1; i < (LED_LENGTH - 1); i++)
      {
         PORTD = (PORTD >> 1); 
        for (uint8_t j = 0x1FFFF; j > 0 ; j--)
        {
          
          __asm__ __volatile__("nop");
        
        
        }

      }
  } 
}

*/





/*
 //2-2-1
#include <avr/io.h>
 int main()
{
  uint32_t i;

  DDRB |= (1 << 5);
  while (1)
  {
    PORTB |= (1 <<5);
  i = 0x3FFFF;
    do
    {
    __asm__ __volatile__("nop");
      }
    while (i--);
      PORTB &= !(1 <<5);
      i = 0x3FFFF;
        do
        { __asm__ __volatile__("nop");}
        while (i--);
  }
}
 
*/













 /*//222
 #include <avr/io.h>
#define LED_LENGTH 8
int main()
{
  
  DDRD |= 0XFF;
  while (1)
  {
      for (uint8_t i = 0;i <LED_LENGTH; i++)
      {
         PORTD = (1 << i); 
        for (uint8_t j = 0x1FFFF; j > 0 ; j--)
        {
          
          __as__ __volatile__("nop");
        
        
        }

      }
      for (uint8_t i = 1; i < (LED_LENGTH - 1); i++)
      {
         PORTD = (PORTD >> 1); 
        for (uint8_t j = 0x1FFFF; j > 0 ; j--)
        {
          
          __as__ __volatile__("nop");
        
        
        }

      }
  } 
}

*/






