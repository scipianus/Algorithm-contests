#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int n, K;
bool uz[1010][1010];
vector <pii> sol;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, nr;
	cin >> n >> K;
	for(i = 1; i <= n; ++i)
	{
		nr = 0;
		for(j = 1; j <= n && nr < K; ++j)
		{
			if(i == j)
				continue;
			if(!uz[i][j] && !uz[j][i])
			{
				uz[i][j] = true;
				nr++;
				sol.push_back(make_pair(i, j));
			}
		}
		if(nr < K)
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << sol.size() << "\n";
	for(i = sol.size() - 1; i >= 0; --i)
		cout << sol[i].first << ' ' << sol[i].second << "\n";
	return 0;
}
