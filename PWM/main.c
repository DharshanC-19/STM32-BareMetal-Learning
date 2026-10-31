#include<stdint.h>
#include "stm32f1xx.h"
/*
void motor_control(void)
{
	TIM2->PSC=7999;
	TIM2->ARR=999;
	TIM2->CCR1 =250;
	TIM2->CCMR1 &= ~(7U<<4);
	TIM2->CCMR1 |= (6U<<4);
	TIM2->CCMR1|=(1U<<3);
	TIM2->CCER |=(1U<<0);
	TIM2->CR1 |=(1U<<0);
}*/

void delay(void)
{
    for (volatile uint32_t i = 0; i < 800000; i++);
}

int main()
{
	 // Enable GPIOA clock
	    RCC->APB2ENR |= (1 << 2);

	    // PA5 → Output, 2 MHz
	    GPIOA->CRL &= ~(0xF << 20);
	    GPIOA->CRL |=  (0x2 << 20);

	    while (1)
	    {
	        GPIOA->ODR |= (1 << 5);    // Buzzer ON
	        delay();

	        GPIOA->ODR &= ~(1 << 5);   // Buzzer OFF
	        delay();
	    }
}


/*RCC->APB1ENR |=(1U<<0);//TIM2 CLOCK ENABLE
	RCC->APB2ENR |=(1U<<2);//GPIOA CLOCK ENABLE

	//CONFIGURE
	GPIOA->CRL &= ~(0xF<<0); //PAO AFIO
	GPIOA->CRL |=(0xB<<0); // 10 11

	TIM2->PSC =7999;	//SPEED
	TIM2->ARR=999;		// MAXIMUM COUNT
	TIM2->CCR1 =150;	//DUTY CYCLE = (500/1000)x100  =  50%
	TIM2->CCMR1 |=(6U<<4); // 110 PWM MODE
	TIM2->CCMR1 |=(1U<<3); // OCIPE PRE LOAD
	TIM2->CCER |=(1U<<0); // OUTPUT CAPTTURE ENABLE
	TIM2->CR1 |=(1U<<0); // CONTROL REGISTER ENABLE





	RCC->APB1ENR |= (1U<<0); // tim2 clk
	RCC->APB2ENR |= (1U<<0) ;//afio clk
	RCC->APB2ENR |= (1U<<2) ;//gpio a clk


	//CONF
	GPIOA->CRL &=  ~(0xF << 0);	//PA0
	GPIOA->CRL |= (0xB <<0);

	GPIOA->CRL &=  ~(0xF << 4);	//PA1
	GPIOA->CRL |= (0x2 <<4);

	GPIOA->CRL &=  ~(0xF << 8);	//PA2
	GPIOA->CRL |= (0x2 <<8);

	//direction
	GPIOA->BSRR=(1U<<1);
	GPIOA->BSRR=(1U<<(2 +16));

	motor_control();




	 */
