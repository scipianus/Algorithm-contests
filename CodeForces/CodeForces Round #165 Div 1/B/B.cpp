#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ns,V[5010],v[5010],nr[5010],sum,sol,nr2[5010];
double poz[5010];
bool viz[5010];

int main()
{
	int i,now=1;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d %lf",v+i,poz+i);
		nr[v[i]]++;
	}
	sum=nr[1];
	for(i=1;i<=n;i++)
	{
		while(i>sum)
		{
			now++;
			sum+=nr[now];
		}
		if(v[i]!=now)
			nr2[v[i]]++;
	}
	sort(nr2+1,nr2+m+1);
	for(i=1;i<m;i++)
		sol+=nr2[i];
	
	printf("%d\n",sol);
	return 0;
}
