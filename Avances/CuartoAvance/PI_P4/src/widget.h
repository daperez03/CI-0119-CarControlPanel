#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtCore>
#include "ui_widget.h"
#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <QDebug>
#include "Funciones.h"
#include <unistd.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

/// @brief Main class in charge of interface manipulation
class Widget : public QWidget {
  Q_OBJECT

private:
  /// @brief To determine the graphical interface of a specific Widget
  Ui::Widget ui;
  /// @brief Timer to perform in real time all the functions for the sensors
  QTimer timer = QTimer(this);
  /// @brief Timer to perform the gasoline function every so often
  QTimer timerGas = QTimer(this);
  /// @brief Indicates if the vehicle is on or off
  bool Encendido = false;
  /// @brief Gas value
  int gas = 63;
  /// @brief Wheel values
  int wheel[4] = {33,33,33,33};

public:
  /// @brief 
  /// @param parent 
  Widget(QWidget *parent = nullptr);
  /// @brief Widget class destroyer
  ~Widget();
  /// @brief Call the assembly temperature_simulation function
  /// @return Value of temperature
  int temperatura();
  /// @brief Call the assembly gas_simulation function
  /// @return Value of gas
  int gasValue();
  /// @brief Call the assembly pressure_simulation function
  /// @param i Number of the wheel
  /// @return Value of wheel
  int pressure(int i);
  /// @brief Init objets of type QTimer
  void TimerStart();
  /// @brief Concurrence control in class
  QMutex mutex;

private slots:
  /// @brief Simulates the start of the car
  void Encender();
  /// @brief Function in case the vehicle is without gas
  void no_Gas();
  /// @brief Assign value to the temperature panel
  void Temperatura_Value();
  /// @brief Assign value to the gas panel
  void Gasolina_Value();
  /// @brief Assign value to the wheels panel
  void Wheels_Value();
  /// @brief Slot for the function to activate the left turn signal
  void on_pushButton_clicked();
  /// @brief slot for the function to activate the right turn signal
  void on_pushButton_2_clicked();
  /// @brief Assign the status of the lights
  void on_btn_LucesDelanteras_clicked();
  /// @brief Enciende Luz altas del vehiculo
  void on_checkBox_stateChanged();
  /// @brief Assign the status of the emergency lights
  void on_btnLucesEmergencia_clicked();
  /// @brief Assign the status of the anticollision panel
  void SensorAnticolision();
};
#endif // WIDGET_H
