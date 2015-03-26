#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#define pdi pair<double, int>
using namespace std;
int n, S1, S2, D, C[810][810], F[810][810], maxflow, pred[810];
struct Punct{double x, y;};
Punct P[410];
vector <int> G[810];
double sol, best[810], cost[810][810], sum;
queue <int> Q;
int H[810],poz[810],size;

inline int Min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
 
inline void Swap(int &a,int &b)
{
    if(a==b)
        return;
    a^=b^=a^=b;
}

inline void Citire()
{
	int i;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> P[i].x >> P[i].y;
}

inline double Dist(Punct A, Punct B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

inline void ConstruireRetea()
{
	int i, j;
	S1 = 2 * n + 1;
	S2 = 2 * n + 2;
	D = 2 * n + 3;
	
	G[S1].push_back(S2);
	G[S2].push_back(S1);
	C[S1][S2] = n - 1;
	
	for(i = 1; i <= n; ++i)
	{
		G[S2].push_back(i);
		G[i].push_back(S2);
		C[S2][i] = 2;
		for(j = 1; j <= n; ++j)
		{
			if(P[i].y > P[j].y)
			{
				G[i].push_back(n + j);
				G[n + j].push_back(i);
				C[i][n + j] = 2;
				cost[i][n + j] = Dist(P[i], P[j]);
				cost[n + j][i] = -Dist(P[i], P[j]);
			}
		}
	}
	
	for(i = 1; i <= n; ++i)
	{
		G[n + i].push_back(D);
		G[D].push_back(n + i);
		C[n + i][D] = 1;
	}
}

inline void Bellman_Ford()
{
    queue <int> Q;
    vector <int>::iterator it;
    int i,x;
    for(i=1;i<=n;i++)
        best[i]=2000000000.0;
    best[S1]=0.0;
    Q.push(S1);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(it=G[x].begin();it!=G[x].end();it++)
        {
            if(C[x][*it]>0 && best[*it]>best[x]+cost[x][*it])
            {
                best[*it]=best[x]+cost[x][*it];
                Q.push(*it);
            }
        }
    }
    sum=best[D];
}
 
inline void Up_Heap(int nod)
{
    int tata=nod/2;
    while(tata>0 && best[H[nod]]<best[H[tata]])
    {
        Swap(H[nod],H[tata]);
        poz[H[nod]]=nod;
        poz[H[tata]]=tata;
        nod=tata;
        tata=nod/2;
    }
}
 
inline void Down_Heap(int nod)
{
    int tata=0;
    while(nod!=tata)
    {
        tata=nod;
        if(2*tata<=size && best[H[nod]]>best[H[2*tata]])
            nod=2*tata;
        if(2*tata+1<=size && best[H[nod]]>best[H[2*tata+1]])
            nod=2*tata+1;
        Swap(H[nod],H[tata]);
        poz[H[nod]]=nod;
        poz[H[tata]]=tata;
    }
}
 
inline bool Dijkstra()
{
    int i,x;
    vector <int>::iterator it;
    for(i=1;i<=D;i++)
    {
        if(best[i]==2000000000.0)
            continue;
        for(it=G[i].begin();it!=G[i].end();it++)
        {
            if(best[*it]==2000000000.0)
                continue;
            cost[i][*it]+=best[i]-best[*it];
        }
    }
    for(i=1;i<=D;i++)
    {
        best[i]=2000000000.0;
        pred[i]=0;
        H[i]=i;
        poz[i]=i;
    }
    best[S1]=0;
    H[1]=S1; H[S1]=1;
    poz[1]=S1; poz[S1]=1;
    size=D;
    while(size>1 && best[H[1]]!=2000000000.0)
    {
        x=H[1];
        H[1]=H[size]; poz[H[1]]=1;
        size--;
        if(size>1)
            Down_Heap(1);
        for(it=G[x].begin();it!=G[x].end();it++)
        {
            if(C[x][*it]>F[x][*it] && best[*it]>best[x]+cost[x][*it])
            {
                best[*it]=best[x]+cost[x][*it];
                pred[*it]=x;
                Up_Heap(poz[*it]);
            }
        }
    }
    if(best[D]==2000000000.0)
        return false;
    return true;
}
 
inline void MinCostMaxFlow()
{
    int x,val;
    while(1)
    {
        if(Dijkstra()==false)
            return;
        val=2000000000;
        x=D;
        while(pred[x])
        {
            val=Min(val,C[pred[x]][x]-F[pred[x]][x]);
            x=pred[x];
        }
        x=D;
        while(pred[x])
        {
            F[pred[x]][x]+=val;
            F[x][pred[x]]-=val;
            x=pred[x];
        }
		maxflow += val;
        sum += best[D];
        sol += 1.0 * val * sum;
    }
}

inline void Afisare()
{
	if(maxflow < n - 1)
		printf("-1\n");
	else
		printf("%.7lf\n", sol);
}

int main()
{
	Citire();
	ConstruireRetea();
	MinCostMaxFlow();
	Afisare();
	return 0;
}
