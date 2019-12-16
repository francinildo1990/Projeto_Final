   
   #include"corrente.h"

   SensorCorrente::SensorCorrente(int a)
   {

    pino = a;
   
     pinMode(pino,OUTPUT);
     
    }


   void SensorCorrente::ligar()
   {
     digitalWrite(pino,HIGH);

   }

   void SensorCorrente::desligar()
   {
     digitalWrite(pino,LOW);
   }

 

