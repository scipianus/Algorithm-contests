#include <iostream>
using namespace std;
int T, n, loga[100100];
long long v[100100], rmq[18][100100], sol;

inline long long Gcd(long long a, long long b)
{
	long long r;
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

inline long long GcdSecv(int st, int dr)
{
	int diff = dr - st + 1;
	return Gcd(rmq[loga[diff]][st], rmq[loga[diff]][dr - (1 << loga[diff]) + 1]);
}

inline int CautareBinara(int start, int st, long long val)
{
	int dr = n, mij, rez = n + 1;
	long long gcd;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		gcd = GcdSecv(start, mij);
		if(gcd < val)
		{
			rez = min(rez, mij);
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
	return rez;
}

int main()
{
	int i, j, k;
	loga[1] = 0;
	for(i = 2; i <= 100000; ++i)
		loga[i] = loga[i / 2] + 1;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(i = 1; i <= n; ++i)
		{
			cin >> v[i];
			rmq[0][i] = v[i];
		}
		for(k = 1; (1 << k) <= n; ++k)
			for(i = 1; i + (1 << k) - 1 <= n; ++i)
				rmq[k][i] = Gcd(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
		sol = 0;
		for(i = 1; i <= n; ++i)
		{
			j = CautareBinara(i, i, v[i]);
			sol = max(sol, 1LL * (j - i) * GcdSecv(i, j - 1));
			while(j <= n)
			{
				j = CautareBinara(i, j, GcdSecv(i, j));
				sol = max(sol, 1LL * (j - i) * GcdSecv(i, j - 1));
			}
		}
		cout << sol << "\n";
	}
	return 0;
}
