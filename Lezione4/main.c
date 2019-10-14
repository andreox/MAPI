/*Abilito GPIOA
Configuro PA0 come input digitale
se IDR ( linea 0 ) è alto //se il pulsante è premuto
	accendi led

altrimenti
	spegni led
*/

#include "stm32f30x.h"

void main( void ) {

	RCC->AHBENR = RCC_AHBENR_GPIOEEN ; //Abilito GPIOE per l'accensione del LED 
	RCC->AHBENR = RCC_AHBENR_GPIOAEN ; //Abilito GPIOA per il controllo sul pulsante User

	GPIOA->MODER &=~ ( 1 << 0 ) ;
	GPIOA->MODER &=~ ( 1 << 1 ) ; //Abilito GPIOA e lo se potrei anche fare GPIOA->MODER &=~ ( 3 << 0 ) ;
	GPIOE->MODER |= ( 1 << 20 ) ;
	
	while ( 1 ) {

		if ( GPIOA->IDR & ( 1 << 0 ) == ( 1 << 0 ) { //Il pulsante user, se premuto , setta a 1 PA0 : verifico se è stata effettuata tale op
	 		
			GPIOE->ODR |= ( 1 << 10 ) ; // Accendo il led
			for ( unsigned int i = 0 ; i < 100000 ; i++ ) ;
		}

		else GPIOE->ODR &=~ ( 1 << 10 ) ; // Altrimenti spengo il led ( premo 2 volte User sullo schedino ) 

	}

}
