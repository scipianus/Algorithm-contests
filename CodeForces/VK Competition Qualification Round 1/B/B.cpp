#include<iostream>
using namespace std;
int n,nr[5],sol;

int main()
{
	int i,x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		nr[x]++;
	}
	sol+=nr[4];
	nr[1]-=nr[3];
	sol+=nr[3];
	if(nr[2]%2==0)
	{
		nr[2]/=2;
		sol+=nr[2];
		if(nr[1]>0)
		{
			if(nr[1]%4==0)
				sol+=(nr[1]/4);
			else
				sol+=(nr[1]/4+1);
		}
	}
	else
	{
		nr[2]/=2;
		sol+=nr[2];
		nr[1]-=2;
		sol++;
		if(nr[1]>0)
		{
			if(nr[1]%4==0)
				sol+=(nr[1]/4);
			else
				sol+=(nr[1]/4+1);
		}
	}
	cout<<sol<<"\n";
	return 0;
}
