#include<iostream>
#include<vector>
using namespace std;
int n,m,nivmin[1010],nivmax[1010],sol[5010];
vector <int> G[1010];
struct Muchie{int x,y;};
Muchie M[5010];

inline void DFS(int x,int lvl)
{
	int nod;
	vector <int>::iterator it;
	for(it=G[x].begin();it!=G[x].end();it++)
	{
		nod=M[*it].y;
		nivmin[nod]=min(nivmin[nod],lvl+1);
		nivmax[nod]=max(nivmax[nod],lvl+1);
		DFS(nod,lvl+1);
	}
}

inline void DFSC(int x,int lvl)
{
	int nod;
	vector <int>::iterator it;
	for(it=G[x].begin();it!=G[x].end();it++)
	{
		nod=M[*it].y;
		if(nivmin[nod]!=nivmax[nod])
		{
			if(nivmin[nod]==lvl+1)
				sol[*it]=2;
			else
				sol[*it]=1;
		}
		else
			sol[*it]=1;
		DFSC(nod,lvl+1);
	}
}

int main()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>M[i].x>>M[i].y;
		G[M[i].x].push_back(i);
	}
	
	nivmin[1]=nivmax[1]=0;
	for(i=2;i<=n;i++)
		nivmin[i]=2000000000;
	DFS(1,0);
	for(i=1;i<=n;i++)
	{
		if(nivmax[i]-nivmin[i]>=2)
		{
			cout<<"No\n";
			return 0;
		}
	}
	DFSC(1,0);
	cout<<"Yes\n";
	for(i=1;i<=m;i++)
	{
		if(!sol[i])
			sol[i]=1;
		cout<<sol[i]<<"\n";
	}
	return 0;
}
