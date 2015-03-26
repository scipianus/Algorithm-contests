#include<iostream>
#include<algorithm>
using namespace std;
int T,n,m,K;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>K;
		if(n>m)
			swap(n,m);
		if(n==1)
		{
			if(m>=3)
				cout<<K<<"\n";
			else
				cout<<"0\n";
		}
		else
			cout<<(K/2+K%2)<<"\n";
	}
	return 0;
}
