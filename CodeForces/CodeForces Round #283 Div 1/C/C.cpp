#include <iostream>
#include <algorithm>
#include <set>
#define piii pair<int, pair<int, int> >
using namespace std;
int n, m, sol[100100];
struct Interval{int st, dr, nr, ind;};
Interval v[100100], actor[100100];
multiset <piii> S;

inline bool Sortare(Interval A, Interval B)
{
	if(A.st == B.st)
		return A.dr > B.dr;
	return A.st < B.st;
}

int main()
{
	int i, j;
	multiset <piii>::iterator it;
	piii now;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> v[i].st >> v[i].dr;
		v[i].ind = i;
	}
	sort(v + 1, v + n + 1, Sortare);
	cin >> m;
	for(i = 1; i <= m; ++i)
	{
		cin >> actor[i].st >> actor[i].dr >> actor[i].nr;
		actor[i].ind = i;
	}
	sort(actor + 1, actor + m + 1, Sortare);
	
	j = 1;
	for(i = 1; i <= n; ++i)
	{
		while(j <= m && actor[j].st <= v[i].st)
		{
			S.insert(make_pair(actor[j].dr, make_pair(actor[j].nr, actor[j].ind)));
			j++;
		}
		it = S.lower_bound(make_pair(v[i].dr, make_pair(0, 0)));
		if(it == S.end())
		{
			cout << "NO\n";
			return 0;
		}
		now = *it;
		S.erase(it);
		now.second.first--;
		if(now.second.first > 0)
			S.insert(now);
		sol[v[i].ind] = now.second.second;
	}
	cout << "YES\n";
	for(i = 1; i <= n; ++i)
		cout << sol[i] << ' ';
	cout << "\n";
	return 0;
}
