/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QLedLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget {
 public:
  QPushButton *Encender;
  QWidget *horizontalLayoutWidget;
  QHBoxLayout *Velocidad;
  QSplitter *splitter;
  QLCDNumber *LCDVelocidad;
  QSlider *SliderVelocidad;
  QLabel *VelocidadLabel;
  QWidget *horizontalLayoutWidget_2;
  QHBoxLayout *Temperatura;
  QSplitter *splitter_2;
  QLCDNumber *LCDTemperatura;
  QLabel *TemperaturaLabel;
  QWidget *horizontalLayoutWidget_3;
  QHBoxLayout *Gasolina;
  QSplitter *splitter_3;
  QLCDNumber *LCDGasolina_2;
  QLabel *GasolinaLabel;
  QWidget *horizontalLayoutWidget_5;
  QHBoxLayout *Presion_Neumaticos;
  QVBoxLayout *Neumaticos34;
  QLCDNumber *lcdNeumatico_4;
  QLCDNumber *lcdNeumatico_3;
  QVBoxLayout *Neumaticos12;
  QLCDNumber *lcdNeumatico_1;
  QLCDNumber *lcdNeumatico_2;
  QLabel *PresionLabel;
  QLabel *Encendido_Apagado;
  QPushButton *pushButton;
  QPushButton *pushButton_2;
  QLedLabel *widget;
  QLedLabel *widget_2;
  QLabel *label_2;
  QLabel *label;
  QPushButton *btn_LucesDelanteras;
  QCheckBox *checkBox;
  QLabel *label_3;
  QLedLabel *widget_3;
  QPushButton *btnLucesEmergencia;
  QLedLabel *widget_4;
  QLabel *label_4;
  QLedLabel *widget_5;
  QLabel *label_5;
  QLedLabel *widget_6;
  QLabel *label_6;
  QLedLabel *widget_7;
  QLabel *label_7;
  QLedLabel *widget_8;
  QLabel *label_12;
  QLedLabel *widget_9;
  QLabel *label_14;
  QLabel *label_16;
  QLabel *label_17;
  QLabel *AnticolisionLabel;
  QLedLabel *widget_10;
  QLedLabel *widget_11;

  void setupUi(QWidget* Widget) {
    if (Widget->objectName().isEmpty())
        Widget->setObjectName("Widget");
    Widget->resize(1300, 801);
    Widget->setStyleSheet("background-color: rgb(32, 34, 42);");
    Encender = new QPushButton(Widget);
    Encender->setObjectName("Encender");
    Encender->setGeometry(QRect(1070, 10, 221, 25));
    Encender->setStyleSheet( "color : white;");
    horizontalLayoutWidget = new QWidget(Widget);
    horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
    horizontalLayoutWidget->setGeometry(QRect(500, 320, 661, 211));
    Velocidad = new QHBoxLayout(horizontalLayoutWidget);
    Velocidad->setSpacing(3);
    Velocidad->setObjectName("Velocidad");
    Velocidad->setContentsMargins(0, 0, 0, 0);
    splitter = new QSplitter(horizontalLayoutWidget);
    splitter->setObjectName("splitter");
    splitter->setOrientation(Qt::Vertical);
    splitter->setOpaqueResize(true);
    splitter->setHandleWidth(6);
    LCDVelocidad = new QLCDNumber(splitter);
    LCDVelocidad->setObjectName("LCDVelocidad");
    LCDVelocidad->setMinimumSize(QSize(25, 25));
    LCDVelocidad->setStyleSheet( "color : red;");
    QFont font;
    font.setFamily({QString::fromUtf8("Gidugu")});
    font.setItalic(true);
    LCDVelocidad->setFont(font);
    splitter->addWidget(LCDVelocidad);
    SliderVelocidad = new QSlider(splitter);
    SliderVelocidad->setObjectName("SliderVelocidad");
    SliderVelocidad->setMinimumSize(QSize(268, 15));
    SliderVelocidad->setMaximum(0);
    SliderVelocidad->setValue(0);
    SliderVelocidad->setOrientation(Qt::Horizontal);
    splitter->addWidget(SliderVelocidad);

    Velocidad->addWidget(splitter);

    VelocidadLabel = new QLabel(horizontalLayoutWidget);
    VelocidadLabel->setObjectName("VelocidadLabel");
    VelocidadLabel->setMinimumSize(QSize(20, 23));
    VelocidadLabel->setStyleSheet( "color : white;");
    QFont font1;
    font1.setFamily({QString::fromUtf8("Gidugu")});
    font1.setPointSize(17);
    font1.setBold(true);
    font1.setItalic(true);
    VelocidadLabel->setFont(font1);

    Velocidad->addWidget(VelocidadLabel);

    horizontalLayoutWidget_2 = new QWidget(Widget);
    horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
    horizontalLayoutWidget_2->setGeometry(QRect(50, 130, 611, 141));
    Temperatura = new QHBoxLayout(horizontalLayoutWidget_2);
    Temperatura->setSpacing(3);
    Temperatura->setObjectName("Temperatura");
    Temperatura->setContentsMargins(0, 0, 0, 0);
    splitter_2 = new QSplitter(horizontalLayoutWidget_2);
    splitter_2->setObjectName("splitter_2");
    splitter_2->setOrientation(Qt::Vertical);
    splitter_2->setOpaqueResize(true);
    splitter_2->setHandleWidth(6);
    LCDTemperatura = new QLCDNumber(splitter_2);
    LCDTemperatura->setObjectName("LCDTemperatura");
    LCDTemperatura->setMinimumSize(QSize(25, 25));
    LCDTemperatura->setStyleSheet( "color : red;");
    LCDTemperatura->setFont(font);
    splitter_2->addWidget(LCDTemperatura);

    Temperatura->addWidget(splitter_2);

    TemperaturaLabel = new QLabel(horizontalLayoutWidget_2);
    TemperaturaLabel->setObjectName("TemperaturaLabel");
    TemperaturaLabel->setMinimumSize(QSize(20, 23));
    TemperaturaLabel->setFont(font1);
    TemperaturaLabel->setStyleSheet( "color : white;");

    Temperatura->addWidget(TemperaturaLabel);

    horizontalLayoutWidget_3 = new QWidget(Widget);
    horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
    horizontalLayoutWidget_3->setGeometry(QRect(930, 130, 611, 141));
    Gasolina = new QHBoxLayout(horizontalLayoutWidget_3);
    Gasolina->setSpacing(3);
    Gasolina->setObjectName("Gasolina");
    Gasolina->setContentsMargins(0, 0, 0, 0);
    splitter_3 = new QSplitter(horizontalLayoutWidget_3);
    splitter_3->setObjectName("splitter_3");
    splitter_3->setOrientation(Qt::Vertical);
    splitter_3->setOpaqueResize(true);
    splitter_3->setHandleWidth(6);
    LCDGasolina_2 = new QLCDNumber(splitter_3);
    LCDGasolina_2->setObjectName("LCDGasolina_2");
    LCDGasolina_2->setMinimumSize(QSize(25, 25));
    LCDGasolina_2->setFont(font);
    LCDGasolina_2->setProperty("value", QVariant(63.000000000000000));
    splitter_3->addWidget(LCDGasolina_2);
    LCDGasolina_2->setStyleSheet( "color : red;");

    Gasolina->addWidget(splitter_3);

    GasolinaLabel = new QLabel(horizontalLayoutWidget_3);
    GasolinaLabel->setObjectName("GasolinaLabel");
    GasolinaLabel->setMinimumSize(QSize(20, 23));
    GasolinaLabel->setFont(font1);
    GasolinaLabel->setStyleSheet( "color : white;");

    Gasolina->addWidget(GasolinaLabel);

    horizontalLayoutWidget_5 = new QWidget(Widget);
    horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
    horizontalLayoutWidget_5->setGeometry(QRect(50, 590, 611, 141));
    Presion_Neumaticos = new QHBoxLayout(horizontalLayoutWidget_5);
    Presion_Neumaticos->setObjectName("Presion_Neumaticos");
    Presion_Neumaticos->setContentsMargins(0, 0, 0, 0);
    Neumaticos34 = new QVBoxLayout();
    Neumaticos34->setObjectName("Neumaticos34");
    lcdNeumatico_4 = new QLCDNumber(horizontalLayoutWidget_5);
    lcdNeumatico_4->setObjectName("lcdNeumatico_4");

    Neumaticos34->addWidget(lcdNeumatico_4);

    lcdNeumatico_3 = new QLCDNumber(horizontalLayoutWidget_5);
    lcdNeumatico_3->setObjectName("lcdNeumatico_3");

    Neumaticos34->addWidget(lcdNeumatico_3);


    Presion_Neumaticos->addLayout(Neumaticos34);

    Neumaticos12 = new QVBoxLayout();
    Neumaticos12->setObjectName("Neumaticos12");
    lcdNeumatico_1 = new QLCDNumber(horizontalLayoutWidget_5);
    lcdNeumatico_1->setObjectName("lcdNeumatico_1");

    Neumaticos12->addWidget(lcdNeumatico_1);

    lcdNeumatico_2 = new QLCDNumber(horizontalLayoutWidget_5);
    lcdNeumatico_2->setObjectName("lcdNeumatico_2");

    Neumaticos12->addWidget(lcdNeumatico_2);


    Presion_Neumaticos->addLayout(Neumaticos12);

    lcdNeumatico_1->setStyleSheet( "color : red;");
    lcdNeumatico_2->setStyleSheet( "color : red;");
    lcdNeumatico_3->setStyleSheet( "color : red;");
    lcdNeumatico_4->setStyleSheet( "color : red;");
    PresionLabel = new QLabel(horizontalLayoutWidget_5);
    PresionLabel->setObjectName("PresionLabel");
    QFont font2;
    font2.setBold(true);
    font2.setPointSize(21);
    PresionLabel->setFont(font2);
    PresionLabel->setStyleSheet( "color : white;");

    Presion_Neumaticos->addWidget(PresionLabel);

    Encendido_Apagado = new QLabel(Widget);
    Encendido_Apagado->setObjectName("Encendido_Apagado");
    Encendido_Apagado->setGeometry(QRect(130, 0, 161, 51));
    Encendido_Apagado->setStyleSheet( "color : white;");
    QFont font3;
    font3.setFamily({QString::fromUtf8("Gidugu")});
    font3.setBold(true);
    font3.setItalic(true);
    font3.setPointSize(15);
    Encendido_Apagado->setFont(font3);
    pushButton = new QPushButton(Widget);
    pushButton->setObjectName("pushButton"); //direccional izquierda
    pushButton->setGeometry(QRect(550, 20, 121, 24));
    pushButton_2 = new QPushButton(Widget);
    pushButton_2->setObjectName("pushButton_2"); //direccional derecha
    pushButton_2->setGeometry(QRect(680, 20, 121, 24));
    pushButton->setStyleSheet( "color : white;");
    pushButton_2->setStyleSheet( "color : white;");

    btn_LucesDelanteras = new QPushButton(Widget);
    btn_LucesDelanteras->setObjectName("btn_LucesDelanteras");
    btn_LucesDelanteras->setGeometry(QRect(1070, 70, 221, 25));
    btn_LucesDelanteras->setStyleSheet( "color : white;");

    checkBox = new QCheckBox(Widget);
    checkBox->setObjectName("checkBox");
    checkBox->setGeometry(QRect(1070, 100, 221, 22));

    btnLucesEmergencia = new QPushButton(Widget);
    btnLucesEmergencia->setObjectName("btnLucesEmergencia");
    btnLucesEmergencia->setGeometry(QRect(1070, 40, 221, 25));
    btnLucesEmergencia->setStyleSheet( "color : white;");
    
    widget = new QLedLabel(Widget);
    widget->setObjectName("widget");
    widget->setGeometry(QRect(500, 20, 51, 31));

    widget_2 = new QLedLabel(Widget);
    widget_2->setObjectName("widget_2");
    widget_2->setGeometry(QRect(830, 20, 51, 31));

    widget_3 = new QLedLabel(Widget);
    widget_3->setObjectName("widget_3");
    widget_3->setGeometry(QRect(1040, 80, 51, 50)); //luces

    widget_4 = new QLedLabel(Widget);
    widget_4->setObjectName("widget_4"); //temp R
    widget_4->setGeometry(QRect(55, 135, 51, 31));

    widget_5 = new QLedLabel(Widget);
    widget_5->setObjectName("widget_5"); //gas  R
    widget_5->setGeometry(QRect(935, 135, 51, 31));

    widget_6 = new QLedLabel(Widget);
    widget_6->setObjectName("widget_6"); // ??????????
    widget_6->setGeometry(QRect(935, 135, 0, 0));

    widget_7 = new QLedLabel(Widget);
    widget_7->setObjectName("widget_7"); //presion
    widget_7->setGeometry(QRect(55, 595, 0, 0));

    widget_8 = new QLedLabel(Widget);
    widget_8->setObjectName("widget_8"); //presion
    widget_8->setGeometry(QRect(55, 668, 0, 0));

    widget_9 = new QLedLabel(Widget);
    widget_9->setObjectName("widget_9"); //presion
    widget_9->setGeometry(QRect(260, 595, 0, 0));

    widget_10 = new QLedLabel(Widget);
    widget_10->setObjectName("widget_10"); //presion
    widget_10->setGeometry(QRect(260, 668, 0, 0));

    widget_11 = new QLedLabel(Widget);
    widget_11->setObjectName("widget_11"); 
    widget_11->setGeometry(QRect(1020, 650, 0, 0));
    
    label = new QLabel(Widget);
    label->setObjectName("label");
    label->setGeometry(QRect(500, 0, 0, 0));
    label->setFrameShape(QFrame::Box);
    label->setScaledContents(false);

    label_2 = new QLabel(Widget);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(830, 0, 0, 0));
    label_2->setFrameShape(QFrame::Box);
    label_2->setScaledContents(false);

    label_3 = new QLabel(Widget);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(1130, 690, 0, 0));
    label_3->setFrameShape(QFrame::Box);
    label_3->setScaledContents(false);
    
    label_4 = new QLabel(Widget);
    label_4->setObjectName("label_4");
    label_4->setGeometry(QRect(180, 90, 0, 0));
    label_4->setFrameShape(QFrame::Box);
    label_4->setScaledContents(false);
    
    label_5 = new QLabel(Widget);
    label_5->setObjectName("label_5");
    label_5->setGeometry(QRect(1050, 90, 0, 0));
    label_5->setFrameShape(QFrame::Box);
    label_5->setScaledContents(false);
    
    label_6 = new QLabel(Widget);
    label_6->setObjectName("label_6");
    label_6->setGeometry(QRect(380, 320, 0, 0));
    label_6->setFrameShape(QFrame::Box);
    label_6->setScaledContents(false);

    label_7 = new QLabel(Widget);
    label_7->setObjectName("label_7");
    label_7->setGeometry(QRect(140, 550, 0, 0));
    label_7->setFrameShape(QFrame::Box);
    label_7->setScaledContents(false);

    label_12 = new QLabel(Widget);
    label_12->setObjectName("label_12");
    label_12->setGeometry(QRect(140, 640, 0, 0));
    label_12->setFrameShape(QFrame::Box);
    label_12->setScaledContents(false);

    label_14 = new QLabel(Widget);
    label_14->setObjectName("label_14");
    label_14->setGeometry(QRect(730, 200, 0, 0));
    label_14->setFrameShape(QFrame::Box);
    label_14->setScaledContents(false);

    label_16 = new QLabel(Widget);
    label_16->setObjectName("label_16");
    label_16->setGeometry(QRect(730, 630, 0, 0));
    label_16->setFrameShape(QFrame::Box);
    label_16->setScaledContents(false);


    QFont font4;
    font4.setFamily({QString::fromUtf8("Gidugu")});
    font4.setPointSize(25);
    font4.setItalic(true);
    AnticolisionLabel  = new QLabel(Widget);
    AnticolisionLabel ->setObjectName("AnticolisionLabel");
    AnticolisionLabel ->setGeometry(QRect(920, 595, 300, 25));
    AnticolisionLabel->setFont(font4);
    AnticolisionLabel->setStyleSheet( "color : white;");

    retranslateUi(Widget);
    QObject::connect(SliderVelocidad, SIGNAL(valueChanged(int)), LCDVelocidad, SLOT(display(int)));

    QMetaObject::connectSlotsByName(Widget);
  } // setupUi

  void retranslateUi(QWidget* Widget) {
    Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    Encender->setText(QCoreApplication::translate("Widget", "Encender/Apagar Vehiculo", nullptr));
    VelocidadLabel->setText(QCoreApplication::translate("Widget", "KM/H", nullptr));
    TemperaturaLabel->setText(QCoreApplication::translate("Widget", "\302\260C", nullptr));
    GasolinaLabel->setText(QCoreApplication::translate("Widget", "Litros", nullptr));
    PresionLabel->setText(QCoreApplication::translate("Widget", "PSI", nullptr));
    Encendido_Apagado->setText(QCoreApplication::translate("Widget", "Apagado", nullptr));
    pushButton->setText(QCoreApplication::translate("Widget", "<---------", nullptr));
    pushButton_2->setText(QCoreApplication::translate("Widget", "--------->", nullptr));
    label_2->setText(QString());
    label->setText(QString());
    btn_LucesDelanteras->setText(QCoreApplication::translate("Widget", "Luces Delanteras", nullptr));
    checkBox->setText(QCoreApplication::translate("Widget", "Luces Altas", nullptr));
    label_3->setText(QString());
    btnLucesEmergencia->setText(QCoreApplication::translate("Widget", "Luces de emergencia", nullptr));
    label_4->setText(QString());
    label_5->setText(QString());
    label_6->setText(QString());
    label_7->setText(QString());
    AnticolisionLabel->setText(QCoreApplication::translate("Widget", "Sistema Anticolisiones ", nullptr));
  } // retranslateUi
};

namespace Ui {
  class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
