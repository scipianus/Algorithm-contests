#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int T,n;
long long lim=10000000000000000LL,sol;
long long fib[1100],A,B,N;
int nrfib;

inline int CautareBinara(long long x)
{
	int st,dr,mij,rez=100000;
	st=0;
	dr=nrfib;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		if(fib[mij]>=x)
		{
			rez=min(rez,mij);
			dr=mij-1;
		}
		else
			st=mij+1;
	}
	return rez;
}

inline long long Dist(int ord,long long nod,long long x)
{
	if(nod==x)
		return 0LL;
	if(ord<=2)
		return 1LL;
	int poz1=CautareBinara(nod),poz2=CautareBinara(x);
	if(poz1!=poz2)
		return 1LL+Dist(ord-2,nod-fib[ord-1],1LL)+Dist(ord-1,x,1LL);
	return Dist(ord-2,nod-fib[ord-1],1LL)+Dist(ord-1,x,1LL);
}

int main()
{
	cin>>T>>n;
	
	fib[0]=1LL; fib[1]=2LL;
	nrfib=1;
	while(fib[nrfib]<lim && nrfib<n)
	{
		nrfib++;
		fib[nrfib]=fib[nrfib-1]+fib[nrfib-2];
	}
	nrfib++;
	fib[nrfib]=fib[nrfib-1]+fib[nrfib-2];
	
	int poz1,poz2;
	while(T--)
	{
		cin>>A>>B;
		if(A<=3 && B<=3)
		{
			cout<<1<<"\n";
			continue;
		}
		if(A>B)
			swap(A,B);
		poz1=CautareBinara(A);
		poz2=CautareBinara(B);
		sol=Dist(poz2,B,A);
		cout<<sol<<"\n";
	}
	return 0;
}
