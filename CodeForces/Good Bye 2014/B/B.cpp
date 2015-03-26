#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, perm[310];
char s[310];
vector <int> G[310], C[310];
int comp[310], nrcomp, ind[310];

inline void DFS(int x)
{
	comp[x] = nrcomp;
	C[nrcomp].push_back(perm[x]);
	vector <int>::iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(!comp[*it])
			DFS(*it);
}

int main()
{
	int i, j;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> perm[i];
	for(i = 1; i <= n; ++i)
	{
		cin >> (s + 1);
		for(j = 1; j <= n; ++j)
			if(s[j] == '1')
				G[i].push_back(j);
	}
	for(i = 1; i <= n; ++i)
		if(!comp[i])
		{
			nrcomp++;
			DFS(i);
		}
	for(i = 1; i <= nrcomp; ++i)
		sort(C[i].begin(), C[i].end());
	for(i = 1; i <= n; ++i)
	{
		cout << C[comp[i]][ind[comp[i]]] << ' ';
		ind[comp[i]]++;
	}
	cout << "\n";
	return 0;
}
