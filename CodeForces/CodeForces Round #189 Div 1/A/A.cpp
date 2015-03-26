#include<iostream>
#include<cstring>
#define MOD 1000000007
using namespace std;
int n,sol,doi[110];
char s[110];

int main()
{
	int i;
	cin>>s;
	n=strlen(s);
	doi[0]=1;
	for(i=1;i<=n;i++)
	{
		doi[i]=2*doi[i-1];
		while(doi[i]>=MOD)
			doi[i]-=MOD;
	}
	sol=((1LL*doi[n-1]*(doi[n]-1+MOD))%MOD);
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			sol=sol+MOD-((1LL*doi[n-i-1]*doi[n-1])%MOD);
			sol%=MOD;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
