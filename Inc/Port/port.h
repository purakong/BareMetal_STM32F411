#ifndef PORT_PORT_H_
#define PORT_PORT_H_

#include "../Device/stm32f411xe.h"
#include "sys/_stdint.h"

#define PORT_MAX		(7U)

#define GPIO_EN			(1U)
#define GPIO_DIS		(0U)

typedef enum
{
	INPUT,
	OUTPUT,
	ALT_FUNC,
	ANALOG
}gpioMode;

typedef struct
{
	GPIO_TypeDef * typeDef;
	uint32_t pinNumber;
	gpioMode pinMode;
	uint8_t enable;
}gpioPortType;

extern gpioPortType portConf[PORT_MAX];

extern void gpioInit(gpioPortType * ports);


#endif /* PORT_PORT_H_ */
