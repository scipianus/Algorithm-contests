#include<iostream>
#define INF 1000000000
using namespace std;
int n,A[22][22],bestmin[22][22][22][22],bestmax[22][22][22][22];
char mat[22][22];

int main()
{
	int lg,i,j,ii,jj;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>(mat[i]+1);
		for(j=1;j<=n;j++)
		{
			if(mat[i][j]=='a')
				A[i][j]=1;
			if(mat[i][j]=='b')
				A[i][j]=-1;
		}
	}
	for(i=0;i<=n+1;i++)
		for(j=0;j<=n+1;j++)
			for(ii=0;ii<=n+1;ii++)
				for(jj=0;jj<=n+1;jj++)
				{
					bestmin[i][j][ii][jj]=INF;
					bestmax[i][j][ii][jj]=-INF;
				}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			bestmin[i][j][i][j]=bestmax[i][j][i][j]=A[i][j];
	for(lg=1;lg<2*n;lg++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(ii=i;ii<=n;ii++)
				{
					jj=lg-(ii-i)+j;
					if(jj<j || jj>n)
						continue;
					if(i+1<=ii && j+1>jj)
					{
						bestmin[i][j][ii][jj]=min(bestmin[i][j][ii][jj],max(bestmax[i+1][j][ii][jj]+A[i][j],bestmax[i][j][ii-1][jj]+A[ii][jj]));
						bestmax[i][j][ii][jj]=max(bestmax[i][j][ii][jj],min(bestmin[i+1][j][ii][jj]+A[i][j],bestmin[i][j][ii-1][jj]+A[ii][jj]));
					}
					if(j+1<=jj && i+1>ii)
					{
						bestmin[i][j][ii][jj]=min(bestmin[i][j][ii][jj],max(bestmax[i][j+1][ii][jj]+A[i][j],bestmax[i][j][ii][jj-1]+A[ii][jj]));
						bestmax[i][j][ii][jj]=max(bestmax[i][j][ii][jj],min(bestmin[i][j+1][ii][jj]+A[i][j],bestmin[i][j][ii][jj-1]+A[ii][jj]));
					}
					if(i+1<=ii && j+1<=jj)
					{
						bestmin[i][j][ii][jj]=min(bestmin[i][j][ii][jj],max(max(bestmax[i+1][j][ii][jj],bestmax[i][j+1][ii][jj])+A[i][j],max(bestmax[i][j][ii-1][jj],bestmax[i][j][ii][jj-1])+A[ii][jj]));
						bestmax[i][j][ii][jj]=max(bestmax[i][j][ii][jj],min(min(bestmin[i+1][j][ii][jj],bestmin[i][j+1][ii][jj])+A[i][j],min(bestmin[i][j][ii-1][jj],bestmin[i][j][ii][jj-1])+A[ii][jj]));
					}
				}
			}
		}
	}
	if(bestmax[1][1][n][n]>0)
		cout<<"FIRST\n";
	else
	{
		if(bestmax[1][1][n][n]<0)
			cout<<"SECOND\n";
		else
			cout<<"DRAW\n";
	}
	return 0;
}
