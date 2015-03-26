#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int n,m,K,mat[110][110],dist[10][10],d[110][110],c[10],h[10],nr,solcost;
struct Pozitie{int x,y;};
Pozitie P[10];
struct Muchie{int x,y,cost;};
vector <Muchie> v;
vector <Pozitie> drum[10][10];
Muchie arbore[110];
char sol[110][110];

short dx[]={1,0,-1,0};
short dy[]={0,1,0,-1};

inline int Lee(Pozitie A,Pozitie B,int i1,int j1)
{
	int i,j,k;
	Pozitie pre[110][110];
	Pozitie aux,poz;
	aux.x=aux.y=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			d[i][j]=2000000000;
			pre[i][j]=aux;
		}
	}
	queue <Pozitie> Q;
	Q.push(A);
	d[A.x][A.y]=mat[A.x][A.y];
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		for(k=0;k<4;k++)
		{
			poz.x=aux.x+dx[k];
			poz.y=aux.y+dy[k];
			if(d[poz.x][poz.y]>d[aux.x][aux.y]+mat[poz.x][poz.y])
			{
				d[poz.x][poz.y]=d[aux.x][aux.y]+mat[poz.x][poz.y];
				pre[poz.x][poz.y]=aux;
				Q.push(poz);
			}
		}
	}
	aux=B;
	while(!(aux.x==0 && aux.y==0))
	{
		drum[i1][j1].push_back(aux);
		drum[j1][i1].push_back(aux);
		aux=pre[aux.x][aux.y];
	}
	return d[B.x][B.y];
}

int Find(int x)
{
	int r=x;
	while(c[r])
		r=c[r];
	int y=x,aux;
	while(y!=r)
	{
		aux=c[y];
		c[y]=r;
		y=aux;
	}
	return r;
}

void Union(int x,int y)
{
	if(h[x]>h[y])
		c[y]=x;
	else
	{
		c[x]=y;
		if(h[x]==h[y])
			h[y]++;
	}
}

inline bool Ordonare(Muchie A,Muchie B)
{
	return A.cost>B.cost;
}

inline void Kruskal()
{
	int i,A,B;
	make_heap(v.begin(),v.end(),Ordonare);
	Muchie aux;
	for(i=1;nr<K-1;i++)
	{
		aux=v.front();
		pop_heap(v.begin(),v.end(),Ordonare);
		v.pop_back();
		
		A=Find(aux.x);
		B=Find(aux.y);
		
		if(A!=B)
		{
			arbore[++nr]=aux;
			Union(A,B);
		}
	}
}

int main()
{
	int i,j,lim;
	Muchie aux;
	//ifstream fin("E.in");
	//fin>>n>>m>>K;
	cin>>n>>m>>K;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			//fin>>mat[i][j];
			cin>>mat[i][j];
			sol[i][j]='.';
		}
	}
	for(i=1;i<=K;i++)
	{
		//fin>>P[i].x>>P[i].y;
		cin>>P[i].x>>P[i].y;
	}
	for(i=1;i<=K;i++)
	{
		for(j=i+1;j<=K;j++)
		{
			dist[i][j]=dist[j][i]=Lee(P[i],P[j],i,j);
			aux.x=i;
			aux.y=j;
			aux.cost=dist[i][j];
			v.push_back(aux);
		}
	}
	Kruskal();
	for(i=1;i<=nr;i++)
	{
		lim=drum[arbore[i].x][arbore[i].y].size();
		for(j=0;j<lim;j++)
		{
			if(sol[drum[arbore[i].x][arbore[i].y][j].x][drum[arbore[i].x][arbore[i].y][j].y]!='X')
			{
				sol[drum[arbore[i].x][arbore[i].y][j].x][drum[arbore[i].x][arbore[i].y][j].y]='X';
				solcost+=mat[drum[arbore[i].x][arbore[i].y][j].x][drum[arbore[i].x][arbore[i].y][j].y];
			}
			
		}
	}
	cout<<solcost<<"\n";
	for(i=1;i<=n;i++)
		cout<<(sol[i]+1)<<"\n";
	return 0;
}
