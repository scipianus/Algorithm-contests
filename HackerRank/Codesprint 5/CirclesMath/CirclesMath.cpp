#include <iostream>
#define MOD 1000000007
using namespace std;
int T, n, K, sol, fact[1000100], nofix[1000100];

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
	int i, sgn = 1, lim, aux;
	fact[0] = fact[1] = 1;
	nofix[0] = 1;
	nofix[1] = 0;
	for(i = 2; i <= 1000000; ++i)
	{
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
		nofix[i] = (1LL * i * nofix[i - 1] + sgn) % MOD;
		sgn = -sgn;
	}
	cin >> T;
	while(T--)
	{
		cin >> n >> K;
		sol = 0;
		if(K == 1)
			cout << "0\n";
		else
		{
			sol = 0;
			lim = n / K;
			for(i = 1, sgn = 1; i <= lim; ++i, sgn = -sgn)
			{
				aux = (1LL * LgPut(K, i) * fact[n - i * K]) % MOD;
				aux = LgPut(aux, MOD - 2);
				aux = (1LL * aux * fact[n]) % MOD;
				aux = (1LL * aux * nofix[n - i * K]) % MOD;
				aux = (1LL * aux * LgPut(fact[i], MOD - 2)) % MOD;
				sol += 1LL * sgn * aux;
				while(sol < 0)
					sol += MOD;
				while(sol >= MOD)
					sol -= MOD;
			}
			cout << sol << "\n";
		}
	}
	return 0;
}
