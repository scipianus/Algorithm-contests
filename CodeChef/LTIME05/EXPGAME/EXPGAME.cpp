#include<iostream>
using namespace std;
int T,n,a[110],put[10];
bool used[100100];
int grundy[100100];

int main()
{
	int i,j,sumaxor;
	for(i=1;i<=7;i++)
	{
		put[i]=1;
		for(j=1;j<=i;j++)
			put[i]*=i;
	}
	grundy[0]=0;
	for(i=1;i<=100000;i++)
	{
		for(j=1;i-put[j]>=0;j++)
			used[grundy[i-put[j]]]=true;
		grundy[i]=0;
		while(used[grundy[i]])
			grundy[i]++;
		for(j=1;i-put[j]>=0;j++)
			used[grundy[i-put[j]]]=false;
	}
	cin>>T;
	while(T--)
	{
		cin>>n;
		sumaxor=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			sumaxor^=grundy[a[i]];
		}
		if(sumaxor)
			cout<<"Little Chef\n";
		else
			cout<<"Head Chef\n";
	}
	return 0;
}
