#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
int n, sum[2][100100];
vector <pii> sol;

inline int CautaBinar(int t, int i, int tip)
{
	int st, dr, mij, rez;
	st = i;
	dr = n;
	rez = n + 1;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		if(sum[tip][mij] - sum[tip][i - 1] >= t)
		{
			rez = mij;
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
	return rez;
}

inline void Check(int t)
{
	int scor[2], i, j, j1, j2, S, last;
	i = 1;
	scor[0] = scor[1] = 0;
	while(i <= n)
	{
		j1 = CautaBinar(t, i, 0);
		j2 = CautaBinar(t, i, 1);
		j = min(j1, j2);
		if(j == n + 1)
			return;
		if(j == j1)
		{
			scor[0]++;
			last = 0;
		}
		else
		{
			scor[1]++;
			last = 1;
		}
		i = j + 1;
	}
	if(scor[0] > scor[1])
	{
		if(last == 1)
			return;
		S = scor[0];
		sol.push_back(make_pair(S, t));
		return;
	}
	if(scor[0] < scor[1])
	{
		if(last == 0)
			return;
		S = scor[1];
		sol.push_back(make_pair(S, t));
		return;
	}
}

int main()
{
	int i, x;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> x;
		x--;
		sum[0][i] = sum[0][i - 1];
		sum[1][i] = sum[1][i - 1];
		sum[x][i]++;
	}
	for(i = 1; i <= n; ++i)
		Check(i);
	sort(sol.begin(), sol.end());
	cout << sol.size() << "\n";
	for(i = 0; i < sol.size(); ++i)
		cout << sol[i].first << ' ' << sol[i].second << "\n";
	return 0;
}
