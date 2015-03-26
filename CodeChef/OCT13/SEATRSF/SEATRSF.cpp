#include<iostream>
#define MOD 1000000007
using namespace std;
int T,n,m,dif,sol;

inline int LgPut(int baz,int put)
{
	int p=1;
	while(put>0)
	{
		if(put%2==1)
		{
			p=(1LL*p*baz)%MOD;
			put--;
		}
		baz=(1LL*baz*baz)%MOD;
		put/=2;
	}
	return p;
}

int main()
{
	int aux;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>dif>>aux;
		if(m<=dif)
			cout<<"0\n";
		else
		{
			sol=(1LL*LgPut(dif+1,n)-(2LL*LgPut(dif,n))%MOD+1LL*LgPut(dif-1,n)+2LL*MOD)%MOD;
			sol=(1LL*(m-dif)*sol)%MOD;
			cout<<sol<<"\n";
		}
	}
	return 0;
}
