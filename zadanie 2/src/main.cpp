




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
/*//223
#inculde <avr/io.h>

uint8_t ledState[] = {0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x18, 0x3C, 0x7E};
uint8_t *pLedState = ledState ;
bool state = true;
void togglePinD13(bool *state)
{
  PORTB = (*state << 5);
  *state = !(*state);
}

*/







