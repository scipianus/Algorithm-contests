#include<iostream>
#include<vector>
using namespace std;
int n,m,a[100100],val[100100];
vector <int> G[100100],GT[100100];
bool viz[100100],viz2[100100];

inline void DFS(int x)
{
	vector <int>::iterator it;
	for(it=G[x].begin();it!=G[x].end();it++)
	{
		if(!viz[*it])
		{
			viz[*it]=true;
			DFS(*it);
		}
	}
}

inline void DFS2(int x)
{
	vector <int>::iterator it;
	for(it=GT[x].begin();it!=GT[x].end();it++)
	{
		if(!viz2[*it])
		{
			viz2[*it]=true;
			if(a[*it]!=1)
				DFS2(*it);
		}
	}
}

int main()
{
	int i,x=1,y;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		G[x].push_back(y);
		GT[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==1 && !viz[i])
		{
			viz[i]=true;
			DFS(i);
		}
		if(a[i]==2 && !viz2[i])
		{
			viz2[i]=true;
			DFS2(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(viz[i]==true && viz2[i]==true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
	return 0;
}
