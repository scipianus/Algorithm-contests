#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, w[510], v[1010], sol;
bool viz[510];
vector <int> ord;

int main()
{
	int i, j;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(i = 1; i <= n; ++i)
		cin >> w[i];
	for(i = 1; i <= m; ++i)
		cin >> v[i];
	for(i = 1; i <= m; ++i)
	{
		if(!viz[v[i]])
		{
			viz[v[i]] = true;
			ord.push_back(v[i]);
		}
		j = 0;
		while(ord[j] != v[i])
		{
			sol += w[ord[j]];
			j++;
		}
		while(j + 1 < ord.size())
		{
			ord[j] = ord[j + 1];
			j++;
		}
		while(j > 0)
		{
			ord[j] = ord[j - 1];
			j--;
		}
		ord[0] = v[i];
	}
	cout << sol << "\n";
	return 0;
}
