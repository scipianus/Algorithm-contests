#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000000000000LL
#define pil pair<int, long long>
using namespace std;
int n, m, K, sol;
vector <pil> G[100100];
long long train[100100], best[100100];
queue <int> Q;
bool bagat[100100];

int main()
{
	int i, x, y;
	long long z;
	bool gasit;
	vector <pil>::iterator it;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m >> K;
	for(i = 1; i <= m; ++i)
	{
		cin >> x >> y >> z;
		G[x].push_back(make_pair(y, z));
		G[y].push_back(make_pair(x, z));
	}
	for(i = 1; i <= K; ++i)
	{
		cin >> x >> z;
		if(!train[x])
			train[x] = z;
		else
		{
			train[x] = min(train[x], z);
			sol++;
		}
	}
	for(i = 1; i <= n; ++i)
		best[i] = INF;
	for(i = 2; i <= n; ++i)
	{
		if(train[i])
		{
			best[i] = train[i];
			Q.push(i);
			bagat[i] = true;
		}
	}
	best[1] = 0;
	Q.push(1);
	bagat[1] = true;
	while(!Q.empty())
	{
		x = Q.front();
		Q.pop();
		bagat[x] = false;
		for(it = G[x].begin(); it != G[x].end(); ++it)
		{
			y = (*it).first;
			z = (*it).second;
			if(best[y] > best[x] + z)
			{
				best[y] = best[x] + z;
				if(!bagat[y])
				{
					bagat[y] = true;
					Q.push(y);
				}
			}
		}
	}
	for(i = 2; i <= n; ++i)
	{
		if(!train[i])
			continue;
		if(best[i] < train[i])
			sol++;
		else
		{
			// best[i] == train[i]
			gasit = false;
			for(it = G[i].begin(); it != G[i].end() && !gasit; ++it)
			{
				y = (*it).first;
				z = (*it).second;
				if(best[i] == best[y] + z)
					gasit = true;
			}
			if(gasit)
				sol++;
		}
	}
	cout << sol << "\n";
	return 0;
}
