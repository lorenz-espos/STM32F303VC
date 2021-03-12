#include <stm32f30x.h>
#include <stdio.h>
//vanno cortociruitati PA4 e PA2
int codice_in=500;//valore che va da [0;2^n-1]
float tensione_out;

void DACSetup(){
DAC1->CR|=DAC_CR_EN1;
DAC1->SDHR12R1=codice_in;
for(int i=0;i<1000;i++);//tempo di attesa per avere una tensione stabile
}
void ADCSetup(){
ADC1->CR&=˜ADC_CR_ADVREGEN_1;
ADC1->CR=ADC_CR_ADVREGEN_0
for(int i=0;i<1000;i++);//attendo l'abilitazione del regolatore di tensione;

ADC1_2->CCR!=ADC1_2_CCR_CKMODE_0;

ADC1->CR|=ADC_CR_ADCAL;
while ((ADC1->ISR & ADC_CR_ADCAL)!=ADC_CR_ADCAL);

ADC1->CR|=ADC_CR_ADEN;
while ((ADC1->ISR & ADC_CR_ADRD)!=ADC_CR_ADRD);

ADC1->CFGR &=˜ADC_CFGR_CONT; //CONVERSIONE SINGOLA
ADC1->SQR1=(3<<6);
ADC1->SQR2&=˜ADC_SQR1_L;//1 CONV
ADC1->SMPR1|=ADC_SMPR1_SMP3;
}

void main(){

    RCC->AHBENR|=RCC_AHBENR_GPIOAEN;
    RCC->AHBENR|=RCC_AHBENR_ADC12EN;
    RCC->APB1ENR|=RCC_APB1ENR_DAC12EN;

GPIOA->MODER=GPIO_MODER_MODER2;//ABILITO 11
GPIOA->MODER|=GPIO_MODER_MODER4;//ABILITO 11
ADCSetup();
DACSetup();

ADC1->CR|=ADC_CR_ADSTART;
while((ADC1->ISR & ADC_ISR_EOC)!= ADC_ISR_EOC);

tensione_out=codice_in*(3.0/4095);
printf("DAC\n");
printf("ingresso %f V \n",codice_in);
printf("uscita %d\n",tensione_out);

int codice_out=ACD1->DR;
float tensione_in=codice_out*(3/4096);
printf("ADC\n");
printf("ingresso %f V \n",tensione_in);
printf("uscita %d\n",codice_out);


while (1);

}