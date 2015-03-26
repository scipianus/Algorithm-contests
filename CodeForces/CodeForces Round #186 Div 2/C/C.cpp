#include<iostream>
#include<algorithm>
using namespace std;
int n,m,v[2000100],put[25];
long long sol,sum[2000100];

inline bool Sortare(int a,int b)
{
	return a>b;
}

int main()
{
	int i,aux,poz;
	cin>>m;
	for(i=1;i<=m;i++)
		cin>>v[i];
	sort(v+1,v+m+1,Sortare);
	aux=m;
	while(aux>1)
	{
		n++;
		aux/=4;
	}
	put[0]=1;
	for(i=1;i<=22;i++)
		put[i]=put[i-1]*4;
	poz=0;
	for(i=1;i<=m;i++)
	{
		sum[i]=sum[i-1]+1LL*v[i];
		if(i==put[poz])
		{
			sol+=sum[i];
			poz++;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
