#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int L,nrcif,cost[12];

int main()
{
	int i,j,minim=1;
	cin>>L;
	for(i=1;i<10;i++)
	{
		cin>>cost[i];
		nrcif=max(nrcif,L/cost[i]);
		if(cost[i]<cost[minim])
			minim=i;
	}
	if(nrcif==0)
	{
		cout<<"-1\n";
		return 0;
	}
	for(i=1;i<=nrcif;i++)
	{
		for(j=9;j>0;j--)
		{
			if(L>=cost[j] && (L-cost[j])/cost[minim]==nrcif-i)
			{
				cout<<j;
				L-=cost[j];
				j=0;
			}
		}
	}
	cout<<"\n";
	return 0;
}
