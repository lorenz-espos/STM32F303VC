#include <stm32f30x.h>
short int flag=0;//flag 0==> led spento flag 1==> led acceso
void main()
{
  RCC->AHBENR|=RCC_AHBENR_GPIOEEN; //abilito il clock a GPIOE
  RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;// abilito il clock al timer
  GPIOE->MODER|=0X55550000;//abilito i led
  
 TIM2->DIER|=TIM_DIER_UIE;//abilito le interrupt
 NVIC->ISER[0]|=(1<<28);//seleziono l'ISR su TIM2
 
 TIM2->ARR=36000000;// numero di conteggi che desidero effettuare per un blink di 0,5 s
 TIM2->CNT=0;
 TIM2->CR1=1;//abilito il conteggio;
 
 while(1);
}


 void TIM2_IRQHandler(){
TIM2->SR&=~TIM_SR_UIF;
if(flag==0){
GPIOE->ODR=(1<<8);//accendo il led
flag=1;
}
else{
GPIOE->ODR=0;//spengo il led
flag=0;
}
   
}
