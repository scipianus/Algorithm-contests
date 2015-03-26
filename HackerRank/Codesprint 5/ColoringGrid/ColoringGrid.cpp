#include <iostream>
#define MOD 1000000007
using namespace std;
int T, n, m, K, mat[10][10], sol;

inline void Back(int x, int y)
{
	if(x == n + 1)
	{
		sol++;
		if(sol == MOD)
			sol = 0;
		return;
	}
	int i, nextX, nextY;
	if(y < m)
	{
		nextX = x;
		nextY = y + 1;
	}
	else
	{
		nextX = x + 1;
		nextY = 1;
	}
	for(i = 1; i <= K; ++i)
	{
		if(i != mat[x - 1][y] && i != mat[x][y - 1])
		{
			mat[x][y] = i;
			Back(nextX, nextY);
		}
	}
}

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> K;
		sol = 0;
		Back(1, 1);
		cout << sol << "\n";
	}
	return 0;
}
