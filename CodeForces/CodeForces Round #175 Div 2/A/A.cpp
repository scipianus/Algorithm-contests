#include<iostream>
#include<algorithm>
using namespace std;
int n,K,p[100100];

int main()
{
	int i,j;
	cin>>n>>K;
	for(i=1;i<=n;i++)
		p[i]=i;
	for(i=n,j=n-K;i>j;i--,j++)
		swap(p[i],p[j]);
	for(i=1;i<=n;i++)
		cout<<p[i]<<' ';
	cout<<"\n";
	return 0;
}
