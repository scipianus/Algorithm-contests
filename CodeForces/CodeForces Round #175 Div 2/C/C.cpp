#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,p[300100];
long long sol;

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+n+1);
	for(i=1;i<=n;i++)
		sol+=1LL*abs(p[i]-i);
	cout<<sol<<"\n";
	return 0;
}
