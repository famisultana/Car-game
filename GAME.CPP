#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>


void start(void);
void road(void);
void car (void);
void carclear(void);
void keys (void);
void quit(void);
void sorting(void);
void game (void);
void barrier (int,int,int);
void barrierclear (int,int);
void logo (void);
void levels (void);
void accident(void);
void mainmenu(void);
void collision(void);
void score_store(void);
void display_score(void);
void instructions (void);
void highscore(void);
void title(void);
void circle(void);
void speed_set (void);


int skore=0,i,speed,j,s,n,a=0,b,p,k,a0,b0,a1,b1,a2,b2,a3,b3,a4,b4,a5,b5,a6,b6,a7,b7,a8,b8,x,y,z;
int maxX,maxY;
char scr[10];
char lvl[3];
char life[3];
int arr[20];
char p1[10];
char p2[10];
char p3[10];

int player1,player2,player3;
char names[15][20];

struct play{
char name[20];
int level;
int lif;
int skore;
}player;

FILE *fp;

main()
{
int gd=DETECT, gm;
initgraph (&gd, &gm, "c:\\TC\\bgi");
cleardevice();
logo();
title();
mainmenu();
getch();
closegraph();
}

void game(void)
{
setbkcolor(0);
start();

player.skore=0;player.lif=3;player.level=1;
a=0;

srand(time(NULL));
b1=180+((rand()%5)*60); a1=0;
b2=180+((rand()%5)*60); a2=-100;
b3=180+((rand()%5)*60); a3=-200;
b4=180+((rand()%5)*60); a4=-300;
b5=180+((rand()%5)*60); a5=-400;
b6=180+((rand()%5)*60); a6=-500;

for(player.skore=0;player.skore<=4700,player.lif>=0;)
{
srand(time(NULL));
if(a1==600)  { a1=0;     player.skore=player.skore+25;	p=p+5; }
if(a2==600)  { a2=-100;  player.skore=player.skore+25;	p=p+5; }
if(a3==600)  { a3=-200;  player.skore=player.skore+25;	p=p+5; }
if(a4==600)  { a4=-300;  player.skore=player.skore+25;	p=p+5; }
if(a5==600)  { a5=-400;  player.skore=player.skore+25;	p=p+5; }
if(a6==600)  { a6=-500;  player.skore=player.skore+25;	p=p+5; }
if(p>=300)     p=0;

if (player.skore==4700)
{
cleardevice();
for(i=0;i<10;i++)
{
  sound(800*i);
  delay(100);
  nosound();
}

setfillstyle(SOLID_FILL,RED);
bar(180,180,460,300);
settextstyle(1,0,4);
setcolor(15);
outtextxy(190,200,"YOU HAVE WON !");
settextstyle(7,0,1);
outtextxy(200,244,"Do want to play again?");
outtextxy(270,270," < Y/N >");
j=getch();
if(j=='Y' || j=='y'){
cleardevice();
score_store();
cleardevice();
mainmenu();
}
else
{
cleardevice();
score_store();
cleardevice();
quit();
getch();
}
break;
}

road();
car();
barrierclear(a1,b1);
barrierclear(a2,b2);
barrierclear(a3,b3);
barrierclear(a4,b4);
barrierclear(a5,b5);
barrierclear(a6,b6);

a1+=5;
a2+=5;
a3+=5;
a4+=5;
a5+=5;
a6+=5;

barrier(a1,b1,9);
barrier(a2,b2,2);
barrier(a3,b3,3);
barrier(a4,b4,13);
barrier(a5,b5,12);
barrier(a6,b6,14);

levels();
gotoxy(5,3);
cout<<"Level = "<<player.level;
gotoxy(5,5);
cout<<"Lives = "<<player.lif;
gotoxy(65,3);
cout<<"Score = "<<player.skore;

collision();

if(player.lif==0)
{
 cleardevice();
 score_store();
 cleardevice();
 mainmenu();
 break;
}

keys();

if(j==27)
{
 cleardevice();
 score_store();
 cleardevice();
 quit();
 getch();
 break;
}

delay(speed);
}}


