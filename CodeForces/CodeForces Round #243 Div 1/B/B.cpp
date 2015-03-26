#include <iostream>
using namespace std;
int n, m, K, mat[110][110], sol = 11;
bool modificat[110][110];

inline bool Interior(int x, int y)
{
	if(x < 1 || x > n || y < 1 || y > m)
		return false;
	return true;
}

inline bool Rau(int x, int y)
{
	int c = mat[x][y];
	if(Interior(x + 1, y) && Interior(x, y + 1) && Interior(x + 1, y + 1))
	{
		if(mat[x + 1][y] == 1 - c && mat[x][y + 1] == 1 - c && mat[x + 1][y + 1] == 1 - c)
			return true;
		if(mat[x + 1][y] == c && mat[x][y + 1] == c && mat[x + 1][y + 1] == 1 - c)
			return true;
		if(mat[x + 1][y] == c && mat[x][y + 1] == 1 - c && mat[x + 1][y + 1] == c)
			return true;
		if(mat[x + 1][y] == 1 - c && mat[x][y + 1] == c && mat[x + 1][y + 1] == c)
			return true;
	}
	if(Interior(x - 1, y) && Interior(x, y - 1) && Interior(x - 1, y - 1))
	{
		if(mat[x - 1][y] == 1 - c && mat[x][y - 1] == 1 - c && mat[x - 1][y - 1] == 1 - c)
			return true;
		if(mat[x - 1][y] == c && mat[x][y - 1] == c && mat[x - 1][y - 1] == 1 - c)
			return true;
		if(mat[x - 1][y] == c && mat[x][y - 1] == 1 - c && mat[x - 1][y - 1] == c)
			return true;
		if(mat[x - 1][y] == 1 - c && mat[x][y - 1] == c && mat[x - 1][y - 1] == c)
			return true;
	}
	if(Interior(x + 1, y) && Interior(x, y - 1) && Interior(x + 1, y - 1))
	{
		if(mat[x + 1][y] == 1 - c && mat[x][y - 1] == 1 - c && mat[x + 1][y - 1] == 1 - c)
			return true;
		if(mat[x + 1][y] == c && mat[x][y - 1] == c && mat[x + 1][y - 1] == 1 - c)
			return true;
		if(mat[x + 1][y] == c && mat[x][y - 1] == 1 - c && mat[x + 1][y - 1] == c)
			return true;
		if(mat[x + 1][y] == 1 - c && mat[x][y - 1] == c && mat[x + 1][y - 1] == c)
			return true;
	}
	if(Interior(x - 1, y) && Interior(x, y + 1) && Interior(x - 1, y + 1))
	{
		if(mat[x - 1][y] == 1 - c && mat[x][y + 1] == 1 - c && mat[x - 1][y + 1] == 1 - c)
			return true;
		if(mat[x - 1][y] == c && mat[x][y + 1] == c && mat[x - 1][y + 1] == 1 - c)
			return true;
		if(mat[x - 1][y] == c && mat[x][y + 1] == 1 - c && mat[x - 1][y + 1] == c)
			return true;
		if(mat[x - 1][y] == 1 - c && mat[x][y + 1] == c && mat[x - 1][y + 1] == c)
			return true;
	}
	return false;
}

inline bool Verif()
{
	int i, j;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if(Rau(i, j))
				return false;
	return true;
}

inline void Back(int pas)
{
	if(pas >= sol)
		return;
	if(Verif())
	{
		sol = min(sol, pas);
		return;
	}
	if(pas == K)
		return;
	int i, j;
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= m; ++j)
		{
			if(Rau(i, j) && !modificat[i][j])
			{
				modificat[i][j] = true;
				mat[i][j] = 1 - mat[i][j];
				Back(pas + 1);
				mat[i][j] = 1 - mat[i][j];
				modificat[i][j] = false;
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j;
	cin >> n >> m >> K;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			cin >> mat[i][j];
	Back(0);
	if(sol == 11)
		sol = -1;
	cout << sol << "\n";
	return 0;
}
