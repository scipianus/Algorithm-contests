#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int na,nb,m,str[210],S,D,C[210][210],F[210][210],viz[210],maxflow;
int cost[210][210],sol;
vector <int> G[210];
bool def[210],used[210];
 
void Citire()
{
    int i,x,y;
	char s[5];
    cin>>nb>>na;
	S=na+nb+1;
    D=na+nb+2;
	for(i=1;i<=nb;i++)
	{
		cin>>s;
		cin>>str[na+i];
		if(s[0]=='D')
			def[na+i]=true;
	}
	for(i=1;i<=na;i++)
		cin>>str[i];
	for(x=1;x<=na;x++)
	{
		for(y=na+1;y<=nb+na;y++)
		{
			if(def[y] && str[x]>str[y])
			{
				G[x].push_back(y);
				G[y].push_back(x);
				C[x][y]=1;
				cost[x][y]=0;
				cost[y][x]=0;
				m++;
			}
			if(!def[y] && str[x]>=str[y])
			{
				G[x].push_back(y);
				G[y].push_back(x);
				C[x][y]=1;
				cost[x][y]=str[y]-str[x];
				cost[y][x]=str[x]-str[y];
				m++;
			}
		}
	}
}
 
void Construire_Retea_Transport()
{
    int i;
    for(i=1;i<=na;i++)
    {
        G[S].push_back(i);
        G[i].push_back(S);
        C[S][i]=1;
        cost[S][i]=cost[i][S]=0;
    }
    for(i=1;i<=nb;i++)
    {
        G[na+i].push_back(D);
        G[D].push_back(na+i);
        C[na+i][D]=1;
        cost[na+i][D]=cost[D][na+i]=0;
    }
}
 
bool BFS()
{
    int i,x;
    int dist[210];
    queue <int> Q;
    vector <int>::iterator it;
    for(i=1;i<=D;i++)
    {
        dist[i]=1000000000;
        viz[i]=0;
    }
    Q.push(S);
    viz[S]=0;
    dist[S]=0;
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(it=G[x].begin();it!=G[x].end();it++)
        {
            if(C[x][*it]>F[x][*it] && dist[*it]>dist[x]+cost[x][*it])
            {
                dist[*it]=dist[x]+cost[x][*it];
                viz[*it]=x;
                Q.push(*it);
            }
        }
    }
    if(viz[D]==0)
        return false;
    return true;
}
 
void Max_Flow()
{
    int i,x,val,now;
	vector <int>::iterator it;
    while(1)
    {
        if(BFS()==false)
            break;
        val=1000000000;
        x=D;
        while(viz[x])
        {
            val=min(val,C[viz[x]][x]-F[viz[x]][x]);
            x=viz[x];
        }
        x=D;
        while(viz[x])
        {
            F[viz[x]][x]+=val;
            F[x][viz[x]]-=val;
            x=viz[x];
        }
        maxflow+=val;
		for(i=1;i<=na;i++)
			used[i]=false;
		now=0;
		for(i=1;i<=na;i++)
		{
			for(it=G[i].begin();it!=G[i].end();it++)
			{
				if(F[i][*it]>0)
				{
					used[i]=true;
					now-=cost[i][*it];
				}
			}
		}
		if(maxflow==nb)
		{
			for(i=1;i<=na;i++)
				if(!used[i])
					now+=str[i];
		}
		sol=max(sol,now);
    }
	for(i=1;i<=na;i++)
		used[i]=false;
	now=0;
	for(i=1;i<=na;i++)
	{
		for(it=G[i].begin();it!=G[i].end();it++)
		{
			if(F[i][*it]>0)
			{
				used[i]=true;
				now-=cost[i][*it];
			}
		}
	}
	if(maxflow==nb)
	{
		for(i=1;i<=na;i++)
			if(!used[i])
				now+=str[i];
	}
	sol=max(sol,now);
	cout<<sol<<"\n";
}
 
int main()
{
    Citire();
    Construire_Retea_Transport();
    Max_Flow();
    return 0;
}