void road(void)
{
setcolor(RED);
rectangle(565,120,580,420);
setfillstyle(1,13);
bar(565,420-p,580,420);
maxX=getmaxx();
maxY=getmaxy();
setcolor(WHITE);
rectangle(0,0,maxX,maxY);
setfillstyle(SOLID_FILL,WHITE);
bar(155, 0, 160, maxY);
bar(480, 0, 485, maxY);
}

void car (void)
{
x=320+a;
setfillstyle(1,BLUE);
bar (300+a,410,340+a,460); //main
setcolor(GREEN);
setfillstyle(8,YELLOW);
bar (315+a,410, 325+a,460);         //centre
setfillstyle(1,LIGHTCYAN);
bar(305+a,395,335+a,410);
setfillstyle(1,YELLOW);     //front
bar(303+a,399,305+a,405);           //right tyre
bar(335+a,399,337+a,405);           //left tyre
}


void carclear (void)
{
x=320+a;
setcolor(0);
setfillstyle(1,0);
bar(300+a,410,340+a,460); //main
setcolor(0);
setfillstyle(SOLID_FILL,0);
bar (315+a,410, 325+a,460);         //centre
bar(305+a,395,335+a,410);     //front
bar(303+a,399,305+a,405);           //right tyre
bar(335+a,399,337+a,405);           //left tyre
}


void barrier (int a1,int b1,int k)
{
setfillstyle(SOLID_FILL,k);
bar(b1,(-100+a1),40+b1,(-50+a1));
setcolor(k);
rectangle(5+b1,(-50+a1),35+b1,(-40+a1));
}


void barrierclear (int a1,int b1)
{
setfillstyle(SOLID_FILL,0);
bar(b1,(-100+a1),40+b1,(-50+a1));
setcolor(0);
rectangle(5+b1,(-50+a1),35+b1,(-40+a1));
}


void keys (void)
{
if(kbhit())
{
  sound(2500);
  delay(10);
  nosound();

j=getch();
if(j==75)
{
 carclear();
 if(a>-100)
 a=a-60;
}
if (j==77)
{
 carclear();
 if(a<100)
 a=a+60;
}
}
}


void quit (void)
{
setbkcolor(15);
setcolor(RED);
settextstyle(7,0,5);
outtextxy(220,350,"Quiting the Game...");
}


void logo (void)
{
for(int i=1;i<250;i++)
{
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
settextstyle(4,HORIZ_DIR,5);
outtextxy(150,100,"ROAD");
outtextxy(250,140,"RACING");
bar3d(50,200,550,220,10,40);
setcolor(RED);
settextstyle(1,HORIZ_DIR,2);
outtextxy(100,400,"LOADING");
setfillstyle(SOLID_FILL,LIGHTRED);
bar(190,400,190+i,420);
delay(1);
}
getch();
cleardevice();
}


void levels (void)
{
if(player.skore>=1500)
 player.level=2;
if(player.skore>=3200)
 player.level=3;

if(player.skore==1500 || player.skore==3200)
{
 p=0;
 for(i=0;i<10;i++)
{
  sound(800*i);
  delay(100);
  nosound();
}
 setfillstyle(SOLID_FILL,CYAN);
 bar(180,180,460,280);
 settextstyle(1,0,4);
 outtextxy(220,210,"NEXT LEVEL !");
 delay(1000);
 cleardevice();
 player.skore=player.skore+200;
}

if(player.skore==4700)
   player.skore=5000;
}


void accident (void)
{
 for(i=0;i<10;i++)
{
  sound(300*i);
  delay(100);
  nosound();
}

 if(a==120)
 a=a-60;
 else
 a=a+60;
 player.lif=player.lif-1;;
 setcolor(WHITE);
 rectangle(160,180,480,280);
 setfillstyle(SOLID_FILL,8);
 bar(160,180,480,280);
 settextstyle(1,0,4);
 outtextxy(180,210,"YOU LOST A LIFE!");
 delay(1000);
 cleardevice();
 carclear();
}


