#include<iostream>
using namespace std;
int T;
long long n,d,m;

long long Cmmdc(long long a,long long b)
{
	long long r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n==1)
			cout<<3<<"\n";
		else
		{
			d=Cmmdc(n*4LL,n+1);
			m=n;
			m*=4LL;
			m*=(n+1);
			m/=d;
			m/=(n+1);
			m++;
			cout<<m<<"\n";
		}
	}
	return 0;
}
