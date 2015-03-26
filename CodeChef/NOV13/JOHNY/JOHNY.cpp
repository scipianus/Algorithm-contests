#include<iostream>
#include<algorithm>
using namespace std;
int T,n,K,v[110];

int main()
{
	int i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>v[i];
		cin>>K;
		K=v[K];
		sort(v+1,v+n+1);
		for(i=1;i<=n;i++)
		{
			if(v[i]==K)
			{
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}
