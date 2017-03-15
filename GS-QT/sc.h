#ifndef SC_H
#define SC_H

#include <QObject>
#include "QThread"
#include "QWidget"
#include <iostream>
using std::cout;
using std::endl;

class sc : public QThread
{
    Q_OBJECT
public:
    explicit sc(QObject *parent = 0);
    int map[22][22];
    char shuru1;
    int ax,ay,score=0;
    bool die = false;
    void init ();
    void run () ;

    char shuru,last_shuru;
    int length,head_x,head_y,tail_x,tail_y,i;
    struct guanxi{
        int x,y;
    }a[401];
    void solve ();
    void eat();
    int pd_apple ();
    void shuchu();
    void move();


signals:
    void updatesig();
    void diesig();

public slots:
};

#endif // SC_H
