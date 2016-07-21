#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
#include<alloc.h>
#include<dos.h>
void main()
{
void tim(int u,int v);
int x,y,*a,i,j,k,m,n,c,N,*b,q[2],*r,u,v,w,z,l,e,p,o;
char f;
time_t t,t1;
eee:
clrscr();
printf("\n\nENTER THE NUMBER OF ROWS AND COLUMNS: ");
scanf("%d %d",&x,&y);
if(x>20||y>38) goto eee;
printf("\n\nENTER THE NUMBER OF MINES: ");
QWE:
scanf("%d",&l);
if(l==x*y) {printf("\n\nPLEASE ENTER LESS NUMBER OF MINES :");goto QWE;}
ee:
a=(int *)calloc(x,y*2);
b=(int *)calloc(x,y*2);
for(i=0;i<x;i++)
	for(j=0;j<y;j++)
	       {*(a+i*y+j)=-1;*(b+i*y+j)=0;}
t=0,t1=0;
q[0]=0;q[1]=0;
randomize();
for(i=0;i<l;i++)
{
j=random(x);
k=random(y);
if(*(a+j*y+k)==-1)
*(a+j*y+k)=9;
else i--;
} o=0;
for(i=0;i<x;i++)
{
	for(j=0;j<y;j++)
	{
	c=0;
	if(*(a+i*y+j)==-1)
	{
		u=i-1;v=i+2;w=j-1;z=j+2;
		if(u<0) u=0;if(w<0) w=0;
		if(v>x) v=x;if(z>y) z=y;
		for(m=u;m<v;m++)
		for(n=w;n<z;n++)
		if(*(a+m*y+n)==9) c++;
		*(a+i*y+j)=c;if(c==0) o++;
	}
	}
}
r=(int *)calloc(o*2,2);
k=0;c=1;o=0;
clrscr();
for(i=0;i<x;i++)
{for(j=0;j<y;j++)
printf(" @");printf("\n\n");}
gotoxy(1,1);printf("%c",175);
while(k<=x*y-l)
{
if(k==x*y-l) break;
while(!kbhit()&&t1!=0)
{
	if(c==0)
	{
	gotoxy(1,(x+2)*2);printf("STUPID.DON'T OPEN THE CELL THAT IS ALREADY OPENED.\n");
	c=-1;
	}
	gotoxy(1,(x+2)*2);
	if(t1+1==time(NULL)){gotoxy(1,(x+1)*2);t1=time(NULL);tim(t,t1);}
}
if(c==-1)
	{gotoxy(1,(x+2)*2);printf("                                                  \n");}
f=getch();
if(t1==0) {t=time(NULL);t1=t;}
n=q[0];N=q[1];
gotoxy(2*q[1]+1,2*q[0]+1);cprintf(" ");
if(f=='2') {if(n==x-1) n=-1; n++;}
if(f=='6') {if(N==y-1) N=-1; N++;}
if(f=='8') {if(n==0) n=x; n--;}
if(f=='4') {if(N==0) N=y; N--;}
q[0]=n;q[1]=N;
gotoxy(2*q[1]+1,2*q[0]+1);textcolor(7);cprintf("%c",175);
if(f=='0'){o=2;break;}
if(f=='7')
{
if(*(b+n*y+N)==0)
	{*(b+n*y+N)=2;gotoxy((N+1)*2,2*n+1);textcolor(4);cprintf("$");}
else if(*(b+n*y+N)==2)
	{*(b+n*y+N)=3;gotoxy((N+1)*2,2*n+1);textcolor(2);cprintf("?");}
else if(*(b+n*y+N)==3)
	{*(b+n*y+N)=0;gotoxy((N+1)*2,2*n+1);textcolor(7);cprintf("@");}
}
if(f=='5')
{
	if(*(b+n*y+N)==1) {c=0;continue;}
	if(*(a+n*y+N)!=9&&*(a+n*y+N)!=0)
	{*(b+n*y+N)=1;k++;
	gotoxy((N+1)*2,2*n+1);textcolor(3);cprintf("%d",*(a+n*y+N));
	}
	if(*(a+n*y+N)==9) {*(b+n*y+N)=4;o=1;break;}
	if(*(a+n*y+N)==0)
	{
		c=1;
		*r=n;*(r+1)=N;
		for(m=1;m<=c;m++)
		{
		u=n-1;v=n+2;w=N-1;z=N+2;
		if(u<0) u=0; if(w<0) w=0;
		if(v>x) v=x; if(z>y) z=y;
		for(i=u;i<v;i++)
		for(j=w;j<z;j++)
		if(*(a+i*y+j)==0)
		{
		e=0;
		for(p=0;p<c;p++)
		if(*(r+p*2)==i&&*(r+p*2+1)==j) e=1;
		if(e==0) {*(r+c*2)=i;*(r+c*2+1)=j;c++;}
		}
		n=*(r+m*2);N=*(r+m*2+1);
		}
		for(m=0;m<c;m++)
		{
			n=*(r+m*2);N=*(r+m*2+1);
			u=n-1;v=n+2;w=N-1;z=N+2;
			if(u<0) u=0; if(w<0) w=0;
			if(v>x) v=x; if(z>y) z=y;
			for(i=u;i<v;i++)
			for(j=w;j<z;j++)
			{
			if(*(b+i*y+j)==0) k++;
			*(b+i*y+j)=1;
			gotoxy((j+1)*2,2*i+1);textcolor(7);
			if(*(a+i*y+j)==0) cprintf(".");
			else {textcolor(3);cprintf("%d",*(a+i*y+j));}
			}
		}

	}
}
}
for(i=0;i<x;i++)
for(j=0;j<y;j++)
{
if(*(a+i*y+j)!=9) continue;
gotoxy((j+1)*2,i*2+1);
if(o==0) {textcolor(2);cprintf("$");}
else if(i==n&&j==N) {textcolor(4);cprintf("*");}
else {textcolor(5);cprintf("*");}
}
textcolor(7);
gotoxy(1,(x+2)*2);
if(o==0)
printf("\nCOOL!! YOU ARE A GOOD MINESWEPER.");
else if(o==1) printf("\nBOMB!   BOMB!   BOMB!");
printf("\n\nTO CONTINUE PRESS Y.FOR NEW GAME PRESS N.");
f=getch();
if(f=='y'||f=='Y') goto ee;
else if(f=='n'||f=='N') goto eee;
free(a);free(b);free(r);
}
void tim(int u,int v)
{
int h,m;
v=v-u;
h=v/3600;
v=v%3600;
m=v/60;
v=v%60;
printf("TIME:  %d:%d:%d\n\n",h,m,v);
}