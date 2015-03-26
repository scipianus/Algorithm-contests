#include<iostream>
using namespace std;
int n,m,sol;

int main()
{
	int i,j,good;
	sol=4;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>good;
			if(good==1 && (i==1 || i==n || j==1 || j==m))
				sol=2;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
