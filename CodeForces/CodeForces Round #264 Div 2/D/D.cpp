#include <iostream>
#include <algorithm>
using namespace std;
int n, K, best[1010], sol;
struct Element
{
	int poz[5];
	bool operator <(const Element &A) const
	{
		return poz[0] < A.poz[0];
	}
};
Element v[1010];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, k, x;
	bool ok;
	cin >> n >> K;
	for(i = 0; i < K; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			cin >> x;
			v[x].poz[i] = j;
		}
	}
	sort(v + 1, v + n + 1);
	for(i = 1; i <= n; ++i)
	{
		best[i] = 1;
		for(j = 1; j < i; ++j)
		{
			ok = true;
			for(k = 0; k < K; ++k)
				if(v[j].poz[k] > v[i].poz[k])
					ok = false;
			if(ok)
				best[i] = max(best[i], best[j] + 1);
		}
		sol = max(sol, best[i]);
	}
	cout << sol << "\n";
	return 0;
}
