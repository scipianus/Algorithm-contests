#include<iostream>
using namespace std;
int n,R,r,size;
int main()
{
	int i,nr=0,tot;
	cin>>n>>R>>r;
	
	while(R && R/2>r)
	{
		nr++;
		R/=2;
	}
	tot=1;
	for(i=1;i<=nr;i++)
		tot*=4;
	if(n<=tot)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	
	return 0;
}
