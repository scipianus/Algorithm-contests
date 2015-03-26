#include<iostream>
using namespace std;
int n,m;
int rez1[100100],rez2[100100];
long long sol1,sol2;

int main()
{
	int i,x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		rez1[x]=i;
		rez2[x]=n-i+1;
	}
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x;
		sol1+=(long long)rez1[x];
		sol2+=(long long)rez2[x];
	}
	cout<<sol1<<' '<<sol2<<"\n";
	return 0;
}
