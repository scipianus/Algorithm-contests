#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct Vaca{int a, b;};
Vaca v[50100];
long long sol = 2000000000000000000LL;

inline bool Sortare1(Vaca x, Vaca y)
{
	if(x.a == y.a)
		return x.b > y.b;
	return x.a < y.a;
}

inline bool Sortare2(Vaca x, Vaca y)
{
	if(x.b == y.b)
		return x.a < y.a;
	return x.b > y.b;
}

inline bool Sortare3(Vaca x, Vaca y)
{
	if(x.b - x.a == y.b - y.a)
		return x.a < y.a;
	return (x.b - x.a) < (y.b - y.a);
}

inline bool Sortare4(Vaca x, Vaca y)
{
	return (x.b + x.a) > (y.b + y.a);
}

inline void Solve()
{
	int i;
	long long sum = 0, now = -2000000000000000000LL;
	for(i = n; i > 0; --i)
	{
		now = max(now, sum - 1LL * v[i].b);
		sum += 1LL * v[i].a;
	}
	sol = min(sol, now);
}

int main()
{
	int i;
	long long sum = 0LL, now = -2000000000000000000LL;
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> v[i].a >> v[i].b;
		sum += 1LL * v[i].a;
	}
	sort(v + 1, v + n + 1, Sortare1);
	Solve();
	sort(v + 1, v + n + 1, Sortare2);
	Solve();
	sort(v + 1, v + n + 1, Sortare3);
	Solve();
	sort(v + 1, v + n + 1, Sortare4);
	Solve();
	for(i = 1; i <= n; ++i)
	{
		now = max(now, sum - 1LL * v[i].a - 1LL * v[i].b);
		sum -= 1LL * v[i].a;
	}
	sol = min(sol, now);
	cout << sol << "\n";
	return 0;
}
