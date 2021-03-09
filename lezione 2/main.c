unsigned int * p;
void main(){
  p=(unsigned int*)0x40021014;
  *p=0x00200000;//abilito il clock
  
  p=(unsigned int *)0x48001000;
  *p=1<<16;//abilito moder 8
  
  p=(unsigned int *)0x48001014;
  *p=1<<8;//accendo il led blu l8
  
  p=(unsigned int *)0x48001000;
  *p|=1<<18;//abilito moder 9
  
   p=(unsigned int *)0x48001014;
  *p|=1<<9;//accendo il led rosso l9
  
    p=(unsigned int *)0x48001014;
  *p&=~(1<<8);//spengo il led blu l8
  
  
  while(1);
}