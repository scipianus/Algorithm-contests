#include<iostream>
using namespace std;
int n,K;
int v[100100];
int nr[100100];

int main()
{
	int i,st,dr,nrt=0;
	cin>>n>>K;
	for(i=1;i<=n;i++)
		cin>>v[i];
	st=1;
	dr=1;
	nr[v[1]]++;
	nrt=1;
	while(dr<n && nrt<K)
	{
		dr++;
		if(nr[v[dr]]==0)
			nrt++;
		nr[v[dr]]++;
	}
	if(nrt<K)
		cout<<"-1 -1\n";
	else
	{
		while(1)
		{
			if(nr[v[st]]>1)
			{
				nr[v[st]]--;
				st++;
			}
			else
			{
				cout<<st<<' '<<dr<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
