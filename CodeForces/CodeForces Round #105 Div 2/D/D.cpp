#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int alb,negru;
double sol;

inline int Joc(int n,int m)
{
	int x,y,tot=n+m;
	while(1)
	{
		srand(time(NULL));
		x=rand()%tot; //dragonul
		if(x<n)
			x=1;
		else
			x=0;
		if(x==1)
			return 0;
		else
			m--;
		y=rand()%tot; //scapa
		if(y<n)
			y=1;
		else
			y=0;
		if(y==0)
			m--;
		else
			n--;
		if(n==0)
			return -1;
		y=rand()%tot; //printesa
		if(y<n)
			y=1;
		else
			y=0;
		if(y==1)
			return 1;
		else
			m--;
		tot=n+m;
	}
}

inline int Joc1(int n,int m)
{
	int x,y,tot=n+m;
	while(1)
	{
		srand(time(NULL));
		y=rand()%tot; //printesa
		if(y<n)
			y=1;
		else
			y=0;
		if(y==1)
			return 1;
		else
			m--;
		x=rand()%tot; //dragonul
		if(x<n)
			x=1;
		else
			x=0;
		if(x==1)
			return 0;
		else
			m--;
		y=rand()%tot; //scapa
		if(y<n)
			y=1;
		else
			y=0;
		if(y==0)
			m--;
		else
			n--;
		if(n==0)
			return -1;
		tot=n+m;
	}
}

int main()
{
	int i,rez;
	cin>>alb>>negru;
	for(i=1;i<=10000;i++)
	{
		rez=Joc(alb,negru);
		if(rez==1)
			sol+=1.0;
		rez=Joc1(alb,negru);
		if(rez==1)
			sol+=1.0;
	}
	sol=(double)sol/(double)20000;
	printf("%.9f\n",sol);
	return 0;
}
