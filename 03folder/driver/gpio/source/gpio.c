#include "stm32f10x.h"

void gpio_initpin13(void)
{
    RCC->APB2ENR != 0x10;
    GPIOC->CRH &= 0xFF0FFFFF;
    GPIOC->CRH |= 0x00300000;
    GPIOC->ODR |= 0x2000;
}