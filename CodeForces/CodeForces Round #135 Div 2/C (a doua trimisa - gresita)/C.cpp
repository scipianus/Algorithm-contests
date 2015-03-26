#include<iostream>
#include<cstring>
using namespace std;
int n,K;
char s[500100],Sol[500100];
int best[500100][27],pred[500100][27],sol=2000000000;
int minim[500100][3];

int main()
{
	int i,j,k;
	bool ok;
	cin>>n>>K;
	cin>>(s+1);
	if(K>2)
	{
		for(i=0;i<K;i++)
			best[1][i]=1;
		best[1][s[1]-'A']=0;
		minim[1][0]=s[1]-'A';
		minim[1][1]=-1;
		for(i=0;i<K;i++)
		{
			if(best[1][i]==1)
			{
				if(minim[1][1]==-1)
					minim[1][1]=i;
				else
					minim[1][2]=i;
			}
		}
		for(i=2;i<=n;i++)
		{
			minim[i][0]=minim[i][1]=minim[i][2]=2000000000;
			for(j=0;j<K;j++)
			{
				best[i][j]=2000000000;
				if(s[i]-'A'!=j)
				{
					for(k=0;k<3;k++)
					{
						if(j!=minim[i-1][k])
						{
							if(best[i][j]>best[i-1][minim[i-1][k]]+1)
							{
								best[i][j]=best[i-1][minim[i-1][k]]+1;
								pred[i][j]=minim[i-1][k];
							}
						}
					}
				}
				else
				{
					for(k=0;k<3;k++)
					{
						if(j!=minim[i-1][k])
						{
							if(best[i][j]>best[i-1][minim[i-1][k]])
							{
								best[i][j]=best[i-1][minim[i-1][k]];
								pred[i][j]=minim[i-1][k];
							}
						}
					}
				}
				if(best[i][j]<minim[i][0])
				{
					minim[i][2]=minim[i][1];
					minim[i][1]=minim[i][0];
					minim[i][0]=j;
				}
				else
				{
					if(best[i][j]<minim[i][1])
					{
						minim[i][2]=minim[i][1];
						minim[i][1]=j;
					}
					else
					{
						if(best[i][j]<minim[i][2])
							minim[i][2]=j;
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
	}
	else
	{
		int x1=0,x2=0;
		for(i=1;i<=n;i++)
		{
			if(i%2==1)
			{
				if(s[i]!='A')
					x1++;
				else
					x2++;
			}
			else
			{
				if(s[i]!='A')
					x2++;
				else
					x1++;
			}
		}
		if(x1<x2)
		{
			cout<<x1<<"\n";
			for(i=1;i<=n;i++)
			{
				if(i%2==1)
					cout<<'A';
				else
					cout<<'B';
			}
			cout<<"\n";
		}
		else
		{
			cout<<x2<<"\n";
			for(i=1;i<=n;i++)
			{
				if(i%2==1)
					cout<<'B';
				else
					cout<<'A';
			}
			cout<<"\n";
		}
	}
	return 0;
}
