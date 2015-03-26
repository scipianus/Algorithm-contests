#include <iostream>
#include <set>
#define INF 1000000000
using namespace std;
int n, K, v[210], sum[210], sol = -INF;
multiset <int> S1, S2;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, k, nr, a, b, now;
	cin >> n >> K;
	for(i = 1; i <= n; ++i)
	{
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}
	for(i = 1; i <= n; ++i)
	{
		for(j = i; j <= n; ++j)
		{
			now = sum[j] - sum[i - 1];
			S2.clear();
			S1.clear();
			for(k = 1; k < i; ++k)
				S1.insert(-v[k]);
			for(k = j + 1; k <= n; ++k)
				S1.insert(-v[k]);
			for(k = i; k <= j; ++k)
				S2.insert(v[k]);
			nr = 0;
			while(nr < K && S1.size() && S2.size())
			{
				a = *(S2.begin());
				b = -(*(S1.begin()));
				if(a < b)
				{
					S2.erase(S2.find(a));
					S1.erase(S1.find(-b));
					S2.insert(b);
					now += (b - a);
					nr++;
				}
				else
					nr = K;
			}
			sol = max(sol, now);
		}
	}
	cout << sol << "\n";
	return 0;
}
