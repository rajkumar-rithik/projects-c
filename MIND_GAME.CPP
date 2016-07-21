#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>
class mind
{
time_t t,t1;
char d,*a,zu,*h,*f;
int z,x,y,n,N,i,j,k,u,b,c,*r,q,m,g,mx,my,w;
void rect(int l)
{
setcolor(l);i=q/10;j=q%10;
rectangle(mx+j*g,my+i*g,mx+j*g+g,my+i*g+g);
setcolor(7);
}
void show(int l)
{
moveto(mx+10+l%10*g,my+l/10*g);setcolor(0);outtext("@");
moveto(mx+10+l%10*g,my+l/10*g);setcolor(7);
zu=*(a+l/10*y+l%10);outtext(&zu);
}
void close(int l)
{
moveto(mx+10+l%10*g,my+l/10*g);setcolor(0);
zu=*(a+l/10*y+l%10);outtext(&zu);
moveto(mx+10+l%10*g,my+l/10*g);setcolor(7);outtext("@");
}
public:
void input();
void que();
void output();
}tri;
void mind::input()
{
q:
clrscr();
printf("\n\nTO QUIT DURING THE GAME PRESS 0");
printf("\n\nENTER THE NUMBER OF ROWS AND COLUMNS :");
scanf("%d %d",&x,&y);
z=x*y;
if(z<4||z>100) goto q;
as:printf("\n\nENTER THE NUMBER OF REPITIONS :");
scanf("%d",&k);
if((k>x&&k>y)||k==1) goto as;
}
void mind::que()
{
r=(int *)calloc(50,2);
a=(char *)malloc(x*y);
for(i=0;i<50;i++)
*(r+i)=1;
for(i=0;i<x;i++)
	for(j=0;j<y;j++)
		*(a+i*y+j)=' ';
char s[50]="ABCDEFGHIJKLMNOPQRSTUVWXYZ!;#$%^&*()~-+=/[]{}|<>?:";
randomize();
for(i=0;i<z/k;i++)
{
	ro:
	m=random(50);
	if(*(r+m)==0) goto ro;
	*(r+m)=0;
	for(j=0;j<k;j++)
	{
	st:
	n=random(x);
	N=random(y);
	if(*(a+n*y+N)!=' ') goto st;
	*(a+n*y+N)=s[m];
	}
}
}
void mind::output()
{
int o=0;
char *p;
p=(char *)malloc(z/k);
for(j=0;j<z/k;j++) *(p+j)=' ';
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

r=(int *)calloc(k,2);
c=0;q=0;t=0;t1=0;
m=0;u=0;w=0;
cleardevice();
setbkcolor(0);
setcolor(4);
g=40-x;
mx=getmaxx()/2-g*y/2,my=getmaxy()/2-g*x/2;
setlinestyle(0,0,3);
for(i=0;i<=y;i++)
   line(mx+i*g,my,mx+i*g,my+x*g);
for(i=0;i<=x;i++)
   line(mx,my+i*g,mx+y*g,my+i*g);
settextstyle(1,0,3);
for(i=0;i<x;i++)
for(j=0;j<y;j++)
close(i*10+j);
rect(2);
outtextxy(15,15,"TIME : ");
outtextxy(350,15,"NO. OF ATTEMPTS : ");
d='s';
while(u<x*y/k)
{b=0;
while(b<k)
{
setcolor(m);
outtextxy(15,400,"STUPID.DON`T OPEN CELL THAT IS ALREADY OPENED.");
m=0;
if(w==0)
{w=1;
itoa(c-1,f,10);setcolor(0);outtextxy(580,15,f);
itoa(c,f,10);setcolor(7);outtextxy(580,15,f);
}
while(!kbhit())
{
if(o==t1-t)
{
setcolor(0);
moveto(97,15);itoa((o-1)/60,f,10);outtext(f);outtext(" : ");
itoa((o-1)%60,f,10);outtext(f);
setcolor(7);
moveto(97,15);itoa(o/60,f,10);outtext(f);outtext(" : ");
itoa(o%60,f,10);outtext(f);
o++;
}
if(t1==0) t=time('\0');
if(d!='s') t1=time('\0');
}
d=getch();
n=q/10;N=q%10;rect(4);
if(d=='2') {if(n==x-1) n=-1; n++;}
if(d=='6') {if(N==y-1) N=-1; N++;}
if(d=='8') {if(n==0) n=x; n--;}
if(d=='4') {if(N==0) N=y; N--;}
q=n*10+N;rect(2);
if(d=='0') break;
if(d=='5')
{
if(b!=0)
{
for(j=b-1;j>=0;j--) if(*(r+j)==n*10+N) {m=7;break;}
if(j!=-1) continue;
}
for(j=0;j<u;j++) if(*(p+j)==*(a+n*y+N)) {m=7;break;}
if(j!=u) continue;
c++;*(r+b)=n*10+N;
show(*(r+b));b++;w=0;
}
}
for(i=0;i<k-1;i++)
if(*(a+(*(r+i)/10*y)+(*(r+i)%10))!=*(a+(*(r+i+1)/10*y)+(*(r+i+1)%10))) break;
if(i==k-1) {*(p+u)=*(a+(*r/10*y)+(*r%10));u++;}
else
{
delay(500);
for(i=0;i<k;i++)
close(*(r+i));
}
if(d=='0') break;
}
if(u==x*y/k)
{setcolor(7);outtextxy(15,400,"COOL .YOU FINISHED THE GAME .");
itoa(c-1,f,10);setcolor(0);outtextxy(580,15,f);
itoa(c,f,10);setcolor(7);outtextxy(580,15,f);
}
free(a);free(r);
getch();
}
void main()
{
tri.input();
tri.que();
tri.output();
closegraph();
}




