#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1000000000
using namespace std;
int n, poz[110], ns, bestL[110][110], best[110];
string cuv[110];
char S[110];
vector <int> L[110];
bool good[110];

int main()
{
	int i, j, sz, now;
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> cuv[i];
		L[0].push_back(i);
	}
	sort(cuv + 1, cuv + n + 1);
	cin >> (S + 1);
	ns = strlen(S + 1);
	for(i = 1; i <= n; ++i)
	{
		j = -1;
		while(j + 1 < cuv[i].size() && j + 2 <= ns && cuv[i][j + 1] == S[j + 2])
			j++;
		if(j == cuv[i].size() - 1)
			good[i] = true;
		while(j >= 0)
		{
			L[j + 1].push_back(i);
			j--;
		}
	}
	for(i = 0; i <= ns; ++i)
	{
		best[i] = INF;
		for(j = 0; j < 110; ++j)
			bestL[i][j] = INF;
	}
	best[0] = 0;
	for(i = 0; i < ns; ++i)
	{
		if(best[i] != INF)
		{
			if(i + 1 == ns)
				best[ns] = min(best[ns], best[i] + 2);
			else
				best[i + 1] = min(best[i + 1], best[i] + 1);
			sz = L[i].size();
			now = best[i] + 1; // apas TAB
			for(j = 0; j < sz; ++j)
			{
				bestL[i][j] = min(bestL[i][j], now);
				if(good[L[i][j]])
				{
					if(cuv[L[i][j]].size() == ns)
						best[ns] = min(best[ns], now + 1); // dau ENTER
					else
						best[cuv[L[i][j]].size()] = min(best[cuv[L[i][j]].size()], now); // nu dau ENTER
				}
				now++; // TAB la urmatorul
			}
		}
	}
	cout << best[ns] << "\n";
	return 0;
}
