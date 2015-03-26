#include <iostream>
using namespace std;
int n, m, K, nr[2010][2010], sum[2010];
char mat[2010][2010];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, t;
	cin >> n >> m >> K;
	for(i = 1; i <= n; ++i)
		cin >> (mat[i] + 1);
	for(i = 1; i <= n; ++i)
	{
		t = i - 1;
		for(j = 1; j <= m; ++j)
		{
			if(j - t > 0 && mat[i][j - t] == 'R')
				nr[i][j]++;
			if(j + t <= m && mat[i][j + t] == 'L')
				nr[i][j]++;
			if(i - t > 0 && mat[i - t][j] == 'D')
				nr[i][j]++;
			if(i + t <= n && mat[i + t][j] == 'U')
				nr[i][j]++;
		}
	}
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			sum[j] += nr[i][j];
	for(j = 1; j <= m; ++j)
		cout << sum[j] << ' ';
	cout << "\n";
	return 0;
}
