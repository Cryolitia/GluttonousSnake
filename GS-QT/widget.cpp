#include "widget.h"
#include "ui_widget.h"

sc s;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QObject::connect(&s, SIGNAL(updatesig()), SLOT(updateslot()), Qt::DirectConnection);
    QObject::connect(&s, SIGNAL(diesig()),  SLOT(dieslot()));

    QPixmap pix(211,211);
    QPainter painter(&pix);

    pix.fill(Qt::white);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawLine(QPoint(1,1),QPoint(1,210));
    painter.drawLine(QPoint(0,0),QPoint(210,1));
    painter.drawLine(QPoint(210,1),QPoint(210,210));
    painter.drawLine(QPoint(1,210),QPoint(210,210));
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

void Widget::updateslot()
{
    QPixmap pix(211,211);
    QPainter painter(&pix);

    pix.fill(Qt::white);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawLine(QPoint(1,1),QPoint(1,210));
    painter.drawLine(QPoint(0,0),QPoint(210,1));
    painter.drawLine(QPoint(210,1),QPoint(210,210));
    painter.drawLine(QPoint(1,210),QPoint(210,210));
    for(int i=2;i<=21;i++)
    {
      for(int j=2;j<=21;j++)
      {
        if(s.map[i][j]==1) {
            painter.setBrush(Qt::black);
            painter.drawEllipse((j-2)*10+5,(i-2)*10+5,15,15);
            }
        if(s.map[i][j]==2) {
            painter.setBrush(Qt::white);
            painter.drawRect((j-2)*10+5,(i-2)*10+5,10,10);
            }
      }
    }
    painter.end();
    ui->drawlabel->setPixmap(pix);
    cout<<"update"<<endl;
    QString score = QString::number(s.score);
    ui->score->setText(score);
}

void Widget::dieslot()
{
    QPixmap pix(211,211);
    QPainter painter(&pix);

    pix.fill(Qt::white);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawLine(QPoint(1,1),QPoint(1,211));
    painter.drawLine(QPoint(0,0),QPoint(211,1));
    painter.drawLine(QPoint(211,1),QPoint(210,211));
    painter.drawLine(QPoint(1,211),QPoint(210,211));
    painter.drawText(75,100,"Game Over!");
    painter.end();
    ui->drawlabel->setPixmap(pix);
    ui->start->setEnabled(true);

    cout<<"die"<<endl;
}
