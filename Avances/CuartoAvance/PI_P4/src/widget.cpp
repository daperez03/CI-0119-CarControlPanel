#include "widget.h"

static int temperature = 65;

Widget::Widget(QWidget* parent) 
  : QWidget(parent) {
  ui.setupUi(this);
  ui.widget->setState(QLedLabel::StateWarning);
  ui.widget_2->setState(QLedLabel::StateWarning);
  ui.widget_3->setState(QLedLabel::StateOk);
  ui.widget_4->setState(QLedLabel::StateError);
  ui.widget_5->setState(QLedLabel::StateError);
  ui.widget_6->setState(QLedLabel::StateError);
  ui.widget_7->setState(QLedLabel::StateError);
  ui.widget_8->setState(QLedLabel::StateError);
  ui.widget_9->setState(QLedLabel::StateError);
  ui.widget_10->setState(QLedLabel::StateError);
  ui.widget_11->setState(QLedLabel::StateError);
  ui.widget->setVisible(false);
  ui.widget_2->setVisible(false);
  ui.widget_3->setVisible(false);
  ui.widget_4->setVisible(false);
  ui.widget_5->setVisible(false);
  ui.widget_6->setVisible(false);
  ui.widget_7->setVisible(false);
  ui.widget_8->setVisible(false);
  ui.widget_9->setVisible(false);
  ui.widget_10->setVisible(false);
  ui.widget_11->setVisible(false);
  QTimer* timer = new QTimer(this);
  QTimer* timerGas = new QTimer(this);
  setWindowTitle("Panel de Instrumentos");
  connect(ui.Encender,SIGNAL(clicked()),this,SLOT(Encender()));
  connect(timer,SIGNAL(timeout()),this,SLOT(no_Gas()));
  connect(timer,SIGNAL(timeout()),this,SLOT(Temperatura_Value()));
  connect(timerGas,SIGNAL(timeout()),this,SLOT(Gasolina_Value()));
  connect(timer,SIGNAL(timeout()),this,SLOT(Wheels_Value()));
  connect(timer,SIGNAL(timeout()),this,SLOT(SensorAnticolision()));
  ui.pushButton->setDisabled(true);
  ui.pushButton_2->setDisabled(true);
  ui.checkBox->setDisabled(true);
  timer->start(1000);
  timerGas->start(5000);
}

Widget::~Widget() {}

void Widget::Encender() {
  if (this->Encendido) {
    ui.SliderVelocidad->setMaximum(0);
    this->Encendido = false;
    ui.Encendido_Apagado->setText("Apagado");
    ui.pushButton->setDisabled(true);
    ui.pushButton_2->setDisabled(true);
    if((ui.widget->isVisible()) && (ui.widget_2->isVisible())) {
      ui.widget->setVisible(true);
      ui.widget_2->setVisible(true);
    } else {
      ui.widget->setVisible(false);
      ui.widget_2->setVisible(false);
    }
  } else {
    ui.SliderVelocidad->setMaximum(300);
    this->Encendido = true;
    ui.Encendido_Apagado->setText("Encendido");
    if((ui.widget->isVisible()) && (ui.widget_2->isVisible())) {
      ui.pushButton->setDisabled(true);
      ui.pushButton_2->setDisabled(true);
    } else {
      ui.pushButton->setDisabled(false);
      ui.pushButton_2->setDisabled(false);
    }
  }
}

int Widget::temperatura(){
  qDebug();
  temperature = temperature_simulation(temperature,  ui.SliderVelocidad->value() + 1);
  return temperature;
}

int Widget::gasValue(){
  this->gas = gas_simulation(this->gas,  ui.SliderVelocidad->value() + 1);
  return this->gas;
}

int Widget::pressure(int i){
  wheel[i] -= pressure_simulation(wheel[i]);
  return wheel[i];
}

void Widget::Temperatura_Value() {
  mutex.lock();
  if(this->Encendido && this->gas) {
    ui.LCDTemperatura->display(temperatura()); //agregar metodo para calcular temperatura
    ui.widget_4->setVisible(umbrales(temperature, 70, 150));
    if (umbrales(temperature, 70, 150))
        system("(speaker-test -t sine -f 1000)& pid=$!; sleep 0.1s; kill -9 $pid");
  } else {
    ui.LCDTemperatura->display(0);
  }
  mutex.unlock();
}

            
void Widget::Gasolina_Value() {
  mutex.lock();
  if(this->Encendido && this->gas) {
    ui.LCDGasolina_2->display(gasValue()); //agregar metodo para bajar gasolina // gasolina ==0
    ui.widget_5->setVisible(umbrales(this->gas, 5,63));
     if (umbrales(this->gas, 5, 63))
        system("(speaker-test -t sine -f 100000)& pid=$!; sleep 0.1s; kill -9 $pid");
  } else {
    ui.LCDGasolina_2->display(0);
  }
  mutex.unlock();
}

