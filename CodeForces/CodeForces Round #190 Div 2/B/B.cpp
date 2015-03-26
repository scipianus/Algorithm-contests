#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long R,G,B,sol;

int main()
{
	cin>>R>>G>>B;
	if(R>G)
		swap(R,G);
	if(R>B)
		swap(R,B);
	if(G>B)
		swap(G,B);
	sol=max(R%3,max(G%3,B%3));
	if(sol<=R)
	{
		R-=sol;
		G-=sol;
		B-=sol;
	}
	else
		sol=0;
	sol+=max((G-R)/3LL+(B-R)/3LL+R,R/3LL+B/3LL+G/3LL+min(R%3,min(G%3,B%3)));
	cout<<sol<<"\n";
	return 0;
}
