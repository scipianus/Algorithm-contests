#include<iostream>
#include<cmath>
using namespace std;
long long P,D;
long long v[20];

inline int Nrcif(long long x)
{
	if(x==0)
		return 1;
	int nr=0;
	while(x)
	{
		x/=10LL;
		nr++;
	}
	return nr;
}

int main()
{
	int i;
	long long x1,x2;
	double y;
	cin>>P>>D;
	v[1]=9;
	for(i=2;i<=18;i++)
		v[i]=v[i-1]*10LL+9LL;
	for(i=18;i>0;i--)
	{
		if(P<v[i])
			continue;
		x1=P-v[i]-D;
		y=(double)x1;
		y/=(double)(v[i]+1LL);
		x1=(long long)y;
		
		x2=P-v[i];
		y=(double)x2;
		y/=(double)(v[i]+1LL);
		x2=(long long)y;
		
		if(x1>x2)
			continue;
		x2*=(long long)(v[i]+1LL);
		x2+=v[i];
		if(P-x2<=D)
		{
			cout<<x2<<"\n";
			return 0;
		}
	}
	cout<<P<<"\n";
	return 0;
}
