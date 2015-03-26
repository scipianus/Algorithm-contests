#include <iostream>
using namespace std;
int T, n, sol, sumL[1010][1010], sumC[1010][1010];
char mat[1010][1010];

int main()
{
	int i, j;
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(i = 1; i <= n; ++i)
			cin >> (mat[i] + 1);
		sol = 0;
		for(i = n; i > 0; --i)
		{
			for(j = n; j > 0; --j)
			{
				sumL[i][j] = sumL[i][j + 1];
				sumC[i][j] = sumC[i + 1][j];
				if(mat[i][j] == '#')
				{
					sumL[i][j]++;
					sumC[i][j]++;
				}
				else
				{
					if(sumL[i][j] == 0 && sumC[i][j] == 0)
						sol++;
				}
			}
		}
		cout << sol << "\n";
		for(i = 1; i <= n; ++i)
			for(j = 1; j <= n; ++j)
				sumL[i][j] = sumC[i][j] = 0;
	}
	return 0;
}
