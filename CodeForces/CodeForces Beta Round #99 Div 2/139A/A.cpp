#include<iostream>
using namespace std;
int n,v[10],sol;
int main()
{
	int i;
	cin>>n;
	for(i=1;i<=7;i++)
		cin>>v[i];
	sol=1;
	while(n>0)
	{
		n-=v[sol];
		if(n<=0)
			cout<<sol<<"\n";
		else
			sol++;
		if(sol==8)
			sol=1;
	}
	return 0;
}
