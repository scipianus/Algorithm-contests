#include<iostream>
using namespace std;
int n,m,maxim,minim;

int main()
{
	cin>>n>>m;
	if(n==0)
	{
		if(m==0)
			cout<<"0 0\n";
		else
			cout<<"Impossible\n";
		return 0;
	}
	if(m<=1)
	{
		maxim=n;
		minim=n;
	}
	else
	{
		maxim=n+m-1;
		if(m<=n)
			minim=n;
		else
			minim=m;
	}
	cout<<minim<<' '<<maxim<<"\n";
	return 0;
}
