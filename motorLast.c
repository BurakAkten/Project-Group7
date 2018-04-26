#include <wiringPi.h>
#include <stdio.h>

#define STOP 0
#define LEFT 1
#define RIGHT 2
#define EXIT 3

int main(void)
{       

  int command = STOP;
  if (wiringPiSetup () == -1)
        return 1 ;  

   pinMode(0,OUTPUT);
   pinMode(2,OUTPUT); 
   pinMode(1,OUTPUT);

                                                
   for(;command != EXIT;){

        scanf("%d",&command);

        switch (command) {

          case STOP: {
            digitalWrite(0,LOW); 
            digitalWrite(1,LOW);
          }break;

          case LEFT: {
            digitalWrite(0,HIGH); 
            digitalWrite(1,LOW); 
          }break;

          case RIGHT: {
            digitalWrite(0,LOW); 
            digitalWrite(1,HIGH);
          } break;

          default: break;
        }
   } 
     
   return 0;
}
