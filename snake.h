#ifndef _SNAKE_H_
#define _SNAKE_H_
#include<windows.h>
#include<math.h>
#include<stdio.h>
#include<unistd.h>
#include<conio.h>
#include<time.h>
#define N 25
#define M 60
#define O 6

int a[N][M],MARK,MOD,SPEED=100,RECORD;
int HEADx,HEADy,HEADx2,HEADy2,LENGTH,LENGTH2,FLAG=1,FLAG2=1;
int FOODx,FOODy; 
int NEWGAME=0;
char BODY='#',BODY2='#',GETONE;
FILE *fp; 


void color(int i);
void gotoxy(int x,int y);
void putcharxy(int x,int y,char temp);
void printfxy(int x,int y,const char *p);
void gotoclean(int x,int y,const char*p);
void keys();
void screen1(int i);
void screen2(int i);
void screen3(int i);
void screen4(int i);
void rightscreen();
void screen();
void screenclean();
void selectscreen();
int selectmod();
void pclean(int i);
void pout(int i,char pn);
void select(int i,char pn);
void selectclean();
void wall();
void snake();
void snake2();
void food();
void wallrand1(int i);
void wallrand2(int i);
void search(int y,int x);
void search2(int y,int x);
void test();
void test2();
void move();
void move2();
void move3();
void record();
void clean1();
void clean2();
void newgame();
#endif
