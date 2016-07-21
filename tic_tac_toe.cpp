#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
class tick
{
public:
int a[3][3],i,j,k,u,v,n,e,o,p,l;
char x;
void start();
void initial();
void ins();
void out(int q,int w);
void in();
void com(int r);
void check();
void result(int z);
private:
void time(int p);
};
void tick :: start()
{
clrscr();
cout <<"\n\n\n\t\tWELCOME TO THE GAME OF TIC-TAC-TOE";
cout <<"\n\n\t1 EASY\n\n\t2 NORMAL\n\n\t3 HARD\n\n\nENTER YOUR OPTION :";
cin >>l;
cout <<"\n\n\n\nIF YOU WANT TO START PRESS 1 ELSE 0 :";
x=getche();
}
void tick :: initial()
{
e=2;
for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		a[i][j]=2;
}
void tick :: ins()
{
clrscr();
cout <<"\n\n\nPRESS THE CORESPONDING NUMBERS AND ENTER\n\n\n\n\n";
for(i=0;i<3;i++)
{
cout <<"\t\t       ";
for(j=0;j<3;j++)
cout <<"   "<<i<<j;
cout <<"\n\n\n";
}
cout <<"\n\nBEGIN THE GAME : ";
}
void tick :: out(int q,int w)
{
clrscr();
ch:
cout <<"\n\n\nCOMPUTER";
time(q);
cout <<"\t\t\tYOUR";
time(w);
cout <<"\n\n\n\n\n";
for(i=0;i<3;i++)
{
	cout <<"\t\t       ";
	for(j=0;j<3;j++)
	{
		textcolor(7);
		if(a[i][j]==2) cout <<"   "<<i<<j;
		else if(a[i][j]==1) {textcolor(2);cprintf("    X");}
		else {textcolor(4);cprintf("    O");}
	}
	cout <<"\n\n\n";
}
textcolor(7);
cout <<"\n\nCOMPUTER MOVE: "<<u<<v;
cout <<"\t\t\t ";
cout <<"YOUR MOVE: ";
}
void tick :: in()
{
ch:
cin >>n;
if(a[n/10][n%10]!=2)
{
cout<<"\n\nYOU STUPID CAN'T YOU ENTER CORRECTLY.DON'T TRY TO CHEAT ME.I GIVE YOU ONE CHANCE\n\n";
cout <<"\nYOUR MOVE: ";goto ch;
}
else a[n/10][n%10]=1;
}
void tick :: com(int r)
{
int m,n=0,z=0;
randomize();
if(r==1&&x=='0') goto st;
if(l==3&&r==3&&x=='0')
{
for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(a[i][j]==1) {u=i;v=j;}
if(u!=1||v!=1) goto st;
}
if(r==3&&x=='0'&&a[1][1]==2&&n==0) {a[1][1]=0;u=1;v=1;n=1;}
if(r==1&&x=='1')
{
if(a[1][1]==2)
{
if(l==3) {a[1][1]=0;n=1;u=1;v=1;}
if(l==2&&random(2)==1) {a[1][1]=0;n=1;u=1;v=1;}
}
else
{
st:u=random(3);v=random(3);
if(u==1||v==1||a[u][v]!=2) goto st;
a[u][v]=0;n=1;
}
}
if(n==0)
{start:
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
		for(k=0;k<3;k++)
		{
		if(a[i][j]==z) if(j!=k&&a[i][j]==a[i][k])
		{
			for(m=0;m<3;m++) if(m!=j&&m!=k) break;
			if(a[i][m]==2) {a[i][m]=0;u=i;v=m;n=1;goto end;}
		}
		if(a[j][i]==z) if(j!=k&&a[j][i]==a[k][i])
		{
			for(m=0;m<3;m++) if(m!=j&&m!=k) break;
			if(a[m][i]==2) {a[m][i]=0;u=m;v=i;n=1;goto end;}
		}
		if(a[j][j]==z) if(j!=k&&a[j][j]==a[k][k])
		{
			for(m=0;m<3;m++) if(m!=j&&m!=k) break;
			if(a[m][m]==2) {a[m][m]=0;u=m;v=m;n=1;goto end;}
		}
		if(a[j][k]==z&&j+k==2)
		{
		if(j!=k)
		{if(a[j][k]==a[k][j]&&a[1][1]==2) {a[1][1]=0;u=1;v=1;n=1;goto end;}}
		else
		{
		if(a[0][2]==a[1][1]&&a[2][0]==2) {a[2][0]=0;u=2;v=0;n=1;goto end;}
		if(a[2][0]==a[1][1]&&a[0][2]==2) {a[0][2]=0;u=0;v=2;n=1;goto end;}
		}
		}
		}
	}
}
}
if(z==0&&n==0) {z=1;goto start;}
end:
/*z=0;
if(n==0)
{
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{       m=0;
	o=0;p=0;
	if(a[i][j]==2)
	{
	for(k=0;k<3;k++)
	{
		if(a[i][k]==z) o++; if(a[i][k]==2) p++;
		if(a[k][j]==z) o++; if(a[k][j]==2) p++;
		if(a[k][k]==z) o++; if(a[k][k]==2) p++;
		if(j+k==2) {if(a[j][k]==z) o++; if(a[k][j]==2) p++;}
	}
	if(o>=2&&p>=4) {m++;u=i;v=j;}
	}
}
}
if(m>=2&&z!=0)
{if(u==1||v==1) m=1; else m=0;
sqt:u=random(3);v=random(3);
if(u==m||v==m||a[u][v]!=2) goto sqt;
a[u][v]=0;n=1;
}
else {a[u][v]=0;n=1;}
}    */
if(z==0&&n==0) {z=1;goto end;}
if(n==0)
{
re:
u=random(3);v=random(3);
if(a[u][v]==2) a[u][v]=0;
else goto re;
delay(1000);
}
}
void tick :: check()
{
for(i=0;i<3;i++)
{
if(a[i][0]!=2) if(a[i][0]==a[i][1]&&a[i][0]==a[i][2])
e=a[i][0];
if(a[0][i]!=2) if(a[0][i]==a[1][i]&&a[0][i]==a[2][i])
e=a[0][i];
if(e!=2) break;
}
if(e==2)
{
if(a[0][0]!=2) if(a[0][0]==a[1][1]&&a[0][0]==a[2][2])
e=a[0][0];
if(a[1][1]!=2) if(a[0][2]==a[1][1]&&a[0][2]==a[2][0])
e=a[0][2];
}
}
void tick :: result(int z)
{
cout <<"\n\n\n\nMATCH RESULT :";
if(z==0) {textcolor(4);cprintf(" YOU LOSE");}
else if(z==1) {textcolor(2);cprintf(" YOU WON");}
else cout <<" TIE";
textcolor(7);
}
void main()
{
int a1,a2,r;
char o='y';
time_t t,t1;
tick game;
while(o=='y'||o=='Y')
{
int ct=0,yt=0;
game.start();
game.initial();
if(game.x=='1')  {a1=0;a2=8;}
else {a1=1;a2=9;}
for(r=a1;r<=a2;r++)
{
t=time(NULL);
if(r%2==0)
{
	if(r==0) game.ins();
	else game.out(ct,yt);
	game.in();
}
else game.com(r);
t1=time(NULL);
if(r%2==0) yt+=t1-t;
else ct+=t1-t;
game.check();
if(game.e!=2||r==a2)
{
	game.out(ct,yt);
	game.result(game.e);
	break;
}
}
cout <<"\n\n\nTO CONTINUE PRESS Y: ";
o=getch();
}
}
void tick :: time(int p)
{
int h,m;
h=p/3600;
p=p%3600;
m=p/60;
p=p%60;
cout <<" TIME:  "<<h<<" :"<<m<<" :"<<p;
}






