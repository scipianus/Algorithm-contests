#include<iostream>
#include<cstring>
using namespace std;
int n,K;
char s[500100],Sol[500100];
int best[500100][27],pred[500100][27],sol=2000000000;

int main()
{
	int i,j,k;
	bool ok;
	cin>>n>>K;
	cin>>(s+1);
	for(i=0;i<K;i++)
		best[1][i]=1;
	best[1][s[1]-'A']=0;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<K;j++)
		{
			best[i][j]=2000000000;
			for(k=0;k<K;k++)
			{
				if(j!=k)
				{
					if(s[i]-'A'==j)
					{
						if(best[i][j]>best[i-1][k])
						{
							best[i][j]=best[i-1][k];
							pred[i][j]=k;
						}
					}
					else
					{
						if(best[i][j]>best[i-1][k]+1)
						{
							best[i][j]=best[i-1][k]+1;
							pred[i][j]=k;
						}
					}
				}
			}
		}
	}
	for(i=0;i<K;i++)
		sol=min(sol,best[n][i]);
	cout<<sol<<"\n";
	ok=true;
	for(j=0;j<K && ok;j++)
	{
		if(best[n][j]==sol)
		{
			Sol[n]=(char)(j+'A');
			if(s[n]-'A'!=j)
				sol--;
			ok=false;
			k=pred[n][j];
		}
	}
	for(i=n-1;i>0;i--)
	{
		Sol[i]=(char)(k+'A');
		k=pred[i][k];
	}
	cout<<(Sol+1)<<"\n";
	return 0;
}
