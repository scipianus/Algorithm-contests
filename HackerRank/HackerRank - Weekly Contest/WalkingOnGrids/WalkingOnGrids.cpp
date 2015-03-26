#include<iostream>
#define MOD 10007
using namespace std;
int n,nr[2010][2010],sol;

int main()
{
	int i,j;
	cin>>n;
	nr[1][1]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			nr[i][j]=nr[i][j-1]+nr[i-1][j];
			if(nr[i][j]>=MOD)
				nr[i][j]-=MOD;
		}
	}
	sol=(2*nr[n][n])%MOD;
	cout<<sol<<"\n";
	return 0;
}
