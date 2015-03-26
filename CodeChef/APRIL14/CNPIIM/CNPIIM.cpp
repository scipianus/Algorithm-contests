#include <iostream>
using namespace std;
int T, n;
long long nr[1600000], sol;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j;
	for(i = 1; i < 1600000; ++i)
		for(j = 1; i * j < 1600000; ++j)
			nr[i * j]++;
	for(i = 2; i < 1600000; ++i)
		nr[i] += nr[i - 1];
	cin >> T;
	while(T--)
	{
		cin >> n;
		sol = 0;
		for(i = 1; 2 * i <= n; ++i)
		{
			if(2 * i != n)
				sol += 2LL * nr[i * (n - i) - 1];
			else
				sol += nr[i * (n - i) - 1];
		}
		cout << sol << "\n";
	}
	return 0;
}
