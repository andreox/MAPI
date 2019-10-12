/*      0x40021000 +
        0x00000014
        ----------
        0x40020014


        0b11000110 |
        0b00100000
        -----------
        0b11100110
*/
unsigned int* punt;

int main()
{
  punt = (unsigned int*)0x40021014;
  *punt |= (unsigned int)1<<21;
  
  return 0;
}
