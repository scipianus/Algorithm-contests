#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,perm[110],poz[110],nrc,comp[110],ind[110];
char pos[110][110];
vector <int> G[110],C[110];
bool viz[110];

inline void DFS(int x)
{
	viz[x]=true;
	C[nrc].push_back(perm[x]);
	comp[x]=nrc;
	vector <int>::iterator it;
	for(it=G[x].begin();it!=G[x].end();it++)
		if(!viz[*it])
			DFS(*it);
}

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>perm[i];
		poz[perm[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		cin>>(pos[i]+1);
		for(j=1;j<=n;j++)
		{
			if(pos[i][j]=='Y')
				G[i].push_back(j);
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(!viz[i])
		{
			nrc++;
			DFS(i);
		}
	}
	for(i=1;i<=nrc;i++)
		sort(C[i].begin(),C[i].end());
	for(i=1;i<=n;i++)
	{
		cout<<C[comp[i]][ind[comp[i]]]<<' ';
		ind[comp[i]]++;
	}
	cout<<"\n";
	return 0;
}
