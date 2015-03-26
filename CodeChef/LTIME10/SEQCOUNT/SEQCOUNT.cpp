#include <iostream>
#define MOD 1000000007
using namespace std;
int n, K, D, nr[410][410][410], sol;

int main()
{
	int i, j, k, p;
	cin >> n >> K >> D;
	for(i = 1; i <= n; ++i)
		nr[1][i][i] = 1;
	for(i = 1; i < K; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			for(k = 1; k <= j; ++k)
			{
				if(nr[i][j][k] == 0)
					continue;
				for(p = k + 1; p <= k + D && p + j <= n; ++p)
				{
					nr[i + 1][j + p][p] += nr[i][j][k];
					if(nr[i + 1][j + p][p] >= MOD)
						nr[i + 1][j + p][p] -= MOD;
				}
			}
		}
	}
	for(i = 1; i <= n; ++i)
	{
		sol += nr[K][n][i];
		if(sol >= MOD)
			sol -= MOD;
	}
	cout << sol << "\n";
	return 0;
}
