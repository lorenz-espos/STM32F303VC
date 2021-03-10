#include <stm32f30x.h>
#include <math.h>
#include <stdio.h>
#define Tck 125*pow(10,-9)
int count=0;
int contatore=0;
float tau=0;
void main()
{
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN;//ABILITO IL CLOCK AL PULSANTE
 RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;//ABILITO IL CLOCK AL TIMER
 
 while(1){
   if((GPIOA->IDR & GPIO_IDR_0)== GPIO_IDR_0){
   TIM2->CR1=1;//ABILITO IL CONTEGGIO
   TIM2->CNT=0;
   while((GPIOA->IDR & GPIO_IDR_0)== GPIO_IDR_0);//attendo mentre il tasto è premuto
   TIM2->CR1=0;
   contatore=TIM2->CNT;//copio il valore del contatore
   tau=(float)contatore*Tck;//calcolo l' intervallo di tempo trascorso
   
   printf("conteggio %d:\t%f secondi\n",count,tau);
   count++;
          
   }
   
   
   
   
 }
  
}
