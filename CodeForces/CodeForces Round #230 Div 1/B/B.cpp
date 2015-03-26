#include <iostream>
#include <set>
#include <map>
#define pll pair<long long, long long>
using namespace std;
int n, mat[3][3];
long long put[45], sol;
map <long long, long long> best;
set <pll> Q;

int main()
{
	bool gasit[3];
	pll now, Next;
	long long conf;
	int i, j, nr, nrgasit;
	for(i = 0; i < 3; ++i)
		for(j = 0; j < 3; ++j)
			cin >> mat[i][j];
	cin >> n;
	put[0] = 1;
	for(i = 1; i <= n; ++i)
		put[i] = 3LL * put[i - 1];
	
	Q.insert(make_pair(0, 0));
	best[0] = 0;
	while(Q.size())
	{
		now = *Q.begin();
		Q.erase(now);
		gasit[0] = gasit[1] = gasit[2] = false;
		conf = now.second;
		if(conf == put[n] - 1LL)
		{
			sol = best[conf];
			continue;
		}
		if(sol && now.first >= sol)
			continue;
		nrgasit = 0;
		for(i = 0; i < n && nrgasit < 3; ++i)
		{
			nr = 0;
			while(conf >= put[i])
			{
				nr++;
				conf -= put[i];
			}
			if(!gasit[nr])
			{
				nrgasit++;
				gasit[nr] = true;
				for(j = 0; j < 3; ++j)
				{
					if(j == nr || gasit[j])
						continue;
					Next.first = now.first + 1LL * mat[nr][j];
					Next.second = now.second - 1LL * nr * put[i] + 1LL * j * put[i];
					if(!best.count(Next.second))
					{
						best[Next.second] = Next.first;
						Q.insert(Next);
					}
					else
						if(best[Next.second] > Next.first)
						{
							Q.erase(Q.find(make_pair(best[Next.second], Next.second)));
							best[Next.second] = Next.first;
							Q.insert(Next);
						}
				}
			}
		}
	}
	cout << sol << "\n";
	return 0;
}
