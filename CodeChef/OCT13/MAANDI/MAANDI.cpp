#include<iostream>
using namespace std;
int T,n,f[100],e[100],nrf,sol;

inline bool Lucky(int x)
{
	while(x)
	{
		if(x%10==4 || x%10==7)
			return true;
		x/=10;
	}
	return false;
}

inline void Back(int pas,int F)
{
	if(pas==nrf+1)
	{
		if(Lucky(F))
			sol++;
		return;
	}
	Back(pas+1,F);
	int newF=F;
	for(int i=1;i<=e[pas];i++)
	{
		newF*=f[pas];
		Back(pas+1,newF);
	}
}

int main()
{
	int i,d;
	cin>>T;
	while(T--)
	{
		cin>>n;
		//descompun pe n in factori primi
		nrf=0;
		if(n%2==0)
		{
			f[++nrf]=2;
			while(n%2==0)
			{
				e[nrf]++;
				n/=2;
			}
		}
		for(d=3;d*d<=n;d+=2)
		{
			if(n%d==0)
			{
				f[++nrf]=d;
				while(n%d==0)
				{
					e[nrf]++;
					n/=d;
				}
			}
		}
		if(n>1)
		{
			f[++nrf]=n;
			e[nrf]=1;
		}
		//generez toti divizorii si ii contorizez pe cei potriviti
		sol=0;
		Back(1,1);
		cout<<sol<<"\n";
		for(i=1;i<=nrf;i++)
			f[i]=e[i]=0;
	}
	return 0;
}
