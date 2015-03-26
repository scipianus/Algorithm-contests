#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
long long K,d[1010],f[1010],sol;

int main()
{
	int i;
	cin>>m>>K;
	n=m+1;
	for(i=1;i<=m;i++)
		cin>>d[i];
	for(i=1;i<=m;i++)
		cin>>f[i];
	
	long long now=f[1],maxim=f[1];
	i=1;
	while(i<n)
	{
		while(now<d[i])
		{
			sol+=K;
			now+=maxim;
		}
		sol+=d[i];
		now-=d[i];
		i++;
		now+=f[i];
		maxim=max(maxim,f[i]);
	}
	
	cout<<sol<<"\n";
	return 0;
}
