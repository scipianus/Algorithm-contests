/*
PROB: rblock
LANG: C++
*/
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,sol;
struct Muchie{short x,y;int cost;};
vector <short> G[105],A;
Muchie v[10010];
int d1[105],dn[105],d[105];

void Citire()
{
	int i;
	ifstream fin("rblock.in");
	fin>>n>>m;
	for(i=1;i<=m;i++)
	{
		fin>>v[i].x>>v[i].y>>v[i].cost;
		G[v[i].x].push_back(i);
		G[v[i].y].push_back(i);
	}
	fin.close();
}

void Bellman_Ford_Initial()
{
	vector <short>::iterator it;
	short i,x,nod;
	for(i=1;i<=n;i++)
		d1[i]=2000000000;
	queue <short> Q;
	Q.push(1);
	d1[1]=0;
	while(!Q.empty())
	{
		x=Q.front();
		Q.pop();
		for(it=G[x].begin();it!=G[x].end();it++)
		{
			nod=v[*it].x+v[*it].y-x;
			if(d1[nod]>d1[x]+v[*it].cost)
			{
				d1[nod]=d1[x]+v[*it].cost;
				Q.push(nod);
			}
		}
	}
	for(i=1;i<=n;i++)
		dn[i]=2000000000;
	Q.push(n);
	dn[n]=0;
	while(!Q.empty())
	{
		x=Q.front();
		Q.pop();
		for(it=G[x].begin();it!=G[x].end();it++)
		{
			nod=v[*it].x+v[*it].y-x;
			if(dn[nod]>dn[x]+v[*it].cost)
			{
				dn[nod]=dn[x]+v[*it].cost;
				Q.push(nod);
			}
		}
	}
}

void Selectare_Muchii()
{
	short i;
	int dist1,dist2,dist;
	for(i=1;i<=m;i++)
	{
		dist1=d1[v[i].x]+dn[v[i].y]+v[i].cost;
		dist2=d1[v[i].y]+dn[v[i].x]+v[i].cost;
		dist=min(dist1,dist2);
		if(dist==d1[n])
			A.push_back(i);
	}
}

void Bellman_Ford()
{
	vector <short>::iterator it;
	short i,x,nod;
	for(i=1;i<=n;i++)
		d[i]=2000000000;
	queue <short> Q;
	Q.push(1);
	d[1]=0;
	while(!Q.empty())
	{
		x=Q.front();
		Q.pop();
		for(it=G[x].begin();it!=G[x].end();it++)
		{
			nod=v[*it].x+v[*it].y-x;
			if(d[nod]>d[x]+v[*it].cost)
			{
				d[nod]=d[x]+v[*it].cost;
				Q.push(nod);
			}
		}
	}
}

void Rezolvare()
{
	vector <short>::iterator it;
	Bellman_Ford_Initial();
	Selectare_Muchii();
	for(it=A.begin();it!=A.end();it++)
	{
		v[*it].cost*=2;
		Bellman_Ford();
		sol=max(sol,d[n]-d1[n]);
		v[*it].cost/=2;
	}
}

void Afisare()
{
	ofstream fout("rblock.out");
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
