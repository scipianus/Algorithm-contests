#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,K;
int mat[1010][1010],X[1010],Y[1010];

inline void Swap(int &x,int &y)
{
	x^=y^=x^=y;
}

int main()
{
	int i,j,x,y;
	char op;
	cin>>n>>m>>K;
	for(i=1;i<=n;i++)
	{
		X[i]=i;
		for(j=1;j<=m;j++)
		{
			Y[j]=j;
			cin>>mat[i][j];
		}
	}
	for(i=1;i<=K;i++)
	{
		cin>>op>>x>>y;
		if(op=='r')
			Swap(X[x],X[y]);
		if(op=='c')
			Swap(Y[x],Y[y]);
		if(op=='g')
			cout<<mat[X[x]][Y[y]]<<"\n";
	}
	return 0;
}
