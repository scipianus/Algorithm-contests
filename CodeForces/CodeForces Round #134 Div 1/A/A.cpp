#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int n,sol,nrc;
struct Pozitie{int x,y;};
Pozitie P[110];
queue <Pozitie> Q;
bool viz[110];

inline void BFS(int x)
{
	int i;
	Pozitie aux;
	while(!Q.empty())
		Q.pop();
	Q.push(P[x]);
	viz[x]=true;
	while(!Q.empty())
	{
		aux=Q.front();
		Q.pop();
		for(i=1;i<=n;i++)
		{
			if(!viz[i] && (P[i].x==aux.x || P[i].y==aux.y))
			{
				viz[i]=true;
				Q.push(P[i]);
			}
		}
	}
}

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>P[i].x>>P[i].y;
	
	for(i=1;i<=n;i++)
	{
		if(!viz[i])
		{
			nrc++;
			BFS(i);
		}
	}
	sol=nrc-1;
	
	cout<<sol<<"\n";
	return 0;
}
