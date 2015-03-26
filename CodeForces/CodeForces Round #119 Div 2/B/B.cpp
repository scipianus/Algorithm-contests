#include<iostream>
#include<cmath>
using namespace std;
int n,m;
long long sol;

int main()
{
	int i,j,nr;
	cin>>n>>m;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			nr=(m-j)/2*min(i,n-i);
			sol+=(long long)nr;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
