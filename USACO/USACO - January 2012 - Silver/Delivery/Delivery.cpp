/*
PROB: delivery
LANG: C++
*/
#include<fstream>
#include<cmath>
#include<deque>
using namespace std;
int N,sol,n,m;
struct Punct{int x,y;};
Punct P[110];
short mat[2000][2000];
deque <Punct> D;
int d[2000][2000];

short dx[]={1,0,-1,0};
short dy[]={0,1,0,-1};

void Citire()
{
	int i;
	ifstream fin("delivery.in");
	fin>>N;
	for(i=1;i<=N;i++)
		fin>>P[i].x>>P[i].y;
	N++;
	P[N]=P[1];
	fin.close();
}

void Rezolvare()
{
	int i,j,k;
	int minc=200000000,minl=2000000000,maxl=0,maxc=0;
	Punct aux,poz;
	for(i=1;i<N;i++)
	{
		minl=min(minl,P[i].x);
		minc=min(minc,P[i].y);
		maxl=max(maxl,P[i].x);
		maxc=max(maxc,P[i].y);
	}
	n=maxl-minl+1;
	m=maxc-minc+1;
	
	n++;
	m++;
	
	if(n>2000 || m>2000)
	{
		sol=-1;
		return;
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			mat[i][j]=false;
			d[i][j]=2000000000;
		}
	}
	
	for(i=1;i<N;i++)
	{
		P[i].x=P[i].x-minl+1;
		P[i].y=P[i].y-minc+1;
		mat[P[i].x][P[i].y]=i;
	}
	P[i].x=P[i].x-minl+1;
	P[i].y=P[i].y-minc+1;
	
	for(i=2;i<N;i++)
	{
		d[P[i-1].x][P[i-1].y]=0;
		D.push_back(P[i-1]);
		while(D.size())
		{
			aux=D.front();
			D.pop_front();
			for(k=0;k<4;k++)
			{
				poz.x=aux.x+dx[k];
				poz.y=aux.y+dy[k];
				if(1<=poz.x && poz.x<=n && 1<=poz.y && poz.y<=m)
				{
					if(mat[poz.x][poz.y]==i)
					{
						if(d[poz.x][poz.y]>d[aux.x][aux.y]+1)
						{
							d[poz.x][poz.y]=d[aux.x][aux.y]+1;
							D.push_back(poz);
						}
					}
					else
					{
						if(!mat[poz.x][poz.y])
						{
							if(d[poz.x][poz.y]>d[aux.x][aux.y]+1)
							{
								d[poz.x][poz.y]=d[aux.x][aux.y]+1;
								D.push_back(poz);
							}
						}
					}
				}
			}
		}
		if(d[P[i].x][P[i].y]==2000000000)
		{
			sol=-1;
			return;
		}
		sol+=d[P[i].x][P[i].y];
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=m;k++)
			{
				d[j][k]=2000000000;
			}
		}
	}
	d[P[i-1].x][P[i-1].y]=0;
	D.push_back(P[i-1]);
	while(D.size())
	{
		aux=D.front();
		D.pop_front();
		for(k=0;k<4;k++)
		{
			poz.x=aux.x+dx[k];
			poz.y=aux.y+dy[k];
			if(1<=poz.x && poz.x<=n && 1<=poz.y && poz.y<=m)
			{
				if(mat[poz.x][poz.y]==1)
				{
					if(d[poz.x][poz.y]>d[aux.x][aux.y]+1)
					{
						d[poz.x][poz.y]=d[aux.x][aux.y]+1;
						D.push_back(poz);
					}
				}
				else
				{
					if(!mat[poz.x][poz.y])
					{
						if(d[poz.x][poz.y]>d[aux.x][aux.y]+1)
						{
							d[poz.x][poz.y]=d[aux.x][aux.y]+1;
							D.push_back(poz);
						}
					}
				}
			}
		}
	}
	if(d[P[1].x][P[1].y]==2000000000)
	{
		sol=-1;
		return;
	}
	sol+=d[P[1].x][P[1].y];
}

void Afisare()
{
	ofstream fout("delivery.out");
	fout<<sol<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Rezolvare();
	Afisare();
	return 0;
}
