
unsigned int* punt;
int main()
{
  punt = (unsigned int*)0x40021014;
  *punt |= 1<<21;
  
  punt = (unsigned int*)0x48001000;
  *punt |= 1<<16;
  
  punt = (unsigned int*)0x48001014;
  *punt |= 1<<8;
  
  return 0;
}
