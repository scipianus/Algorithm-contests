#include<iostream>
using namespace std;
int n,v[20100],sol=-2000000000;

int main()
{
	int i,d,j,sum;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>v[i];
	for(d=1;(n/d)>=3;d++)
	{
		if(n%d==0)
		{
			for(i=1;i<=d;i++)
			{
				sum=0;
				for(j=i;j<=n;j+=d)
					sum+=v[j];
				if(sum>sol)
					sol=sum;
			}
		}
	}
	cout<<sol<<"\n";
	return 0;
}
