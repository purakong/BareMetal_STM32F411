#include "../../Inc/Port/port.h"

uint32_t setGpioMode(gpioMode mode, uint32_t pinNumber);

gpioPortType portConf[PORT_MAX] =
{
		{GPIOA, 	0,  INPUT,			GPIO_EN	},
		{GPIOA, 	1,  OUTPUT, 		GPIO_DIS},
		{GPIOA,     2,  OUTPUT, 		GPIO_EN	},
		{GPIOA,     3,  ALT_FUNC, 		GPIO_EN	},
		{GPIOA,     4,  OUTPUT, 		GPIO_EN	},
		{GPIOA,     5,  OUTPUT, 		GPIO_EN	},
		{GPIOC,     13, INPUT, 			GPIO_EN	},
};


void gpioInit(gpioPortType * ports)
{
	uint8_t cnt;

	if(ports[cnt].enable)
	{
		for(cnt = 0; cnt<PORT_MAX; cnt++)
		{
			//Like This..
			ports[cnt].typeDef->MODER |= setGpioMode(ports[cnt].pinMode, ports[cnt].pinNumber);
		}
	}
}

uint32_t setGpioMode(gpioMode mode, uint32_t pinNumber)
{
	//Set Mode accroding to mode value
	uint32_t moder;

	switch(mode)
	{
		case INPUT:
			moder = 0;
			break;

		case OUTPUT:
			moder |= (0x1UL << (pinNumber * 2U));
			break;

		case ALT_FUNC:
			moder |= (0x1UL << (pinNumber * 2U));
			moder |= (0x2UL << (pinNumber * 2U)+1);
			break;

		default:
			//none
			break;
	}

	return moder;
}