void mainmenu(void)
{
 int ch=0,z=0,x=250,y=168,m,n,u;
 setbkcolor(YELLOW);
 setcolor(MAGENTA);
 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(5,5,getmaxx()-5,getmaxy()-5);
 setcolor(RED);
 settextstyle(4,0,6);
 outtextxy(110,40,"ROAD RACING");
 settextstyle(8,0,3);
 outtextxy(270,150,"START");
 outtextxy(270,200,"SCORE");
 outtextxy(270,250,"HIGH SCORES");
 outtextxy(270,300,"INSTRUCTIONS");
 outtextxy(270,350,"QUIT");
 circle(x,y,5);
 circle(x,y+50,5);
 circle(x,y+100,5);
 circle(x,y+150,5);
 circle(x,y+200,5);
 while(1)
 {
 if(ch==13 && y==168)
 {
 cleardevice();
 speed_set();
 break;
 }

 if(ch==13 && y==218)
 {
 cleardevice();
 display_score();
 getch();
 cleardevice();
 mainmenu();
 break;
 }

 if(ch==13 && y==318)
 {
 cleardevice();
 instructions();
 getch();
 cleardevice();
 mainmenu();
 break;
 }
 if(ch==13 && y==268)
 {
 cleardevice();
 highscore();
 getch();
 cleardevice();
 mainmenu();
 break;
 }

 if(ch==13 && y==368)
 {
 cleardevice();
 quit();
 getch();
 break;
 }
 if(y>=168 && y<=368)
 {
 if(z==0)
 {
 setfillstyle(1,12);
 floodfill(x,y,RED);
 z++;
 n=y;
 }
}

if(kbhit())
{
ch=getch();
if(ch==72)
{
if(y>168)
{
y=y-50;
}
}
if(ch==80)
{
if(y<368)
{
y=y+50;
}
}
if(y>=168 && y<=368)
{
setfillstyle(1,12);
floodfill(x,y,RED);
if(y!=168 && y!=368)
{
setfillstyle(1,YELLOW);
floodfill(x,n,RED);
}
 n=y;
}}

if(ch==27)
exit(0);
}
 cleardevice();
 closegraph();
}


void start()
  {
  char a[3];
  for(int i=3;i>=1;i--)
  {
  road();
  sprintf(a,"%d",i);
  setcolor(BLUE);
  settextstyle(1,0,5);
  outtextxy(312,200,a);
  delay(500);
  cleardevice();
  road();
  }
  if(a==0)
  setfillstyle(1,8);
  setcolor(RED);
  settextstyle(1,0,5);
  outtextxy(312,200,"GO");
  delay(500);
  cleardevice();
  road();
  }

void collision (void)
{
if(x>(5+b1) && x<(35+b1) && (-40+a1)==395)
accident();

if(x>(5+b2) && x<(35+b2) && (-40+a2)==395)
accident();

if(x>(5+b3) && x<(35+b3) && (-40+a3)==395)
accident();

if(x>(5+b4) && x<(35+b4) && (-40+a4)==395)
accident();

if(x>(5+b5) && x<(35+b5) && (-40+a5)==395)
accident();

if(x>(5+b6) && x<(35+b6) && (-40+a6)==395)
accident();

if((-100+a1)>380 && (-50+a1)<500 && (340+a)==(40+b1))
accident();

if((-100+a2)>380 && (-50+a2)<500 && (340+a)==(40+b2))
accident();

if((-100+a3)>380 && (-50+a3)<500 && (340+a)==(40+b3))
accident();

if((-100+a4)>380 && (-50+a4)<500 && (340+a)==(40+b4))
accident();

if((-100+a5)>380 && (-50+a5)<500 && (340+a)==(40+b5))
accident();

if((-100+a6)>380 && (-50+a6)<500 && (340+a)==(40+b6))
accident();
}


void score_store (void)
{
 setcolor(15);
 sprintf(scr,"Your score is %d",player.skore);
 settextstyle(1,0,1);
 outtextxy(50,80,scr);
 outtextxy(50,105,"Enter your name : ");
 gotoxy(30,8);
 gets(player.name);
 fp=fopen("scoring.dat","ab");
 fwrite(&player,sizeof(player),1,fp);
 fclose(fp);
}

