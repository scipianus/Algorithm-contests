#include<iostream>
using namespace std;
int n,K,v[300100],valmin=1000000000;

inline bool Posibil(int gcd)
{
	int i;
	for(i=1;i<=n;i++)
		if(v[i]%gcd>K)
			return false;
	return true;
}

inline int CautareBinara()
{
	int i,st,dr,mij,rez=1;
	bool ok;
	st=1;
	dr=valmin;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		ok=false;
		for(i=0;i<=10;i++)
			if(mij+i<=dr)
				ok|=Posibil(mij+i);
		if(ok)
		{
			if(Posibil(mij))
				rez=mij;
			st=mij+1;
		}
		else
			dr=mij-1;
	}
	return rez;
}

int main()
{
	int i;
	cin>>n>>K;
	for(i=1;i<=n;i++)
	{
		cin>>v[i];
		valmin=min(valmin,v[i]);
	}
	cout<<CautareBinara()<<"\n";
	return 0;
}
