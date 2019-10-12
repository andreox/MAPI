#include "stm32f30x.h"

//#define GPIOA 0x48000000
//#define GPIOE 0x48001000
int i;
void main(void) {

// punt = (unsigned int*) 0x40021014;
//*punt |= (1<<17);
RCC -> AHBENR |= (1<<21);
GPIOE -> MODER |= (1<<20);

while(1) {
GPIOE -> ODR |= (1<<10);
for(i=0; i<100000; i++);
GPIOE -> ODR &= (0<<10);
for(i=0; i<1000000; i++);
}


//punt = (unsigned int*) (GPIOA+0x00);
//*punt |= (1<<20);
//punt = (unsigned int*) (GPIOA+0x14);
//*punt |= (1<<10);
}