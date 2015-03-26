#include<fstream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n,v[110];
int r1,c1,r2,c2,sol=2000000000;
int best[110][100100];
struct Pozitie{int x,y;};
queue <Pozitie> Q;

int main()
{
	int i,j,c;
	Pozitie aux,poz;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>v[i];
	fin>>r1>>c1>>r2>>c2;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=v[i]+1;j++)
			best[i][j]=2000000000;
	best[r1][c1]=0;
	aux.x=r1;
	aux.y=c1;
	Q.push(aux);
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		c=best[aux.x][aux.y];
		if(aux.x==r2 && aux.y==c2)
			sol=min(sol,c);
		if(c>sol)
			continue;
		// up
		if(aux.x>1)
		{
			poz.x=aux.x-1;
			poz.y=min(aux.y,v[poz.x]+1);
			if(best[poz.x][poz.y]>c+1)
			{
				best[poz.x][poz.y]=c+1;
				Q.push(poz);
			}
		}
		// down
		if(aux.x<n)
		{
			poz.x=aux.x+1;
			poz.y=min(aux.y,v[poz.x]+1);
			if(best[poz.x][poz.y]>c+1)
			{
				best[poz.x][poz.y]=c+1;
				Q.push(poz);
			}
		}
		// left
		if(aux.y>1)
		{
			poz.x=aux.x;
			poz.y=aux.y-1;
			if(best[poz.x][poz.y]>c+1)
			{
				best[poz.x][poz.y]=c+1;
				Q.push(poz);
			}
		}
		// right
		if(aux.y<=v[aux.x])
		{
			poz.x=aux.x;
			poz.y=aux.y+1;
			if(best[poz.x][poz.y]>c+1)
			{
				best[poz.x][poz.y]=c+1;
				Q.push(poz);
			}
		}
	}
	fout<<sol<<"\n";
	
	fin.close();
	fout.close();
	return 0;
}
