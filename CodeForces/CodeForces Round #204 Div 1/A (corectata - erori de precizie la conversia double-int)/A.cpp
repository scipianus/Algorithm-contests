#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int v[4010],sum,sol=2000000000;

int main()
{
	int i,nr0=0;
	double x;
	cin>>n;
	for(i=1;i<=2*n;i++)
	{
		cin>>x;
		x*=1000.0;
		v[i]=(int)(x+0.0001);
		v[i]%=1000;
		sum+=v[i];
		if(v[i]==0)
			nr0++;
	}
	if(nr0>=n)
	{
		for(i=1;i<=2*n-nr0;i++)
		{
			sol=min(sol,abs(sum));
			sum-=1000;
		}
		sol=min(sol,abs(sum));
	}
	else
	{
		sum-=1000*(n-nr0);
		for(i=1;i<=nr0;i++)
		{
			sol=min(sol,abs(sum));
			sum-=1000;
		}
		sol=min(sol,abs(sum));
	}
	printf("%.3lf\n",1.0*sol/1000.0);
	return 0;
}
