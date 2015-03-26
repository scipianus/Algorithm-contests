#include <iostream>
using namespace std;
int T, n, sol;

int main()
{
	int i, x;
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		sol = 0;
		cin >> n;
		for(i = 1; i <= n; ++i)
		{
			cin >> x;
			sol = max(sol, x + i - 1);
		}
		cout << sol << "\n";
	}
	return 0;
}
