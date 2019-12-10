#include "objeto.h"

Objeto::Objeto()
{

}


float Objeto::getMaiorCorrente1(){  // calcula maior corrente

   Dados *a = std::max_element(equipamento.begin(),equipamento.end(),compararPorCorrente1);
    return  a->getCorrente1();
}

float Objeto::getMaiorCorrente2(){ // calcula menor corrente

    Dados *a = std::max_element(equipamento.begin(),equipamento.end(),compararPorCorrente2);
    return  a->getCorrente2();
}


void Objeto::inserirCadastro(Dados a){
    equipamento.push_back(a);
}

int Objeto::size(){
    return equipamento.size();
}

Dados Objeto::operator[](int indice){
    return equipamento[indice];
}

bool compararPorCorrente1(Dados a, Dados b){

    return a.getCorrente1()<b.getCorrente1();
}
bool compararPorCorrente2(Dados a, Dados b){

    return a.getCorrente2()<b.getCorrente2();
}

void Objeto::salvarDados(QString file) // Salva os dados do arquivo
{
    QFile arquivo(file);

    arquivo.open(QIODevice::WriteOnly);

    for(auto a:equipamento){
        QString linha = QString::number(a.getCorrente1()) + "," + QString::number(a.getCorrente2()) +"\n";
        arquivo.write(linha.toLocal8Bit());
    }
    arquivo.close();

}


void Objeto::carregarDados(QString file)  // Carrega os dados do arquivo
{
    QFile arquivo(file);
    arquivo.open(QIODevice::ReadOnly);


    QString linha;
    QStringList dados;
    while(!arquivo.atEnd()){
        Dados equipamento;
        linha = arquivo.readLine();
        dados = linha.split(",");
        equipamento.setCorrente1(dados[0].toFloat());
        equipamento.setCorrente2(dados[1].toFloat());
        inserirCadastro(equipamento);
    }
    arquivo.close();

}
