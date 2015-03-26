#include <iostream>
#include <cassert>
using namespace std;
int n, K, L, R, sumtotal, sumK, v[1010];

int main()
{
	int i;
	cin >> n >> K >> L >> R >> sumtotal >> sumK;
	for(i = 1; i <= n; ++i)
		v[i] = L;
	sumtotal -= n * L;
	sumK -= K * L;
	sumtotal -= sumK;
	for(i = 1; i <= K; ++i)
		v[i] += sumK / K;
	sumK -= K * (sumK / K);
	for(i = 1; i <= sumK; ++i)
		v[i]++;
	if(K < n)
	{
		for(i = K + 1; i <= n; ++i)
			v[i] += sumtotal / (n - K);
		sumtotal -= (n - K) * (sumtotal / (n - K));
		for(i = K + 1; i <= K + sumtotal; ++i)
			v[i]++;
	}
	for(i = 1; i <= n; ++i)
	{
		cout << v[i] << ' ';
		assert(v[i] <= R);
	}
	cout << "\n";
	return 0;
}
