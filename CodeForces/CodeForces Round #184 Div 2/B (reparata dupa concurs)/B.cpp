#include<iostream>
#include<algorithm>
using namespace std;
long long A,B,x;
int n;

int main()
{
	int i;
	cin>>A>>B;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(B==0LL)
		{
			cout<<"NO\n";
			return 0;
		}
		if(B==1LL)
		{
			if(A<x)
			{
				cout<<"NO\n";
				return 0;
			}
			A-=x;
		}
		else
		{
			if(A/B!=x)
			{
				cout<<"NO\n";
				return 0;
			}
			A%=B;
			swap(A,B);
		}
	}
	if(B==1LL)
	{
		if(A==0LL)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	else
	{
		if(B==0LL)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
