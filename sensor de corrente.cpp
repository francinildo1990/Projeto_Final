#include "corrente.h"
#include "EmonLib.h"


EnergyMonitor CorrenteSCT;  //CorrenteSCT é um objeto da classe EnergyMonitor

int pin_1 = A0;

int tensao = 220;    // Tensão da rede elétrica

int potencia;

void setup()
{
    CorrenteSCT.current(pin_1, 9.0909);

    Serial.begin(9600);
}

void loop()
{
    double Irms =  CorrenteSCT.calcIrms(1480);   // Calcula o valor da Corrente

    if (Irms<0.1){
      Irms=0;
      }
    potencia = Irms * tensao;          // Calcula o valor da Potencia Instantanea

    Serial.print("Corrente = ");
    Serial.print(Irms);
    Serial.println(" A");

    Serial.print("Potencia = ");
    Serial.print(potencia);
    Serial.println(" W");

    delay(500);
    Serial.print(".");
    delay(500);
    Serial.print(".");
    delay(500);

}
