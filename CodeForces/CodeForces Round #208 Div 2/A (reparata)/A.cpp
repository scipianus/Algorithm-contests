#include<iostream>
using namespace std;
int n,v[1010],mx[1010],mn[1010];

int main()
{
	int i,j;
	bool ok;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>v[i];
	for(i=1;i<n;i++)
	{
		mn[i]=min(v[i],v[i+1]);
		mx[i]=max(v[i],v[i+1]);
	}
	for(i=1;i<=n;i++)
	{
		ok=false;
		for(j=i+2;j<=n;j++)
		{
			if(mx[j]<mx[i] && mn[j]<mn[i] && mx[j]>mn[i])
				ok=true;
			if(mx[j]>mx[i] && mn[j]>mn[i] && mn[j]<mx[i])
				ok=true;
		}
		if(ok)
		{
			cout<<"yes\n";
			return 0;
		}
	}
	cout<<"no\n";
	return 0;
}
