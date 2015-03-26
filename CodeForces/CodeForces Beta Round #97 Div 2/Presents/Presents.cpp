#include<iostream>
using namespace std;
int n,sol[110];

int main()
{
	int i,x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		sol[x]=i;
	}
	for(i=1;i<=n;i++)
		cout<<sol[i]<<' ';
	cout<<"\n";
	return 0;
}
