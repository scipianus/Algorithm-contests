#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <deque>
#define pii pair<int, int>
#define INF 2000000000
using namespace std;
int n, S, L, v[100100];
int minim[400100], maxim[400100], rez[2], best[100100];
set <pii> bestset;

inline void Build(int nod, int st, int dr)
{
	if(st == dr)
	{
		minim[nod] = v[st];
		maxim[nod] = v[st];
		return;
	}
	int mij = (st + dr) / 2;
	Build(2 * nod, st, mij);
	Build(2 * nod + 1, mij + 1, dr);
	minim[nod] = min(minim[2 * nod], minim[2 * nod + 1]);
	maxim[nod] = max(maxim[2 * nod], maxim[2 * nod + 1]);
}

inline void Query(int nod, int st, int dr, int L, int R)
{
	if(L <= st && dr <= R)
	{
		rez[0] = min(rez[0], minim[nod]);
		rez[1] = max(rez[1], maxim[nod]);
		return;
	}
	int mij = (st + dr) / 2;
	if(L <= mij)
		Query(2 * nod, st, mij, L, R);
	if(mij + 1 <= R)
		Query(2 * nod + 1, mij + 1, dr, L, R);
}

int main()
{
	int i, st, dif;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> S >> L;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	Build(1, 1, n);
	best[0] = 0;
	st = 1;
	for(i = 1; i <= n; ++i)
	{
		if(i >= L && st - 1 <= i - L)
			bestset.insert(make_pair(best[i - L], i - L));
		rez[0] = INF;
		rez[1] = -INF;
		Query(1, 1, n, st, i);
		dif = rez[1] - rez[0];
		while(dif > S)
		{
			if(bestset.find(make_pair(best[st - 1], st - 1)) != bestset.end())
				bestset.erase(make_pair(best[st - 1], st - 1));
			st++;
			rez[0] = INF;
			rez[1] = -INF;
			Query(1, 1, n, st, i);
			dif = rez[1] - rez[0];
		}
		if(bestset.size())
			best[i] = (*bestset.begin()).first + 1;
		else
			best[i] = INF;
	}
	if(best[n] >= INF)
		best[n] = -1;
	cout << best[n] << "\n";
	return 0;
}
