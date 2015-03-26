#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
using namespace std;
int n, K, v[2010], sol;

inline bool Posibil(int diff)
{
	int i, j, difmed, dif, moves[2010];
	moves[1] = 0;
	for(i = 2; i <= n; ++i)
	{
		moves[i] = i - 1;
		for(j = i - 1; j > 0; --j)
		{
			dif = abs(v[i] - v[j]);
			difmed = dif / (i - j);
			if(dif % (i - j) != 0)
				difmed++;
			if(difmed <= diff)
				moves[i] = min(moves[i], moves[j] + i - j - 1);
		}
	}
	for(i = 1; i <= n; ++i)
		if(moves[i] + n - i <= K)
			return true;
	return false;
}

inline void CautareBinara()
{
	int st, dr, mij;
	st = 0;
	dr = sol;
	while(st <= dr)
	{
		mij = st + (dr - st) / 2;
		if(Posibil(mij))
		{
			sol = mij;
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
}

int main()
{
	int i;
	scanf("%d %d",&n, &K);
	for(i = 1; i <= n; ++i)
		scanf("%d",v + i);
	
	for(i = 1; i < n; ++i)
		sol = max(sol, abs(v[i] - v[i + 1]));
	CautareBinara();
	
	printf("%d\n", sol);
	return 0;
}
