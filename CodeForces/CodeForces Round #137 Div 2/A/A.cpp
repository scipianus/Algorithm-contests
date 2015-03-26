#include<iostream>
using namespace std;
int n,K;
int v[100100];

int main()
{
	int i;
	cin>>n>>K;
	for(i=1;i<=n;i++)
		cin>>v[i];
	for(i=K;i<=n;i++)
	{
		if(v[i]!=v[K])
		{
			cout<<"-1\n";
			return 0;
		}
	}
	i=K;
	while(i>0 && v[i]==v[K])
		i--;
	cout<<i<<"\n";
	return 0;
}
