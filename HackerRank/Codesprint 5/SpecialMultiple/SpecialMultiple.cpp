#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int T, n, best[510], last[510], pred[510];
string sol[510];
queue <int> Q;

inline void Solve()
{
	int i, j, x, r;
	for(i = 0; i < n; ++i)
	{
		best[i] = 1000000000;
		last[i] = 0;
		pred[i] = -1;
	}
	best[9 % n] = 1;
	last[9 % n] = 9;
	pred[9 % n] = -1;
	Q.push(9 % n);
	while(!Q.empty())
	{
		x = Q.front();
		Q.pop();
		// pun 0
		r = (x * 10 + 0) % n;
		if(best[r] > best[x] + 1)
		{
			best[r] = best[x] + 1;
			last[r] = 0;
			pred[r] = x;
			Q.push(r);
		}
		// pun 9
		r = (x * 10 + 9) % n;
		if(best[r] > best[x] + 1)
		{
			best[r] = best[x] + 1;
			last[r] = 9;
			pred[r] = x;
			Q.push(r);
		}
	}
	r = 0;
	while(r != -1)
	{
		sol[n] += (char)(last[r] + '0');
		r = pred[r];
	}
	for(i = 0, j = best[0] - 1; i <= j; ++i, --j)
		swap(sol[n][i], sol[n][j]);
}

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		if(sol[n].size() == 0)
			Solve();
		cout << sol[n] << "\n";
	}
	return 0;
}
