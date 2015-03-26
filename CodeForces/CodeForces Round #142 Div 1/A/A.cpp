#include<iostream>
#include<cmath>
using namespace std;
int n,m,sol=2000000000;
char mat[110][10100];
int st[110][10100],dr[110][10100];

int main()
{
	int i,j,now;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>(mat[i]+1);
	for(i=1;i<=n;i++)
	{
		if(mat[i][1]=='1')
			st[i][1]=0;
		else
		{
			j=m;
			while(j>1 && mat[i][j]!='1')
				j--;
			if(j>1)
				st[i][1]=m-j+1;
			else
			{
				cout<<"-1\n";
				return 0;
			}
		}
		for(j=2;j<=m;j++)
		{
			if(mat[i][j]=='1')
				st[i][j]=0;
			else
				st[i][j]=st[i][j-1]+1;
		}
		if(mat[i][m]=='1')
			dr[i][m]=0;
		else
		{
			j=1;
			while(j<m && mat[i][j]!='1')
				j++;
			if(j<m)
				dr[i][m]=j;
			else
			{
				cout<<"-1\n";
				return 0;
			}
		}
		for(j=m-1;j>0;j--)
		{
			if(mat[i][j]=='1')
				dr[i][j]=0;
			else
				dr[i][j]=dr[i][j+1]+1;
		}
	}
	for(j=1;j<=m;j++)
	{
		now=0;
		for(i=1;i<=n;i++)
			now+=min(st[i][j],dr[i][j]);
		sol=min(sol,now);
	}
	cout<<sol<<"\n";
	return 0;
}
