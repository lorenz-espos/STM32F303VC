#include <stm32f30x.h>
int cont=0; //variabile di conteggio

void main(){
  
  RCC->AHBENR|=RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOEEN;//abilito il clock
  GPIOA->MODER &=~GPIO_MODER_MODER0;//abilito la linea in input per il tasto
  GPIOE->MODER=0X55550000;//abilito le linee dei led
  GPIOE->ODR=(255<<8);// all avvio tutti i led sono accesi
  while(1){
    if((GPIOA->IDR & GPIO_IDR_0)==GPIO_IDR_0 ){
      while((GPIOA->IDR & GPIO_IDR_0)==GPIO_IDR_0 );
  cont++;//incrementa la variabile di conteggio
  GPIOE->ODR=(cont<<8);//shifta cont a sinistra
  };
  
};
}