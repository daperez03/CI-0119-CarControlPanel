#include "widget.h"
#include "ui_widget.h"
#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <QDebug>

bool Encendido = false;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->widget->setState(QLedLabel::StateWarning);
    ui->widget_2->setState(QLedLabel::StateWarning);
    ui->widget_3->setState(QLedLabel::StateOk);
    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->widget_3->setVisible(false);
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
    ui->pushButton->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->checkBox->setDisabled(true);

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
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(true);
        if((ui->widget->isVisible()) && (ui->widget_2->isVisible())) {
            ui->widget->setVisible(true);
            ui->widget_2->setVisible(true);
        } else {
            ui->widget->setVisible(false);
            ui->widget_2->setVisible(false);
        }

    }else if(!Encendido){
        ui->SliderVelocidad->setMaximum(300);
        Encendido=true;
        ui->Encendido_Apagado->setText("Encendido");
        if((ui->widget->isVisible()) && (ui->widget_2->isVisible())) {
            ui->pushButton->setDisabled(true);
            ui->pushButton_2->setDisabled(true);
        } else {
            ui->pushButton->setDisabled(false);
            ui->pushButton_2->setDisabled(false);
        }

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

void Widget::on_pushButton_clicked()
{
    if(ui->widget->isVisible()){
        ui->widget->setVisible(false);
    } else {

        ui->widget_2->setVisible(false);
        ui->widget->setVisible(true);
    }
}


void Widget::on_pushButton_2_clicked()
{
    if(ui->widget_2->isVisible()){
        ui->widget_2->setVisible(false);
    } else {
        ui->widget_2->setVisible(true);
        ui->widget->setVisible(false);
    }
}


void Widget::on_btn_LucesDelanteras_clicked()
{
    if(ui->widget_3->isVisible()){
        ui->widget_3->setVisible(false);
        ui->checkBox->setDisabled(true);
    } else {
        ui->widget_3->setVisible(true);
        ui->checkBox->setDisabled(false);
    }
}


void Widget::on_checkBox_stateChanged(int arg1)
{

    if(ui->checkBox->isChecked()) {
        ui->widget_3->setState(QLedLabel::StateOkBlue);
    } else {
        ui->widget_3->setState(QLedLabel::StateOk);
    }
}


void Widget::on_btnLucesEmergencia_clicked()
{
    if(!ui->widget->isVisible() || !ui->widget_2->isVisible())
    {
        ui->widget->setVisible(true);
        ui->widget_2->setVisible(true);
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(true);
    } else {
        ui->widget->setVisible(false);
        ui->widget_2->setVisible(false);

        if(Encendido) {
            ui->pushButton->setDisabled(false);
            ui->pushButton_2->setDisabled(false);
        }
    }
}
