#include<iostream>
#include<cmath>
using namespace std;
int T;
long long A,B,C;

inline long long GCD(long long x,long long y)
{
	long long r;
	while(y)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}

int main()
{
	int cmmdc;
	long long x,y;
	cin>>T;
	while(T--)
	{
		cin>>A>>B>>C;
		if(A+B<=C)
			x=y=1LL;
		else
		{
			x=C*C*100LL/2LL;
			if(C>A)
				x-=(C-A)*(C-A)*100LL/2LL;
			if(C>B)
				x-=(C-B)*(C-B)*100LL/2LL;
			y=A*B*100LL;
			cmmdc=GCD(x,y);
			x/=cmmdc;
			y/=cmmdc;
		}
		cout<<x<<'/'<<y<<"\n";
	}
	return 0;
}
