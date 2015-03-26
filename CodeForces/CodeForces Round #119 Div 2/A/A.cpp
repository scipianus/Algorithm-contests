#include<iostream>
#include<cmath>
using namespace std;
int n,a,b,c;
int sol;

int main()
{
	int i,j;
	cin>>n>>a>>b>>c;
	for(i=0;i*a<=n;i++)
	{
		for(j=0;j*b+i*a<=n;j++)
		{
			if((n-i*a-j*b)%c==0)
				sol=max(sol,i+j+(n-i*a-j*b)/c);
		}
	}
	cout<<sol<<"\n";
	return 0;
}
