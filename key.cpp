#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 51
#define N 26
#define O 6
int main()
{
	char key[N],a[M],b[O][O]={'0'};
	int i1=0,i2=0,flag,temp,x1,x2,y1,y2;
	
	gets(key);
	srand((unsigned)time(NULL));
	
	for(int k1=0;k1<6;k1++)
	{
		a[k1]=rand()%25+'a';
		
		for(int k2=0;k2<k1;k2++)
		if(a[k1]==a[k2]) k1--;
	}
	
	a[6]='\0';
	puts(a);
	
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
	
	puts(a);
	getchar();
return 0;
}
