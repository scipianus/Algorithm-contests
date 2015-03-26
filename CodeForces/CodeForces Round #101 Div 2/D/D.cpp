#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,L,best[100100],sol=2000000000,nrsol;
struct Interval{int st,dr,t,nr;};
vector <Interval> v,v2;
int Sol[100100],list[100100];

inline bool Sortare(Interval A,Interval B)
{
	return A.st>B.st;
}

int main()
{
	int i,j,st,dr,nr;
	int x,d,t,p;
	long long T;
	Interval aux,poz;
	cin>>n>>L;
	for(i=1;i<=n;i++)
	{
		cin>>x>>d>>t>>p;
		aux.st=x-p;
		aux.dr=x+d;
		aux.t=t+p;
		if(aux.st<0 || aux.dr>L || aux.t>=(aux.dr-aux.st))
			continue;
		aux.nr=i;
		v.push_back(aux);
	}
	make_heap(v.begin(),v.end(),Sortare);
	while(v.size())
	{
		aux=v[0];
		pop_heap(v.begin(),v.end(),Sortare);
		v.pop_back();
		
		st=0;
		dr=aux.dr;
		T=aux.st+aux.t;
		nr=0;
		list[++nr]=aux.nr;
		
		while(v.size())
		{
			poz=v[0];
			pop_heap(v.begin(),v.end(),Sortare);
			v.pop_back();
			if(poz.st>=dr)
			{
				T+=(poz.st-dr)+poz.t;
				dr=poz.dr;
				list[++nr]=poz.nr;
			}
			else
			{
				if(poz.dr>=dr && T+(poz.dr-dr)>T+dr-poz.st+poz.t)
				{
					T+=dr-poz.st+poz.t;
					dr=poz.dr;
					list[++nr]=poz.nr;
				}
				else
				{
					v2.push_back(poz);
					push_heap(v2.begin(),v2.end(),Sortare);
				}
			}
		}
		T+=L-dr;
		if(sol>T)
		{
			sol=T;
			nrsol=nr;
			for(j=1;j<=nrsol;j++)
				Sol[j]=list[j];
		}
		while(v2.size())
		{
			poz=v2[0];
			pop_heap(v2.begin(),v2.end(),Sortare);
			v2.pop_back();
			v.push_back(poz);
		}
		make_heap(v.begin(),v.end(),Sortare);
	}
	if(sol>L)
	{
		cout<<L<<"\n"<<0<<"\n";
		return 0;
	}
	cout<<sol<<"\n";
	cout<<nrsol<<"\n";
	for(i=1;i<=nrsol;i++)
		cout<<Sol[i]<<' ';
	cout<<"\n";
	return 0;
}
