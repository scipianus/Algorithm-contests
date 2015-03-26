#include<iostream>
#include<algorithm>
using namespace std;
int n,v[100010];

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>v[i];
	sort(v+1,v+n+1);
	if(v[n]==1)
	{
		v[n]=2;
		sort(v+1,v+n+1);
		for(i=1;i<=n;i++)
			cout<<v[i]<<' ';
		cout<<"\n";
	}
	else
	{
		v[n]=1;
		sort(v+1,v+n+1);
		for(i=1;i<=n;i++)
			cout<<v[i]<<' ';
		cout<<"\n";
	}
	return 0;
}
