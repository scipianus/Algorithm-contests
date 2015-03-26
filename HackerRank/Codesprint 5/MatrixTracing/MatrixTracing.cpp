#include <iostream>
#define MOD 1000000007
using namespace std;
int T, n, m, fact[2000100], sol;

inline int LgPut(int baz, int put)
{
	int rez = 1;
	while(put > 0)
	{
		if(put % 2 == 1)
		{
			rez = (1LL * rez * baz) % MOD;
			put--;
		}
		baz = (1LL * baz * baz) % MOD;
		put /= 2;
	}
	return rez;
}

int main()
{
	int i;
	fact[0] = 1;
	for(i = 1; i <= 2000000; ++i)
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		// combinari de (n + m - 2) luate cate (n - 1)
		sol = fact[n + m - 2];
		sol = (1LL * sol * LgPut(fact[n - 1], MOD - 2)) % MOD;
		sol = (1LL * sol * LgPut(fact[m - 1], MOD - 2)) % MOD;
		cout << sol << "\n";
	}
	return 0;
}
