/*
PROB: seating
LANG: C++
*/
#include<fstream>
using namespace std;
int n,m,sol;
bool ocupat[500100];

int main()
{
	int i,j,p,a,b,sum,poz;
	char op;
	ifstream fin("seating.in");
	fin>>n>>m;
	for(i=1;i<=m;i++)
	{
		fin>>op;
		if(op=='A')
		{
			fin>>p;
			sum=0;
			poz=0;
			for(j=1;j<=n;j++)
			{
				if(ocupat[j]==true)
					sum=0;
				else
				{
					sum++;
					if(sum==p)
					{
						poz=j;
						j=n+1;
					}
				}
			}
			if(poz==0)
				sol++;
			else
			{
				while(sum)
				{
					ocupat[poz]=true;
					poz--;
					sum--;
				}
			}
		}
		else
		{
			fin>>a>>b;
			for(j=a;j<=b;j++)
				ocupat[j]=false;
		}
	}
	fin.close();
	
	ofstream fout("seating.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
