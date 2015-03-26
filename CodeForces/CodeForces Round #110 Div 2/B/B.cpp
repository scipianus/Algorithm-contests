#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
long double Pi=3.141592653589793,sol;
int n,r[110],nr;

int main()
{
	int i,tip=1;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>r[i];
	sort(r+1,r+n+1);
	for(i=n;i>0;i--)
	{
		if(tip==1)
		{
			nr+=r[i]*r[i];
			tip=2;
		}
		else
		{
			nr-=r[i]*r[i];
			tip=1;
		}
	}
	sol=(long double)nr;
	sol=sol*Pi;
	cout<<sol<<"\n";
	return 0;
}
