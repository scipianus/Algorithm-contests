#include <iostream>
#include <algorithm>
#include <set>
#define pii pair<int, pair<int, int> >
#define INF 2000100000
using namespace std;
int n, best[200100], nrc, sol;
pair <int, int> v[200100];
int aint[800100], A[200100];

inline void Update(int nod, int st, int dr, int poz, int val)
{
	if(st == dr)
	{
		aint[nod] = max(aint[nod], val);
		return;
	}
	int mij = (st + dr) / 2;
	if(poz <= mij)
		Update(2 * nod, st, mij, poz, val);
	else
		Update(2 * nod + 1, mij + 1, dr, poz, val);
	aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
}

inline int Query(int nod, int st, int dr, int poz)
{
	if(dr <= poz)
		return aint[nod];
	int mij = (st + dr) / 2;
	int rez = Query(2 * nod, st, mij, poz);
	if(mij + 1 <= poz)
		rez = max(rez, Query(2 * nod + 1, mij + 1, dr, poz));
	return rez;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, poz;
	set <pii>::iterator it;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i].first >> v[i].second;
	sort(v + 1, v + n + 1);
	for(i = 1; i <= n; ++i)
		A[i] = v[i].first + v[i].second;
	sort(A + 1, A + n + 1);
	for(i = 1; i <= n; ++i)
	{
		poz = upper_bound(A + 1, A + n + 1, v[i].first - v[i].second) - A - 1;
		if(poz < 1)
			best[i] = 1;
		else
			best[i] = 1 + Query(1, 1, n, poz);
		poz = lower_bound(A + 1, A + n + 1, v[i].first + v[i].second) - A;
		Update(1, 1, n, poz, best[i]);
		sol = max(sol, best[i]);
	}
	cout << sol << "\n";
	return 0;
}
