#include <iostream>
using namespace std;
int n, m, K, A[110][110], sol[110], nr[110];
bool locked[110];

int main()
{
	int i, j;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m >> K;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			cin >> A[i][j];
	for(j = 1; j <= m; ++j)
	{
		for(i = 1; i <= K; ++i)
			nr[i] = 0;
		for(i = 1; i <= n; ++i)
		{
			if(sol[i] || A[i][j] == 0)
				continue;
			if(locked[A[i][j]])
				sol[i] = j;
			else
				nr[A[i][j]]++;
		}
		for(i = 1; i <= n; ++i)
		{
			if(sol[i] || A[i][j] == 0)
				continue;
			if(nr[A[i][j]] > 1)
			{
				sol[i] = j;
				locked[A[i][j]] = true;
			}
		}
	}
	for(i = 1; i <= n; ++i)
		cout << sol[i] << "\n";
	return 0;
}
