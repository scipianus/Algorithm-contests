#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<fstream>
using namespace std;
int n,m;
struct Muchie{int x,y,c;};
Muchie M[100100];
struct Interval{long long st,dr;};
vector <Interval> I[100100];
vector <int> G[100100];
long long dist[100100],sol=4000000000000000000LL;
int nri[100100];
queue <int> Q;
bool viz[100100];

inline int CautareBinara(long long t,int nod)
{
	int st,dr,mij;
	st=0;
	dr=nri[nod]-1;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		if((I[nod][mij].st<=t && I[nod][mij].dr>=t) || (I[nod][mij].st>t && mij>=1 && I[nod][mij-1].dr<t))
			return mij;
		if(I[nod][mij].st<=t)
			st=mij+1;
		else
			dr=mij-1;
	}
	return 0;
}

inline long long Max(long long a,long long b)
{
	if(a<b)
		return b;
	return a;
}

inline long long Min(long long a,long long b)
{
	if(a>b)
		return b;
	return a;
}

inline void BellmanFord()
{
	int i,x,nod,p;
	long long t;
	vector <int>::iterator it;
	for(i=1;i<=n;i++)
		dist[i]=4000000000000000000LL;
	dist[1]=I[1][0].st;
	Q.push(1);
	while(!Q.empty())
	{
		x=Q.front();
		Q.pop();
		if(x==n)
		{
			sol=Min(sol,dist[x]);
			continue;
		}
		if(dist[x]>=sol)
			continue;
		for(it=G[x].begin();it!=G[x].end();it++)
		{
			nod=M[*it].x+M[*it].y-x;
			t=dist[x]+(long long)M[*it].c;
			p=CautareBinara(t,nod);
			if(nod!=n)
				t=Max(t,I[nod][p].st);
			if(dist[nod]>t)
			{
				dist[nod]=t;
				Q.push(nod);
			}
		}
	}
}

inline void DFS(int x)
{
	int nod;
	viz[x]=true;
	vector <int>::iterator it;
	for(it=G[x].begin();it!=G[x].end();it++)
	{
		nod=M[*it].x+M[*it].y-x;
		if(!viz[nod])
			DFS(nod);
	}
}

int main()
{
	int i,j,nr;
	long long x,st;
	Interval aux;
	//ifstream fin("B.in");
	//fin>>n>>m;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		//fin>>M[i].x>>M[i].y>>M[i].c;
		cin>>M[i].x>>M[i].y>>M[i].c;
		G[M[i].x].push_back(i);
		G[M[i].y].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		//fin>>nr;
		cin>>nr;
		st=0LL;
		for(j=1;j<=nr;j++)
		{
			//fin>>x;
			cin>>x;
			if(st<=x-1LL)
			{
				aux.st=st;
				aux.dr=x-1LL;
				I[i].push_back(aux);
			}
			st=x+1LL;
		}
		aux.st=st;
		aux.dr=4000000000000000000LL;
		I[i].push_back(aux);
		nri[i]=I[i].size();
	}
	
	DFS(1);
	if(!viz[n])
	{
		cout<<"-1\n";
		return 0;
	}
	BellmanFord();
	
	if(sol==4000000000000000000LL)
		cout<<"-1\n";
	else
		cout<<sol<<"\n";
	return 0;
}
