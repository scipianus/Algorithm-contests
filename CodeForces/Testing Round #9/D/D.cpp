#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define INF 1000000000
using namespace std;
int n, best[75][75][75];
char mat[75][75];
struct Stare{int a, b, c;};
Stare start, now, urm;
queue <Stare> Q;
pii mutare[75][75][75];
vector <pii> sol;
bool bagat[75][75][75];

inline void Ordoneaza(Stare &X)
{
	if(X.a > X.b)
		swap(X.a, X.b);
	if(X.a > X.c)
		swap(X.a, X.c);
	if(X.b > X.c)
		swap(X.b, X.c);
}

int main()
{
	int i, j, k;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> start.a >> start.b >> start.c;
	for(i = 1; i <= n; ++i)
		cin >> (mat[i] + 1);
	
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			for(k = 1; k <= n; ++k)
				best[i][j][k] = INF;
	Ordoneaza(start);
	best[start.a][start.b][start.c] = 0;
	bagat[start.a][start.b][start.c] = true;
	Q.push(start);
	while(!Q.empty())
	{
		now = Q.front();
		Q.pop();
		for(i = 1; i <= n; ++i)
		{
			if(now.a == i || now.b == i || now.c == i)
				continue;
			if(mat[now.b][now.c] == mat[now.a][i])
			{
				urm = now;
				urm.a = i;
				Ordoneaza(urm);
				if(best[urm.a][urm.b][urm.c] > best[now.a][now.b][now.c] + 1)
				{
					best[urm.a][urm.b][urm.c] = best[now.a][now.b][now.c] + 1;
					mutare[urm.a][urm.b][urm.c] = make_pair(now.a, i);
					if(!bagat[urm.a][urm.b][urm.c])
					{
						bagat[urm.a][urm.b][urm.c] = true;
						Q.push(urm);
					}
				}
			}
			if(mat[now.a][now.c] == mat[now.b][i])
			{
				urm = now;
				urm.b = i;
				Ordoneaza(urm);
				if(best[urm.a][urm.b][urm.c] > best[now.a][now.b][now.c] + 1)
				{
					best[urm.a][urm.b][urm.c] = best[now.a][now.b][now.c] + 1;
					mutare[urm.a][urm.b][urm.c] = make_pair(now.b, i);
					if(!bagat[urm.a][urm.b][urm.c])
					{
						bagat[urm.a][urm.b][urm.c] = true;
						Q.push(urm);
					}
				}
			}
			if(mat[now.a][now.b] == mat[now.c][i])
			{
				urm = now;
				urm.c = i;
				Ordoneaza(urm);
				if(best[urm.a][urm.b][urm.c] > best[now.a][now.b][now.c] + 1)
				{
					best[urm.a][urm.b][urm.c] = best[now.a][now.b][now.c] + 1;
					mutare[urm.a][urm.b][urm.c] = make_pair(now.c, i);
					if(!bagat[urm.a][urm.b][urm.c])
					{
						bagat[urm.a][urm.b][urm.c] = true;
						Q.push(urm);
					}
				}
			}
		}
	}
	if(best[1][2][3] == INF)
	{
		cout << "-1\n";
		return 0;
	}
	now.a = 1;
	now.b = 2;
	now.c = 3;
	while(mutare[now.a][now.b][now.c].first != 0)
	{
		sol.push_back(mutare[now.a][now.b][now.c]);
		i = mutare[now.a][now.b][now.c].first;
		j = mutare[now.a][now.b][now.c].second;
		if(now.a == j)
			now.a = i;
		if(now.b == j)
			now.b = i;
		if(now.c == j)
			now.c = i;
		Ordoneaza(now);
	}
	cout << sol.size() << "\n";
	for(i = sol.size() - 1; i >= 0; --i)
		cout << sol[i].first << ' ' << sol[i].second << "\n";
	return 0;
}
