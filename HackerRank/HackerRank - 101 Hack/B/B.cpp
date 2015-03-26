#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
int n,m,sol;
char mat[510][510];
int sus[510][510],st[510][510];
queue <int> Q;

int main()
{
	int i,j,k,p,last;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>(mat[i]+1);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mat[i][j]=='.')
			{
				sus[i][j]=sus[i-1][j]+1;
				st[i][j]=st[i][j-1]+1;
			}
		}
	}
	for(i=1;i<n;i++)
	{
		for(k=i+1;k<=n;k++)
		{
			for(j=1;j<=m;j++)
			{
				last=j-min(st[i][j],st[k][j])+1;
				while(!Q.empty() && Q.front()<last)
					Q.pop();
				if(sus[k][j]>=k-i+1)
				{
					if(!Q.empty())
					{
						p=Q.front();
						sol=max(sol,2*(k-i+j-p));
					}
					Q.push(j);
				}
			}
			while(!Q.empty())
				Q.pop();
		}
	}
	
	if(sol>0)
		cout<<sol<<"\n";
	else
		cout<<"impossible\n";
	return 0;
}
