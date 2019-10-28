#include "stm32f30x.h"
#include <math.h>
#include <stdio.h>

#define TCK 125*pow(10,-9)

void main() {

	RCC->AHBENR |= RCC_AHBENR_GPIOAEN ;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;

	while(1) {

		if ( (GPIOA->IDR & 1) == 1 ) {

				TIM2->CR1 |= TIM_CR1_CEN ;
				TIM2->CNT = 0 ;

				while( (GPIOA->IDR & 1) == 1 ) ;

				TIM2->CR1 &= ~TIM_CE1_CEN ;
				int conteggio = TIM2->CNT ;
				float tau = (float) conteggio * TCK ;

				printf(" tau : %f\n",tau) ;

		}
	}
}
