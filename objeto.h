#ifndef OBJETO_H
#define OBJETO_H


#include<QString>
#include<QVector>
#include "QMainWindow"
#include "dados.h"
#include <QFile>
#include <QStringList>
#include <QObject>


class Objeto
{

private:
    QVector<Dados> equipamento;

public:
    Objeto();

    float getMaiorCorrente1();
    float getMaiorCorrente2();
    void inserirCadastro(Dados a);
    void remover(int i);
    int size();
    void salvarDados(QString file);
    void carregarDados(QString file);


    Dados operator[](int indice);


};
bool compararPorCorrente1(Dados a, Dados b);
bool compararPorCorrente2(Dados a, Dados b);

#endif // OBJETO_H








