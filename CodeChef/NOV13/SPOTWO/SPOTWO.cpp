#include<iostream>
#define MOD 1000000007
using namespace std;
int T,n;
unsigned long long P;

inline int Solve(unsigned long long put)
{
	int p=1,baz=2;
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
	p=(1LL*p*p)%MOD;
	return p;
}

int main()
{
	int i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		P=0LL;
		for(i=20;i>=0;i--)
		{
			if(n&(1<<i))
				P=P*10LL+1LL;
			else
				P=P*10LL;
		}
		cout<<Solve(P)<<"\n";
	}
	return 0;
}
