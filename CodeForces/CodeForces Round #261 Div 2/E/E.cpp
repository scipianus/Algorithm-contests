#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, best[300100], bst[300100], sol;
struct Muchie
{
	int x, y, cost;
	bool operator <(const Muchie &A) const
	{
		return cost < A.cost;
	}
};
Muchie M[300100];
vector <int> G[300100];

int main()
{
	int i, j, x, y;
	vector <int>::iterator it;
	cin >> n >> m;
	for(i = 1; i <= m; ++i)
		cin >> M[i].x >> M[i].y >> M[i].cost;
	sort(M + 1, M + m + 1);
	for(i = 1; i <= m; ++i)
	{
		best[i] = 1;
		G[M[i].y].push_back(i);
	}
	for(i = 1; i <= m; ++i)
	{
		j = i;
		while(M[j].cost == M[i].cost)
		{
			x = M[j].x;
			best[j] = max(best[j], bst[x] + 1);
			j++;
		}
		j = i;
		while(M[j].cost == M[i].cost)
		{
			y = M[j].y;
			bst[y] = max(bst[y], best[j]);
			j++;
		}
		i = j - 1;
	}
	for(i = 1; i <= m; ++i)
		sol = max(sol, best[i]);
	cout << sol << "\n";
	return 0;
}
