#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int n;
long long X,a[100100],sum,sol;

inline long long LgPut(long long baz,long long put)
{
	long long p=1LL;
	while(put)
	{
		if(put%2LL==1LL)
		{
			p=(1LL*p*baz)%MOD;
			put-=1LL;
		}
		baz=(1LL*baz*baz)%MOD;
		put/=2LL;
	}
	return p;
}

inline long long Putere(int aux)
{
	int rez=0;
	while(1LL*aux%X==0LL)
	{
		aux/=X;
		rez++;
	}
	return 1LL*rez;
}

int main()
{
	int i;
	long long now,nr;
	cin>>n>>X;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	nr=0;
	now=sum-a[n];
	for(i=n;i>0;i--)
	{
		a[i]=sum-a[i];
		if(a[i]==now)
			nr++;
		else
		{
			if(nr%X!=0LL)
				break;
			nr/=X;
			now++;
			while(nr%X==0LL && a[i]!=now)
			{
				nr/=X;
				now++;
			}
			if(a[i]!=now)
				break;
			nr++;
		}
	}
	while(nr%X==0LL)
	{
		nr/=X;
		now++;
	}
	sol=min(now,sum);
	cout<<LgPut(X,sol)<<"\n";
	return 0;
}
