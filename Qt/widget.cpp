#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <stdbool.h>
#include <stdio.h>

bool Encendido;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Panel de Instrumentos");
    connect(ui->Encender,SIGNAL(clicked()),this,SLOT(on_Encender_pressed()));
    connect(ui->SliderVelocidad,SIGNAL(valueChanged(int)),this,SLOT(Temperatura_Value()));
    connect(ui->SliderVelocidad,SIGNAL(valueChanged(int)),this,SLOT(Gasolina_Value()));
    connect(ui->SliderVelocidad,SIGNAL(valueChanged(int)),this,SLOT(Wheels_Value_1()));
    connect(ui->SliderVelocidad,SIGNAL(valueChanged(int)),this,SLOT(Wheels_Value_2()));
    connect(ui->SliderVelocidad,SIGNAL(valueChanged(int)),this,SLOT(Wheels_Value_3()));
    connect(ui->SliderVelocidad,SIGNAL(valueChanged(int)),this,SLOT(Wheels_Value_4()));
    qDebug()<<Encendido;
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_Encender_clicked()
{
    if(Encendido){
        ui->SliderVelocidad->setMaximum(0);
        Encendido=false;
    }else if(!Encendido){
        ui->SliderVelocidad->setMaximum(300);
        Encendido=true;
    }
}

void Widget::on_Encender_pressed()
{
    if(Encendido){
        ui->SliderVelocidad->setMaximum(0);
        Encendido=false;
    }else if(!Encendido){
        ui->SliderVelocidad->setMaximum(300);
        Encendido=true;
    }
}

void Widget::Temperatura_Value()
{
    ui->LCDTemperatura->display(ui->SliderVelocidad->value()/2); //agregar metodo para calcular temperatura
}

void Widget::Gasolina_Value()
{
    ui->LCDGasolina_2->display(63); //agregar metodo para bajar gasolina
}

void Widget::Wheels_Value_1(){
    ui->lcdNeumatico_1->display(ui->SliderVelocidad->value()/8);//agregar random para calcular presion de las llantas
}

void Widget::Wheels_Value_2(){
    ui->lcdNeumatico_2->display(ui->SliderVelocidad->value()/8);
}

void Widget::Wheels_Value_3(){
    ui->lcdNeumatico_3->display(ui->SliderVelocidad->value()/8);
}

void Widget::Wheels_Value_4(){
    ui->lcdNeumatico_4->display(ui->SliderVelocidad->value()/8);
}


