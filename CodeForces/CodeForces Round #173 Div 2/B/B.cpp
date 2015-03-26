#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,sa,sb,K=-1;

int main()
{
	int i,a,b;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		sa+=a;
		sb+=b;
	}
	for(i=0;i<=n;i++)
	{
		if(abs(i*1000-sb)<=500)
		{
			K=i;
			break;
		}
	}
	if(K==-1)
		cout<<"-1\n";
	else
	{
		for(i=1;i<=n;i++)
		{
			if(i<=K)
				cout<<"A";
			else
				cout<<"G";
		}
		cout<<"\n";
	}
	return 0;
}
