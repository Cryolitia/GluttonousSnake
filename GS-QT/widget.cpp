#include "widget.h"
#include "ui_widget.h"
#include "snake.cpp"
#include "QTime"
#include "QString"
#include "QThread"

snake s;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    s.init();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_up_clicked()
{
    s.shuru1 = 'w';
}

void Widget::on_left_clicked()
{
    s.shuru1 = 'a';
}

void Widget::on_right_clicked()
{
    s.shuru1 = 'd';
}

void Widget::on_down_clicked()
{
    s.shuru1 = 's';
}

void Widget::on_start_clicked()
{
        ui->start->setEnabled(false);
}
