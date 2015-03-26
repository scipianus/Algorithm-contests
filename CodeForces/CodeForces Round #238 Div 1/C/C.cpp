#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <queue>
#define pii pair<int, int>
using namespace std;
int n,m,grad[100100],fii[100100],father[100100],niv[100100];
set <int> G[100100];
bool viz[100100];
queue <int> Q;
 
inline void DFS(int x,int tata,int lvl)
{
    viz[x]=true;
    niv[x]=lvl;
    set <int>::iterator it;
    for(it=G[x].begin();it!=G[x].end();it++)
    {
        if(!viz[*it])
        {
            father[*it]=x;
            DFS(*it,x,lvl+1);
        }
        if(niv[x]<niv[*it])
            fii[x]++;
    }
}
 
inline void Solve()
{
    int i,x,a,b;
    set <int>::iterator it;
    for(i=1;i<=n;i++)
        if(fii[i]==0)
            Q.push(i);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        if(grad[x]%2==1)
        {
            G[x].erase(father[x]);
            fii[father[x]]--;
            if(fii[father[x]]==0)
                Q.push(father[x]);
        }
        for(it=G[x].begin();it!=G[x].end();it++)
        {
            a=*it;
            it++;
            b=*it;
			cout << a << ' ' << x << ' ' << b << "\n";
            grad[a]--;
            grad[b]--;
            if(niv[a]<niv[x])
            {
                fii[a]--;
                G[a].erase(x);
                if(fii[a]==0)
                    Q.push(a);
            }
            if(niv[b]<niv[x])
            {
                fii[b]--;
                G[b].erase(x);
                if(fii[b]==0)
                    Q.push(b);
            }
        }
    }
}

int main()
{
	int i, x, y;
	std::ios_base::sync_with_stdio(false);
	//ifstream cin("C.in");
	cin >> n >> m;
	if(m % 2 == 1)
	{
		cout << "No solution\n";
		return 0;
	}
	for(i = 1; i <= m; ++i)
	{
		cin >> x >> y;
		G[x].insert(y);
        grad[x]++;
        G[y].insert(x);
        grad[y]++;
	}
	DFS(1,0,0);
	Solve();
	return 0;
}
