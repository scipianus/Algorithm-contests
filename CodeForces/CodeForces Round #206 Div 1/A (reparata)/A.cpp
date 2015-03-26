#include<iostream>
#include<algorithm>
using namespace std;
int n,L,R,QL,QR,sum[100100],sol=2000000000;
int g[100100];

int main()
{
	int i;
	cin>>n>>L>>R>>QL>>QR;
	for(i=1;i<=n;i++)
	{
		cin>>g[i];
		sum[i]=sum[i-1]+g[i];
	}
	for(i=0;i<=n;i++)
	{
		if(i<n-i)
			sol=min(sol,sum[i]*L+(sum[n]-sum[i])*R+(n-2*i-1)*QR);
		else
		{
			if(i>n-i)
				sol=min(sol,sum[i]*L+(sum[n]-sum[i])*R+(2*i-n-1)*QL);
			else
				sol=min(sol,sum[i]*L+(sum[n]-sum[i])*R);
		}
	}
	cout<<sol<<"\n";
	return 0;
}
