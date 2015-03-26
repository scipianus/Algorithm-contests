#include<iostream>
#include<cassert>
#define MOD 1000000007
using namespace std;
int n,K,v[1000100],cod[1000100],sol,aib[100100];
bool exista[1000100];

inline void Update(int poz,int val)
{
	while(poz<=K)
	{
		aib[poz]=min(aib[poz],val);
		poz+=(poz & -poz);
	}
}

inline int Query(int poz)
{
	int rz=n+1;
	while(poz>0)
	{
		rz=min(rz,aib[poz]);
		poz-=(poz & -poz);
	}
	return rz;
}

int main()
{
	int i,j;
	cin>>n>>K;
	for(i=1;i<=n;i++)
	{
		cin>>v[i];
		exista[v[i]]=true;
		assert(v[i]<=1000000);
	}
	for(i=1,j=1;i<=1000000;i++)
	{
		if(exista[i])
		{
			cod[i]=j;
			j++;
		}
	}
	for(i=1;i<=n;i++)
		v[i]=cod[v[i]];
	for(i=1;i<=K;i++)
		aib[i]=n+1;
	sol=1;
	for(i=n;i>0;i--)
	{
		if(v[i]>1)
		{
			j=Query(v[i]-1);
			if(j!=n+1)
				sol=(1LL*sol*(j-i+1))%MOD;
		}
		Update(v[i],i);
	}
	cout<<sol<<"\n";
	return 0;
}
