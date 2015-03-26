#include<iostream>
#include<algorithm>
#include<cmath>
#define INF 4000000000000000000LL
using namespace std;
int n,m,K;
struct Companie{int st,dr,cost;};
Companie v[100100];
long long best[310][310],sol;

inline bool Sortare(Companie A,Companie B)
{
	return A.st<B.st;
}

int main()
{
	int i,j,k,p,lg;
	cin>>n>>m>>K;
	for(i=1;i<=m;i++)
		cin>>v[i].st>>v[i].dr>>v[i].cost;
	sort(v+1,v+m+1,Sortare);
	for(i=0;i<=n;i++)
		for(j=1;j<=n;j++)
			best[i][j]=INF;
	j=1;
	for(i=0;i<n;i++)
	{
		best[i][0]=0;
		if(i>0)
		{
			for(k=1;k<=i;k++)
				best[i][k]=min(best[i][k],best[i-1][k]);
		}
		while(j<=m && v[j].st<=i)
			j++;
		while(j<=m && v[j].st==i+1)
		{
			for(k=0;k<=i;k++)
			{
				if(best[i][k]!=INF)
				{
					lg=v[j].dr-v[j].st+1;
					for(p=1;p<=lg;p++)
						best[i+p][k+p]=min(best[i+p][k+p],best[i][k]+v[j].cost);
				}
			}
			j++;
		}
	}
	sol=INF;
	for(i=K;i<=n;i++)
		for(j=K;j<=i;j++)
			sol=min(sol,best[i][j]);
	if(sol==INF)
		cout<<"-1\n";
	else
		cout<<sol<<"\n";
	return 0;
}
