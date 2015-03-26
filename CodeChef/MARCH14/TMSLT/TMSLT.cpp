#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MOD 1000000
using namespace std;
int T, n, nr[1000100];
long long sum1, sum2, A, B, C, D;

int main()
{
	int i;
	long long x, y;
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> n >> A >> B >> C >> D;
		nr[D]++;
		x = D;
		for(i = 1; i < n; ++i)
		{
			y = A * x * x + B * x + C;
			y %= MOD;
			nr[y]++;
			x = y;
		}
		sum1 = sum2 = 0;
		for(i = 1000000; i >= 0; --i)
		{
			if(!(nr[i] & 1))
			{
				nr[i] = 0;
				continue;
			}
			sum1 += 1LL * i;
			swap(sum1, sum2);
			nr[i] = 0;
		}
		cout << abs(sum1 - sum2) << "\n";
	}
	return 0;
}
