#include<iostream>
#include<cmath>
#define MOD 10007
using namespace std;
int n,sol;

int main()
{
	int d,rad;
	cin>>n;
	if(n==1)
	{
		cout<<1<<"\n";
		return 0;
	}
	rad=(int)floor(sqrt(1.0*n));
	for(d=1;d<=rad;d++)
	{
		if(n%d==0)
		{
			sol+=2;
			if(sol>=MOD)
				sol-=MOD;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
