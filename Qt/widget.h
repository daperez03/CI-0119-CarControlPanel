#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_Encender_clicked();
    void Temperatura_Value();
    void Gasolina_Value();
    void Wheels_Value_1();
    void Wheels_Value_2();
    void Wheels_Value_3();
    void Wheels_Value_4();
    void on_Encender_pressed();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
