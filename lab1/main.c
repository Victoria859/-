#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>


void delayL1(int millisL1);
void initL1 (void);

int main(void)
{ 
initL1();
	
while (1) 
	{
 GPIOA->ODR |= GPIO_Pin_6;
 delayL1 (9);
	
 GPIOA->ODR &= ~GPIO_Pin_6;
 delayL1 (7);
 }
}

void delayL1 (int millisL1)
	{
for(int i=0;i< millisL1*0x010000 ;i++);
  }

void initL1 (void) 
	{
 GPIO_InitTypeDef GPIO_InitS;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 GPIO_InitS.GPIO_Pin = GPIO_Pin_6;
 GPIO_InitS.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitS.GPIO_Speed = GPIO_Speed_2MHz;
 GPIO_Init(GPIOA, & GPIO_InitS);
 GPIO_SetBits(GPIOA, GPIO_Pin_6);
  }
