#include <iostream>
using namespace std;
int T, n;
int prime[10000], nrp;
bool ciur[32010];
unsigned long long P, Q, C;

inline bool Prim(int x)
{
	if(x == 2)
		return true;
	if(x % 2 == 0)
		return false;
	int i;
	for(i = 1; prime[i] * prime[i] <= x; ++i)
	{
		if(x % prime[i] == 0)
			return false;
	}
	return true;
}

inline long long Euclid(unsigned long long a, unsigned long long b)
{
	unsigned long long r;
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int i, j;
	unsigned long long st, dr;
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
	prime[nrp + 1] = 32000;
	
	cin >> T;
	while(T--)
	{
		cin >> n;
		st = 1LL * n; dr = 1LL * n + 1LL;
		while(!Prim(dr))
			dr++;
		while(!Prim(st))
			st--;
		P = (st - 2LL) * dr + 2LL * (n - st + 1);
		Q = 2LL * st * dr;
		C = Euclid(P, Q);
		P /= C;
		Q /= C;
		cout << P << "/" << Q << "\n";
	}
	return 0;
}
