#include<iostream>
using namespace std;
long long n,K,sum;

inline long long Sum(long long val)
{
	return val*(val+1LL)/2LL;
}

inline long long CautareBinara()
{
	long long st,dr,mij;
	bool gasit=false;
	st=1LL;
	dr=K;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		if(Sum(K)-Sum(mij-1LL)<=n)
		{
			gasit=true;
			dr=mij-1LL;
		}
		else
			st=mij+1LL;
	}
	if(!gasit)
		return 0LL;
	return st;
}

inline long long Solve()
{
	long long rez=0,p;
	while(n>0LL)
	{
		if(K==0LL)
			return -1LL;
		if(Sum(K)==n)
		{
			rez+=K;
			return rez;
		}
		if(Sum(K)>n)
		{
			p=CautareBinara();
			if(p>=1LL)
			{
				n-=(Sum(K)-Sum(p-1));
				rez+=K-p+1LL;
				K=p-1LL;
			}
			else
			{
				rez+=1LL;
				return rez;
			}
		}
		else
			return -1LL;
	}
	return rez;
}

int main()
{
	cin>>n>>K;
	n=n-1LL;
	K=K-1LL;
	sum=K*(K+1LL)/2LL;
	if(sum<n)
		cout<<"-1\n";
	else
		cout<<Solve();
	return 0;
}
