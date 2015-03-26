#include <iostream>
using namespace std;
int n, v[100100], best[2][100100], sol;

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	best[0][0] = 0;
	for(i = 1; i <= n; ++i)
	{
		if(v[i] > v[i - 1])
			best[0][i] = best[0][i - 1] + 1;
		else
			best[0][i] = 1;
	}
	best[1][n + 1] = 0;
	v[n + 1] = 2000000000;
	for(i = n; i > 0; --i)
	{
		if(v[i] < v[i + 1])
			best[1][i] = best[1][i + 1] + 1;
		else
			best[1][i] = 1;
		sol = max(sol, best[1][i]);
	}
	if(sol < n)
		sol = sol + 1;
	for(i = 2; i < n; ++i)
	{
		if(v[i - 1] + 2 <= v[i + 1])
			sol = max(sol, best[0][i - 1] + best[1][i + 1] + 1);
	}
	cout << sol << "\n";
	return 0;
}
