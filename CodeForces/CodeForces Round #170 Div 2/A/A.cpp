#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,d[110],A,B,total,sol;

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>d[i];
		total+=d[i];
	}
	cin>>A>>B;
	if(A==B)
		cout<<"0\n";
	else
	{
		if(A>B)
			swap(A,B);
		for(i=A;i<B;i++)
			sol+=d[i];
		sol=min(sol,total-sol);
		cout<<sol<<"\n";
	}
	return 0;
}
