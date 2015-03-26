#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int T, n, sol, prime[500], nrp, v[100100];
bool ciur[1000010], viz[1000100];
vector <int> f[1000100];

int main()
{
	int i, j, st, dr, x, y, d;
	vector <int>::iterator it, jt;
	for(i = 4; i <= 1000000; i += 2)
		ciur[i] = true;
	prime[++nrp] = 2;
	for(i = 3; i < 1000; i += 2)
	{
		if(!ciur[i])
		{
			prime[++nrp] = i;
			for(j = i * i; j < 1000000; j += 2 * i)
				ciur[j] = true;
		}
	}
	prime[++nrp] = 10000;
	for(i = 1; i <= 1000000; ++i)
	{
		x = i;
		if(x % 2 == 0)
		{
			f[i].push_back(2);
			while(x % 2 == 0)
				x /= 2;
		}
		if(!ciur[x])
		{
			f[i].push_back(x);
			continue;
		}
		d = 2;
		while(prime[d] * prime[d] <= x)
		{
			if(x % prime[d] == 0)
			{
				f[i].push_back(prime[d]);
				while(x % prime[d] == 0)
					x /= prime[d];
			}
			d++;
		}
		if(x > 1)
			f[i].push_back(x);
	}
	std::ios_base::sync_with_stdio(false);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		st = 1;
		dr = 0;
		sol = -1;
		for(i = 1; i <= n; ++i)
		{
			scanf("%d", &x);
			v[i] = x;
			dr++;
			for(it = f[x].begin(); it != f[x].end(); ++it)
			{
				if(!viz[*it])
					viz[*it] = true;
				else
				{
					while(viz[*it])
					{
						y = v[st];
						st++;
						for(jt = f[y].begin(); jt != f[y].end(); ++jt)
							viz[*jt] = false;
					}
					viz[*it] = true;
				}
			}
			if(dr - st + 1 > 1)
				sol = max(sol, dr - st + 1);
		}
		while(st <= n)
		{
			y = v[st];
			for(it = f[y].begin(); it != f[y].end(); ++it)
				viz[*it] = false;
			st++;
		}
		printf("%d\n", sol);
	}
	return 0;
}
