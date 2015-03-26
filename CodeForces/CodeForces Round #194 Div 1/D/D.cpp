#include<iostream>
#include<cmath>
using namespace std;
int n,m,sol;
int mat[1010][1010];

int main()
{
	int i,j,k,minim;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>mat[i][j];
	sol=min(min(mat[1][1],mat[1][m]),min(mat[n][1],mat[n][m]));
	for(i=n-1;i>0;i--)
	{
		for(k=n;k>i;k--)
		{
			minim=min(mat[i][1],mat[k][1]);
			for(j=2;j<=m;j++)
			{
				sol=max(sol,min(min(mat[i][j],mat[k][j]),minim));
				minim=max(minim,min(mat[i][j],mat[k][j]));
			}
		}
	}
	cout<<sol<<"\n";
	return 0;
}
