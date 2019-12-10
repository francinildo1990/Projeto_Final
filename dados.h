#ifndef DADOS_H
#define DADOS_H

#include<QString>
#include<QVector>



class Dados
{
public:
    Dados();

    float getCorrente1()const;
    void setCorrente1(const float &valeu);


    float getCorrente2() const;
    void setCorrente2(const float &valeu);


    float getSensor1()const;
    void setSensor1(const float &valeu);


    float getSensor2()const;
    void setSensor2(const float &valeu);

private:

    float corrente1;
    float corrente2;
    float sensor1;
    float sensor2;
};

#endif // DADOS_H



