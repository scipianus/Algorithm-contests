#include<iostream>
#include<cstdlib>
using namespace std;
int T,n,A[55],B[55],sol;

inline bool Ok()
{
	int i;
	for(i=1;i<=n;i++)
		if(sol-B[i]+A[i]<0 || (sol-B[i]+A[i])%2==1)
			return false;
	return true;
}

int main()
{
	int i,sum;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>A[i];
		for(i=1;i<=n;i++)
			cin>>B[i];
		if(n==1)
		{
			if(A[1]>=B[1])
				cout<<(A[1]-B[1])<<"\n";
			else
				cout<<"-1\n";
			continue;
		}
		if(n==2)
		{
			if(A[1]-B[1]==B[2]-A[2])
				cout<<abs(A[1]-B[1])<<"\n";
			else
				cout<<"-1\n";
			continue;
		}
		sum=0;
		for(i=1;i<=n;i++)
			sum+=(B[i]-A[i]);
		if(sum>=0 && sum%(n-2)==0)
		{
			sol=sum/(n-2);
			if(!Ok())
				sol=-1;
		}
		else
			sol=-1;
		cout<<sol<<"\n";
	}
	return 0;
}
