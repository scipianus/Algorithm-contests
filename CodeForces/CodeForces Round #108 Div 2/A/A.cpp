#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,maxim[150],sol;
char s[110][110];

int main()
{
	int i,j;
	bool gata;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>(s[i]+1);
		for(j=1;j<=m;j++)
		{
			maxim[j]=max(maxim[j],s[i][j]-'0');
		}
	}
	for(i=1;i<=n;i++)
	{
		gata=false;
		for(j=1;j<=m && !gata;j++)
		{
			if(s[i][j]-'0'==maxim[j])
			{
				sol++;
				gata=true;
			}
		}
	}
	cout<<sol<<"\n";
	return 0;
}
