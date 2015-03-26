#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int n, color[100100], nr[2][100100], prodst[100100], proddr[100100];
vector <int> G[100100];

inline void DFS(int x, int tata)
{
	int i, sz = G[x].size();
	vector <int>::iterator it;
	for(i = 0; i < sz; ++i)
	{
		if(G[x][i] == tata)
		{
			swap(G[x][i], G[x][sz - 1]);
			G[x].pop_back();
			sz--;
			break;
		}
	}
	if(sz == 0)
	{
		if(color[x] == 0)
		{
			nr[0][x] = 0;
			nr[1][x] = 1;
		}
		else
		{
			nr[0][x] = 1;
			nr[1][x] = 0;
		}
		return;
	}
	for(it = G[x].begin(); it != G[x].end(); ++it)
		DFS(*it, x);
	if(color[x] == 1)
	{
		nr[1][x] = 0;
		nr[0][x] = 1;
		for(i = 0; i < sz; ++i)
			nr[0][x] = (1LL * nr[0][x] * (nr[0][G[x][i]] + nr[1][G[x][i]])) % MOD;
		return;
	}
	prodst[0] = proddr[sz - 1] = 1;
	for(i = 1; i < sz; ++i)
		prodst[i] = (1LL * prodst[i - 1] * (nr[0][G[x][i - 1]] + nr[1][G[x][i - 1]])) % MOD;
	for(i = sz - 2; i >= 0; --i)
		proddr[i] = (1LL * proddr[i + 1] * (nr[0][G[x][i + 1]] + nr[1][G[x][i + 1]])) % MOD;
	nr[1][x] = 1;
	for(i = 0; i < sz; ++i)
	{
		nr[0][x] += (1LL * ((1LL * prodst[i] * proddr[i]) % MOD) * nr[0][G[x][i]]) % MOD;
		if(nr[0][x] >= MOD)
			nr[0][x] -= MOD;
		nr[1][x] = (1LL * nr[1][x] * (nr[0][G[x][i]] + nr[1][G[x][i]])) % MOD;
	}
}

int main()
{
	int i, x;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 2; i <= n; ++i)
	{
		cin >> x;
		x++;
		G[i].push_back(x);
		G[x].push_back(i);
	}
	for(i = 1; i <= n; ++i)
		cin >> color[i];
	DFS(1, 0);
	cout << nr[0][1] << "\n";
	return 0;
}
