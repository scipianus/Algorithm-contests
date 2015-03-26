/*
PROB: umbrella
LANG: C++
*/
#include<fstream>
#include<algorithm>
using namespace std;
int n,m,poz[5010],cost[100010],best[5010],minim[100010];

void Citire()
{
	int i;
	ifstream fin("umbrella.in");
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>poz[i];
	for(i=1;i<=m;i++)
		fin>>cost[i];
	fin.close();
	
	sort(poz+1,poz+n+1);
	minim[m]=cost[m];
	for(i=m-1;i>0;i--)
		minim[i]=min(minim[i+1],cost[i]);
}

void Rezolvare()
{
	int i,j,x;
	poz[0]=0;
	best[0]=0;
	best[1]=minim[1];
	for(i=2;i<=n;i++)
	{
		x=poz[i];
		best[i]=best[i-1]+minim[1];
		for(j=i-2;j>=0;j--)
		{
			best[i]=min(best[i],best[j]+minim[x-poz[j+1]+1]);
		}
	}
}

void Afisare()
{
	ofstream fout("umbrella.out");
	fout<<best[n]<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Rezolvare();
	Afisare();
	return 0;
}
