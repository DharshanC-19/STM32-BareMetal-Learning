
#include <stdint.h>
#include<stm32f1xx.h>


/*uint8_t prev_state1,curr_state1;
uint8_t prev_state2,curr_state2;
uint8_t prev_state3,curr_state3;*/

void delay(uint32_t ms)
{
	for(uint32_t i=0; i<ms;i++)
	{
		SysTick ->LOAD =8000 -1;
		SysTick ->VAL =0;
		SysTick ->CTRL = 5;
		while((SysTick ->CTRL & (1U<<16))==0);
	}
}
void EXTI0_IRQHandler(void)
{
	if(EXTI->PR & (1U<<0))
	{
		EXTI->PR =(1U<<0); // CLEAR PR
		GPIOA->ODR ^= (1U<<5);
		delay(5000);
		GPIOA->ODR ^=(1U<<6);
		delay(5000);
		GPIOA->ODR ^=(1U<<7);
		delay(5000);
	}
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & (1U<<8))
	{
		EXTI->PR =(1U<<8); // CLEAR PR
		GPIOA->ODR ^= (1U<<5);
		delay(500);
		GPIOA->ODR ^= (1U<<6);
		delay(500);
		GPIOA->ODR ^= (1U<<7);
		delay(500);
	}
}

void 	EXTI15_10_IRQHandler(void)
{

	if(EXTI->PR & (1U<<13))
	{
		EXTI->PR =(1U<<13); // CLEAR PR
		GPIOA->ODR ^= (1U<<5);
		delay(1000);
		GPIOA->ODR ^= (1U<<6);
		delay(1000);
		GPIOA->ODR ^= (1U<<7);
		delay(1000);
	}

}
int main(void)
{
	RCC->APB2ENR|=(1U<<2); // GPIOA CLOCK
	RCC->APB2ENR|=(1U<<3); // GPIOB CLOCK
	RCC->APB2ENR|=(1U<<4); // GPIOC CLOCK
	RCC->APB2ENR|=(1U<<0); //AFIO CLOCK

	// CONFIGURATION PINS , CRL
	//GPIOA
	GPIOA->CRL &= ~((0xF<<0)|(0xF<<20) | (0xF<<24) | (0xF<<28)); // PIN0 PIN 5 PIN 6 PIN 7
	GPIOA->CRL |= (0x2<<20) | (0x2<<24) | (0x2<<28);  // 00 10 IN PIN0 PIN 5 PIN6 PIN 7
	GPIOA->CRL |= (0x8<<0); // 10 00 PULL UP PA0
	//GPIOB
	GPIOB->CRH &= ~(0xF<<0); //PB8
	GPIOB->CRH |= (0x8<<0);//10 00 PULL UP PB8

	//GPIOC
	GPIOC->CRH &= ~(0xF<<12); //PC13
	GPIOC->CRH |=(0x8<<12); // 10 00 PULL UP PC13

	GPIOA->ODR |=(1U<<0);
	GPIOB->ODR |=(1U<<8);
	GPIOC->ODR |=(1U<<13);


	 //EXTI[1] FOR PA0
	AFIO->EXTICR[0]&=~(0xF<<0); //PA0

	//EXTI[3] FOR PB8
	AFIO->EXTICR[2] &= ~(0xF<<0); // PB8
	AFIO->EXTICR[2] |= (0x1<<0);

	//EXTI[4] FOR PC PIN 12 AND 13
	AFIO->EXTICR[3] &= ~(0xF<<4);  //PC13
	AFIO->EXTICR[3] |=(0x2<<4);

	// ENABLE IMR FOR INTERRUPT
	EXTI->IMR |=(1U<<0) |(1U<<8) |(1U<<13); // IMR FOR PA0,PB8,PC13

	//FALLING DEGE TRIGGER SELECTION REGISTER
	EXTI->FTSR |=(1U<<0) |(1U<<8) |(1U<<13);// FTSR FOR PA0,PB8,PC13

	//EXTI PENDING REGISTER ENABLE
	EXTI->PR |=(1U<<0) |(1U<<8) |(1U<<13); //PR FOR PA0,PB8,PC13

	//NVIC PRIORITY GROUPING
	NVIC_SetPriorityGrouping(3);

	//NVIC PRIORITY
	NVIC_SetPriority(EXTI0_IRQn,2);
	NVIC_SetPriority(EXTI9_5_IRQn,1);
	NVIC_SetPriority(EXTI15_10_IRQn,0);

	//ENABLE NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	NVIC_EnableIRQ(EXTI15_10_IRQn);


	//GPIOC->CRH &= ~(0xF<<20); //PIN 13
	//GPIOC->CRH |= (0x8<<20); // 10 00 PULL UP

	// SYSTICK CONFIGURATION AND DEBOUNCE


	/*prev_state1 = (GPIOC->IDR & (1U<<10)) ? 1 : 0;
	prev_state2 = (GPIOC->IDR & (1U<<13)) ? 1 : 0;
	prev_state3 = (GPIOC->IDR & (1U<<12)) ? 1 : 0;*/

	while(1)
	{
				// INSIDE EVERYTHING WHILE  IS KNOWN AS POLLING (CHECKS AGAIN AND AGAIN)


		GPIOA->ODR ^= (1U<<5);delay(50);
		GPIOA->ODR ^=(1U<<6);delay(50);
		GPIOA->ODR ^=(1U<<7);delay(50);
	}

		/*curr_state1=(GPIOC->IDR & (1U<<10)) ? 1 : 0;
		curr_state2=(GPIOC->IDR & (1U<<13)) ? 1 : 0;
		curr_state3=(GPIOC->IDR & (1U<<12)) ? 1 : 0;

		//BUTTON 1
		if((prev_state1==1)&&(curr_state1==0))
		{
			delay(20);
			curr_state1=(GPIOC->IDR & (1U<<10)) ? 1 : 0;
			if(curr_state1==0)
			{

				GPIOA->ODR ^= (1U<<5);
				delay(1000);
			}


		}
		//BUTTON 2
		if((prev_state2==1)&&(curr_state2==0))
		{
			delay(20);
			curr_state2=(GPIOC->IDR & (1U<<13)) ? 1 : 0;
			if(curr_state2==0)
			{

				GPIOA->ODR ^= (1U<<6);
			}

		}
		// BUTTON 3
		if((prev_state3==1)&&(curr_state3==0))
		{
			delay(20);
			curr_state3=(GPIOC->IDR & (1U<<12)) ? 1 : 0;
			if(curr_state3==0)
			{
				GPIOA->ODR ^= (1U<<7);
			}

		}
		prev_state1 = curr_state1;
		prev_state2 = curr_state2;
		prev_state3 = curr_state3;

	}*/
}
