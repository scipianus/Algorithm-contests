#include<iostream>
#include<cmath>
using namespace std;
long long N,aux;
int f[10000],e[10000],nrf;

inline long long Sqrt()
{
	long long st,dr,m;
	st=0LL;
	dr=3170000LL;
	while(st<=dr)
	{
		m=(st+dr)/2LL;
		if(m*m<=N && (m+1LL)*(m+1LL)>N)
			return m;
		if(m*m<=N)
			st=m+1LL;
		else
			dr=m-1LL;
	}
	return 0LL;
}

int main()
{
	int i,lim;
	cin>>N;
	aux=N;
	if(N==1)
	{
		cout<<"1\n0\n";
		return 0;
	}
	if(N==2)
	{
		cout<<"1\n0\n";
		return 0;
	}
	if(N%2==0)
	{
		f[++nrf]=2;
		while(N%2LL==0)
		{
			N=N/2LL;
			e[1]++;
		}
	}
	lim=(int)Sqrt();
	for(i=3;i<=lim && N>1LL;i+=2)
	{
		if(N%(long long)i==0)
		{
			f[++nrf]=i;
			while(N%(long long)i==0LL)
			{
				N=N/(long long)i;
				e[nrf]++;
			}
			lim=(int)Sqrt();
		}
	}
	if(nrf==0)
	{
		cout<<"1\n0\n";
		return 0;
	}
	if(N>1LL)
	{
		nrf++;
		e[nrf]=1;
	}
	if(nrf==1 && e[1]==2)
	{
		cout<<"2\n";
		return 0;
	}
	if(nrf==2 && e[1]==1 && e[2]==1)
	{
		cout<<"2\n";
		return 0;
	}
	long long sol;
	sol=(long long)f[1];
	if(e[1]>1)
		sol*=sol;
	else
	{
		if(f[2]==0)
			sol*=N;
		else
			sol*=(long long)f[2];
	}
	cout<<"1\n"<<sol<<"\n";
	return 0;
}
