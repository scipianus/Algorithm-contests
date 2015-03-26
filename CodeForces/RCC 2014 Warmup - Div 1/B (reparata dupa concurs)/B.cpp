#include <iostream>
#include <algorithm>
#define INF 2000000000000000000LL
using namespace std;
int n, m, B, pret[110], nrB[110], cf[110], ord[110];
long long best[1100000], sol = INF;

inline bool Sortare(int i, int j)
{
	return nrB[i] < nrB[j];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, b, x, nr, conf;
	cin >> n >> m >> B;
	for(i = 1; i <= n; ++i)
	{
		cin >> pret[i] >> nrB[i] >> nr;
		cf[i] = 0;
		while(nr)
		{
			cin >> x;
			x--;
			cf[i] |= (1 << x);
			nr--;
		}
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, Sortare);
	for(conf = 0; conf < (1 << m); ++conf)
		best[conf] = INF;
	best[0] = 0;
	for(b = 1; b <= n; ++b)
	{
		i = ord[b];
		for(conf = (1 << m) - 1; conf >= 0; --conf)
			best[conf | cf[i]] = min(best[conf | cf[i]], best[conf] + 1LL * pret[i]);
		sol = min(sol, best[(1 << m) - 1] + 1LL * nrB[i] * B);
	}
	if(sol < INF)
		cout << sol << "\n";
	else
		cout << "-1\n";
	return 0;
}
