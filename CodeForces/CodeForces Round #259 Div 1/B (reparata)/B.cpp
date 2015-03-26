#include <iostream>
#include <algorithm>
using namespace std;
int n, A[110], B[110], sol;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int cheie[65];
int best[110][263000], numar[110][263000];

inline int Modul(int x)
{
	if(x > 0)
		return x;
	return (-x);
}

int main()
{
	int i, j, lim, conf, maxim, dif;
	lim = (1 << 17);
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> A[i];
		sol += A[i] - 1;
		B[i] = 1;
	}
	for(i = 1; i <= 62; ++i)
	{
		for(j = 0; j < 17; ++j)
			if(i % prime[j] == 0)
				cheie[i] += (1 << j);
	}
	for(i = 0; i <= n; ++i)
	{
		for(conf = 0; conf < lim; ++conf)
			best[i][conf] = -1;
	}
	best[0][0] = 0;
	for(i = 0; i < n; ++i)
	{
		maxim = 2 * A[i + 1] + 1;
		for(conf = 0; conf < lim; ++conf)
		{
			if(best[i][conf] == -1 || best[i][conf] >= sol)
				continue;
			for(j = 1; j < maxim; ++j)
			{
				if(!(cheie[j] & conf))
				{
					dif = Modul(A[i + 1] - j);
					if(best[i + 1][cheie[j] | conf] == -1 || best[i + 1][cheie[j] | conf] > best[i][conf] + dif)
					{
						best[i + 1][cheie[j] | conf] = best[i][conf] + dif;
						numar[i + 1][cheie[j] | conf] = j;
					}
				}
			}
		}
	}
	conf = -1;
	for(i = 1; i < lim; ++i)
	{
		if(conf == -1 && best[n][i] >= 0)
			conf = i;
		else
		{
			if(conf >= 0 && best[n][i] >= 0 && best[n][conf] > best[n][i])
				conf = i;
		}
	}
	if(conf > 0)
	{
		i = n;
		while(i)
		{
			B[i] = numar[i][conf];
			conf -= cheie[numar[i][conf]];
			i--;
		}
	}
	for(i = 1; i <= n; ++i)
		cout << B[i] << ' ';
	cout << "\n";
	return 0;
}
