#include<iostream>
#include<algorithm>
using namespace std;
int n,v[100100];

inline bool Posibil(long long m)
{
	int i;
	long long cover=0LL;
	for(i=n;i>0;i--)
	{
		cover+=(m-1LL*v[i]);
		if(cover>=m)
			return true;
	}
	return false;
}

inline long long CautareBinara()
{
	long long st,dr,mij,rez;
	st=1LL*v[n];
	dr=rez=200000000000000LL;
	while(st<=dr)
	{
		mij=(st+dr)/2LL;
		if(Posibil(mij))
		{
			rez=mij;
			dr=mij-1LL;
		}
		else
			st=mij+1LL;
	}
	return rez;
}

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>v[i];
	sort(v+1,v+n+1);
	cout<<CautareBinara()<<"\n";
	return 0;
}
