#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,X,sol;
vector <int> v;

int main()
{
	int i,val;
	cin>>n>>X;
	v.push_back(0);
	for(i=1;i<=n;i++)
	{
		cin>>val;
		v.push_back(val);
	}
	sort(v.begin(),v.end());
	for(i=1;i<=n && v[i]!=X;i++);
	if(i==n+1 || v[i]!=X)
	{
		v.push_back(X);
		sort(v.begin(),v.end());
		n++;
		for(i=1;i<=n && v[i]!=X;i++);
		sol++;
	}
	if(i==(n+1)/2)
	{
		cout<<sol<<"\n";
		return 0;
	}
	if(i<(n+1)/2)
	{
		while(i<(n+1)/2 && v[i+1]==X)
			i++;
		if(i==(n+1)/2)
		{
			cout<<sol<<"\n";
			return 0;
		}
		val=X-1;
	}
	else
		val=X+1;
	bool gata=false;
	while(!gata)
	{
		v.push_back(val);
		sol++;
		sort(v.begin(),v.end());
		n++;
		for(i=1;i<=n && v[i]!=X;i++);
		if(i==(n+1)/2)
		{
			gata=true;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
