/*
PROB: island
LANG: C++
*/
#include<fstream>
#include<queue>
#include<cmath>
using namespace std;
int R,C,n,nr[55][55],dist[20][20],best[33000][16],sol=1000000000;
char mat[55][55];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
struct Pozitie{int x,y;};

inline void DFS(int i,int j)
{
	nr[i][j]=n;
	int k,x,y;
	for(k=0;k<4;k++)
	{
		x=i+dx[k];
		y=j+dx[k];
		if(mat[x][y]=='X' && nr[x][y]==0)
			DFS(x,y);
	}
}

inline int Lee(int A,int B)
{
	int i,j,k,d[55][55],sol=1000000000;
	Pozitie aux,poz;
	queue <Pozitie> Q;
	for(i=1;i<=R;i++)
	{
		for(j=1;j<=C;j++)
		{
			if(nr[i][j]==A)
			{
				d[i][j]=0;
				aux.x=i;
				aux.y=j;
				Q.push(aux);
			}
			else
				d[i][j]=1000000000;
		}
	}
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		if(d[aux.x][aux.y]>sol)
			continue;
		for(k=0;k<4;k++)
		{
			poz.x=aux.x+dx[k];
			poz.y=aux.y+dy[k];
			if(mat[poz.x][poz.y]=='X')
			{
				if(d[poz.x][poz.y]>d[aux.x][aux.y])
				{
					d[poz.x][poz.y]=d[aux.x][aux.y];
					Q.push(poz);
					if(nr[poz.x][poz.y]==B)
						sol=min(sol,d[poz.x][poz.y]);
				}
				continue;
			}
			if(mat[poz.x][poz.y]=='S')
			{
				if(d[poz.x][poz.y]>d[aux.x][aux.y]+1)
				{
					d[poz.x][poz.y]=d[aux.x][aux.y]+1;
					Q.push(poz);
				}
			}
		}
	}
	return sol;
}

int main()
{
	int i,j,conf,lim;
	ifstream fin("island.in");
	fin>>R>>C;
	for(i=1;i<=R;i++)
		fin>>(mat[i]+1);
	fin.close();
	
	for(i=1;i<=R;i++)
	{
		for(j=1;j<=C;j++)
		{
			if(mat[i][j]=='X' && nr[i][j]==0)
			{
				n++;
				DFS(i,j);
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			dist[i-1][j-1]=dist[j-1][i-1]=Lee(i,j);
	lim=(1<<n)-1;
	for(conf=0;conf<=lim;conf++)
		for(i=0;i<n;i++)
			best[conf][i]=1000000000;
	for(i=0;i<n;i++)
		best[(1<<i)][i]=0;
	for(conf=1;conf<lim;conf++)
	{
		for(i=0;i<n;i++)
		{
			if(best[conf][i]<1000000000)
			{
				for(j=0;j<n;j++)
				{
					if((conf&(1<<j))!=0)
						continue;
					best[(conf|(1<<j))][j]=min(best[(conf|(1<<j))][j],best[conf][i]+dist[i][j]);
				}
			}
		}
	}
	for(i=0;i<n;i++)
		sol=min(sol,best[lim][i]);
	
	ofstream fout("island.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
