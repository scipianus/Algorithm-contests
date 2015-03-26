#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int n,a[300100],sol,nrsol,rmq[20][300100],loga[300100];
set <int> v;

inline int GCD(int a,int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

inline int Query(int st,int dr)
{
	int lg=dr-st+1;
	int ex=loga[lg];
	int dif=lg-(1<<ex);
	return GCD(rmq[ex][st],rmq[ex][st+dif]);
}

inline int CautareBinaraSt(int ind)
{
	int st=1,dr=ind,mij,rez=ind;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		if(Query(mij,ind)==a[ind])
		{
			rez=mij;
			dr=mij-1;
		}
		else
			st=mij+1;
	}
	return rez;
}

inline int CautareBinaraDr(int ind)
{
	int st=ind,dr=n,mij,rez=ind;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		if(Query(ind,mij)==a[ind])
		{
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
	int i,j,st,dr;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)
	{
		cout<<"1 "<<(n-1)<<"\n";
		cout<<"1\n";
		return 0;
	}
	loga[1]=0;
	for(i=2;i<=n+1;i++)
		loga[i]=loga[i/2]+1;
	for(i=1;i<=n;i++)
		rmq[0][i]=a[i];
	for(j=1;(1<<j)<=n;j++)
		for(i=1;i+(1<<j)-1<=n;i++)
			rmq[j][i]=GCD(rmq[j-1][i],rmq[j-1][i+(1<<(j-1))]);
	for(i=1;i<=n;i++)
	{
		st=CautareBinaraSt(i);
		dr=CautareBinaraDr(i);
		if(dr-st==sol)
			v.insert(st);
		else
			if(dr-st>sol)
			{
				sol=dr-st;
				v.clear();
				v.insert(st);
			}
	}
	
	nrsol=v.size();
	cout<<nrsol<<' '<<sol<<"\n";
	for(i=0;i<nrsol;i++)
	{
		cout<<*v.begin()<<"\n";
		v.erase(v.begin());
	}
	cout<<"\n";
	return 0;
}
