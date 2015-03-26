#include <iostream>
#include <map>
using namespace std;
int n, m, a[5010], b[5010], prime[5000], nrp, val[5010], sol;
bool ciur[32000];
map <int, bool> rau;

inline int GetValue(int x)
{
	int i, sgn, rez = 0;
	i = 1;
	while(prime[i] * prime[i] <= x)
	{
		if(x % prime[i] == 0)
		{
			if(rau.count(prime[i]))
				sgn = -1;
			else
				sgn = 1;
			while(x % prime[i] == 0)
			{
				rez += sgn;
				x /= prime[i];
			}
		}
		i++;
	}
	if(x > 1)
	{
		if(rau.count(x))
			rez--;
		else
			rez++;
	}
	return rez;
}

inline int Gcd(int x, int y)
{
	int r;
	while(y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, gcd, now;
	cin >> n >> m;
	for(i = 1; i <= n; ++i)
		cin >> a[i];
	for(i = 1; i <= m; ++i)
	{
		cin >> b[i];
		rau[b[i]] = true;
	}
	
	prime[++nrp] = 2;
	for(i = 3; i < 32000; i += 2)
	{
		if(!ciur[i])
		{
			prime[++nrp] = i;
			for(j = i * i; j < 32000; j += 2 * i)
				ciur[j] = true;
		}
	}
	prime[++nrp] = 32000;
	
	for(i = n; i > 0; --i)
	{
		gcd = a[1];
		for(j = 1; j <= i; ++j)
			gcd = Gcd(gcd, a[j]);
		now = GetValue(gcd);
		if(now < 0)
		{
			for(j = 1; j <= i; ++j)
				a[j] /= gcd;
		}
	}
	
	for(i = 1; i <= n; ++i)
		sol += GetValue(a[i]);
	
	cout << sol << "\n";
	return 0;
}
