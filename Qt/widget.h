#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int numRandom();
private slots:
    void on_Encender_clicked();
    void Temperatura_Value();
    void Gasolina_Value();
    void Wheels_Value_1();
    void Wheels_Value_2();
    void Wheels_Value_3();
    void Wheels_Value_4();
    void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_LucesDelanteras_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_btnLucesEmergencia_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    QTimer *timerGas;
};
#endif // WIDGET_H
