#include <iostream>
using namespace std;
int n, K;
long long p[3010], sol, best[3010][1510];

int main()
{
	int i, j, ind;
	cin >> n >> K;
	for(i = 1; i <= n; ++i)
		cin >> p[i];
	for(i = 0; i < K; ++i)
	{
		ind = 2 * i + 1;
		for(j = 2 * i + 2; j <= n; ++j)
		{
			best[j][i + 1] = max(best[ind - 1][i] + p[j] - p[ind], best[j - 1][i + 1]);
			if(best[j - 1][i] - p[j] > best[ind - 1][i] - p[ind])
				ind = j;
			sol = max(sol, best[j][i + 1]);
		}
	}
	cout << sol << "\n";
	return 0;
}
