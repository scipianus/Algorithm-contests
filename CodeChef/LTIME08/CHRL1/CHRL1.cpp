#include <iostream>
using namespace std;
int T, n, K, cost[11], weight[11], sol;

inline void Back(int pas, int C, int G)
{
	sol = max(sol, G);
	if(pas == n + 1)
		return;
	Back(pas + 1, C, G);
	if(C + cost[pas] <= K)
		Back(pas + 1, C + cost[pas], G + weight[pas]);
}

int main()
{
	int i;
	cin >> T;
	while(T--)
	{
		cin >> n >> K;
		for(i = 1; i <= n; ++i)
			cin >> cost[i] >> weight[i];
		sol = 0;
		Back(1, 0, 0);
		cout << sol << "\n";
	}
	return 0;
}
