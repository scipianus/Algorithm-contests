#include<iostream>
#define MOD 1000000007
using namespace std;
int n;
unsigned int nr[4][2];
//A=0
//B=1
//C=2
//D=3

int main()
{
	register int i,j;
	cin>>n;
	nr[3][0]=1;
	for(i=1;i<=n;i++)
	{
		nr[0][1]=nr[1][0]+nr[2][0]+nr[3][0]; nr[0][1]%=MOD;
		nr[1][1]=nr[0][0]+nr[2][0]+nr[3][0]; nr[1][1]%=MOD;
		nr[2][1]=nr[0][0]+nr[1][0]+nr[3][0]; nr[2][1]%=MOD;
		nr[3][1]=nr[0][0]+nr[1][0]+nr[2][0]; nr[3][1]%=MOD;
		for(j=0;j<4;j++)
			nr[j][0]=nr[j][1];
	}
	cout<<nr[3][1]<<"\n";
	return 0;
}