void display_score (void)
{
 s=0;
 setbkcolor(LIGHTCYAN);
 fp=fopen("scoring.dat","rb");
if(fp==NULL)
{
 outtextxy(20,20,"File not found");
 exit(1);
}
 setcolor(RED);
 settextstyle(8,0,4);
 outtextxy(215,0,"SCORE BOARD");
 bar(210,39,445,41);
 setcolor(LIGHTRED);
 settextstyle(7,0,2);
 outtextxy(80,45,"NAMES");
 outtextxy(240,45,"SCORE");
 outtextxy(395,45,"LEVEL");
 outtextxy(515,45,"LIVES");

 while(fread(&player,sizeof(player),1,fp)==1){
 setcolor(BROWN);
 settextstyle(1,0,1);
 outtextxy(80,80+s,player.name);
 sprintf(scr,"%d",player.skore);
 outtextxy(240,80+s,scr);
 sprintf(lvl,"%d",player.level);
 outtextxy(400,80+s,lvl);
 sprintf(life,"%d",player.lif);
 outtextxy(520,80+s,life);
 s=s+25;
 }
 fclose(fp);
 getch();
 cleardevice();
 mainmenu();
}


void highscore(void)
{
 setbkcolor(0);
 cleardevice();
 setcolor(RED);
 settextstyle(7,0,3);
 outtextxy(40,5,"HIGH SCORES");
 setcolor(YELLOW);
 line(35,35,215,35);
 line(35,40,215,40);

 sorting();

 player1=arr[0];
 player2=arr[1];
 player3=arr[2];

 char n3[20];
 char n2[20];
 char n1[20];

 strcpy(n1,names[0]);
 strcpy(n2,names[1]);
 strcpy(n3,names[2]);

 setcolor(CYAN);
 settextstyle(7,0,2);
 outtextxy(10,50,"1st Position");
 outtextxy(10,200,"2nd Position");
 outtextxy(10,350,"3rd Position");
 setcolor(MAGENTA);
 outtextxy(10,100,n1);
 outtextxy(10,250,n2);
 outtextxy(10,400,n3);
 setcolor(LIGHTRED);
 sprintf(p1,"%d",player1);
 outtextxy(130,100,p1);
 sprintf(p2,"%d",player2);
 outtextxy(130,250,p2);
 sprintf(p3,"%d",player3);
 outtextxy(130,400,p3);

 setlinestyle(SOLID_LINE,0,2);
 setcolor(15);
 line(350,410,350,80);
 line(350,410,620,410);
 line(345,90,350,80);
 line(355,90,350,80);
 line(615,405,620,410);
 line(615,415,620,410);
 for(i=380;i>=110;){
 line(340,i,350,i);
 i=i-30;
 }

 setcolor(BROWN);
 settextstyle(11,0,5);
 outtextxy(305,380,"500");
 outtextxy(305,350,"1000");
 outtextxy(305,320,"1500");
 outtextxy(305,290,"2000");
 outtextxy(305,260,"2500");
 outtextxy(305,230,"3000");
 outtextxy(305,200,"3500");
 outtextxy(305,170,"4000");
 outtextxy(305,140,"4500");
 outtextxy(305,110,"5000");
 settextstyle(3,0,1);
 outtextxy(330,50,"Score");
 outtextxy(575,415,"Player");
 outtextxy(340,415,"0");

 setcolor(15);
 setfillstyle(SOLID_FILL, RED);
 bar3d(380,410-(player1/16.6),410,410, 15, 1);
 setfillstyle(SOLID_FILL, BLUE);
 bar3d(450,410-(player2/16.6),480,410, 15, 1);
 setfillstyle(SOLID_FILL, GREEN);
 bar3d(520,410-(player3/16.6),550,410, 15, 1);
 setcolor(MAGENTA);
 settextstyle(11,0,6);
 outtextxy(380,420,n1);
 outtextxy(450,420,n2);
 outtextxy(520,420,n3);
 getch();
 cleardevice();
 mainmenu();
}


void sorting (void)
{
 i=0;
 char q[20];
 fp=fopen("scoring.dat","rb");
 while(fread(&player,sizeof(player),1,fp)==1){
 arr[i]=player.skore;
 strcpy(names[i],player.name);
 i++;
 }
 fclose(fp);
 int round,t;
 for(round=1;round<15;round++)
{
 for(i=0;i<14;i++){
 if(arr[i]<arr[i+1]){
 t=arr[i];
 arr[i]=arr[i+1];
 arr[i+1]=t;
 strcpy(q,names[i]);
 strcpy(names[i],names[i+1]);
 strcpy(names[i+1],q);
}}}}


