#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, K, ramas;
char mat[510][510];
bool viz[510][510];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline void DFS(int x, int y)
{
	if(ramas > 0)
	{
		viz[x][y] = true;
		ramas--;
		int k;
		for(k = 0; k < 4; ++k)
		{
			if(mat[x + dx[k]][y + dy[k]] == '.' && !viz[x + dx[k]][y + dy[k]])
				DFS(x + dx[k], y + dy[k]);
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m >> K;
	for(i = 1; i <= n; ++i)
		cin >> (mat[i] + 1);
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if(mat[i][j] == '.')
				ramas++;
	ramas -= K;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if(mat[i][j] == '.')
				DFS(i, j);
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if(mat[i][j] == '.' && !viz[i][j])
				mat[i][j] = 'X';
	for(i = 1; i <= n; ++i)
		cout << (mat[i] + 1) << "\n";
	return 0;
}
