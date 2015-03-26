#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, n, m;
bool interzis[26][26];
vector <int> G[26], path;
int viz[26], pred[26], postordine[30], nrp, best[26];
bool cycle;
char sol[22][22];

inline void FormCycle(int first, int last)
{
	int i, j, lg;
	vector <int> C;
	C.clear();
	while(last != first)
	{
		C.push_back(last);
		last = pred[last];
	}
	C.push_back(last);
	lg = C.size();
	j = 0;
	i = lg - 1;
	while(j < 39)
	{
		path.push_back(C[i]);
		i--;
		if(i < 0)
			i = lg - 1;
		j++;
	}
	n = 20;
}

inline void DFS(int x)
{
	if(cycle)
		return;
	viz[x] = 1;
	vector <int>::iterator it;
	for(it = G[x].begin(); it != G[x].end() && !cycle; ++it)
	{
		if(!viz[*it])
		{
			pred[*it] = x;
			DFS(*it);
		}
		else
		{
			if(viz[*it] == 1)
			{
				cycle = true;
				FormCycle(*it, x);
				return;
			}
		}
	}
	viz[x] = 2;
	postordine[++nrp] = x;
}

inline void Solve()
{
	int i, j, k, x;
	vector <int>::iterator it;
	cycle = false;
	path.clear();
	nrp = 0;
	for(i = 0; i < 26 && !cycle; ++i)
		if(!viz[i])
			DFS(i);
	if(!cycle)
	{
		for(i = 0; i < 26; ++i)
		{
			best[i] = 1;
			pred[i] = -1;
		}
		k = postordine[26];
		for(i = 26; i > 0; --i)
		{
			x = postordine[i];
			for(it = G[x].begin(); it != G[x].end(); ++it)
			{
				if(best[*it] < best[x] + 1)
				{
					pred[*it] = x;
					best[*it] = best[x] + 1;
					if(best[*it] > best[k])
						k = *it;
				}
			}
		}
		while(k >= 0)
		{
			path.push_back(k);
			k = pred[k];
		}
		reverse(path.begin(), path.end());
		if(path.size() % 2 == 0)
			path.pop_back();
		n = path.size() / 2 + 1;
	}
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
			sol[i][j] = (char)(path[i + j] + 'a');
}

int main()
{
	int i, j;
	char s[2];
	cin >> T;
	while(T--)
	{
		cin >> m;
		for(i = 1; i <= m; ++i)
		{
			cin >> s;
			interzis[s[0] - 'a'][s[1] - 'a'] = true;
		}
		for(i = 0; i < 26; ++i)
			for(j = 0; j < 26; ++j)
				if(!interzis[i][j])
					G[i].push_back(j);
		Solve();
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
				cout << sol[i][j];
			cout << "\n";
		}
		for(i = 0; i < 26; ++i)
		{
			G[i].clear();
			viz[i] = 0;
			for(j = 0; j < 26; ++j)
				interzis[i][j] = false;
		}
	}
	return 0;
}
