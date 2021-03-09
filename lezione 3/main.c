#define RCC_AHBENR (unsigned int *) 0x40021014;
#define GPIOA_MODER (unsigned int *) 0x48000000;
#define GPIOE_MODER (unsigned int *) 0x48001000;
#define GPIOE_ODR (unsigned int *) 0x48001014;
#define GPIOA_IDR (unsigned int *) 0x48000010;
unsigned int *p;
void main()
{
 p=(unsigned int*)RCC_AHBENR;
 *p=(1<<21)|(1<<17);//abilito il clock a gpioe e gpioa
 
   p=(unsigned int *)GPIOE_MODER;
  *p=(1<<16);//abilito moder 8
  
  p=(unsigned int*)GPIOA_MODER;
  *p&=0xFFFFFFFC;//impostro 00 sulla linea zero attraverso una and
  

  while(1){
    p=(unsigned int*)GPIOA_IDR;
    if((*p&1)==1){//se il pulsante viene premuto si accende il led blu
      p=(unsigned int*)GPIOE_ODR;
      *p=1<<8;
  }
    else{
       p=(unsigned int*)GPIOE_ODR;
      *p&=~(1<<8);//se il pulsante viene rilasciato il led si spegne
    }
  
  
}
}
