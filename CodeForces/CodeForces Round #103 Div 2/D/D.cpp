#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<fstream>
using namespace std;
int n,m,S,L,d[100100],sol;
vector <int> G[100100];
struct Muchie{int x,y,lg;};
Muchie M[100100];

void Citire()
{
	int i;
	//ifstream fin("D.in");
	//fin>>n>>m>>S;
	cin>>n>>m>>S;
	for(i=1;i<=m;i++)
	{
		//fin>>M[i].x>>M[i].y>>M[i].lg;
		cin>>M[i].x>>M[i].y>>M[i].lg;
		G[M[i].x].push_back(i);
		G[M[i].y].push_back(i);
	}
	//fin>>L;
	//fin.close();
	cin>>L;
}

void Bellman_Ford()
{
	int i,nod1,nod2;
	vector <int>::iterator it;
	queue <int> Q;
	for(i=1;i<=n;i++)
		d[i]=2000000000;
	d[S]=0;
	Q.push(S);
	while(!Q.empty())
	{
		nod1=Q.front();
		Q.pop();
		for(it=G[nod1].begin();it!=G[nod1].end();it++)
		{
			nod2=M[*it].x+M[*it].y-nod1;
			if(d[nod2]>d[nod1]+M[*it].lg)
			{
				d[nod2]=d[nod1]+M[*it].lg;
				Q.push(nod2);
			}
		}
	}
}

void Rezolvare()
{
	int i,x,y,lg,p1,p2;
	Bellman_Ford();
	for(i=1;i<=m;i++)
	{
		x=M[i].x;
		y=M[i].y;
		lg=M[i].lg;
		p1=p2=-1;
		if(d[x]<L && d[x]+lg>L)
			p1=L-d[x];
		if(d[y]<L && d[y]+lg>L)
			p2=lg-(L-d[y]);
		if(p1!=-1 && p2!=-1 && p1==p2)
			sol++;
		else
		{
			if(p1!=-1 && d[x]+p1<=d[y]+lg-p1)
				sol++;
			if(p2!=-1 && d[y]+lg-p2<=d[x]+p2)
				sol++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(d[i]==L)
			sol++;
	}
	cout<<sol<<"\n";
}

int main()
{
	Citire();
	Rezolvare();
	return 0;
}
