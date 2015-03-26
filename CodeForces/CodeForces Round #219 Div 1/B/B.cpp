#include <iostream>
using namespace std;
int n, m, Q, nr[43][43][43][43];
char mat[45][45];
bool good[43][43][43][43];

int main()
{
	int i, j, i1, j1, i2, j2, Nr;
	cin >> n >> m >> Q;
	for(i = 1; i <= n; ++i)
		cin >> (mat[i] + 1);
	
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= m; ++j)
		{
			if(mat[i][j] == '1')
				continue;
			i1 = i;
			while(i1 <= n && mat[i1][j] == '0')
			{
				good[i][j][i1][j] = true;
				i1++;
			}
			j1 = j + 1;
			while(j1 <= m && mat[i][j1] == '0')
			{
				good[i][j][i][j1] = true;
				j1++;
			}
		}
	}
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= m; ++j)
		{
			for(i1 = i + 1; i1 <= n; ++i1)
			{
				if(!good[i][j][i1][j])
					continue;
				j1 = j + 1;
				while(j1 <= m && good[i][j1][i1][j1])
				{
					good[i][j][i1][j1] = true;
					j1++;
				}
			}
		}
	}
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= m; ++j)
		{
			for(i1 = i; i1 <= n; ++i1)
			{
				for(j1 = j; j1 <= m; ++j1)
				{
					nr[i][j][i1][j1] = nr[i][j][i1 - 1][j1] + nr[i][j][i1][j1 - 1] - nr[i][j][i1 - 1][j1 - 1];
					if(mat[i1][j1] == '1')
						continue;
					Nr = 0;
					i2 = i1;
					j2 = j;
					while(i2 >= i && j2 <= j1)
					{
						while(!good[i2][j2][i1][j1] && j2 <= j1)
							j2++;
						if(j2 <= j1)
							Nr += j1 - j2 + 1;
						i2--;
					}
					nr[i][j][i1][j1] += Nr;
				}
			}
		}
	}
	
	while(Q--)
	{
		cin >> i >> j >> i1 >> j1;
		cout << nr[i][j][i1][j1] << "\n";
	}
	return 0;
}
