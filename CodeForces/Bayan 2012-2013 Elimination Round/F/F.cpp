#include<iostream>
#include<cstring>
#include<fstream>
#include<queue>
using namespace std;
int n,m,K,nt;
char mat[110][110],traseu[1010];
struct Pozitie{int x,y;};
Pozitie start,final,pozl[30];
int dist[30][30],d1;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

inline int Lee(Pozitie st,Pozitie fi)
{
	queue <Pozitie> Q;
	Pozitie aux,poz;
	int d[110][110],i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			d[i][j]=2000000000;
	d[st.x][st.y]=0;
	Q.push(st);
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		for(i=0;i<4;i++)
		{
			poz.x=aux.x+dx[i];
			poz.y=aux.y+dy[i];
			if(!(1<=poz.x && poz.x<=n && 1<=poz.y && poz.y<=m))
				continue;
			if(mat[poz.x][poz.y]=='#')
				continue;
			if('a'<=mat[aux.x][aux.y] && mat[aux.x][aux.y]<='z')
			{
				if(d[poz.x][poz.y]>d[aux.x][aux.y]+1)
				{
					d[poz.x][poz.y]=d[aux.x][aux.y]+1;
					Q.push(poz);
				}
				continue;
			}
			if(d[poz.x][poz.y]>d[aux.x][aux.y]+mat[aux.x][aux.y]-'0')
			{
				d[poz.x][poz.y]=d[aux.x][aux.y]+mat[aux.x][aux.y]-'0';
				Q.push(poz);
			}
		}
	}
	return d[fi.x][fi.y];
}

inline void Solve(Pozitie st,Pozitie fi)
{
	queue <Pozitie> Q;
	Pozitie aux,poz;
	int d[110][110],d1[110][110],i,j;
	Pozitie pred[110][110];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			d[i][j]=d1[i][j]=2000000000;
	d[st.x][st.y]=0;
	Q.push(st);
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		for(i=0;i<4;i++)
		{
			poz.x=aux.x+dx[i];
			poz.y=aux.y+dy[i];
			if(!(1<=poz.x && poz.x<=n && 1<=poz.y && poz.y<=m))
				continue;
			if(mat[poz.x][poz.y]=='#')
				continue;
			if('a'<=mat[aux.x][aux.y] && mat[aux.x][aux.y]<='z')
			{
				if(d[poz.x][poz.y]>d[aux.x][aux.y]+1)
				{
					d[poz.x][poz.y]=d[aux.x][aux.y]+1;
					pred[poz.x][poz.y]=aux;
					Q.push(poz);
				}
				continue;
			}
			if(d[poz.x][poz.y]>d[aux.x][aux.y]+mat[aux.x][aux.y]-'0')
			{
				d[poz.x][poz.y]=d[aux.x][aux.y]+mat[aux.x][aux.y]-'0';
				pred[poz.x][poz.y]=aux;
				Q.push(poz);
			}
		}
	}
	d1[fi.x][fi.y]=0;
	Q.push(fi);
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		for(i=0;i<4;i++)
		{
			poz.x=aux.x+dx[i];
			poz.y=aux.y+dy[i];
			if(!(1<=poz.x && poz.x<=n && 1<=poz.y && poz.y<=m))
				continue;
			if(mat[poz.x][poz.y]=='#')
				continue;
			if('a'<=mat[aux.x][aux.y] && mat[aux.x][aux.y]<='z')
			{
				if(d1[poz.x][poz.y]>d1[aux.x][aux.y]+1)
				{
					d1[poz.x][poz.y]=d1[aux.x][aux.y]+1;
					Q.push(poz);
				}
				continue;
			}
			if(d1[poz.x][poz.y]>d1[aux.x][aux.y]+mat[aux.x][aux.y]-'0')
			{
				d1[poz.x][poz.y]=d1[aux.x][aux.y]+mat[aux.x][aux.y]-'0';
				Q.push(poz);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(d[i][j]>K && d[pred[i][j].x][pred[i][j].y]<=K && d[i][j]+d1[i][j]==d[fi.x][fi.y])
			{
				cout<<pred[i][j].x<<' '<<pred[i][j].y<<"\n";
				return;
			}
		}
	}
}

int main()
{
	int i,j;
	//ifstream fin("F.in");
	cin>>n>>m>>K;
	for(i=1;i<=n;i++)
		cin>>(mat[i]+1);
	cin>>start.x>>start.y;
	cin>>(traseu+1);
	cin>>final.x>>final.y;
	//fin.close();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if('a'<=mat[i][j] && mat[i][j]<='z')
			{
				pozl[mat[i][j]-'a'].x=i;
				pozl[mat[i][j]-'a'].y=j;
			}
		}
	}
	for(i=0;i<30;i++)
	{
		if(pozl[i].x==0)
			continue;
		for(j=i+1;j<30;j++)
		{
			if(pozl[j].x==0)
				continue;
			dist[i][j]=dist[j][i]=Lee(pozl[i],pozl[j]);
		}
	}
	d1=Lee(start,pozl[traseu[1]-'a']);
	if(d1>=K)
	{
		Solve(start,pozl[traseu[1]-'a']);
		return 0;
	}
	else
	{
		K-=d1;
		i=1;
		nt=strlen(traseu+1);
		while(K && i<nt)
		{
			if(dist[traseu[i]-'a'][traseu[i+1]-'a']<K)
			{
				K-=dist[traseu[i]-'a'][traseu[i+1]-'a'];
				i++;
			}
			else
			{
				Solve(pozl[traseu[i]-'a'],pozl[traseu[i+1]-'a']);
				return 0;
			}
		}
		d1=Lee(pozl[traseu[nt]-'a'],final);
		if(d1>=K)
		{
			Solve(pozl[traseu[nt]-'a'],final);
			return 0;
		}
		cout<<final.x<<' '<<final.y<<"\n";
	}
	return 0;
}
