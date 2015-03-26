#include<iostream>
#include<cmath>
using namespace std;
int N,K,sol=2000000100;

inline bool Bun(int v)
{
	int nr=0,k=1;
	while(nr<N && (v/k)!=0)
	{
		nr+=(v/k);
		k*=K;
	}
	if(nr>=N)
		return true;
	return false;
}

inline void CautareBinara()
{
	int st,dr,mij;
	st=0;
	dr=N;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		if(Bun(mij)==true)
		{
			sol=min(sol,mij);
			dr=mij-1;
		}
		else
			st=mij+1;
	}
}

int main()
{
	cin>>N>>K;
	CautareBinara();
	cout<<sol<<"\n";
	return 0;
}
