#include<iostream>
#include<cstdio>
#include<vector>
#define INF 1000000000
using namespace std;
int n,m,cost[100100],nrcomp,compcost[100100],minim;
long long sol;
vector <int> G[100100];
bool viz[100100],notsol;

inline void DFS(int x)
{
	viz[x]=true;
	if(cost[x]>=0)
		compcost[nrcomp]=min(compcost[nrcomp],cost[x]);
	vector <int>::iterator it;
	for(it=G[x].begin();it!=G[x].end();it++)
		if(!viz[*it])
			DFS(*it);
}

int main()
{
	int i,x,y;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(i=1;i<=n;i++)
		cin>>cost[i];
	
	for(i=1;i<=n;i++)
	{
		if(!viz[i])
		{
			nrcomp++;
			compcost[nrcomp]=INF;
			DFS(i);
			if(compcost[nrcomp]==INF)
				notsol=true;
			if(!minim || compcost[nrcomp]<compcost[minim])
				minim=nrcomp;
		}
	}
	if(nrcomp==1)
	{
		printf("0\n");
		return 0;
	}
	if(notsol)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=nrcomp;i++)
	{
		if(i!=minim)
			sol+=1LL*compcost[i];
		else
			sol+=(1LL*nrcomp-1LL)*compcost[i];
	}
	printf("%lld\n",sol);
	return 0;
}
