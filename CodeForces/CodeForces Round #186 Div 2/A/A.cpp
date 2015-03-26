#include<iostream>
using namespace std;
int n,a,b;

int main()
{
	cin>>n;
	a=n/10;
	b=(n/100)*10+n%10;
	cout<<max(n,max(a,b))<<"\n";
	return 0;
}
