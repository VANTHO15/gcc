#include "stm32f10x.h"

void gpio_initPC13(void)
{
	RCC->APB2ENR |= 0x10; /* Or  0b10000 --> Anabling Preiph GPIOC */
	GPIOC->CRH &= 0xFF0FFFFF;  /* Reset the PORT C PIN 13 */
	GPIOC->CRH |= 0x00300000;  /* Set Port C PIN 13 as Output  */
	GPIOC->ODR  |= 0x2000;     /* Set Port C Pin 13 */
}

void gpio_SetPinPC13(void)
{
	GPIOC->ODR  |= 0x2000;
}
void gpio_ResetPinPC13(void)
{
	GPIOC->ODR  &= ~0x2000;
}