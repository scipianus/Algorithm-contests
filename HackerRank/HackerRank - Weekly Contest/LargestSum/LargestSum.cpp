#include<iostream>
#include<cmath>
#include<cstdlib>
#define MOD 1000000007
using namespace std;
int n,K,m,Z,v[110];
bool pos[110][3010];
int nr[3010];

int main()
{
	int i,j,k;
	cin>>n>>K>>m;
	for(i=1;i<=n;i++)
		cin>>v[i];
	pos[0][0]=true;
	for(i=1;i<=n;i++)
	{
		for(j=min(i,K);j>=1;j--)
		{
			for(k=0;k+v[i]<m;k++)
			{
				if(pos[j-1][k])
					pos[j][k+v[i]]=true;
			}
		}
	}
	for(i=m-1;i>0 && !Z;i--)
		if(pos[K][i])
			Z=i;
	nr[0]=nr[1]=1;
	for(i=2;i<=Z;i++)
	{
		k=1;
		while(i-k*(3*k-1)/2>=0)
		{
			if(k%2==1)
				nr[i]+=nr[i-k*(3*k-1)/2];
			else
				nr[i]-=nr[i-k*(3*k-1)/2];
			while(nr[i]<0)
				nr[i]+=MOD;
			nr[i]%=MOD;
			k++;
		}
		k=-1;
		while(i-k*(3*k-1)/2>=0)
		{
			if(abs(k)%2==1)
				nr[i]+=nr[i-k*(3*k-1)/2];
			else
				nr[i]-=nr[i-k*(3*k-1)/2];
			while(nr[i]<0)
				nr[i]+=MOD;
			nr[i]%=MOD;
			k--;
		}
	}
	cout<<Z<<"\n";
	cout<<nr[Z]<<"\n";
	return 0;
}
