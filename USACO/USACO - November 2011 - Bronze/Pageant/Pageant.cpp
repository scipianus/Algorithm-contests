/*
PROB: pageant
LANG: C++
*/
#include<fstream>
#include<cstring>
#include<queue>
using namespace std;
short n,m,A[60][60],d[60][60],sol=30000;
struct Pozitie{short x,y;};

short dx[]={1,0,-1,0};
short dy[]={0,1,0,-1};

void Citire()
{
	int i,j;
	char s[60];
	ifstream fin("pageant.in");
	fin>>n>>m;
	for(i=1;i<=n;i++)
	{
		fin>>s;
		for(j=0;j<m;j++)
		{
			if(s[j]=='.')
				A[i][j+1]=0;
			else
				A[i][j+1]=1;
		}
	}
	for(i=0;i<=n+1;i++)
		A[i][0]=A[i][m+1]=-1;
	for(j=0;j<=m+1;j++)
		A[0][j]=A[n+1][j]=-1;
	fin.close();
}

inline void Fill(short x,short y)
{
	A[x][y]=2;
	if(A[x+1][y]==1)
		Fill(x+1,y);
	if(A[x-1][y]==1)
		Fill(x-1,y);
	if(A[x][y+1]==1)
		Fill(x,y+1);
	if(A[x][y-1]==1)
		Fill(x,y-1);
}

inline bool Vecin1(short x,short y)
{
	short k;
	for(k=0;k<4;k++)
	{
		if(A[x+dx[k]][y+dy[k]]==1)
			return true;
	}
	return false;
}

inline bool Vecin2(short x,short y)
{
	short k;
	for(k=0;k<4;k++)
	{
		if(A[x+dx[k]][y+dy[k]]==2)
			return true;
	}
	return false;
}

inline short Min(short a,short b)
{
	if(a<b)
		return a;
	return b;
}

void Rezolvare()
{
	short i,j,k;
	bool gasit=false;
	for(i=1;i<=n && !gasit;i++)
	{
		for(j=1;j<=m && !gasit;j++)
		{
			if(A[i][j]==1)
			{
				Fill(i,j);
				gasit=true;
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			d[i][j]=30000;
	queue <Pozitie> Q;
	Pozitie poz,aux;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(A[i][j]==0 && Vecin2(i,j))
			{
				d[i][j]=1;
				aux.x=i; aux.y=j;
				Q.push(aux);
			}
		}
	}
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		if(Vecin1(aux.x,aux.y))
			sol=Min(sol,d[aux.x][aux.y]);
		else
		{
			for(k=0;k<4;k++)
			{
				poz.x=aux.x+dx[k];
				poz.y=aux.y+dy[k];
				if(A[poz.x][poz.y]==0 && d[poz.x][poz.y]>d[aux.x][aux.y]+1)
				{
					d[poz.x][poz.y]=d[aux.x][aux.y]+1;
					Q.push(poz);
				}
			}
		}
	}
}

void Afisare()
{
	ofstream fout("pageant.out");
	fout<<sol<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Rezolvare();
	Afisare();
	return 0;
}
