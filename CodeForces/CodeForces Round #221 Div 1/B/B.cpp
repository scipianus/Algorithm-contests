#include <iostream>
#include <vector>
#include <cmath>
#define pii pair<int, int>
using namespace std;
int n, m, nr[5010][5010], sum[5010][5010], sol;
char mat[5010][5010];

int main()
{
	int i, j, area, d;
	pii now;
	cin >> n >> m;
	for(i = 1; i <= n; ++i)
		cin >> (mat[i] + 1);
	for(i = 1; i <= n; ++i)
	{
		now.first = m + 1; now.second = 0;
		for(j = 1; j <= m; ++j)
		{
			if(mat[i][j] == '0')
			{
				if(now.second != 0)
					nr[now.first][now.second]++;
				now.first = m + 1; now.second = 0;
			}
			else
			{
				now.first = min(now.first, j);
				now.second = j;
			}
		}
		if(now.second != 0)
			nr[now.first][now.second]++;
	}
	for(d = m; d > 0; --d)
	{
		for(i = 1, j = d; j <= m; ++i, ++j)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j + 1] - sum[i - 1][j + 1] + nr[i][j];
		}
	}
	for(d = m; d > 0; --d)
	{
		for(i = 1, j = d; j <= m; ++i, ++j)
		{
			if((j - i + 1) * n <= sol)
				continue;
			area = (j - i + 1) * sum[i][j];
			sol = max(sol, area);
		}
	}
	cout << sol << "\n";
	return 0;
}
