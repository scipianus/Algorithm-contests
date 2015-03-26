#include <iostream>
using namespace std;
int n, S, sol = -1;

int main()
{
	int i, x, y;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> S;
	for(i = 1; i <= n; ++i)
	{
		cin >> x >> y;
		if(y > 0 && x < S)
			sol = max(sol, 100 - y);
		if(y == 0 && x <= S)
			sol = max(sol, 0);
	}
	cout << sol << "\n";
	return 0;
}
