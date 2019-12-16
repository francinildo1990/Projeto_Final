 #ifndef CORRENTE_H
 #define CORRENTE_H

 #include<Arduino.h>


 class SensorCorrente
     {

    private:
          int pino;
          float sensor;
            
      public:

          SensorCorrente(int a);

          void ligar();
          void desligar();
           
          
     };


   #endif
