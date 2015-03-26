#include<iostream>
#define MOD 1000000007
using namespace std;
int T,n;

inline int Solve(int put)
{
	int rez=1,baz=2;
	while(put)
	{
		if(put%2==1)
		{
			rez=(1LL*rez*baz)%MOD;
			put--;
		}
		baz=(1LL*baz*baz)%MOD;
		put/=2;
	}
	rez--;
	if(rez<0)
		rez+=MOD;
	return rez;
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<Solve(n)<<"\n";
	}
	return 0;
}
