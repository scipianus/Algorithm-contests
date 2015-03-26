#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n,m,R;
int t[61][61][61],dmin[61][61][61][1002];
struct Element{int nod,car,nrcar;};

inline void Bellman_Ford(int S)
{
	queue <Element> Q;
	Element aux,poz;
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(k=0;k<=1000;k++)
			dmin[S][i][j][k]=2000000000;
	for(i=1;i<=m;i++)
	{
		dmin[S][S][i][0]=0;
		aux.nod=S;
		aux.car=i;
		aux.nrcar=0;
		Q.push(aux);
	}
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(j!=aux.car)
				{
					if(aux.nrcar+1<=1000 && dmin[S][i][j][aux.nrcar+1]>dmin[S][aux.nod][aux.car][aux.nrcar]+t[j][aux.nod][i])
					{
						dmin[S][i][j][aux.nrcar+1]=dmin[S][aux.nod][aux.car][aux.nrcar]+t[j][aux.nod][i];
						poz.nod=i;
						poz.car=j;
						poz.nrcar=aux.nrcar+1;
						Q.push(poz);
					}
				}
				else
				{
					if(dmin[S][i][j][aux.nrcar]>dmin[S][aux.nod][j][aux.nrcar]+t[j][aux.nod][i])
					{
						dmin[S][i][j][aux.nrcar]=dmin[S][aux.nod][j][aux.nrcar]+t[j][aux.nod][i];
						poz.nod=i;
						poz.car=j;
						poz.nrcar=aux.nrcar;
						Q.push(poz);
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=1000;j++)
		{
			dmin[S][i][0][j]=dmin[S][i][1][j];
			for(k=2;k<=m;k++)
				dmin[S][i][0][j]=min(dmin[S][i][0][j],dmin[S][i][k][j]);
		}
	}
}

int main()
{
	int i,j,k,S,D,Kmax,sol;
	cin>>n>>m>>R;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				cin>>t[i][j][k];
	for(i=1;i<=n;i++)
		Bellman_Ford(i);
	for(i=1;i<=R;i++)
	{
		cin>>S>>D>>Kmax;
		sol=2000000000;
		for(j=0;j<=Kmax;j++)
			sol=min(sol,dmin[S][D][0][j]);
		cout<<sol<<"\n";
	}
	return 0;
}
