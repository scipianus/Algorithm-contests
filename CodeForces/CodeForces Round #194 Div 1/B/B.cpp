#include<iostream>
using namespace std;
int n,m,sol;
bool badL[1010],badC[1010];

int main()
{
	int i,x,y;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		badL[x]=true;
		badC[y]=true;
	}
	for(i=2;i<n;i++)
		if(!badL[i] || !badC[i])
			sol++;
	cout<<sol<<"\n";
	return 0;
}
