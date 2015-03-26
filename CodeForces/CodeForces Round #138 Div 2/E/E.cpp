#include<iostream>
#include<cstring>
#define MOD 1000000007
using namespace std;
int n,K,size;
int v[2010];
long long C[2010];
long long sol[2010];

long long ModN(long long x)
{
	long long a=x%MOD;
	if(a<0)
		return (a+MOD);
	return a;
}

void Euclid_extins(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	else
	{
		Euclid_extins(b,a%b,x,y);
		int aux,q=a/b;
		aux=x;
		x=y;
		y=aux-y*q;
	}
}

inline void Combinari()
{
	long long i,j,f,inv,aux;
	for(i=1;i<=n;i++)
	{
		C[i]=1LL;
		for(j=K;j<=i+K-2;j++)
		{
			C[i]*=j;
			C[i]%=MOD;
		}
		f=1LL;
		for(j=2;j<i;j++)
		{
			f*=j;
			f%=MOD;
		}
		inv=aux=0LL;
		Euclid_extins(f,MOD,inv,aux);
		inv=ModN(inv);
		C[i]*=inv;
		C[i]%=MOD;
	}
}

int main()
{
	int i,j;
	cin>>n>>K;
	for(i=1;i<=n;i++)
		cin>>v[i];
	if(K==0)
	{
		for(i=1;i<=n;i++)
			cout<<v[i]<<' ';
		cout<<"\n";
		return 0;
	}
	Combinari();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			sol[i]+=C[i-j+1]*(long long)v[j];
			sol[i]%=MOD;
		}
	}
	for(i=1;i<=n;i++)
		cout<<sol[i]<<' ';
	cout<<"\n";
	return 0;
}
