unsigned int* puntatore;

void main(){
  puntatore=(unsigned int *)0x40021014;
  *puntatore=0x00200000;
  
  puntatore=(unsigned int *)0x48001000;//indirizzo di moder
  *puntatore=1<<16;//abilito pe8
  
  puntatore=(unsigned int*)0x48001014;// ODR
  *puntatore=1<<8;//accende il led blu
  while(1);// loop infinito

}