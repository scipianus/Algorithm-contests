#include <iostream>
#include <map>
#include <set>
#define MOD 1000000007
using namespace std;
int n, prime[10000], nrp, sol, valmax, fact[100100];
map <int, int> Exp;
set <int> D;
bool ciur[32000];

inline int LgPut(int baz, int put)
{
    int p = 1;
    while(put > 0)
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
	int i, j, x, nre, d, nrnow;
	set <int>::iterator it;
	prime[++nrp] = 2;
	for(i = 3; i < 32000; i += 2)
	{
		if(!ciur[i])
		{
			prime[++nrp] = i;
			for(j = i * i; j <= 32000; j += 2 * i)
				ciur[j] = true;
		}
	}
	prime[nrp + 1] = 32000;
	
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> x;
		j = 1;
		while(prime[j] * prime[j] <= x)
		{
			nre = 0;
			d = prime[j];
			while(x % d == 0)
			{
				x /= d;
				nre++;
			}
			if(nre)
			{
				Exp[d] += nre;
				D.insert(d);
			}
			j++;
		}
		if(x > 1)
		{
			Exp[x]++;
			D.insert(x);
		}
	}
	for(it = D.begin(); it != D.end(); ++it)
		valmax = max(valmax, Exp[*it] + n - 1);
	fact[0] = 1;
	for(i = 1; i <= valmax; ++i)
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
	sol = 1;
	for(it = D.begin(); it != D.end(); ++it)
	{
		nrnow = (1LL * fact[Exp[*it] + n - 1] * LgPut(fact[n - 1], MOD - 2)) % MOD;
		nrnow = (1LL * nrnow * LgPut(fact[Exp[*it]], MOD - 2)) % MOD;
		sol = (1LL * sol * nrnow) % MOD;
	}
	cout << sol << "\n";
	return 0;
}
