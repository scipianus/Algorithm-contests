#include <iostream>
#include <set>
#include <cassert>
#define pii pair<int, int>
using namespace std;
int n, m, v[100100];
struct Interval
{
	int st, dr;
	Interval()
	{
		st = dr = 0;
	}
	Interval(int s, int d)
	{
		st = s;
		dr = d;
	}
	bool operator <(const Interval &A) const
	{
		return (dr - st) > (A.dr - A.st);
	}
};
set <Interval> S;
set <pii> S2;

int main()
{
	Interval best, urm;
	pii now;
	int i, x, y, st, dr;
	set <pii>::iterator it;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	if(n <= 5000 && m <= 5000)
	{
		int sol = 0;
		st = 1;
		dr = 1;
		while(dr <= n)
		{
			if(dr + 1 <= n && v[dr + 1] == v[dr] + 1)
				dr++;
			else
			{
				sol = max(sol, dr - st + 1);
				st = dr + 1;
				dr++;
			}
		}
		cout << sol << "\n";
		while(m--)
		{
			cin >> x >> y;
			v[x] = y;
			sol = 0;
			st = 1;
			dr = 1;
			while(dr <= n)
			{
				if(dr + 1 <= n && v[dr + 1] == v[dr] + 1)
					dr++;
				else
				{
					sol = max(sol, dr - st + 1);
					st = dr + 1;
					dr++;
				}
			}
			cout << sol << "\n";
		}
		return 0;
	}
	st = 1;
	dr = 1;
	while(dr <= n)
	{
		if(dr + 1 <= n && v[dr + 1] == v[dr] + 1)
			dr++;
		else
		{
			S.insert(Interval(st , dr));
			S2.insert(make_pair(st, dr));
			st = dr + 1;
			dr++;
		}
	}
	if(dr <= n)
	{
		S.insert(Interval(st , dr));
		S2.insert(make_pair(st, dr));
		st = dr + 1;
		dr++;
	}
	best = *S.begin();
	cout << (best.dr - best.st + 1) << "\n";
	while(m--)
	{
		cin >> x >> y;
		assert(1 <= x && x <= n);
		if(v[x] == y)
		{
			best = *S.begin();
			cout << (best.dr - best.st + 1) << "\n";
			continue;
		}
		it = S2.upper_bound(make_pair(x, n + 1));
		it--;
		now = *it;
		assert(now.first <= x && x <= now.second);
		S2.erase(now);
		S.erase(Interval(now.first, now.second));
		if(now.first < x)
		{
			S.insert(Interval(now.first, x - 1));
			S2.insert(make_pair(now.first, x - 1));
		}
		if(now.second > x)
		{
			S.insert(Interval(x + 1, now.second));
			S2.insert(make_pair(x + 1, now.second));
		}
		v[x] = y;
		if(1 < x && x < n && v[x - 1] + 1 == v[x] && v[x] == v[x + 1] - 1)
		{
			it = S2.upper_bound(make_pair(x - 1, n + 1));
			it--;
			now = *it;
			urm.st = now.first;
			S2.erase(now);
			S.erase(Interval(now.first, now.second));
			it = S2.upper_bound(make_pair(x + 1, n + 1));
			it--;
			now = *it;
			urm.dr = now.second;
			S2.erase(now);
			S.erase(Interval(now.first, now.second));
			S.insert(urm);
			S2.insert(make_pair(urm.st, urm.dr));
		}
		else
		{
			if(1 < x && v[x - 1] + 1 == v[x])
			{
				it = S2.upper_bound(make_pair(x - 1, n + 1));
				it--;
				now = *it;
				urm.st = now.first;
				S2.erase(now);
				S.erase(Interval(now.first, now.second));
				urm.dr = x;
				S.insert(urm);
				S2.insert(make_pair(urm.st, urm.dr));
			}
			else
			{
				if(x < n && v[x] + 1 == v[x + 1])
				{
					it = S2.upper_bound(make_pair(x + 1, n + 1));
					it--;
					now = *it;
					urm.st = x;
					urm.dr = now.second;
					S2.erase(now);
					S.erase(Interval(now.first, now.second));
					S.insert(urm);
					S2.insert(make_pair(urm.st, urm.dr));
				}
				else
				{
					urm.st = urm.dr = x;
					S.insert(urm);
					S2.insert(make_pair(urm.st, urm.dr));
				}
			}
		}
		best = *S.begin();
		cout << (best.dr - best.st + 1) << "\n";
	}
	return 0;
}
