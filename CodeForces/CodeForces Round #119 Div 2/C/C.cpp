#include<iostream>
#include<algorithm>
using namespace std;
int n,A[200100],B[200100],poz[200100];
int sol;

int main()
{
	int i,nr1=0,nr2=0;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>A[i];
	for(i=1;i<=n;i++)
	{
		cin>>B[i];
		poz[B[i]]=i;
	}
	
	for(i=1;i<=n;i++)
	{
		nr1=max(nr1,poz[A[i]]-i);
		if(i>poz[A[i]])
			nr2++;
	}
	sol=max(nr1,nr2);
	cout<<sol<<"\n";
	return 0;
}
