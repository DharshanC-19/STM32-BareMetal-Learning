
#include <stdint.h>
#include<stm32f1xx.h>


void delay( volatile uint32_t delay)
{
	while(delay--);
}


int main(void)
{
	RCC->APB2ENR|=(1U<<2); // GPIOA CLOCK
	RCC->APB2ENR|=(1U<<3); // GPIOB CLOCK
	RCC->APB2ENR|=(1U<<4); // GPIOC CLOCK

	// CONFIGURATION PINS , CRL
	GPIOA->CRL &= ~(0xF<<20); //PIN 5
	GPIOA->CRL |=(0x2<<20);  // 00 10

	GPIOB->CRH &= ~(0xF<<4); //PB9
	GPIOB->CRH |=(0x2<<4);

	GPIOC->CRL &= ~(0xF<<28); //PC7
	GPIOC->CRL |=(0x2<<28);


	while(1)
	{
		GPIOA->ODR ^=(1U<<5);// PA5
		delay(1000000);

		GPIOB->ODR |=(1U<<9); //PB9
		delay(1000000);
		GPIOB->ODR &= ~(1U<<9);
		delay(1000000);
		GPIOC->ODR |=(1U<<7); //PC7
		delay(1000000);
		GPIOC->ODR &= ~(1U<<7);
		delay(1000000);

		GPIOA->ODR |=(1U<<5);// PA5
		GPIOB->ODR |=(1U<<9);
		delay(1000000);
		GPIOA->ODR &= ~(1U<<5);// PA5
		GPIOB->ODR &= ~(1U<<9);//PB9
		delay(1000000);
		GPIOC->ODR |=(1U<<7); //PC7
		delay(1000000);
		GPIOC->ODR &= ~(1U<<7);
		delay(1000000);

		GPIOA->ODR |=(1U<<5);// PA5
		delay(1000000);
		GPIOA->ODR &= ~(1U<<5);// PA5
		delay(1000000);
		GPIOB->ODR |=(1U<<9); //PB9
		GPIOC->ODR |=(1U<<7); //PC7
		delay(1000000);
		GPIOB->ODR &= ~(1U<<9);
		GPIOC->ODR &= ~(1U<<7);
		delay(1000000);

		GPIOA->ODR |=(1U<<5);// PA5
		delay(100000);
		GPIOA->ODR &= ~(1U<<5);// PA5
		delay(100000);
		GPIOB->ODR |=(1U<<9); //PB9
		delay(100000);
		GPIOB->ODR &= ~(1U<<9);
		delay(100000);
		GPIOC->ODR |=(1U<<7); //PC7
		delay(100000);
		GPIOC->ODR &= ~(1U<<7);
		delay(100000);

	}
}

