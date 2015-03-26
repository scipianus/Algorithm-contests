#include <iostream>
using namespace std;
int n, m, K;
long long sol;

inline long long Solve(long long N, long long M)
{
	if(K > N - 1)
		return M / (K - (N - 1) + 1);
	return N / (K + 1) * M;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m >> K;
	if(K > n + m - 2)
		cout << "-1\n";
	else
	{
		sol = max(Solve(n, m), Solve(m, n));
		cout << sol << "\n";
	}
	return 0;
}
