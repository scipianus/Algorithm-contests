#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int T,n,m,v[255],nr[255],total;
map <int,int> fr;

inline void Prelucrare()
{
	int i,X=0;
	for(i=1;i<=m;i++)
	{
		fr[v[i]]++;
		if(fr[v[i]]>X)
			X=fr[v[i]];
	}
	total++;
	nr[X]++;
	fr.clear();
}

inline void Back(int k)
{
	if(k==m+1)
		Prelucrare();
	else
	{
		int i;
		for(i=v[k-1];i<=n;i++)
		{
			v[k]=i;
			Back(k+1);
		}
	}
}

int main()
{
	int i;
	double sol;
	v[0]=1;
	cin>>T;
	while(T--)
	{
		cin>>m>>n;
		Back(1);
		sol=0.0;
		for(i=1;i<=m;i++)
			sol+=(1.0*i*nr[i])/(1.0*total);
		printf("%.6lf\n",sol);
		for(i=1;i<=m;i++)
			nr[i]=0;
		total=0;
	}
	return 0;
}
