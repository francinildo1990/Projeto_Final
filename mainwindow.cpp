#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonOnOff_1_clicked()
{
       float dados1;
       float dados2;


    dados1 = ui-> LabelCorrente1->text().toFloat();
    dados2 = ui-> labelCorrente2->text().toFloat();

    if(dados1 <= 0 || dados2 <= 0){  //Verificação dos dados
                qDebug()<<"Dado Inválido"<<endl;
                QMessageBox::warning(this,"Alerta","Dado inválido");
            }

   else
    {
    corrente.setCorrente1(ui->LabelCorrente1->text().toFloat());
    corrente.setCorrente2(ui->labelCorrente2->text().toFloat());

    int quantidade_linhas = ui->Tabela->rowCount();
    ui->Tabela->insertRow(quantidade_linhas);
    inserirNaTabela(corrente,quantidade_linhas);
    equipamento.inserirCadastro(corrente);
    atualizarEstatisticas();

    }

}

void MainWindow::inserirNaTabela(Dados a, int linha){


    ui->Tabela->setItem(linha,0,new QTableWidgetItem(QString::number(a.getCorrente1())));
    ui->Tabela->setItem(linha,1,new QTableWidgetItem(QString::number(a.getCorrente2())));
}

void MainWindow::atualizarEstatisticas()
{

       ui->Corrente1->setText(QString::number(equipamento.getMaiorCorrente1()));
       ui->Corrente2->setText(QString::number(equipamento.getMaiorCorrente2()));

}


void MainWindow::on_actionSalvar_triggered()
{
        QString filename;
        filename = QFileDialog::getSaveFileName(this,"Salvar Arquivo","","*.csv");
        equipamento.salvarDados(filename);
}

void MainWindow::on_actionCarregar_triggered()
{
    QString filename;
        filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","*.csv");
        equipamento.carregarDados(filename);

        for(int i=0;i<equipamento.size();i++){
            ui->Tabela->insertRow(i);
            inserirNaTabela(equipamento[i],i);
        }
        atualizarEstatisticas();
}

void MainWindow::on_Tabela_cellDoubleClicked(int row, int column)
{
    if(column == 0){
               QMessageBox::warning(this, "Alerta", "Você não pode alterar cadastro!");
               }
       if(column == 1){
               QMessageBox::warning(this, "Alerta", "Você não pode alterar cadastro!");
               }
}
