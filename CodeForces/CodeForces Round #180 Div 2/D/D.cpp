#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;
int n,m,K;
int A[100100],B[100100];

int main()
{
	int i,j,minim=1000000001;
	cin>>n>>m>>K;
	for(i=1;i<=n;i++)
		cin>>A[i];
	for(i=1;i<=m;i++)
		cin>>B[i];
	sort(A+1,A+n+1);
	sort(B+1,B+m+1);
	if(n>m)
		cout<<"YES\n";
	else
	{
		if(A[n]>B[m])
			cout<<"YES\n";
		else
		{
			i=n;
			j=m;
			while(i>0 && j>0)
			{
				if(A[i]==B[j])
				{
					i--;
					j--;
					continue;
				}
				if(A[i]>B[j])
				{
					if(minim>B[j])
					{
						cout<<"YES\n";
						return 0;
					}
					i--;
					j--;
					continue;
				}
				if(A[i]<B[j])
				{
					minim=min(minim,A[i]);
					i--;
					j--;
					continue;
				}
			}
			if(i>0 && j==0)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}
