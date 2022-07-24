#include "../Inc/Device/stm32f411xe.h"
#include "../Inc/Port/port.h"

#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED_PIN			PIN5

#define GPIOCEN			(1U<<2)
#define PIN13			(1U<<13)
#define BTN_PIN			PIN13

int main()
{
	RCC->AHB1ENR |=	GPIOAEN;
	RCC->AHB1ENR |=	GPIOCEN;

//	GPIOA->MODER |= (1U<<10);
//	GPIOA->MODER &= ~(1U<<11);
//
//	GPIOC->MODER &= ~(1U<<26);
//	GPIOC->MODER &= ~(1U<<27);

	gpioInit(portConf);

	while(1)
	{
		if(GPIOC->IDR & BTN_PIN)
		{
			GPIOA->ODR = LED_PIN;
		}
		else
		{
			GPIOA->ODR = 0;
		}
	}
}
