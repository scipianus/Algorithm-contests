#include <iostream>
#include <algorithm>
using namespace std;
int T, prime[1010], nrp;
bool ciur[3010];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, x, y, sum, poz;
	prime[++nrp] = 2;
	for(i = 3; i < 3000; i += 2)
	{
		if(!ciur[i])
		{
			prime[++nrp] = i;
			for(j = i * i; j < 3000; j += 2 * i)
				ciur[j] = true;
		}
	}
	cin >> T;
	while(T--)
	{
		cin >> x >> y;
		sum = x + y;
		poz = upper_bound(prime + 1, prime + nrp + 1, sum) - prime;
		cout << (prime[poz] - sum) << "\n";
	}
	return 0;
}
