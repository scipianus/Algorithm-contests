#include<iostream>
using namespace std;
int T,A,B,K;
int nrdiv[100100],sum[6][100100];

int main()
{
	int i,j,k;
	for(i=2;i<=100000;i+=2)
		nrdiv[i]=1;
	for(i=3;i<100000;i+=2)
	{
		if(nrdiv[i]==0)
		{
			for(j=i;j<=100000;j+=i)
				nrdiv[j]++;
		}
	}
	for(i=2;i<=100000;i++)
	{
		for(k=1;k<6;k++)
		{
			sum[k][i]=sum[k][i-1];
			if(nrdiv[i]==k)
				sum[k][i]++;
		}
	}
	
	cin>>T;
	while(T--)
	{
		cin>>A>>B>>K;
		cout<<(sum[K][B]-sum[K][A-1])<<"\n";
	}
	return 0;
}
