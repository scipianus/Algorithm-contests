#include<iostream>
using namespace std;
int n,sum;

int main()
{
	int i,j,k;
	cin>>n>>sum;
	for(i=0;i<=n && 2*i<=sum;i++)
	{
		for(j=0;i+j<=n && 2*i+3*j<=sum;j++)
		{
			for(k=0;i+j+k<=n && 2*i+3*j+4*k<=sum;k++)
			{
				if((sum-2*i-3*j-4*k)%5==0 && (sum-2*i-3*j-4*k)/5==n-i-j-k)
				{
					cout<<i<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
