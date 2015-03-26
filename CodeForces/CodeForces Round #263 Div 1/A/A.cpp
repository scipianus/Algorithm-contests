#include <iostream>
#include <algorithm>
using namespace std;
int n, v[300100];
long long sol, sum[300100], sol2;

inline void Solve(int st, int dr)
{
	if(st > dr)
		return;
	sol += sum[dr] - sum[st - 1];
	if(st == dr)
		return;
	int mij = (st + dr) / 2;
	Solve(st, mij);
	Solve(mij + 1, dr);
}

inline void Solve2(int st, int dr)
{
	sol2 += sum[dr] - sum[st - 1];
	if(st == dr)
		return;
	sol2 += v[st];
	Solve2(st + 1, dr);
}

int main()
{
	int i, j;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	sort(v + 1, v + n + 1);
	for(i = 1, j = n; i <= j; ++i, --j)
		swap(v[i], v[j]);
	for(i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + 1LL * v[i];
	Solve(1, n);
	for(i = 1, j = n; i <= j; ++i, --j)
		swap(v[i], v[j]);
	for(i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + 1LL * v[i];
	Solve2(1, n);
	sol = max(sol, sol2);
	cout << sol2 << "\n";
	return 0;
}
