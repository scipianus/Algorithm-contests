#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
long long v[1000100], sol;
long long f[110];
int prime[500100], nrp, nrf, e[110];
bool ciur[1000100];
vector <long long> Div;
map <long long, int> nr;
map <long long, bool> viz;

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

inline void GenereazaDivizori(int pas, long long rez)
{
	if(pas == nrf + 1)
		Div.push_back(rez);
	else
	{
		GenereazaDivizori(pas + 1, rez);
		int i;
		long long newrez = rez;
		for(i = 1; i <= e[pas]; ++i)
		{
			newrez *= f[pas];
			GenereazaDivizori(pas + 1, newrez);
		}
	}
}

int main()
{
	int i, j, t, poz, nrd;
	long long x;
	vector <long long>::iterator it, jt;
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
	for(i = 1001; i < 1000000; i += 2)
	{
		if(!ciur[i])
			prime[++nrp] = i;
	}
	
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	
	srand(time(NULL));
	for(t = 1; t <= 9; ++t)
	{
		poz = rand() % n + 1;
		x = v[poz];
		if(viz.count(x) && viz[x] == true)
			continue;
		viz[x] = true;
		for(i = 1; 1LL * prime[i] * prime[i] <= x; ++i)
		{
			if(x % prime[i] == 0LL)
			{
				f[++nrf] = prime[i];
				while(x % prime[i] == 0LL)
				{
					e[nrf]++;
					x /= prime[i];
				}
			}
		}
		if(x > 1LL)
		{
			f[++nrf] = x;
			e[nrf] = 1;
		}
		GenereazaDivizori(1, 1LL);
		sort(Div.begin(), Div.end());
		for(i = 1; i <= n; ++i)
			nr[Gcd(v[i], v[poz])]++;
		for(it = Div.begin(); it != Div.end() - 1; ++it)
		{
			for(jt = it + 1; jt != Div.end(); ++jt)
			{
				if(*jt % *it == 0LL)
					nr[*it] += nr[*jt];
			}
		}
		for(it = Div.end() - 1; it >= Div.begin(); --it)
		{
			if(2 * nr[*it] >= n)
			{
				sol = max(sol, *it);
				break;
			}
		}
		Div.clear();
		for(i = 1; i <= nrf; ++i)
			e[i] = 0;
		nrf = 0;
		nr.clear();
	}
	nrd = 0;
	for(i = 1; i <= n; ++i)
		if(v[i] % 999999999999LL == 0LL)
			nrd++;
	if(2 * nrd >= n)
		sol = max(sol, 999999999999LL);
	
	cout << sol << "\n";
	return 0;
}
