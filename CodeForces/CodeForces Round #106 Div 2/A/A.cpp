#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int K,a[15],sol;

int main()
{
	int i;
	cin>>K;
	for(i=1;i<=12;i++)
		cin>>a[i];
	sort(a+1,a+13);
	i=12;
	while(K>0 && i>0)
	{
		K-=a[i];
		i--;
		sol++;
	}
	if(i==0 && K>0)
		sol=-1;
	cout<<sol<<"\n";
	return 0;
}
