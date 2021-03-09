#include <stm32f30x.h>
void main(){
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN |RCC_AHBENR_GPIOEEN;//abilito il clock  di GPIOE e di GPIOA
  GPIOE->MODER =GPIO_MODER_MODER8_0; //alza moder 8 come output digitale
  GPIOA->MODER&=~GPIO_MODER_MODER0;//imposta moder 0 come imput digitale 00
  
  while(1){
    if((GPIOA->IDR & GPIO_IDR_0)==GPIO_IDR_0){
    GPIOE->ODR=(1<<8);
    }
  else
  GPIOE->ODR=0;
  }
}