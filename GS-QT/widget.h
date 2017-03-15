#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QTime"
#include "QString"
#include "QThread"
#include "QPixmap"
#include "QPainter"
#include "QPoint"
#include "sc.h"
#include "QString"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_up_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_down_clicked();

    void on_start_clicked();

private:
    Ui::Widget *ui;

public slots:
    void updateslot();

    void dieslot();

};

#endif // WIDGET_H