void Widget::no_Gas() {
  if (this->gas == 0) {
    ui.SliderVelocidad->setMaximum(0);
  } else if(this->Encendido) {
    ui.SliderVelocidad->setMaximum(300);
  }
}

void Widget::Wheels_Value() {
  if(this->Encendido && this->gas) {
    mutex.lock();
    wheel[0] -= (rand()%10 == 1);
    wheel[1] -= (rand()%10 == 1);
    wheel[2] -= (rand()%10 == 1);
    wheel[3] -= (rand()%10 == 1);
    ui.lcdNeumatico_1->display(wheel[0]);//agregar random para calcular presion de las llantas
    ui.widget_7->setVisible(umbrales(wheel[0], 27,33));
    ui.lcdNeumatico_2->display(wheel[1]);
    ui.widget_9->setVisible(umbrales(wheel[1], 27,33));
    ui.lcdNeumatico_3->display(wheel[2]);
    ui.widget_8->setVisible(umbrales(wheel[2], 27,33));
    ui.lcdNeumatico_4->display(wheel[3]);
    ui.widget_10->setVisible(umbrales(wheel[3], 27,33));
      if (umbrales(wheel[0], 27, 33))
        system("(speaker-test -t sine -f 1000)& pid=$!; sleep 0.1s; kill -9 $pid");
      if (umbrales(wheel[1], 27, 33))
        system("(speaker-test -t sine -f 1000)& pid=$!; sleep 0.1s; kill -9 $pid");
      if (umbrales(wheel[2], 27, 33))
        system("(speaker-test -t sine -f 1000)& pid=$!; sleep 0.1s; kill -9 $pid");
      if (umbrales(wheel[3], 27, 33))
        system("(speaker-test -t sine -f 1000)& pid=$!; sleep 0.1s; kill -9 $pid");
      mutex.unlock();
  } else {
    ui.lcdNeumatico_1->display(0);
    ui.lcdNeumatico_2->display(0);
    ui.lcdNeumatico_3->display(0);
    ui.lcdNeumatico_4->display(0);
  }
}

void Widget::on_pushButton_clicked() {
  if(ui.widget->isVisible()){
    ui.widget->setVisible(false);
  } else {
    ui.widget_2->setVisible(false);
    ui.widget->setVisible(true);
  }
}


void Widget::on_pushButton_2_clicked() {
  if(ui.widget_2->isVisible()){
    ui.widget_2->setVisible(false);
  } else {
    ui.widget_2->setVisible(true);
    ui.widget->setVisible(false);
  }
}


void Widget::on_btn_LucesDelanteras_clicked() {
  if(ui.widget_3->isVisible()){
    ui.widget_3->setVisible(false);
    ui.checkBox->setDisabled(true);
  } else {
    ui.widget_3->setVisible(true);
    ui.checkBox->setDisabled(false);
  }
}


void Widget::on_checkBox_stateChanged() {
  if(ui.checkBox->isChecked()) {
    ui.widget_3->setState(QLedLabel::StateOkBlue);
  } else {
    ui.widget_3->setState(QLedLabel::StateOk);
  }
}


void Widget::on_btnLucesEmergencia_clicked() {
  if(!ui.widget->isVisible() || !ui.widget_2->isVisible()) {
    ui.widget->setVisible(true);
    ui.widget_2->setVisible(true);
    ui.pushButton->setDisabled(true);
    ui.pushButton_2->setDisabled(true);
  } else {
    ui.widget->setVisible(false);
    ui.widget_2->setVisible(false);
    if(Encendido) {
      ui.pushButton->setDisabled(false);
      ui.pushButton_2->setDisabled(false);
    }
  }
}

void Widget::SensorAnticolision() {
  if (this -> Encendido) {
    ui.widget_11->setVisible(true);
    // mutex.lock();
    // bool anticolision = 1 == (rand()%20)/*anticollision_simulation()*/;
    // mutex.unlock();
    // if(anticolision) {
    //   ui.widget_11->setVisible(true);
    //   system("(speaker-test -t sine -f 1000)& pid=$!; sleep 0.1s; kill -9 $pid");
    // } else {
    //   ui.widget_11->setVisible(false);
    // }
  }
}
