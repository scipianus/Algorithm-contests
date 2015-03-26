#include<iostream>
using namespace std;
long long n,m,xc,yc,K,pasi;
long long dx,dy,sol;

inline void CautareBinara()
{
	long long st,dr,mij;
	long long dx1,dy1;
	st=0;
	dr=1000000000;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		dx1=xc+mij*dx;
		dy1=yc+mij*dy;
		if(dx1>=1LL && dx1<=n && dy1>=1LL && dy1<=m)
		{
			if(pasi<=mij)
				pasi=mij;
			st=mij+1;
		}
		else
			dr=mij-1;
	}
}

int main()
{
	int i;
	cin>>n>>m;
	cin>>xc>>yc;
	cin>>K;
	for(i=1;i<=K;i++)
	{
		cin>>dx>>dy;
		pasi=0LL;
		CautareBinara();
		xc=xc+pasi*dx;
		yc=yc+pasi*dy;
		sol+=pasi;
	}
	cout<<sol<<"\n";
	return 0;
}
