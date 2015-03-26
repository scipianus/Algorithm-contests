#include<iostream>
#include<cstdio>
using namespace std;
int n;

int main()
{
	int i;
	double x,sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
	}
	sum/=(double)n;
	printf("%.8lf\n",sum);
	return 0;
}
