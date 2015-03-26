#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,sol=2000000000;
char s[2010],u[2010];

int main()
{
	int i,j,k,lim,nr;
	cin>>(s+1); n=strlen(s+1);
	cin>>(u+1); m=strlen(u+1);
	if(n>=m)
	{
		lim=n-m+1;
		for(i=1;i<=lim;i++)
		{
			nr=0;
			for(j=1,k=i;j<=m;j++,k++)
			{
				if(s[k]!=u[j])
					nr++;
			}
			sol=min(sol,nr);
		}
	}
	else
	{
		lim=m-n+1;
		for(i=1;i<=lim;i++)
		{
			nr=m-n;
			for(j=1,k=i;j<=n;j++,k++)
			{
				if(u[k]!=s[j])
					nr++;
			}
			sol=min(sol,nr);
		}
	}
	cout<<sol<<"\n";
	return 0;
}
