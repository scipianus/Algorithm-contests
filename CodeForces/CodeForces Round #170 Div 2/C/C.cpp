#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
#include<vector>
using namespace std;
int n,m,nrc;
bitset <110> L[110],A;
vector <int> G[110];
bool viz[110];

inline void DFS(int x)
{
	viz[x]=true;
	vector <int>::iterator it;
	for(it=G[x].begin();it!=G[x].end();it++)
		if(!viz[*it])
			DFS(*it);
}

int main()
{
	int i,j,k,x,nr0=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		if(k==0)
			nr0++;
		for(j=1;j<=k;j++)
		{
			cin>>x;
			L[i][x]=1;
		}
	}
	if(nr0==n)
	{
		cout<<n<<"\n";
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			A=(L[i]&L[j]);
			if(A.count()>=1)
			{
				G[i].push_back(j);
				G[j].push_back(i);
			}
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
	cout<<(nrc-1)<<"\n";
	return 0;
}
