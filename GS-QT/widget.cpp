#include "widget.h"
#include "ui_widget.h"

snake s;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QPixmap pix(201,201);
    QPainter painter(&pix);

    pix.fill(Qt::white);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawLine(QPoint(1,1),QPoint(1,200));
    painter.drawLine(QPoint(0,0),QPoint(200,1));
    painter.drawLine(QPoint(200,1),QPoint(200,200));
    painter.drawLine(QPoint(1,200),QPoint(200,200));
    painter.end();
    ui->drawlabel->setPixmap(pix);
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
    s.init();
    s.start();
}
