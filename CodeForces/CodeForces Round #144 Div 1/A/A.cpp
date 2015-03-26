#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;
int K,n;
bitset <110> mat[110];

int main()
{
	int i,j,nr,maxim,x,y,nr1;
	cin>>K;
	if(K==1)
	{
		cout<<3<<"\n";
		cout<<"011\n";
		cout<<"101\n";
		cout<<"110\n";
		return 0;
	}
	nr=1;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			if(i!=j)
				mat[i][j]=mat[j][i]=1;
	n=100;
	while(nr<K)
	{
		maxim=-1;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(mat[i][j]==0)
				{
					nr1=(mat[i]&mat[j]).count();
					if(maxim<nr1 && nr+nr1<=K)
					{
						maxim=nr1;
						x=i;
						y=j;
					}
				}
			}
		}
		nr+=maxim;
		mat[x][y]=mat[y][x]=1;
	}
	cout<<n<<"\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<mat[i][j];
		cout<<"\n";
	}
	return 0;
}
