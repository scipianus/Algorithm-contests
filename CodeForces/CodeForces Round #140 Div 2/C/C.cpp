#include<iostream>
using namespace std;
int n;
long long MOD,sol;

inline long long LgPut(long long x,int put)
{
	long long p=1LL;
	while(put)
	{
		if(put%2==1)
		{
			p=p*x;
			p=p%MOD;
			put--;
		}
		x=x*x;
		x=x%MOD;
		put/=2;
	}
	return p;
}

int main()
{
	cin>>n>>MOD;
	sol=LgPut(3LL,n);
	sol--;
	if(sol<0)
		sol+=MOD;
	cout<<sol<<"\n";
	return 0;
}
