#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>
#include<stdlib.h>
int u=24,v=32,h=3,br=3;
class snake
{
int i,j,k,q,m,n,c[2],z[2];
struct sna
{
int d,l[2];
}*a;
void pri(int,int,int,int);
void cir(int x,int y,int c)
{
setcolor(c);setfillstyle(1,c);
fillellipse(y*20+10,x*20+10,5,5);
}
public:
void proc();
}samp;
void snake::pri(int e,int f,int p,int q)
{
int l,r,x,y;
for(l=0;l<360;l+=30,delay(h))
{
for(r=0;r<2;r++)
{
if(r==0) {x=e;y=f;setcolor(2);}
else {x=p;y=q;setcolor(0);}
if((a+x*v+y)->d%10==0)
{
	if((a+x*v+y)->d==60)
	{
		if(l<180) arc(20*y+5,20*x+10,150-l,180-l,5);
		else arc(20*y+15,20*x+10,l,l+30,5);
	}
	if((a+x*v+y)->d==50)
	{
		if(l<180) arc(20*y+10,20*x+5,90+l,120+l,5);
		else arc(20*y+10,20*x+15,600-l,630-l,5);
	}
	if((a+x*v+y)->d==40)
	{
		if(l<180) arc(20*y+15,20*x+10,330-l,360-l,5);
		else arc(20*y+5,20*x+10,l-180,l-150,5);
	}
	if((a+x*v+y)->d==80)
	{
		if(l<180) arc(20*y+10,20*x+15,270+l,300+l,5);
		else arc(20*y+10,20*x+5,420-l,450-l,5);
	}
}
else
{
	if((a+x*v+y)->d/10==8)
	{
		if((a+x*v+y)->d%10==4&&l>30&&l<300)
		arc(20*y+5,20*x+15,270+l/30*22.5,292.5+l/30*22.5,7);
		else if((a+x*v+y)->d%10==6)
		arc(20*y+10,20*x+10,270+l/30*7.5,277.5+l/30*7.5,10);
	}
	if((a+x*v+y)->d/10==6)
	{
		if((a+x*v+y)->d%10==5&&l>30&&l<300)
		arc(20*y+5,20*x+15,517.5-l/30*22.5,540-l/30*22.5,7);
		else if((a+x*v+y)->d%10==8)
		arc(20*y+10,20*x+10,172.5-l/30*7.5,180-l/30*7.5,10);
	}
	if((a+x*v+y)->d/10==4)
	{
		if((a+x*v+y)->d%10==5)
		arc(20*y+10,20*x+10,352.5-(l/30)*7.5,360-(l/30)*7.5,10);
		else if((a+x*v+y)->d%10==8&&l>30&&l<300)
		arc(20*y+15,20*x+5,337.5-(l/30)*22.5,360-(l/30)*22.5,7);
	}
	if((a+x*v+y)->d/10==5)
	{
		if((a+x*v+y)->d%10==4)
		arc(20*y+10,20*x+10,90+(l/30)*7.5,97.5+(l/30)*7.5,10);
		else if((a+x*v+y)->d%10==6&&l<300&&l>30)
		arc(20*y+15,20*x+5,90+(l/30)*22.5,112.5+(l/30)*22.5,7);
	}
}
}
}
}
void snake::proc()
{
char g,t;
setlinestyle(0,0,br);
a=(struct sna *)calloc(u,v*sizeof(struct sna));
randomize();
for(i=0;i<u;i++)
	for(j=0;j<v;j++)
		{(a+i*v+j)->l[0]=-1;(a+i*v+j)->l[1]=-1;}
a->d=60;(a+1)->d=60;(a+2)->d=60;(a+3)->d=60;
pri(0,0,0,v-1);pri(0,1,0,v-1);pri(0,2,0,v-1);pri(0,3,0,v-1);
a->l[0]=0;a->l[1]=1;
(a+1)->l[0]=0;(a+1)->l[1]=2;
(a+2)->l[0]=0;(a+2)->l[1]=3;
(a+3)->l[0]=0;(a+3)->l[1]=4;
g='6';
z[0]=0;z[1]=0;
c[0]=0;c[1]=4;
do{
j=random(u);
k=random(v);
}while((a+j*v+k)->d!=0);
(a+j*v+k)->d=1;cir(j,k,4);
getch();
while(g!='0')
{
if(kbhit())
{
	t=getch();
	if(t=='p') t=getch();
	if(((t=='5'&&g!='8')||(t=='4'&&g!='6')||(t=='6'&&g!='4')||(t=='8'&&g!='5')||t=='0')&&t!=g)
	{(a+c[0]*v+c[1])->d=atoi(&g)*10+atoi(&t)/10;g=t;}
	else
		(a+c[0]*v+c[1])->d=atoi(&g)*10;

}
else
	(a+c[0]*v+c[1])->d=atoi(&g)*10;
pri(c[0],c[1],z[0],z[1]);
m=c[0];n=c[1];
if(g=='5') {if(m==u-1) m=-1; m=m+1;}
if(g=='4') {if(n==0) n=v; n=n-1;}
if(g=='8') {if(m==0) m=u; m=m-1;}
if(g=='6') {if(n==v-1) n=-1; n=n+1;}
(a+c[0]*v+c[1])->l[0]=m;(a+c[0]*v+c[1])->l[1]=n;
c[0]=m;c[1]=n;
if((a+m*v+n)->d==1)
{
cir(m,n,0);
do{
j=random(u);
k=random(v);
}while((a+j*v+k)->d!=0);
(a+j*v+k)->d=1;
cir(j,k,4);
}
else if((a+m*v+n)->d==0||(z[0]==m&&z[1]==n))
{
(a+z[0]*v+z[1])->d=0;
j=z[0];k=z[1];
z[0]=(a+j*v+k)->l[0];z[1]=(a+j*v+k)->l[1];
}
if((a+m*v+n)->d!=0&&(a+m*v+n)->d!=1) break;
}
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

samp.proc();
getch();
closegraph();
}