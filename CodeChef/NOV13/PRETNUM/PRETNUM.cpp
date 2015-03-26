#include<iostream>
#include<algorithm>
using namespace std;
int T,n,prime[500100],nrp;
long long L,R,sol,v[1000100];
bool ciur[1000100];

int main()
{
	int i,j;
	long long x,y;
	bool prim;
	prime[++nrp]=2;
	for(i=3;i<=1000000;i+=2)
	{
		if(!ciur[i])
		{
			prime[++nrp]=i;
			if(i<=1000)
				for(j=i*i;j<=1000000;j+=2*i)
					ciur[j]=true;
		}
	}
	for(i=1;i<=nrp;i++)
	{
		x=1LL*prime[i]*prime[i];
		j=2;
		while(x<=1000000000000LL)
		{
			if(j%2==0 && !ciur[1+j])
				v[++n]=x;
			x*=(1LL*prime[i]);
			j++;
		}
	}
	sort(v+1,v+n+1);
	v[++n]=1000000100000LL;
	prime[++nrp]=1000100;
	cin>>T;
	while(T--)
	{
		cin>>L>>R;
		sol=(upper_bound(v+1,v+n+1,R)-v)-(lower_bound(v+1,v+n+1,L)-v);
		for(i=0;i<=1000000;i++)
			ciur[i]=false;
		for(i=50000;i<nrp && prime[i]<=R;i++)
		{
			y=(L/(1LL*prime[i]))*(1LL*prime[i])+1LL*prime[i];
			while(y<=R)
			{
				ciur[y-L]=true;
				y+=1LL*prime[i];
			}
		}
		for(x=L;x<=R;x++)
		{
			if(x==1LL || ciur[x-L])
				continue;
			prim=true;
			for(i=1;1LL*prime[i]*prime[i]<=x;i++)
			{
				if(x%(1LL*prime[i])==0LL)
				{
					prim=false;
					i=nrp-1;
				}
			}
			if(prim)
				sol++;
		}
		cout<<sol<<"\n";
	}
	return 0;
}
