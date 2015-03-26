#include<iostream>
#define MOD 1000000007
using namespace std;
int n;
long long sol;

int main()
{
	int i;
	cin>>n;
	if(n==1)
		sol=1;
	else
	{
		if(n%2==0)
			sol=0;
		else
		{
			sol=18;
			for(i=4;i<=n;i++)
				sol=(sol*10LL)%MOD;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
