#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<alloc.h>
#include<stdlib.h>
class toa
{
int *a,i,j,k,n,h,l;
void rect(int x,int y,int c)
{
setcolor(c);
rectangle(160*(x+1)-*(a+x*n+y)*l,362-(n-y)*h,160*(x+1)+*(a+x*n+y)*l,358-(n-y-1)*h);
}
void cir(int x,int c)
{
setcolor(c);setfillstyle(1,c);
fillellipse(160*(x+1),361-(n+2)*h,7,7);
}
int top(int x);
public:
void process();
}sam;
int toa::top(int x)
{
int i;
for(i=0;i<n;i++)
	if(*(a+x*n+i)!=0) break;
return(i);
}
void toa::process()
{
int p=0,e=0,t,u,s,c=0;
char d,*b;
n=4;h=20;l=70/n;
a=(int*)calloc(3,n*2);
setlinestyle(0,0,3);
for(i=0;i<n;i++)
	{*(a+i)=i+1;rect(0,i,2);}
for(i=1;i<3;i++)
	for(j=0;j<n;j++)
		*(a+i*n+j)=0;
cir(p,2);
line(240,381-(n+2)*h,240,360);line(80,381-(n+2)*h,80,360);
line(400,381-(n+2)*h,400,360);line(560,381-(n+2)*h,560,360);
line(80,362,560,362);
settextstyle(1,0,4);
outtextxy(200,20,"TOWER OF ANOI");
outtextxy(160,70,"NO OF ATTEMPTS :");itoa(c,b,10);outtextxy(450,70,b);
do
{
d=getch();
cir(p,0);
if(d=='6')
	p=(p+1)%3;
else if(d=='4')
{
	p--;
	if(p<0) p=2;
}
else if(d=='5')
{
	if(e==0)
	{
		t=top(p);
		if(t==n)
		{
			setcolor(3);
			outtextxy(30,430,"NO BOX IN THAT C0LUMN TO SELECT");
			delay(700);setcolor(0);
			outtextxy(30,430,"NO BOX IN THAT C0LUMN TO SELECT");
		}
		else
		{
			e=1;rect(p,t,4);u=p;
		}
	}
	else
	{
		if(u==p) rect(p,t,2);
		else
		{
			s=top(p);
			if(*(a+u*n+t)<*(a+p*n+s)||s==n)
			{
			setcolor(0);itoa(c,b,10);outtextxy(450,70,b);
			c++;setcolor(3);itoa(c,b,10);outtextxy(450,70,b);
			rect(u,t,0);
			e=*(a+u*n+t);*(a+u*n+t)=*(a+p*n+s-1);*(a+p*n+s-1)=e;
			rect(p,s-1,2);
			}
			else
			{
			setcolor(3);
			outtextxy(120,430,"NOT ALLOWED TO PUT BOX");
			delay(700);setcolor(0);
			outtextxy(120,430,"NOT ALLOWED TO PUT BOX");
			rect(u,t,2);
			}
		}
		e=0;
	}
}
cir(p,2);
}while(d!='0');
free(a);
}
void main()
{
int gdriver = DETECT, gmode,errorcode;
initgraph(&gdriver, &gmode, "");
errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
cleardevice();
sam.process();
getch();
closegraph();
}