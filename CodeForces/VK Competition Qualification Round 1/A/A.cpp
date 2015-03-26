#include<iostream>
using namespace std;
int n,k,v[55],sol;

int main()
{
	int i,val;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>v[i];
	val=v[k];
	sol=0;
	while(sol+1<=n && v[sol+1]>=val && v[sol+1]>0)
		sol++;
	cout<<sol<<"\n";
	return 0;
}
