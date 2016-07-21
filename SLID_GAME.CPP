#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
class slid
{
public:
time_t t,t1;
int *a,i,j,k,m,n,x,y,r,c,mx,my,g,p[8];
char *h,*f[];
void input();
void output();
void rect(int l,int b);
}ti;
void slid::rect(int l,int b)
{
int u,v;
u=b/10;v=b%10;
setcolor(8);
setlinestyle(0,0,1);
setfillstyle(1,l);
p[0]=mx+v*g;p[1]=my+u*g;p[6]=mx+v*g;p[7]=my+g+u*g;
p[2]=mx+g+v*g;p[3]=my+u*g;p[4]=mx+g+v*g;p[5]=my+g+u*g;
fillpoly(4,p);
if(*(a+u*c+v)!=0)
{
setcolor(0);
itoa(*(a+u*c+v),h,10);outtextxy(mx+v*g+10,my+u*g,h);
}
}
void slid::input()
{
su: clrscr();
printf("ENTER THE NO. OF ROWS AND COLUMNS : ");
scanf("%d %d",&r,&c);
if(r==1||c==1) goto su;
a=(int *)calloc(r,c*2);
for(i=0;i<r;i++)
	for(j=0;j<c;j++)
		*(a+i*c+j)=0;
randomize();
for(i=0;i<r*c;i++)
{
in:
m=random(r);
n=random(c);
if(*(a+m*c+n)!=0) goto in;
*(a+m*c+n)=i;
}
}
void slid::output()
{
char d='0';
k=0;
int gdriver = DETECT, gmode, errorcode;
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
setbkcolor(0);setcolor(7);
settextstyle(3,0,4);
outtextxy(10,10,"TIME: ");
setcolor(4);
g=50;
mx=getmaxx()/2-g*c/2,my=getmaxy()/2-g*r/2;
setlinestyle(0,0,3);
rectangle(mx+3+c*g,my+3+r*g,mx-3,my-3);
settextstyle(4,0,4);
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
if(*(a+i*c+j)==0) rect(0,i*10+j);
else rect(7,i*10+j);
}
rect(2,0);
m=0;n=0; setcolor(7);
while(k==0)
{
while(kbhit()==0)
{
if(t1==time(NULL)-1)
{
setcolor(0);
itoa((t1-t-1)/60,*f,10);moveto(100,10);outtext(*f);outtext(" : ");
itoa((t1-t-1)%60,*f,10);outtext(*f);
setcolor(7);
itoa((t1-t)/60,*f,10);moveto(100,10);outtext(*f);outtext(" : ");
itoa((t1-t)%60,*f,10);outtext(*f);
t1=time(NULL);
}
if(d=='0') {t=time(NULL);t1=t;}
}
d=getch();
if(*(a+m*c+n)==0) rect(0,m*10+n);
else rect(7,m*10+n);
if(d=='2') {if(m==r-1) m=-1; m++;}
if(d=='4') {if(n==0) n=c; n--;}
if(d=='8') {if(m==0) m=r; m--;}
if(d=='6') {if(n==c-1) n=-1; n++;}
rect(2,m*10+n);
if(d=='0') break;
if(d=='5')
{
	x=m;y=n;
	for(i=0;i<r;i++)
		if(*(a+i*c+y)==0) {x=i;d='2';break;}
	if(d=='2'&&i!=r)
	{
		if(x>m)
		{
			j=x-m;
			for(i=0;i<j;i++)
			{
				*(a+x*c+y)=*(a+(x-1)*c+y);
				rect(7,x*10+y);
				x--;
			}
		}
		if(m>x)
		{
			j=m-x;
			for(i=0;i<j;i++)
			{
				*(a+x*c+y)=*(a+(x+1)*c+y);
				rect(7,x*10+y);
				x++;
			}
		}
		*(a+m*c+n)=0;
	}
	for(i=0;i<c;i++)
		if(*(a+x*c+i)==0) {y=i;d='6';break;}
	if(d=='6'&&i!=c)
	{
		if(y>n)
		{
			j=y-n;
			for(i=0;i<j;i++)
			{
				*(a+x*c+y)=*(a+x*c+y-1);
				rect(7,x*10+y);
				y--;
			}
		}
		if(n>y)
		{
			j=n-y;
			for(i=0;i<j;i++)
			{
				*(a+x*c+y)=*(a+x*c+y+1);
				rect(7,x*10+y);
				y++;
			}
		}
		*(a+m*c+n)=0;
	}
	rect(2,m*10+n);
}
}
getch();
closegraph();
free(a);
}
void main()
{
ti.input();
ti.output();
}


