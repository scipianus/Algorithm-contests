#include<iostream>
#define MOD 1000000007
using namespace std;
int n,m,nr[1000100];

int main()
{
	int i;
	long long p;
	cin>>n>>m;
	nr[0]=1;
	for(p=1LL;p<=1LL*n;p*=1LL*m)
	{
		for(i=p;i<=n;i++)
		{
			nr[i]+=nr[i-p];
			if(nr[i]>=MOD)
				nr[i]-=MOD;
		}
	}
	cout<<nr[n]<<"\n";
	return 0;
}
