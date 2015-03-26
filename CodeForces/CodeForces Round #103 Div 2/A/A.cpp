#include<iostream>
#include<cstring>
using namespace std;
int n,v[110],maxim,minim=105;

int main()
{
	int i;
	cin>>n;
	v[105]=2000000000;
	for(i=1;i<=n;i++)
	{
		cin>>v[i];
		if(v[maxim]<v[i])
			maxim=i;
		if(v[minim]>=v[i])
			minim=i;
	}
	if(maxim==1 && minim==n)
		cout<<0<<"\n";
	else
	{
		if(maxim==1)
			cout<<(n-minim)<<"\n";
		else
		{
			if(minim==n)
				cout<<(maxim-1)<<"\n";
			else
			{
				if(maxim<minim)
					cout<<(maxim-1+n-minim)<<"\n";
				else
					cout<<(maxim-1+n-minim-1)<<"\n";
			}
		}
	}
	return 0;
}
