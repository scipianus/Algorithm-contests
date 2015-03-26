#include <iostream>
using namespace std;
int n, mat[2010][2010], X[2], Y[2];
long long sol, sum[4][2010][2010], maxwhite = -1LL, maxblack = -1LL;

int main()
{
	int i, j;
	long long now;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			cin >> mat[i][j];
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			sum[0][i][j] = sum[0][i - 1][j - 1] + 1LL * mat[i][j];
	for(i = 1; i <= n; ++i)
		for(j = n; j > 0; --j)
			sum[1][i][j] = sum[1][i - 1][j + 1] + 1LL * mat[i][j];
	for(i = n; i > 0; --i)
		for(j = 1; j <= n; ++j)
			sum[2][i][j] = sum[2][i + 1][j - 1] + 1LL * mat[i][j];
	for(i = n; i > 0; --i)
		for(j = n; j > 0; --j)
			sum[3][i][j] = sum[3][i + 1][j + 1] + 1LL * mat[i][j];
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			now = sum[0][i][j] + sum[1][i][j] + sum[2][i][j] + sum[3][i][j] - 3LL * mat[i][j];
			if((i + j) % 2 == 0 && maxblack < now)
			{
				maxblack = now;
				X[0] = i;
				Y[0] = j;
			}
			if((i + j) % 2 == 1 && maxwhite < now)
			{
				maxwhite = now;
				X[1] = i;
				Y[1] = j;
			}
		}
	}
	sol = maxwhite + maxblack;
	cout << sol << "\n";
	cout << X[0] << ' ' << Y[0] << ' ' << X[1] << ' ' << Y[1] << "\n";
	return 0;
}
