#include"snake.h"

void color(int i)
{ 
	if(i==1)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	else
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

void gotoxy(int x,int y)
{
	COORD coord={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void putcharxy(int x,int y,char temp)
{
	gotoxy(x,y);
	printf("%c",temp);
	gotoxy(0,N);
}

void printfxy(int x,int y,const char *p)
{
	gotoxy(x,y);
	puts(p);
	gotoxy(0,N);
}

void gotoclean(int x,int y,const char*p)
{
	gotoxy(x,y);
	for(int i=0;i<strlen(p);i++)
	printf(" ");
	gotoxy(0,N);
}


void keys()
{
	char key[N],a[M],c[M],b[O][O]={'0'};
	int i1=0,i2=0,flag,temp,x1,x2,y1,y2;
 	printfxy((M-20)/2,(N-10)/2,"ID:");
 	printfxy((M-20)/2,(N-8)/2,"PASSWORD:");
 	
 	srand((unsigned)time(NULL));
	for(int k1=0;k1<20;k1++)
	{
		key[k1]=rand()%25+'a';
		for(int k2=0;k2<k1;k2++)
		if(key[k1]==key[k2])
		{
			k1--;
			break;
		}
	}
	key[20]='\0';
	
	gotoxy((M-20)/2,(N-6)/2); 
	puts(key);

	gotoxy((M-14)/2,(N-10)/2); 
	for(int i=0;;i++)
	{
		if(i<0) i=0;
		if(i<9)
		{
			a[i]=getch();
			if(a[i]=='\r')
			{
				a[i]='\0';
				break;
			}
			else if(a[i]=='\b')
			{
				if(i>0) i--;
				gotoxy((M-14)/2+i,(N-10)/2); 
				printf(" ");
				gotoxy((M-14)/2+i,(N-10)/2); 
				i--;
			} 
			else if(i!=8) putchar(a[i]);
			if(i==8) a[i]='\0';
		}
		else
		{
			a[10]=getch();
			if(a[10]=='\b')
			{
				i=6;
				gotoxy((M-14)/2+i+1,(N-10)/2); 
				printf(" ");
				gotoxy((M-14)/2+i+1,(N-10)/2); 
				continue;
			}
			else if(a[10]=='\r') break;
		}
	}
	gotoxy((M-2)/2,(N-8)/2);
	for(int i=0;;i++)
	{
		if(i<0) i=0;
		if(i<9)
		{
			c[i]=getch();
			if(c[i]=='\r')
			{
				c[i]='\0';
				break;
			}
			else if(c[i]=='\b')
			{
				if(i>0) i--;
				gotoxy((M-2)/2+i,(N-8)/2); 
				printf(" ");
				gotoxy((M-2)/2+i,(N-8)/2); 
				i--;
			} 
			else if(i!=8) putchar('*');
			if(i==8) c[i]='\0';
		}
		else 
		{
			c[10]=getch();
			if(c[10]=='\b')
			{
				i=6;
				gotoxy((M-2)/2+i+1,(N-8)/2); 
				printf(" ");
				gotoxy((M-2)/2+i+1,(N-8)/2); 
				continue;
			}
			else if(c[10]=='\r') break;
		}
	}
	
	for(int i=0;key[i]!='\0';i++)
	{	
	    if(i2==O-1)
	    {
	    	i1++;
	    	i2=0;
		}
		b[i1][i2]=key[i];
		i2++;
	}
	
	for(char temp='a';temp<='z';temp++)
	{
		flag=0;
		
		for(int i=0;key[i]!='\0';i++)
		if(temp==key[i]) flag=1;
		
		if(flag==0)
		{	
		    if(i2==O-1)
		    {
		    	i1++;
		    	i2=0;
			}
			b[i1][i2]=temp;
			i2++;
		}
	}

	for(int i=0;a[i]!='\0'&&a[i+1]!='\0';i+=2)
	{	
		flag=0;
		
		for(i1=0;i1<O-1;i1++)
		for(i2=0;i2<O-1;i2++)
		if(b[i1][i2]==a[i])
		{
			x1=i1;
			x2=i2;
			flag+=1;
		}
		else if(b[i1][i2]==a[i+1])
		{
			y1=i1;
			y2=i2;
			flag+=1;
		}
		if(flag==2)
		{
			a[i]=b[x1][y2];
			a[i+1]=b[y1][x2];
		}
		if(x2==y2)
		{
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}	
	
	flag=0;
	for(int k=0;k<strlen(a);k++)
	for(int k1=0;k1<k;k1++)
	if(a[k]==a[k1]) flag=-1;
	for(int k=0;k<strlen(a);k++)
	if(!(a[k]>='a'&&a[k]<='z')) flag=-1;
	
	if(strcmp(a,c)!=0||strlen(c)!=6||flag==-1)
	{
		gotoclean((M-14)/2,(N-10)/2,a);
		gotoclean((M-20)/2,(N-6)/2,key);
		gotoclean((M-2)/2,(N-8)/2,c);
		printfxy((M-20)/2,(N-4)/2,"username or password is wrong");
		keys();
	}
	else
	{
		gotoclean((M-20)/2,(N-8)/2,"PASSWORD:******"); 
		printfxy((M-20)/2,(N-4)/2,"                                 ");
		gotoclean((M-20)/2,(N-6)/2,key);
	} 
}

void screen1(int i)
{
	printfxy(M+3,N/2+i*5,"P.A.:"); 
 	printfxy(M+3,(N+2)/2+i*5,"Believe in ");
 	printfxy(M+3,(N+4)/2+i*5,"yourself.");
}

void screen2(int i)
{
 	printfxy(M+3,N/2+i*5,"P.B.:"); 
 	printfxy(M+3,(N+2)/2+i*5,"Aut Caesar,");
 	printfxy(M+3,(N+4)/2+i*5,"aut nihil.");
}

void screen3(int i)
{
 	printfxy(M+3,N/2+i*5,"P.C.:");
 	printfxy(M+3,(N+2)/2+i*5,"Like for");
 	printfxy(M+3,(N+4)/2+i*5," like.");
}

void screen4(int i)
{
 	printfxy(M+3,N/2+i*5,"P.D.:");
 	printfxy(M+3,(N+2)/2+i*5,"Learn and ");
 	printfxy(M+3,(N+4)/2+i*5,"live.");
}

void rightscreen()
{
 	printfxy(M+3,(N-20)/2,"player1 USE:"); 
 	printfxy(M+3,(N-18)/2," |  W  |");
 	printfxy(M+3,(N-16)/2," |A S D|");
 	printfxy(M+3,(N-14)/2,"to control;");
 	printfxy(M+3,(N-10)/2,"player2 USE:");
 	printfxy(M+3,(N-8)/2," |  5  |");
 	printfxy(M+3,(N-6)/2," |1 2 3|");
 	printfxy(M+3,(N-4)/2,"to control;");
} 

void screen()
{
	printfxy((M-20)/2,(N-10)/2,"!!\'Gluttonous Snake\'");
 	color(0);
 	printfxy((M-10)/2,(N-6)/2,"@POLARBEAR");
 	color(1);
	printfxy((M-10)/2,(N-2)/2,"SELECT");  
	printfxy((M-10)/2,N/2,"1 playerA"); 
	printfxy((M-10)/2,(N+2)/2,"1 playerB"); 
	printfxy((M-10)/2,(N+4)/2,"2 player"); 
	printfxy((M-24)/2,(N+10)/2,"press \'SPACE\' to continue"); 
	printfxy((M-13)/2,N/2,"=>");
	a[N/2][(M-13)/2]=1;
}

void screenclean()
{
 	printfxy((M-20)/2,(N-10)/2,"                    ");
 	printfxy((M-10)/2,(N-6)/2,"          ");
	printfxy((M-10)/2,(N-2)/2,"      ");  
	printfxy((M-10)/2,N/2,"         ");
	printfxy((M-10)/2,(N+2)/2,"         "); 
	printfxy((M-10)/2,(N+4)/2,"        "); 
	printfxy((M-24)/2,(N+10)/2,"                         ");
}

void selectscreen()
{
	printfxy((M-50)/2,(N-10)/2,"\'@#####\'");
	printfxy((M-48)/2,(N-6)/2,"P.A.");
	
	printfxy((M-22)/2,(N-10)/2,"\'@88888\'");
	printfxy((M-20)/2,(N-6)/2,"P.B.");
	
	printfxy((M+6)/2,(N-10)/2,"\'@DDDDD\'");
	printfxy((M+8)/2,(N-6)/2,"P.C.");
	
	printfxy((M+34)/2,(N-10)/2,"\'@OOOOO\'");
	printfxy((M+36)/2,(N-6)/2,"P.D.");
	
	printfxy((M-10)/2,(N+4)/2,"??????");
	printfxy((M-10)/2,(N+6)/2,"random!");
	
	printfxy((M-20)/2,(N+10)/2,"select your role!");
	printfxy((M-24)/2,(N+12)/2,"press \'SPACE\' to select");
}

int selectmod()
{
	int i=N/2,j=(M-13)/2;
	while(1)
	{
		MARK=getch();
		if(MARK==' ') 
		{
			gotoclean(j,i,"=>");
			a[i][j]=0;
			break;
		}
		if(MARK=='8')
		{
			gotoclean(j,i,"=>");
			a[i][j]=0;
			return 10;
		}
		if((MARK=='w'||MARK=='W')&&a[N/2][(M-13)/2]==0)
		{
			gotoclean(j,i,"=>");
			a[i][j]=0;
			i--;
			printfxy(j,i,"=>");
			a[i][j]=1;
		}
		if((MARK=='s'||MARK=='S')&&a[N/2+2][(M-13)/2]==0)
		{
			gotoclean(j,i,"=>");
			a[i][j]=0;
			i++;
			printfxy(j,i,"=>");
			a[i][j]=1;
		}
		else if((MARK=='s'||MARK=='S')&&a[N/2+2][(M-13)/2]==1)
		{
			gotoclean(j,i,"=>");
			a[i][j]=0;
			i=N/2;
			printfxy(j,i,"=>");
			a[i][j]=1;
		}
	}
	return i-N/2;
}

void pclean(int i)
{
	putcharxy((M-52+i)/2,(N-10)/2,' ');
	putcharxy((M-52+i)/2,(N-8)/2,' ');
	putcharxy((M-52+i)/2,(N-6)/2,' ');
	putcharxy((M-34+i)/2,(N-10)/2,' ');
	putcharxy((M-34+i)/2,(N-8)/2,' ');
	putcharxy((M-34+i)/2,(N-6)/2,' ');
	putcharxy((M-42+i)/2,(N-4)/2,' ');
	putcharxy((M-44+i)/2,(N-4)/2,' ');
	putcharxy((M-44+i)/2,(N-2)/2,' ');
	putcharxy((M-42+i)/2,(N-2)/2,' ');
}

void pout(int i,char pn)
{
	putcharxy((M-52+i)/2,(N-10)/2,'|');
	putcharxy((M-52+i)/2,(N-8)/2,'|');
	putcharxy((M-52+i)/2,(N-6)/2,'|');
	putcharxy((M-34+i)/2,(N-10)/2,'|');
	putcharxy((M-34+i)/2,(N-8)/2,'|');
	putcharxy((M-34+i)/2,(N-6)/2,'|');
	putcharxy((M-42+i)/2,(N-4)/2,'-');
	putcharxy((M-44+i)/2,(N-4)/2,'-');
	putcharxy((M-44+i)/2,(N-2)/2,'p');
	putcharxy((M-42+i)/2,(N-2)/2,pn);
}

void select(int i,char pn)
{
	char temp;
	int js=0;
	while(1)
	{
		if(i>=0&&js==0)
		{		
			pout(i,pn);
			Sleep(500);
			js=1-js;
		}
		else if(i>=0)
		{
			pclean(i);
			putcharxy((M-44+i)/2,(N-2)/2,'p');
			putcharxy((M-42+i)/2,(N-2)/2,pn);
			Sleep(500);
			js=1-js;
		} 
		if(kbhit()!=0)
		{
			temp=getch();
			if(temp=='D'||temp=='A'||temp=='W'||temp=='S') temp=temp+32;
			if(temp=='w'&&i<0)
			{
				printfxy((M-10)/2,(N+4)/2,"??????");
				printfxy((M-10)/2,(N+6)/2,"random!");	
				i=0;
				select(i,pn);
				break;
			}
			else if(temp=='s'&&i>=0)
			{
				pclean(i);
				color(0);
				printfxy((M-10)/2,(N+4)/2,"??????");
				printfxy((M-10)/2,(N+6)/2,"random!");
				color(1);
				i=-1;
				select(i,pn);
				break;
			}
			else if(i<0&&temp==' ')
			{
				srand((unsigned)time(NULL));
				i=rand()%4;
				i=i*28;
				pout(i,pn);
				printfxy((M-24)/2,(N+12)/2,"                         ");
				printfxy((M-26)/2,(N+12)/2,"press any key to continue");
				getch();
				pclean(i);
				if(i/28==1&&pn=='1') 
				{
					BODY='8';
					screen2(0); 
				}
				else if(i/28==2&&pn=='1') 
				{
					BODY='D';	
					screen3(0);
				}
				else if(i/28==3&&pn=='1') 
				{
					BODY='O';
					screen4(0);
				}
				else if(pn=='1') screen1(0);
				
				if(i/28==1&&pn=='2') 
				{
					BODY2='8';
					screen2(1); 
				}
				else if(i/28==2&&pn=='2')
				{
					BODY2='D';	
					screen3(1);
				}
				else if(i/28==3&&pn=='2') 
				{
					BODY2='O';
					screen4(1);
				}
				else if(pn=='2') screen1(1);
				
				if(MOD==2&&pn=='1') 
				{
					printfxy((M-10)/2,(N+4)/2,"??????");
					printfxy((M-10)/2,(N+6)/2,"random!");	
					select(0,'2');
				}
				break;
			}
			else if(i<0);
			else if(temp=='d'&&i!=84) 
			{
				pclean(i);
				i+=28;
				select(i,pn);
				break;
			}
			else if(temp=='d'&&i==84) 
			{
				pclean(i);
				i=0;
				select(i,pn);
				break;
			}
			else if(temp=='a'&&i!=0) 
			{
				pclean(i);
				i-=28;
				select(i,pn);
				break;
			}
			else if(temp=='a'&&i==0) 
			{
				pclean(i);
				i=84;
				select(i,pn);
				break;
			}
			else if(temp==' ')
			{
				pout(i,pn);
				printfxy((M-24)/2,(N+12)/2,"                         ");
				printfxy((M-26)/2,(N+12)/2,"press any key to continue");
				getch();
				pclean(i);
				if(i/28==1&&pn=='1') 
				{
					BODY='8';
					screen2(0); 
				}
				else if(i/28==2&&pn=='1') 
				{
					BODY='D';	
					screen3(0);
				}
				else if(i/28==3&&pn=='1') 
				{
					BODY='O';
					screen4(0);
				}
				else if(pn=='1') screen1(0);
				
				if(i/28==1&&pn=='2') 
				{
					BODY2='8';
					screen2(1); 
				}
				else if(i/28==2&&pn=='2')
				{
					BODY2='D';	
					screen3(1);
				}
				else if(i/28==3&&pn=='2') 
				{
					BODY2='O';
					screen4(1);
				}
				else if(pn=='2') screen1(1);
				if(MOD==2&&pn=='1') select(0,'2');
				break;
			}
		} 
	}
}

void selectclean()
{
	printfxy((M-50)/2,(N-10)/2,"        ");
	printfxy((M-48)/2,(N-6)/2,"        ");
	
	printfxy((M-22)/2,(N-10)/2,"        ");
	printfxy((M-20)/2,(N-6)/2,"        ");
	
	printfxy((M+6)/2,(N-10)/2,"        ");
	printfxy((M+8)/2,(N-6)/2,"        ");
	
	printfxy((M+34)/2,(N-10)/2,"        ");
	printfxy((M+36)/2,(N-6)/2,"        ");
	
	printfxy((M-10)/2,(N+4)/2,"        ");
	printfxy((M-10)/2,(N+6)/2,"        ");
	
	printfxy((M-20)/2,(N+10)/2,"                 ");
	printfxy((M-26)/2,(N+12)/2,"                         ");
}

void wall() 
{
	for(int j=0;j<N;j++)
	for(int i=0;i<M;i++)
	{
		a[j][i]=0;
		if(i==0||i==M-1)
		{
			a[j][i]=-1;
			putcharxy(i,j,'|');
		}
		if(j==0||j==N-1)
		{
			a[j][i]=-1;
			putcharxy(i,j,'=');
		}	
		if(i==1||i==M-2)
		{
			a[j][i]=-1;
			putcharxy(i,j,'|');
		}
	}
}

void snake()
{
	putcharxy(2,N-3,BODY);
	putcharxy(3,N-3,'@');
	HEADx=3;
	HEADy=N-3;
	a[HEADy][HEADx]=2;
	a[N-3][2]=1;
	LENGTH=2;
 } 
 
void snake2()
{
	putcharxy(M-5,N-3,BODY2);
	putcharxy(M-6,N-3,'@');
	HEADx2=M-6;
	HEADy2=N-3;
	a[HEADy2][HEADx2]=2+M*N;
	a[N-3][M-5]=1+M*N;
	LENGTH2=2;
 } 

void food()
{
	int x,y;
	x=rand()%M;
	y=rand()%N;
	
	if(a[y][x]==0)
	{
		FOODx=x;
		FOODy=y; 
		a[y][x]=-2;
		putcharxy(x,y,'*');
	}
	else food();
 }
 
void wallrand1(int i)
 {
 	int x,y;
	x=rand()%(M-i-6)+1;
	srand((unsigned)time(NULL));
	y=rand()%(N-i-6)+1;
	if(a[y][x]==0&&a[y+1][x]==0&&a[y+2][x]==0)
	{
		a[y][x]=-1;
		a[y+1][x]=-1;
		a[y+2][x]=-1;
		putcharxy(x,y,'|');
		putcharxy(x,y+1,'|');
		putcharxy(x,y+2,'|');
	}
	else wallrand1(i+1);
 }
 
void wallrand2(int i)
 {
 	int x,y;
	y=rand()%(N-6-i)+3;
 	srand((unsigned)time(NULL));
	x=rand()%(M-6-i)+3;
	if(a[y][x]==0&&a[y][x-1]==0&&a[y][x-2]==0)
	{
		a[y][x]=-1;
		a[y][x-1]=-1;
		a[y][x-2]=-1;
		putcharxy(x,y,'-');
		putcharxy(x-1,y,'-');
		putcharxy(x-2,y,'-');
	}
	else wallrand2(i+1);
 }
 
void search(int y,int x)
{
 	for(int i=-1;i<2;i++)
 	for(int j=-1;j<2;j++)
 	{
 		if(a[y+i][x+j]==a[HEADy][HEADx]&&((y+i)!=HEADy||(x+j)!=HEADx)) putcharxy(x+j,y+i,BODY);
 		if(a[y+i][x+j]==a[HEADy][HEADx]-1&&(i!=0||j!=0)) putcharxy(x+j,y+i,BODY);
		if(a[y+i][x+j]==a[y][x]&&a[y+i][x+j]>0&&abs(i+j)==1)
 		{
 			 a[y+i][x+j]--;
			 if(a[y+i][x+j]==0) putcharxy(x+j,y+i,' ');
			 
			 search(y+i,x+j);
		 }
	 }	
} 

void search2(int y,int x)
{
 	for(int i=-1;i<2;i++)
 	for(int j=-1;j<2;j++)
 	{
 		if(a[y+i][x+j]==a[HEADy2][HEADx2]&&((y+i)!=HEADy2||(x+j)!=HEADx2)) putcharxy(x+j,y+i,BODY2);
 		if(a[y+i][x+j]==a[HEADy2][HEADx2]-1&&(i!=0||j!=0)) putcharxy(x+j,y+i,BODY2);
		if(a[y+i][x+j]==a[y][x]&&a[y+i][x+j]>M*N&&abs(i+j)==1)
 		{
 			 a[y+i][x+j]--;	 
			 if(a[y+i][x+j]==N*M) 
			 {
			 	putcharxy(x+j,y+i,' ');
			 	a[y+i][x+j]=0;
			  }
	
			 search2(y+i,x+j);
		 }
	 }		
} 

void test()
{
	if(a[HEADy][HEADx]!=0&&a[HEADy][HEADx]!=-2) FLAG=0;
	if(a[HEADy][HEADx]==-2)
	{	
	 	food();
	 	if(MOD!=2&&MOD!=10) 
		LENGTH++;
		else LENGTH2++;
	}	 
}
 
void test2()
{
	if(a[HEADy2][HEADx2]!=0&&a[HEADy2][HEADx2]!=-2) FLAG2=0;
	if(a[HEADy2][HEADx2]==-2)
	{	
		food();
		LENGTH++;
	}
}

void move()
{
	static char fx='w',temp=fx;
	if(NEWGAME==1) NEWGAME=0,fx='w',temp=fx;
	Sleep(SPEED);
	
	if(kbhit()!=0) 
	fx=getch();
	
	if(fx=='W'||fx=='A'||fx=='S'||fx=='D') fx=fx+32;
	
	if(temp=='w'&&fx=='s') fx=temp;
	if(temp=='s'&&fx=='w') fx=temp;
	if(temp=='a'&&fx=='d') fx=temp;
	if(temp=='d'&&fx=='a') fx=temp;	
	
	if(fx!='w'&&fx!='a'&&fx!='s'&&fx!='d') fx=temp;
	else temp=fx; 
		
	switch(fx)
	{
		case 'w': HEADy--;test();break;
		case 'a': HEADx--;test();break;
		case 's': HEADy++;test();break;
		case 'd': HEADx++;test();break;
	}
	

	if(LENGTH==(M-2)*(N-2)-1) FLAG=2; 
	if(FLAG==1)
	{
		putcharxy(HEADx,HEADy,'@');
		a[HEADy][HEADx]=LENGTH;
		search(HEADy,HEADx);
		move();
	}

}
 
void move2()
{
 	static char fx='w',temp=fx;
 	static char fx2='5',temp2=fx2;
 	if(NEWGAME==1) NEWGAME=0,fx='w',temp=fx,fx2='5',temp2=fx2;
	Sleep(SPEED);
	
	if(kbhit()!=0) 
	{
		fx=getch();
		fx2=fx;
	}
	if(fx=='W'||fx=='A'||fx=='S'||fx=='D') fx=fx+32;
	
	if(temp=='w'&&fx=='s') fx=temp;
	if(temp=='s'&&fx=='w') fx=temp;
	if(temp=='a'&&fx=='d') fx=temp;
	if(temp=='d'&&fx=='a') fx=temp;	
	
	if(temp2=='5'&&fx2=='2') fx2=temp2;
	if(temp2=='2'&&fx2=='5') fx2=temp2;
	if(temp2=='3'&&fx2=='1') fx2=temp2;
	if(temp2=='1'&&fx2=='3') fx2=temp2;	
	
	if(fx!='w'&&fx!='a'&&fx!='s'&&fx!='d') fx=temp;
	else temp=fx; 
	if(fx2!='5'&&fx2!='1'&&fx2!='2'&&fx2!='3') fx2=temp2;
	else temp2=fx2; 
		
	switch(fx)
	{
		case 'w': HEADy--;test();break;
		case 'a': HEADx--;test();break;
		case 's': HEADy++;test();break;
		case 'd': HEADx++;test();break;
	}
	
	switch(fx2)
	{
		case '5': HEADy2--;test2();break;
		case '1': HEADx2--;test2();break;
		case '2': HEADy2++;test2();break;
		case '3': HEADx2++;test2();break;
	}
	
	if(FLAG2==1)
	{
		putcharxy(HEADx2,HEADy2,'@');
		a[HEADy2][HEADx2]=LENGTH2+M*N;
		search2(HEADy2,HEADx2);
	}

	if(FLAG==1)
	{
		putcharxy(HEADx,HEADy,'@');
		a[HEADy][HEADx]=LENGTH;
		search(HEADy,HEADx);	
	}
	if(FLAG==1&&FLAG2==1) 
	move2();
}

void move3()
{
 	static char fx='w',temp=fx;
 	static char fx2='5',temp2=fx2;
 	int ff=1;
 	if(NEWGAME==1) NEWGAME=0,fx='w',temp=fx,fx2='5',temp2=fx2;
	Sleep(SPEED);
	
	if(kbhit()!=0)
	fx=getch();
	
	if(fx=='W'||fx=='A'||fx=='S'||fx=='D') fx=fx+32;
	
	if(temp=='w'&&fx=='s') fx=temp;
	if(temp=='s'&&fx=='w') fx=temp;
	if(temp=='a'&&fx=='d') fx=temp;
	if(temp=='d'&&fx=='a') fx=temp;	
	
	if(fx!='w'&&fx!='a'&&fx!='s'&&fx!='d') fx=temp;
	else temp=fx; 
		
	switch(fx)
	{
		case 'w': HEADy--;test();break;
		case 'a': HEADx--;test();break;
		case 's': HEADy++;test();break;
		case 'd': HEADx++;test();break;
	}
	
	if(LENGTH2==10) FLAG2=0;
	if(FOODx-HEADx2>0&&(a[HEADy2][HEADx2+1]==0||a[HEADy2][HEADx2+1]==-2)) HEADx2++,ff=0;
	if(FOODx-HEADx2<0&&(a[HEADy2][HEADx2-1]==0||a[HEADy2][HEADx2-1]==-2)&&ff) HEADx2--,ff=0;
	if(FOODy-HEADy2<=0&&(a[HEADy2-1][HEADx2]==0||a[HEADy2-1][HEADx2]==-2)&&ff) HEADy2--,ff=0;
	if(FOODy-HEADy2>=0&&(a[HEADy2+1][HEADx2]==0||a[HEADy2+1][HEADx2]==-2)&&ff) HEADy2++,ff=0;
	if(ff&&(a[HEADy2][HEADx2+1]==0||a[HEADy2][HEADx2+1]==-2)) HEADx2++,ff=0;
	if(ff&&(a[HEADy2][HEADx2-1]==0||a[HEADy2][HEADx2-1]==-2)&&ff) HEADx2--,ff=0;
	if(ff&&(a[HEADy2-1][HEADx2]==0||a[HEADy2-1][HEADx2]==-2)&&ff) HEADy2--,ff=0;
	if(ff) HEADy2++,ff=0;
	
	test2();
	
	if(FLAG==1)
	{
		putcharxy(HEADx,HEADy,'@');
		a[HEADy][HEADx]=LENGTH;
		search(HEADy,HEADx);	
	}
	if(FLAG2==1)
	{
		putcharxy(HEADx2,HEADy2,'@');
		a[HEADy2][HEADx2]=LENGTH2+M*N;
		search2(HEADy2,HEADx2);
	}
	
	if(FLAG==1&&FLAG2==1) 
	move3();
}

void record()
{
	printfxy((M-20)/2,(N-10)/2,"!!\'Gluttonous Snake\'");
	if(MOD!=2&&MOD!=10)
	{
		gotoxy((M-8)/2,(N-2)/2);
		if(FLAG==2) printf("WIN!:)");
	 	else printf("LOSE;(");

	 	if(MOD==1&&FLAG!=2) printfxy((M-20)/2,N/2,"BUT YOU ARE A WARRIOR");
		
		gotoxy((M-8)/2,N/2+1);
		printf("you:%d",LENGTH);	
			
		gotoxy((M-8)/2,N/2+2);
		if(MOD==0) fp=fopen("snake.txt","r+");
		else fp=fopen("snake2.txt","r+");
			
		fscanf(fp,"%d",&RECORD);
		if(RECORD<LENGTH) RECORD=LENGTH;
		printf("record:%d",RECORD);
		rewind(fp);
		fprintf(fp,"%d",RECORD);
		fclose(fp);
	}
	else if(MOD==10)
	{
		gotoxy((M-12)/2,(N-2)/2);
		if(FLAG==0&&FLAG2==0&&a[HEADy2][HEADx2]!=-1&&a[HEADy][HEADx]!=-1) printfxy((M-6)/2,(N-2)/2,"LOVE");
		else if(FLAG==0&&FLAG2!=0) printf("player LOSE!");
		else if(FLAG2==0&&FLAG!=0) printf("player WIN!");
		else printf("play again??");
	} 
	else
	{
		gotoxy((M-12)/2,(N-2)/2);
		if(FLAG==0&&FLAG2==0&&a[HEADy2][HEADx2]!=-1&&a[HEADy][HEADx]!=-1) printfxy((M-6)/2,(N-2)/2,"LOVE");
		else if((FLAG==0&&FLAG2!=0)||((FLAG==0&&FLAG2==0)&&LENGTH>LENGTH2)) printf("player2 WIN!");
		else if((FLAG2==0&&FLAG!=0)||((FLAG==0&&FLAG2==0)&&LENGTH2>LENGTH)) printf("player1 WIN!");
		else printf("play again??");
	} 
	printfxy((M-36)/2,N/2+5,"\'SPACE\' to continue and \'ENTER\' to close");
}

void clean1()
{
	for(int j=0;j<N;j++)
	for(int i=0;i<M;i++)
	if(i==0||i==M-1||i==1||i==M-2||j==0||j==N-1) a[j][i]=-1;
	else if(a[j][i]!=0)
	{
		a[j][i]=0;
		putcharxy(i,j,' ');
	}
	printfxy(M+3,(N+2)/2,"           ");
	printfxy(M+3,N/2,"           ");
	printfxy(M+3,(N+4)/2,"           ");
	printfxy(M+3,(N+2)/2+5,"           ");
	printfxy(M+3,N/2+5,"           ");
	printfxy(M+3,(N+4)/2+5,"           ");
}

void clean2()
{
	for(int j=(N-2)/2;j<=N/2+2;j++)
	for(int i=(M-20)/2;i<M-19;i++)
	if(a[j][i]==0) putcharxy(i,j,' ');
	gotoclean((M-36)/2,N/2+5,"\'SPACE\' to continue and \'ENTER\' to close");
}

void newgame()
{
	FLAG=1,FLAG2=1,SPEED=100;
	NEWGAME=1;
}

int main(int argc, char** argv) 
{
	wall();
	keys();
	rightscreen();
	while(1)
	{
		screen();
		MOD=selectmod();
		screenclean();
		selectscreen();	
		select(0,'1');
		selectclean();
		food();
		if(MOD==2)
		{
			snake();
			snake2();	 
			move2(); 
		}
		else if(MOD==10) 
		{
			snake();
			snake2();
			move3();
		}
		else
		{
			snake();
			if(MOD==1) 
		 	{
				wallrand1(0); 
				wallrand2(0); 
				wallrand1(5);
				wallrand2(5); 
				wallrand1(10);
				wallrand2(10);   
			}
	 		move();
		}
		clean1();
		record();
		while(1)
	 	{
	 		GETONE=getch();
	 		if(GETONE==' ') break;
	 		else if(GETONE=='\r') return 0; 
		}
		clean2();
	 	newgame();
	}
	return 0;
}
