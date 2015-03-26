#include <iostream>
#include <cstring>
using namespace std;
int T, n, nrdif1, nr1;
long long sol;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::ios_base::sync_with_stdio(false);
	int i, x;
	cin >> T;
	while(T--)
	{
		cin >> n;
		nr1 = nrdif1 = 0;
		for(i = 1; i <= n; ++i)
		{
			cin >> x;
			x--;
			if(x == 1)
				nr1++;
			if(x > 1)
				nrdif1++;
		}
		
		sol = 1LL * nr1 * nrdif1;
		sol += 1LL * nrdif1 * (nrdif1 - 1) / 2LL;
		cout << sol << "\n";
	}
	return 0;
}
