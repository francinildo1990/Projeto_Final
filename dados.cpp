#include "dados.h"

Dados::Dados()
{

}


void Dados::setCorrente1(const float &valeu)
{
    if(valeu > 0){
    corrente1 = valeu;
    }
}

float Dados::getCorrente1() const
{
    return corrente1;
}




void Dados::setCorrente2(const float &valeu)
{
    if(valeu > 0){
    corrente2 = valeu;
    }
}

float Dados::getCorrente2() const
{
    return corrente2;
}




void Dados::setSensor1(const float &valeu)
{
    if(valeu >= 0 && valeu <= 1){
    sensor1 = valeu;
    }
}

float Dados::getSensor1() const
{
    return sensor1;
}



void Dados::setSensor2(const float &valeu)
{
    if(valeu >= 0 && valeu <= 1){
    sensor2 = valeu;
    }
}

float Dados::getSensor2() const
{
    return sensor2;
}

