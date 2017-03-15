#include <iostream>
#include <cstdio>
#include <conio.h>//清屏 
#include <cstring>
#include <cstdlib>
#include <unistd.h>//控制休眠 
#define Random(x) (rand() % x)//生成随机数 
using namespace std;
int map[22][22];//地图(最外围一圈未使用) 最外圈为边界 0为空 1为蛇身 2为苹果 
void duqu();//读取函数 
void shuchu();//输出函数 
void move();//移动蛇身函数 
void eat();//吃苹果函数 
int pd_apple();//判断苹果是否在蛇身上 
char shuru,last_shuru;//输入为当前输入的数 shuru1为duqu读取的数 last_输入为上一位输入的有效数 
int length,ax,ay,die=1,head_x,head_y,tail_x,tail_y,score=0;//length长度 ax,ay苹果坐标 die=1未死 die=0死亡 head_x,head_y,tail_x,tail_y蛇头蛇尾坐标 score当前分数 
struct guanxi{//结构体a存储蛇每一位的坐标 
	int x,y;
}a[1001];
int main()
{
	int i;
	a[1].x=4;a[1].y=4;//初始化蛇(坐标为4,4;5,4;6,4) 
	a[2].x=5;a[2].y=4;
	a[3].x=6;a[3].y=4;
	length=3;//长度=3 
	ax=Random(19)+2;//初始化苹果位置 
	ay=Random(19)+2;
	shuru=getch();//按wsad任意键开始 
	last_shuru='w';//初始化last_shuru
	while(die==1)
	{
	  system("cls");//清屏 
	  duqu();//读取 
	  map[ax][ay]=2;//苹果在map中为2 
	  head_x=a[1].x;//从结构体a中读取蛇头蛇尾坐标 
	  head_y=a[1].y;
	  tail_x=a[length].x;
	  tail_y=a[length].y;
	  if(shuru=='w'&&last_shuru!='s')//移动蛇头 注意:像上一次输入为s现在输入为w则无效 无效时按上一次输入执行 
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
	  move();//移动蛇身 
	  if(a[1].x==ax&&a[1].y==ay)//吃到苹果后添加蛇尾,长度,分数 
	  {
	    a[length+1].x=tail_x;
	  	a[length+1].y=tail_y;
	  	length++;
	  	score++;
	    eat();
	  }
	  if(a[1].x==1) a[1].x=21;//穿墙部分 
	  if(a[1].y==1) a[1].y=21;
	  if(a[1].x==22) a[1].x=2;
	  if(a[1].y==22) a[1].y=2;
	  for(i=2;i<=length;i++)//判断是否死亡 
	    if(a[1].x==a[i].x&&a[1].y==a[i].y)
	    {
	      die=0;
	      break;
	    }
	  shuchu();//输出 
	  _sleep(0.15*1000);//暂停时间控制 
	}
	system("cls");//清屏 
	cout<<"SCORE="<<score;//输出分数 
	getch();//按enter退出 
}
void duqu()
{
	if (kbhit()!=0) shuru=getch();//kbhit函数:输入返回1 没有输入返回0 
}
void shuchu()
{
	int i,j;
	for(i=1;i<=length;i++)//按照结构体a在map中画出蛇 
	{
	  map[a[i].x][a[i].y]=1;
    }
    for(i=1;i<=22;i++)//输出map和边界 
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
	memset(map,0,sizeof(map));//清空map 
} 
void move()
{
	int i;
	for(i=length;i>2;i--)//从最后一位到第三位 当前位坐标变为前一位坐标 
	{
	  a[i].x=a[i-1].x;
	  a[i].y=a[i-1].y;
	}
	a[2].x=head_x;//修改第二位坐标 
	a[2].y=head_y;
}
void eat()
{
	do//生成新的苹果坐标 注意:苹果不能在蛇身上 
	{
	  ax=Random(19)+2;
	  ay=Random(19)+2;
    }while(pd_apple()==1);
}
int pd_apple()
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
