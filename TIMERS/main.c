
#include <stdint.h>
#include<stm32f1xx.h>
volatile uint32_t count=0;
void TIM1_UP_IRQHandler(void)
{
	if(TIM1->SR & (1U<<0))
	{
		TIM1->SR &= ~(1U<<0); // CLEAR TIM1 SR
		//GPIOA->ODR ^=(1U<<5);	//PA5 LED
		count++;
	}
}
int main(void)
{
	RCC->APB2ENR |=(1U<<11);	//TIMER 1 CLOCK ENABLE
	RCC->APB2ENR |=(1U<<2);		//GPIOA CLOCK
	//CONFIGURATION
	GPIOA->CRL &= ~(0xF<<20);
	GPIOA->CRL |=(0x2<<20);
	// SET PSC
	TIM1->PSC =7999;
	// SET ARR
	TIM1->ARR =199;

	// TIM INTERRU PT
	TIM1->DIER |=(1U<<0);
	//ENABLE NVIC
	NVIC_EnableIRQ(TIM1_UP_IRQn);
	//START TIMER
	TIM1->CR1 |=(1U<<0);



	while(1)
	{
		/*while(!(TIM1->SR & (1U<<0)));

		TIM1->SR &= ~(1U<<0);
		GPIOA->ODR ^=(1U<<5);	//PA5 LED	*/

	}
}
