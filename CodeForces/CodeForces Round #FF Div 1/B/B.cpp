#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2000000000000000000LL
using namespace std;
int n, m, K, P, mat[1010][1010];
long long sol = -INF, sumL[1010], sumC[1010], total, bestL[1000100], bestC[1000100], now;
vector <long long> SL, SC;

inline bool SortareL(int a, int b)
{
	return sumL[a] < sumL[b];
}

inline bool SortareC(int a, int b)
{
	return sumC[a] < sumC[b];
}

int main()
{
	int i, j, x;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m >> K >> P;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
		{
			cin >> mat[i][j];
			sumL[i] += mat[i][j];
			sumC[j] += mat[i][j];
		}
	for(i = 1; i <= n; ++i)
		SL.push_back(i);
	make_heap(SL.begin(), SL.end(), SortareL);
	for(j = 1; j <= m; ++j)
		SC.push_back(j);
	make_heap(SC.begin(), SC.end(), SortareC);
	for(i = 1; i <= K; ++i)
	{
		x = SL[0];
		pop_heap(SL.begin(), SL.end(), SortareL);
		SL.pop_back();
		bestL[i] = bestL[i - 1] + sumL[x];
		sumL[x] -= 1LL * m * P;
		SL.push_back(x);
		push_heap(SL.begin(), SL.end(), SortareL);
	}
	for(i = 1; i <= K; ++i)
	{
		x = SC[0];
		pop_heap(SC.begin(), SC.end(), SortareC);
		SC.pop_back();
		bestC[i] = bestC[i - 1] + sumC[x];
		sumC[x] -= 1LL * n * P;
		SC.push_back(x);
		push_heap(SC.begin(), SC.end(), SortareC);
	}
	for(i = 0; i <= K; ++i)
	{
		j = K - i;
		now = bestL[i] + bestC[j] - 1LL * i * j * P;
		sol = max(sol, now);
	}
	cout << sol << "\n";
	return 0;
}
