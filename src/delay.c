#include <at89s8253.h>

void delay_ms(unsigned int time){
	unsigned char i,limit;
	limit=(time/50);
	for(i=0;i<limit;i++)
    {
      TMOD=0x01;
      TL0=0xB0;
      TH0=0x04;
      TR0=1;
      while(!TF0);
      TF0=0;
      TR0=0;
    }
}

void delay_us(unsigned int time)
{
  unsigned char i,limit;
  limit=(time/100);
  for(i=0;i<limit;i++)
    {
      TMOD=0x12;
      TL0=0x7B;
      TH0=0x7B;
      TR0=1;
      while(!TF0);
      TF0=0;
      TR0=0;
    }
}

void delay_100ns(unsigned int time)
{
  unsigned char i,limit;
  limit = time;
  for(i=0;i<limit;i++)
    {
      SCON = 0x50;
      TL0 = 0xFF;
      TH0 = 0xFF;
      TR0 = 1;
      while(!TF0);
      TF0=0;
      TR0=0;
    }
}
