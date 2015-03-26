#include<iostream>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;
int n,v[110],best[750],pen[750],sol,pensol;
bitset <110> viz[750];

int main()
{
	int i,j,k,k1;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>v[i];
	sort(v+1,v+n+1);
	for(i=0;i<=9;i++)
		best[i]=pen[i]=0;
	for(i=10;i<=360;i++)
	{
		for(k=1;k<=n;k++)
		{
			if(i-10>=v[k])
			{
				for(j=i-v[k];j>=10;j--)
				{
					if(viz[j][k]==false)
					{
						if(best[j]+1>best[i])
						{
							for(k1=1;k1<=n;k1++)
								viz[i][k1]=viz[j][k1];
							viz[i][k]=true;
							best[i]=best[j]+1;
						}
					}
				}
			}
		}
		if(best[i]>sol)
		{
			sol=best[i];
			pensol=0;
		}
	}
	for(i=361;i<=720;i++)
	{
		for(k=1;k<=n;k++)
		{
			if(i-10>=v[k])
			{
				for(j=i-v[k];j>=10;j--)
				{
					if(viz[j][k]==false)
					{
						if(best[j]+1>best[i])
						{
							for(k1=1;k1<=n;k1++)
								viz[i][k1]=viz[j][k1];
							viz[i][k]=true;
							best[i]=best[j]+1;
							pen[i]=pen[j]+(i-360);
						}
						else
						{
							if(best[j]+1==best[i] && pen[i]>pen[j]+(i-360))
							{
								for(k1=1;k1<=n;k1++)
									viz[i][k1]=viz[j][k1];
								viz[i][k]=true;
								pen[i]=pen[j]+(i-360);
							}
						}
					}
				}
			}
		}
		if(best[i]>sol)
		{
			sol=best[i];
			pensol=pen[i];
		}
		else
		{
			if(best[i]==sol && pensol>pen[i])
				pensol=pen[i];
		}
	}
	cout<<sol<<' '<<pensol<<"\n";
	return 0;
}
