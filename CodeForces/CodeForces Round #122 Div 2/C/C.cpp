#include<iostream>
#include<queue>
using namespace std;
int n,m,sol,vec[55][55],total;
char s[55][55];
struct Pozitie{int x,y;};
Pozitie start;
bool viz[55][55];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

inline bool Connected()
{
	int i,j,k,nr=0;
	queue <Pozitie> Q;
	Pozitie aux,poz;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			viz[i][j]=false;
	Q.push(start);
	viz[start.x][start.y]=true;
	nr++;
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		for(k=0;k<4;k++)
		{
			poz.x=aux.x+dx[k];
			poz.y=aux.y+dy[k];
			if(s[poz.x][poz.y]=='#' && !viz[poz.x][poz.y])
			{
				viz[poz.x][poz.y]=true;
				nr++;
				Q.push(poz);
			}
		}
	}
	if(nr==total)
		return true;
	return false;
}

int main()
{
	int i,j,k,x,y,xs,ys;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>(s[i]+1);
	do
	{
		xs=ys=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(s[i][j]=='.')
					continue;
				total++;
				for(k=0;k<4;k++)
				{
					x=i+dx[k];
					y=j+dy[k];
					if(s[x][y]=='#')
						vec[i][j]++;
				}
				if(vec[i][j]>vec[xs][ys])
				{
					xs=i;
					ys=j;
				}
			}
		}
		s[xs][ys]='.';
		sol++;
		total--;
		if(total<=1)
		{
			cout<<"-1\n";
			return 0;
		}
		for(k=0;k<4;k++)
		{
			x=xs+dx[k];
			y=ys+dy[k];
			if(s[x][y]=='#')
			{
				start.x=x;
				start.y=y;
			}
		}
	}
	while(Connected()==true);
	cout<<sol<<"\n";
	return 0;
}
