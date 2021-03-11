#include <stm32f30x.h>
short int flag=0;
void main()
{
  RCC->AHBENR|=RCC_AHBENR_GPIOEEN;
  RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
  GPIOE->MODER|=0X55550000;
  
 TIM2->DIER|=TIM_DIER_UIE;
 NVIC->ISER[0]|=(1<<28);
 
 TIM2->ARR=36000000;
 TIM2->CNT=0;
 TIM2->CR1=1;
 
 while(1);
}


 void TIM2_IRQHandler(){
TIM2->SR&=~TIM_SR_UIF;
if(flag==0){
GPIOE->ODR=(1<<8);
flag=1;
}
else{
GPIOE->ODR=0;
flag=0;
}
   
}
