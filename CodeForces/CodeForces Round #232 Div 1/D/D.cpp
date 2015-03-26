#include <iostream>
#define MOD 1000000007
using namespace std;
int n, perm[1000100], sol, acum[1000100], sterse[1000100], suminversiuni[1000100], fact[1000100], inv4;

inline void Aduna(int aib[], int poz, int val)
{
	while(poz <= n)
	{
		aib[poz] += val;
		poz += (poz & -poz);
	}
}

inline int Query(int aib[], int poz)
{
	int rez = 0;
	while(poz > 0)
	{
		rez += aib[poz];
		poz -= (poz & -poz);
	}
	return rez;
}

inline int LgPut(int baz, int put)
{
	int p = 1;
	while(put)
	{
		if(put % 2 == 1)
		{
			p = (1LL * p * baz) % MOD;
			put--;
		}
		baz = (1LL * baz * baz) % MOD;
		put /= 2;
	}
	return p;
}

int main()
{
	int i, realval;
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> perm[i];
		Aduna(acum, perm[i], 1);
	}
	fact[0] = 1;
	for(i = 1; i <= n; ++i)
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
	inv4 = LgPut(4, MOD - 2);
	for(i = 1; i <= n; ++i)
	{
		suminversiuni[i] = (1LL * i * (i - 1)) % MOD;
		suminversiuni[i] = (1LL * suminversiuni[i] * inv4) % MOD;
		suminversiuni[i] = (1LL * suminversiuni[i] * fact[i]) % MOD;
	}
	for(i = 1; i < n; ++i)
	{
		Aduna(acum, perm[i], -1);
		realval = perm[i] - Query(sterse, perm[i]);
		sol += (1LL * (realval - 1) * suminversiuni[n - i]) % MOD;
		sol += (1LL * ((1LL * (realval - 1) * (realval - 2) / 2LL) % MOD) * fact[n - i]) % MOD;
		if(sol >= MOD)
			sol -= MOD;
		sol += Query(acum, perm[i]);
		if(sol >= MOD)
			sol -= MOD;
		Aduna(sterse, perm[i], 1);
	}
	cout << sol << "\n";
	return 0;
}
