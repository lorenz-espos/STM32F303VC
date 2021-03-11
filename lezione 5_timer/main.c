#include <stm32f30x.h>
short int flag=0;
void main(){
  RCC->AHBENR|=RCC_AHBENR_GPIOEEN;//abilito gpioe
  RCC->APB1ENR|=RCC_APB1ENR_TIM2EN; //abilito tim2
  GPIOE->MODER=0X55550000;//imposto l'output digitale
  
  
 TIM2->CR1 =1;// abilito il contatore
  TIM2->ARR=4000000;//inserisco arr
  TIM2->CNT=0;//imposto cnt a 0
  
  while(1){
    if((TIM2->SR & TIM_SR_UIF)==TIM_SR_UIF && !flag){//accendo il led
      GPIOE->ODR=(1<<8);
      TIM2->SR &=~(TIM_SR_UIF);//reset contatore
      flag=1;
    }
       if((TIM2->SR & TIM_SR_UIF)==TIM_SR_UIF && flag){//spengo il led
      GPIOE->ODR&=~(1<<8);
      TIM2->SR &=~(TIM_SR_UIF);//reset contatore
      flag=0;
    }
    
    
  }
  
  
  
}