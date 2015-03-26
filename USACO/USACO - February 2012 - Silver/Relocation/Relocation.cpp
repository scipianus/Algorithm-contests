/*
PROB: relocate
LANG: C++
*/
#include<fstream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int n,m,K,S[7],v[7],d[10010],prem[10010],pre[10010],cost,sol=2000000000;
bool uz[7],viz[50010],other;
struct Muchie{int x,y,c;};
Muchie M[50010];
vector <int> G[10010];

void Citire()
{
	int i;
	ifstream fin("relocate.in");
	fin>>n>>m>>K;
	for(i=1;i<=K;i++)
		fin>>S[i];
	for(i=1;i<=m;i++)
	{
		fin>>M[i].x>>M[i].y>>M[i].c;
		G[M[i].x].push_back(i);
		G[M[i].y].push_back(i);
	}
	fin.close();
}

void Rezolvare()
{
	int i,j,nod1,nod2,cost,minim,x;
	queue <int> Q;
	vector <int>::iterator it;
	other=false;
	for(i=1;i<K;i++)
	{
		for(j=1;j<=n;j++)
		{
			d[j]=2000000000;
			prem[j]=pre[j]=0;
		}
		d[v[i]]=0;
		Q.push(v[i]);
		while(!Q.empty())
		{
			nod1=Q.front();
			Q.pop();
			for(it=G[nod1].begin();it!=G[nod1].end();it++)
			{
				nod2=M[*it].x+M[*it].y-nod1;
				cost=M[*it].c;
				if(d[nod2]>d[nod1]+cost)
				{
					d[nod2]=d[nod1]+cost;
					prem[nod2]=*it;
					pre[nod2]=nod1;
					Q.push(nod2);
				}
			}
		}
		x=v[i+1];
		while(x!=v[i])
		{
			viz[prem[x]]=true;
			x=pre[x];
			if(!other)
			{
				for(j=1;j<=K && x!=S[j];j++);
				if(j==K+1)
					other=true;
			}
		}
	}
	cost=0;
	for(i=1;i<=m;i++)
	{
		if(viz[i]==true)
			cost+=M[i].c;
	}
	cost*=2;
	if(other==true)
		sol=min(sol,cost);
	else
	{
		minim=2000000000;
		for(i=1;i<=K;i++)
		{
			for(it=G[S[i]].begin();it!=G[S[i]].end();it++)
			{
				nod1=M[*it].x+M[*it].y-S[i];
				for(j=1;j<=K && nod1!=S[j];j++);
				if(j==K+1)
					minim=min(minim,M[*it].c);
			}
		}
		minim*=2;
		cost+=minim;
		sol=min(sol,cost);
	}
}

void Back(int k)
{
	if(k==K+1)
		Rezolvare();
	else
	{
		int i;
		for(i=1;i<=K;i++)
		{
			if(!uz[i])
			{
				v[i]=S[i];
				uz[i]=true;
				Back(k+1);
				uz[i]=false;
			}
		}
	}
}

void Afisare()
{
	ofstream fout("relocate.out");
	fout<<sol<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Back(1);
	Afisare();
	return 0;
}