void instructions (void)
{
setbkcolor(15);
settextstyle(8,0,5);
outtextxy(160,20,"INSTRUCTIONS");
setcolor(BLUE);
settextstyle(1,0,2);
outtextxy(50,100,"Road Racing is a simple game in which you");
outtextxy(50,130,"have to lead a car by avoiding the cars coming from");
outtextxy(50,160,"the opposite side of the road...");
outtextxy(50,220,"You have to use the following keys to control the car:");
outtextxy(50,260,"-> RIGHT   --- Rightside movement");
outtextxy(50,300,"<- LEFT   --- Leftside movement");
outtextxy(50,370,"Press <Esc> to exit the game!");
getch();
cleardevice();
mainmenu();
}


void title(void)
{
 setbkcolor(15);
 circle();
 setcolor(BLUE);
 settextstyle(1,0,3);
 outtextxy(60,100,"This game is designed by:");
 setcolor(MAGENTA);
 outtextxy(200,150,"Fatima Sultana (SE-33)");
 outtextxy(200,180,"Rija Nadeem (SE-15)");
 setcolor(GREEN);
 outtextxy(60,250,"Students of:");
 setcolor(BROWN);
 outtextxy(60,300,"NED University of Engineering and Technology");
 getch();
 cleardevice();
}


void circle(void)
{
for(i=15,j=1;i<=getmaxy()-15;i++,j++){
 setcolor(j);
 if (j==15)
 j=1;
 circle(15,i,15);
 circle(getmaxx()-15,getmaxy()-i,15);
 delay(2);
}
 for(i=15,j=1;i<=getmaxx()-15;i++,j++){
 setcolor(j);
 if (j==15)
 j=1;
 circle(getmaxx()-i,15,15);
 circle(15+i,getmaxy()-15,15);
 delay(2);
}
}

void speed_set(void)
{
 int ch=0,z=0,x=250,y=168,m,n,u;
 setbkcolor(LIGHTCYAN);
 setcolor(BLUE);
 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(5,5,getmaxx()-5,getmaxy()-5);
 setcolor(RED);
 settextstyle(7,0,4);
 outtextxy(60,40,"SELECT YOUR DESIRED SPEED");
 settextstyle(8,0,3);
 outtextxy(270,150,"SLOW");
 outtextxy(270,200,"MEDIUM");
 outtextxy(270,250,"FAST");
 circle(x,y,5);
 circle(x,y+50,5);
 circle(x,y+100,5);

 while(1)
 {
 if(ch==13 && y==168)
 {
 speed=15;
 p=0;
 setcolor(BLUE);
 settextstyle(7,0,2);
 outtextxy(380,157,"Settings saved!");
 outtextxy(320,400,"Press any key to continue...");
 getch();
 cleardevice();
 game();
 break;
 }

 if(ch==13 && y==218)
 {
 speed=10;
 p=0;
 setcolor(BLUE);
 settextstyle(7,0,2);
 outtextxy(390,207,"Settings saved!");
 outtextxy(320,400,"Press any key to continue...");
 getch();
 cleardevice();
 game();
 break;
 }

 if(ch==13 && y==268)
 {
 speed=0;
 p=0;
 setcolor(BLUE);
 settextstyle(7,0,2);
 outtextxy(380,257,"Settings saved!");
 outtextxy(320,400,"Press any key to continue...");
 getch();
 cleardevice();
 game();
 break;
 }

 if(y>=168 && y<=268)
 {
 if(z==0)
 {
 setfillstyle(1,12);
 floodfill(x,y,RED);
 z++;
 n=y;
 }
}

if(kbhit())
{
ch=getch();
if(ch==72)
{
if(y>168)
{
y=y-50;
}
}
if(ch==80)
{
if(y<268)
{
y=y+50;
}
}
if(y>=168 && y<=268)
{
setfillstyle(1,12);
floodfill(x,y,RED);
if(y!=168 && y!=268)
{
setfillstyle(1,LIGHTCYAN);
floodfill(x,n,RED);
}
 n=y;
}}
}}
