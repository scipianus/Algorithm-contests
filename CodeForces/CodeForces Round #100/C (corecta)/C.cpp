#include<iostream>
#include<algorithm>
using namespace std;
int n,r[100100],sol,a[100100];
struct Sol{int x,y,z;};
Sol v[40000];

inline bool Bun(int k)
{
	int i,nr=0,x=r[1],vf=0;
	for(i=1;i<=n;i++)
	{
		if(r[i]==x)
		{
			nr++;
			if(nr<=k)
				a[++vf]=x;
		}
		else
		{
			x=r[i];
			nr=1;
			a[++vf]=x;
		}
	}
	if(vf<3*k)
		return false;
	return true;
}

inline void CautareBinara()
{
	int st,dr,m;
	st=1;
	dr=n/3;
	while(st<=dr)
	{
		m=(st+dr)/2;
		if(Bun(m))
		{
			sol=max(sol,m);
			st=m+1;
		}
		else
			dr=m-1;
	}
}

void Afisare()
{
	cout<<sol<<"\n";
	int i,nr=0,x=r[1],vf=0;
	for(i=1;i<=n;i++)
	{
		if(r[i]==x)
		{
			nr++;
			if(nr<=sol)
				a[++vf]=x;
		}
		else
		{
			x=r[i];
			nr=1;
			a[++vf]=x;
		}
	}
	for(i=1;i<=sol;i++)
	{
		cout<<a[2*sol+i]<<' '<<a[sol+i]<<' '<<a[i]<<"\n";
	}
}

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>r[i];
	
	sort(r+1,r+n+1);
	CautareBinara();
	
	Afisare();
	return 0;
}
