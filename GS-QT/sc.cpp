#include "sc.h"

sc::sc(QObject *parent) : QThread()
{

}

void sc::init () {
        score=0;
        int initx=qrand()%17+2,inity=qrand()%19+2;
        die=false;
        a[1].x=initx;a[1].y=inity;
        a[2].x=initx+1;a[2].y=inity;
        a[3].x=initx+2;a[3].y=inity;
        length=3;
        ax=qrand()%19+2;
        ay=qrand()%19+2;
        last_shuru='w';
        shuru1 = 'w';
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    }
void sc::run () {
        while (!die) {
            solve();
            shuchu();
            emit updatesig();
            memset(map,0,sizeof(map));
            msleep(200);
        }
        emit diesig();
        return;
    }
void sc::solve (){
          shuru=shuru1;
          map[ax][ay]=2;
          head_x=a[1].x;
          head_y=a[1].y;
          tail_x=a[length].x;
          tail_y=a[length].y;
          if(shuru=='w'&&last_shuru!='s')
          {
            a[1].x=a[1].x-1;
            a[1].y=a[1].y;
            last_shuru=shuru;
          }
          if(shuru=='s'&&last_shuru!='w')
          {
            a[1].x=a[1].x+1;
            a[1].y=a[1].y;
            last_shuru=shuru;
          }
          if(shuru=='a'&&last_shuru!='d')
          {
            a[1].x=a[1].x;
            a[1].y=a[1].y-1;
            last_shuru=shuru;
          }
          if(shuru=='d'&&last_shuru!='a')
          {
            a[1].x=a[1].x;
            a[1].y=a[1].y+1;
            last_shuru=shuru;
          }
          if(shuru=='w'&&last_shuru=='s')
          {
            a[1].x=a[1].x+1;
            a[1].y=a[1].y;
          }
          if(shuru=='s'&&last_shuru=='w')
          {
            a[1].x=a[1].x-1;
            a[1].y=a[1].y;
          }
          if(shuru=='a'&&last_shuru=='d')
          {
            a[1].x=a[1].x;
            a[1].y=a[1].y+1;
          }
          if(shuru=='d'&&last_shuru=='a')
          {
            a[1].x=a[1].x;
            a[1].y=a[1].y-1;
          }
          move();
          if(a[1].x==ax&&a[1].y==ay)
          {
            a[length+1].x=tail_x;
            a[length+1].y=tail_y;
            length++;
            score++;
            eat();
          }
          if(a[1].x==1) a[1].x=21;
          if(a[1].y==1) a[1].y=21;
          if(a[1].x==22) a[1].x=2;
          if(a[1].y==22) a[1].y=2;
          for(i=2;i<=length;i++)
            if(a[1].x==a[i].x&&a[1].y==a[i].y)
            {
              die=true;
            }
    }
void sc::move()
    {
        int i;
        for(i=length;i>2;i--)
        {
          a[i].x=a[i-1].x;
          a[i].y=a[i-1].y;
        }
        a[2].x=head_x;
        a[2].y=head_y;
    }
void sc::eat()
    {
        do
        {
          ax=qrand()%19+2;
          ay=qrand()%19+2;
        }while(pd_apple()==1);
    }
int sc::pd_apple()
    {
        int i,pd=0;
        for(i=1;i<=length;i++)
          if(ax==a[i].x&&ay==a[i].y)
          {
            pd=1;
            break;
          }
        if(pd==1)
          return 1;
        else
          return 0;
    }
void sc::shuchu()
    {
        int i,j;
        for(i=1;i<=length;i++)
        {
          map[a[i].x][a[i].y]=1;
        }
        for(i=1;i<=22;i++)
          cout<<"0";
        cout<<endl;
        for(i=2;i<=21;i++)
        {
          cout<<"0";
          for(j=2;j<=21;j++)
          {
            if(map[i][j]==0) cout<<" ";
            if(map[i][j]==1) cout<<"-";
            if(map[i][j]==2) cout<<"#";
          }
          cout<<"0"<<endl;
        }
        for(i=1;i<=22;i++)
          cout<<"0";
    }
