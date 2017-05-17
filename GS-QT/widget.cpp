#include "widget.h"
#include "ui_widget.h"

sc s;
QColor linecolor = Qt::black;
QColor lastline = Qt::black;
QColor snackcolor = Qt::black;
QColor foodcolor = Qt::white;
QColor background = Qt::white;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QObject::connect(&s, SIGNAL(updatesig()), SLOT(updateslot()), Qt::DirectConnection);
    QObject::connect(&s, SIGNAL(diesig()),  SLOT(dieslot()));

    ui->spinBox->setMaximum(1000);
    ui->spinBox->setMinimum(1);
    ui->horizontalSlider->setMaximum(1000);
    ui->horizontalSlider->setMinimum(1);
    ui->horizontalSlider->setPageStep(50);
    ui->horizontalSlider->setValue(200);
    ui->spinBox->setValue(200);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    QPixmap tmpcolor(50,50);
    ui->checkBox->setChecked(true);
    foodcolor.setAlpha(1);
    QIcon tmpicon;
    tmpcolor.fill(linecolor);
    tmpicon = QIcon(tmpcolor);
    ui->linebutton->setIcon(tmpicon);
    tmpcolor.fill(snackcolor);
    tmpicon = QIcon(tmpcolor);
    ui->snackButton->setIcon(tmpicon);
    tmpcolor.fill(foodcolor);
    tmpicon = QIcon(tmpcolor);
    ui->foodbutton->setIcon(tmpicon);
    tmpcolor.fill(background);
    tmpicon = QIcon(tmpcolor);
    ui->backbutton->setIcon(tmpicon);

    QPixmap pix(211,211);
    QPainter painter(&pix);

    pix.fill(background);
    painter.setPen(linecolor);
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

    pix.fill(background);
    painter.setPen(linecolor);
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
            painter.setBrush(snackcolor);
            painter.drawEllipse((j-2)*10+5,(i-2)*10+5,15,15);
            }
        if(s.map[i][j]==2) {
            painter.setBrush(foodcolor);
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

    pix.fill(background);
    painter.setPen(linecolor);
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

void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    s.speed = value;
}

void Widget::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
    s.speed = arg1;
}

void Widget::on_checkBox_stateChanged(int arg1)
{
    ui->linebutton->setHidden(!bool(arg1));
    if (!bool(arg1)) {
        linecolor.setAlpha(0);
        QPixmap tmpcolor(50,50);
        QIcon tmpicon;
        tmpcolor.fill(linecolor);
        tmpicon = QIcon(tmpcolor);
        ui->linebutton->setIcon(tmpicon);
    }
    else {
        linecolor.setAlpha(1);
        linecolor=lastline;
        QPixmap tmpcolor(50,50);
        QIcon tmpicon;
        tmpcolor.fill(linecolor);
        tmpicon = QIcon(tmpcolor);
        ui->linebutton->setIcon(tmpicon);
    }
}

void Widget::on_linebutton_clicked()
{
    linecolor=QColorDialog::getColor(Qt::black, this, tr("设置描边颜色"), QColorDialog::ShowAlphaChannel);
    lastline=linecolor;
    QPixmap tmpcolor(50,50);
    QIcon tmpicon;
    tmpcolor.fill(linecolor);
    tmpicon = QIcon(tmpcolor);
    ui->linebutton->setIcon(tmpicon);
}

void Widget::on_snackButton_clicked()
{
    snackcolor=QColorDialog::getColor(Qt::black, this, tr("设置蛇身颜色"), QColorDialog::ShowAlphaChannel);
    QPixmap tmpcolor(50,50);
    QIcon tmpicon;
    tmpcolor.fill(snackcolor);
    tmpicon = QIcon(tmpcolor);
    ui->snackButton->setIcon(tmpicon);
}

void Widget::on_foodbutton_clicked()
{
    foodcolor=QColorDialog::getColor(Qt::white, this, tr("设置食物颜色"), QColorDialog::ShowAlphaChannel);
    QPixmap tmpcolor(50,50);
    QIcon tmpicon;
    tmpcolor.fill(foodcolor);
    tmpicon = QIcon(tmpcolor);
    ui->foodbutton->setIcon(tmpicon);
}

void Widget::on_backbutton_clicked()
{
    background=QColorDialog::getColor(Qt::white, this, tr("设置背景颜色"));
    QPixmap tmpcolor(50,50);
    QIcon tmpicon;
    tmpcolor.fill(background);
    tmpicon = QIcon(tmpcolor);
    ui->backbutton->setIcon(tmpicon);
    setPalette(background);
}
