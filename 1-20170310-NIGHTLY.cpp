#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#define Random(x) (rand() % x)//Ëæ»úÊý 
using namespace std;
int map[12][12];
int duqu();
void shuchu();
void move();
char shuru,shuru1;

int length,ax,ay,apple=1;
struct guanxi{
	int x,y;
}a[101];
int main()
{
	a[1].x=4;a[1].y=4;
	a[2].x=5;a[2].y=4;
	a[3].x=6;a[3].y=4;
	length=3;
	ax=Random(9);
	ay=Random(9);

	while(duqu()!='q')
	{
	  system("cls");
	  shuru=shuru1;
	  map[ax][ay]=2;
	  move();
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
	  if(a[1].x==1) a[1].x=11;
	  if(a[1].y==1) a[1].y=11;
	  if(a[1].x==12) a[1].x=2;
	  if(a[1].y==12) a[1].y=2;
	  shuchu();
	  _sleep(0.1*1000);
	}
}
int duqu()
{
	shuru1=getch();
	return shuru1;
}
void shuchu()
{
	int i,j;
	for(i=1;i<=length;i++)
	{
	  map[a[i].x][a[i].y]=1;
    }
	for(i=2;i<=11;i++)
	{
	  for(j=2;j<=11;j++)
	  {
		if(map[i][j]==0) cout<<" ";
		if(map[i][j]==1) cout<<"*";
		if(map[i][j]==2) cout<<"#";
	  }
	  cout<<endl;
	}
	memset(map,0,sizeof(map));
} 
void move()
{
	int i;
	for(i=length;i>=2;i--)
	{
	  a[i].x=a[i-1].x;
	  a[i].y=a[i-1].y;
	}
}
