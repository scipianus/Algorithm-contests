#include <iostream>
#include <algorithm>
using namespace std;
int n, T, v[110], sol;

int main()
{
	int i, j;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	cin >> T;
	sort(v + 1, v + n + 1);
	for(i = 1; i <= n; ++i)
	{
		j = upper_bound(v + i, v + n + 1, v[i] + T) - v;
		sol = max(sol, j - i);
	}
	cout << sol << "\n";
	return 0;
}
