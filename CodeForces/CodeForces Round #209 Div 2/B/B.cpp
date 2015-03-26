#include<iostream>
#include<algorithm>
using namespace std;
int n,K,desired;
int perm[100100];

int main()
{
	int i,j;
	cin>>n>>K;
	for(i=1;i<=2*n;i++)
		perm[i]=i;
	desired=2*K;
	for(i=1,j=2;i<=K;i++,j+=4)
		swap(perm[j],perm[j+2]);
	for(i=1;i<=2*n;i++)
		cout<<perm[i]<<' ';
	cout<<"\n";
	return 0;
}
