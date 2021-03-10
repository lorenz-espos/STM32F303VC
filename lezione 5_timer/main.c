#include <stm32f30x.h>
short int flag=0;
void main(){
  RCC->AHBENR|=RCC_AHBENR_GPIOEEN;
  RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
  GPIOE->MODER=0X55550000;
  
  
 TIM2->CR1 =1;
  TIM2->ARR=4000000;
  TIM2->CNT=0;
  
  while(1){
    if((TIM2->SR & TIM_SR_UIF)==TIM_SR_UIF && !flag){
      GPIOE->ODR=(1<<8);
      TIM2->SR &=~(TIM_SR_UIF);
      flag=1;
    }
       if((TIM2->SR & TIM_SR_UIF)==TIM_SR_UIF && flag){
      GPIOE->ODR&=~(1<<8);
      TIM2->SR &=~(TIM_SR_UIF);
      flag=0;
    }
    
    
  }
  
  
  
}