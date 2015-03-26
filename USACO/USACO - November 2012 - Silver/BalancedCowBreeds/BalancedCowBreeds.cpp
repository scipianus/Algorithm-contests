/*
PROB : bbreeds
LANG : C++
*/
#include<fstream>
#include<cstring>
#define MOD 2012
using namespace std;
int n,nr[2][1010][1010],sum,nrd,sol;
char s[1010];

int main()
{
	int i,j,k,p;
	ifstream fin("bbreeds.in");
	fin>>(s+1);
	fin.close();
	
	n=strlen(s+1);
	nr[0][0][0]=1;
	p=1;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='(')
		{
			sum++;
			nrd++;
			for(j=0;j<=nrd;j++)
			{
				for(k=0;j+k<=nrd;k++)
				{
					nr[p][j][k]=0;
					if(j>=1)
						nr[p][j][k]+=nr[1-p][j-1][k];
					if(k>=1)
						nr[p][j][k]+=nr[1-p][j][k-1];
					while(nr[p][j][k]>=MOD)
						nr[p][j][k]-=MOD;
				}
			}
		}
		else
		{
			sum--;
			for(j=0;j<=nrd;j++)
			{
				for(k=0;j+k<=nrd;k++)
				{
					nr[p][j][k]=nr[1-p][j+1][k]+nr[1-p][j][k+1];
					while(nr[p][j][k]>=MOD)
						nr[p][j][k]-=MOD;
				}
			}
		}
		if(sum<0)
		{
			nr[1][0][0]=nr[0][0][0]=0;
			i=n+1;
			continue;
		}
		p=1-p;
	}
	sol=nr[1-p][0][0];
	
	ofstream fout("bbreeds.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
