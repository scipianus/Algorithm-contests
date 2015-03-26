#include<iostream>
#include<cstring>
using namespace std;
int n,sumL[110],sumC[110],sol;
int main()
{
	int i,j,x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>x;
			sumL[i]+=x;
			sumC[j]+=x;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(sumL[i]>sumC[j])
				sol++;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
