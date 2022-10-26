#include "widget.h"
#include "ui_widget.h"
#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <QDebug>

bool Encendido;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    QTimer *timerGas=new QTimer(this);
    setWindowTitle("Panel de Instrumentos");
    connect(timer,SIGNAL(timeout()),this,SLOT(Temperatura_Value()));
    connect(timerGas,SIGNAL(timeout()),this,SLOT(Gasolina_Value()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Wheels_Value_1()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Wheels_Value_2()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Wheels_Value_3()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Wheels_Value_4()));
    timer->start();
    timerGas->start(5000);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::numRandom()
{
    srand(time(NULL));
    int num=rand()%51;
    return num;
}

void Widget::on_Encender_clicked()
{
    if(Encendido){
        ui->SliderVelocidad->setMaximum(0);
        Encendido=false;
        ui->Encendido_Apagado->setText("Apagado");
    }else if(!Encendido){
        ui->SliderVelocidad->setMaximum(300);
        Encendido=true;
        ui->Encendido_Apagado->setText("Encendido");
    }
}

void Widget::Temperatura_Value()
{
    if(Encendido){
        ui->LCDTemperatura->display(ui->SliderVelocidad->value()/2); //agregar metodo para calcular temperatura
    }else if(!Encendido){
       ui->LCDTemperatura->display(0);
    }
}

void Widget::Gasolina_Value()
{
    if(Encendido){
        ui->LCDGasolina_2->display(numRandom()); //agregar metodo para bajar gasolina // gasolina ==0
    }else if(!Encendido){
        ui->LCDGasolina_2->display(0);
    }
}

void Widget::Wheels_Value_1(){
    if(Encendido){
        ui->lcdNeumatico_1->display(ui->SliderVelocidad->value()/8);//agregar random para calcular presion de las llantas
    }else if(!Encendido){
        ui->lcdNeumatico_1->display(0);
    }
}

void Widget::Wheels_Value_2(){
    if(Encendido){
        ui->lcdNeumatico_2->display(ui->SliderVelocidad->value()/8);//agregar random para calcular presion de las llantas
    }else if(!Encendido){
        ui->lcdNeumatico_2->display(0);
    }
}

void Widget::Wheels_Value_3(){
    if(Encendido){
        ui->lcdNeumatico_3->display(ui->SliderVelocidad->value()/8);//agregar random para calcular presion de las llantas
    }else if(!Encendido){
        ui->lcdNeumatico_3->display(0);
    }
}

void Widget::Wheels_Value_4(){
    if(Encendido){
        ui->lcdNeumatico_4->display(ui->SliderVelocidad->value()/8);//agregar random para calcular presion de las llantas
    }else if(!Encendido){
        ui->lcdNeumatico_4->display(0);
    }
}
