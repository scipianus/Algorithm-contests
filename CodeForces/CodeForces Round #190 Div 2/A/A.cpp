#include<iostream>
using namespace std;
int n,m,sol;

int main()
{
	int i,dif;
	cin>>n>>m;
	sol=n+m-1;
	cout<<sol<<"\n";
	cout<<"1 1\n";
	for(i=2;i<=n;i++)
		cout<<i<<" 1\n";
	for(i=2;i<=m;i++)
		cout<<"1 "<<i<<"\n";
	return 0;
}
