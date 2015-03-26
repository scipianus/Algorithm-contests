#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define pii pair<int, int>
using namespace std;
int n, Q, nr[100100], niv[100100];
struct Muchie{int x, y, cost;};
Muchie M[100100];
vector <int> G[100100];
double total, combinatii, influenta[100100];

inline void DFS(int x, int lvl)
{
	niv[x] = lvl;
	nr[x] = 1;
	vector <int>::iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(!niv[*it])
		{
			DFS(*it, lvl + 1);
			nr[x] += nr[*it];
		}
}

int main()
{
	int i, newcost;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i < n; ++i)
	{
		cin >> M[i].x >> M[i].y >> M[i].cost;
		G[M[i].x].push_back(M[i].y);
		G[M[i].y].push_back(M[i].x);
	}
	combinatii = 1.0 * n * (n - 1) * (n - 2);
	DFS(1, 1);
	for(i = 1; i < n; ++i)
	{
		if(niv[M[i].x] < niv[M[i].y])
			swap(M[i].x, M[i].y);
		influenta[i] = 6.0 * (n - 2) * nr[M[i].x] * (n - nr[M[i].x]);
		total += 1.0 * M[i].cost * influenta[i];
	}
	cin >> Q;
	while(Q--)
	{
		cin >> i >> newcost;
		total -= 1.0 * (M[i].cost - newcost) * influenta[i];
		M[i].cost = newcost;
		printf("%.9lf\n", total / combinatii);
	}
	return 0;
}
