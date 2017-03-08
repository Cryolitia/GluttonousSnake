#include <iostream>
#include <cstdio>
#include <cstring>

//#define win

#ifdef win
#include <conio.h>
#endif

using namespace std;
int map[12][12];
int duqu();
void shuchu();
char shuru;
struct guanxi{
    int x,y;
}a[101];
int main()
{
    a[1].x=5;a[1].y=5;
    while(duqu()!='q')
    {
#ifdef win
        system("cls");
#else
        system("clear");
#endif
        if(shuru=='w')
        {
            a[1].x=a[1].x-1;a[1].y=a[1].y;
        }
        if(shuru=='s')
        {
            a[1].x=a[1].x+1;a[1].y=a[1].y;
        }
        if(shuru=='a')
        {
            a[1].x=a[1].x;a[1].y=a[1].y-1;
        }
        if(shuru=='d')
        {
            a[1].x=a[1].x;a[1].y=a[1].y+1;
        }
        if(a[1].x==1) {a[1].x=11;}
        if(a[1].y==1) {a[1].y=11;}
        if(a[1].x==12) {a[1].x=2;}
        if(a[1].y==12) {a[1].y=2;}
        shuchu();
    }
}
int duqu()
{
    char x;
    x=getchar();
    shuru=x;
    return x;
}
void shuchu()
{
    int i,j;
    map[a[1].x][a[1].y]=1;
    for(i=2;i<=11;i++)
    {
        for(j=2;j<=11;j++)
        {
            if(map[i][j]==0) cout<<" ";
            if(map[i][j]==1) cout<<"*";
        }
        cout<<endl;
    }
    memset(map,0,sizeof(map));
}
