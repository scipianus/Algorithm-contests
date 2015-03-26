#include<iostream>
#include<cmath>
using namespace std;
int n,sol;
int nr[2][2];

int main()
{
	int i,st,dr;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>st>>dr;
		if(st==1)
			nr[0][0]++;
		else
			nr[0][1]++;
		if(dr==1)
			nr[1][0]++;
		else
			nr[1][1]++;
	}
	sol=min(nr[0][0],nr[0][1])+min(nr[1][0],nr[1][1]);
	cout<<sol<<"\n";
	return 0;
}
