#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
int n;
vector <pii> G[100100];
vector <int> sol;
bool viz[100100], ales[100100];

inline void DFS(int x)
{
	viz[x] = true;
	vector <pii>::iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
	{
		if(!viz[(*it).first])
		{
			DFS((*it).first);
			if(!ales[(*it).first] && (*it).second == 2)
			{
				sol.push_back((*it).first);
				ales[x] = true;
			}
			if(ales[(*it).first])
				ales[x] = true;
		}
	}
}

int main()
{
	int i, x, y, tip, nr;
	cin >> n;
	for(i = 1; i < n; ++i)
	{
		cin >> x >> y >> tip;
		G[x].push_back(make_pair(y, tip));
		G[y].push_back(make_pair(x, tip));
	}
	
	DFS(1);
	sort(sol.begin(), sol.end());
	nr = sol.size();
	
	cout << nr << "\n";
	for(i = 0; i < nr; ++i)
		cout << sol[i] << ' ';
	cout << "\n";
	return 0;
}
