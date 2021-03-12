#include <stm32f30x.h>
float risultato;

void ADCsetup(){//si effettua a adc disabilitato
  ADC1->CR &=~ADC_CR_ADVREGEN_1;//10->00
  ADC1->CR|=ADC_CR_ADVREGEN_0;//00->01
  for(int i=0;i<1000;i++);//attendo 10us
  
  ADC1_2->CCR|=ADC12_CCR_CKMODE_0;//abilito il clock dal bus ahb
  
  ADC1->CR|=ADC_CR_ADCAL;//avvio la calibrazione
  while((ADC1->ISR & ADC_ISR_ADRD) != ADC_ISR_ADRD);
  
  ADC1->CR|=ADC_CR_ADEN;
  while((ADC1->ISR & ADC_ISR_ADRD) != ADC_ISR_ADRD);
  
  ADC1->CFGR |=ADC_CFGR_CONT;
  ADC1->SQR1 =ADC_SQR1_SQ1_0;
  ADC1->SQR1 &=~ADC_SQR1_L;
  ADC1->SMPR1 |= ADC_SMPR1_SMP1;
  
  
  
}


void main()
{
  
RCC->AHBENR|=RCC_AHBENR_GPIOAEN | RCC_AHBENR_ADC12EN;//abilito il clock a GPIOA E ADC12
GPIOA->MODER |=GPIO_MODER_MODER0;//moder in modalita 11
ADCsetup();
ADC1->CR |=ADC_CR_ADSTART;

while(1){
  while((ADC1->ISR & ADC_ISR_EOC) != ADC_ISR_EOC);//ATTENDI EOC
  
  risultato=ADC1->DR*(3.0/4096.0);
}

}


