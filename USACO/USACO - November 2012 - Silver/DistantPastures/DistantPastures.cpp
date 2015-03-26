/*
PROB: distant
LANG: C++
*/
#include<fstream>
#include<queue>
#include<cmath>
using namespace std;
int n,A,B,sol;
char mat[35][35];
struct Pozitie{int x,y;};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

inline int Lee(int stx,int sty)
{
	int i,j,k,best[35][35],rez=0;
	queue <Pozitie> Q;
	while(!Q.empty())
		Q.pop();
	Pozitie aux,poz;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			best[i][j]=2000000000;
	for(i=0;i<=n+1;i++)
		best[i][0]=best[i][n+1]=best[0][i]=best[n+1][i]=0;
	best[stx][sty]=0;
	aux.x=stx;
	aux.y=sty;
	Q.push(aux);
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		for(k=0;k<4;k++)
		{
			poz.x=aux.x+dx[k];
			poz.y=aux.y+dy[k];
			if(mat[poz.x][poz.y]==mat[aux.x][aux.y])
			{
				if(best[poz.x][poz.y]>best[aux.x][aux.y]+A)
				{
					best[poz.x][poz.y]=best[aux.x][aux.y]+A;
					Q.push(poz);
				}
			}
			else
			{
				if(best[poz.x][poz.y]>best[aux.x][aux.y]+B)
				{
					best[poz.x][poz.y]=best[aux.x][aux.y]+B;
					Q.push(poz);
				}
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			rez=max(rez,best[i][j]);
	return rez;
}

int main()
{
	int i,j,rez;
	ifstream fin("distant.in");
	fin>>n>>A>>B;
	for(i=1;i<=n;i++)
		fin>>(mat[i]+1);
	fin.close();
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			rez=Lee(i,j);
			sol=max(sol,rez);
		}
	}
	
	ofstream fout("distant.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
