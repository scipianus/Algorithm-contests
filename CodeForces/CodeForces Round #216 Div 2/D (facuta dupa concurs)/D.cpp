#include <iostream>
#include <queue>
#define pii pair<int, int>
using namespace std;
int n, K, p[3010], best[3010][3010], sol;
bool sigur[3010], maybe[3010];
queue <pii> Q;

int main()
{
	int i, j, a, b;
	pii now;
	cin >> n >> K;
	for(i = 1; i <= n; ++i)
		cin >> p[i];
	for(i = n; i > 0; --i)
	{
		sigur[i] = (sigur[i + 1] | (p[i] == 100));
		maybe[i] = (maybe[i + 1] | (p[i] > 0));
	}
	for(i = 1; i <= n + 1; ++i)
		for(j = i; j <= n + 2; ++j)
			best[i][j] = 1000000000;
	best[1][2] = 0;
	Q.push(make_pair(1, 2));
	while(!Q.empty())
	{
		now = Q.front();
		Q.pop();
		// in viata este a si intervalul [b,n]
		a = now.first;
		b = now.second;
		if(best[a][b] == K || a > n || b > n)
			continue;
		// moare doar a
		if(p[a] != 100 && maybe[b])
		{
			if(best[b][b + 1] > best[a][b] + 1)
			{
				best[b][b + 1] = best[a][b] + 1;
				Q.push(make_pair(b, b + 1));
			}
		}
		// moare doar b
		if(!sigur[b] && p[a] > 0)
		{
			if(best[a][b + 1] > best[a][b] + 1)
			{
				best[a][b + 1] = best[a][b] + 1;
				Q.push(make_pair(a, b + 1));
			}
		}
		// mor si a si b
		if(p[a] > 0 && maybe[b])
		{
			if(best[b + 1][b + 2] > best[a][b] + 1)
			{
				best[b + 1][b + 2] = best[a][b] + 1;
				Q.push(make_pair(b + 1, b + 2));
			}
		}
	}
	for(i = 1; i <= n + 1; ++i)
		for(j = i + 1; j <= n + 2; ++j)
			if(best[i][j] <= K)
				sol++;
	cout << sol << "\n";
	return 0;
}
