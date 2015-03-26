#include <iostream>
#define MOD 1000000007
using namespace std;
int T, n, m, A[33][33], B[33][33], rez[33][33], sol, nr[33];

inline void Inmulteste(int a[33][33], int b[33][33])
{
	int i, j, k;
	for(k = 1; k <= m; ++k)
	{
		for(i = 1; i <= m; ++i)
		{
			for(j = 1; j <= m; ++j)
			{
				rez[i][j] += (1LL * a[i][k] * b[k][j]) % MOD;
				if(rez[i][j] >= MOD)
					rez[i][j] -= MOD;
			}
		}
	}
	for(i = 1; i <= m; ++i)
	{
		for(j = 1; j <= m; ++j)
		{
			a[i][j] = rez[i][j];
			rez[i][j] = 0;
		}
	}
}

inline void LgPut(int put)
{
	while(put > 0)
	{
		if(put % 2 == 1)
		{
			Inmulteste(B, A);
			put--;
		}
		Inmulteste(A, A);
		put /= 2;
	}
}

int main()
{
	int i, j;
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		sol = 0;
		if(n == 1)
		{
			cout << m << "\n";
			continue;
		}
		if(m == 1)
		{
			cout << "0\n";
			continue;
		}
		for(i = 1; i <= m; ++i)
		{
			for(j = 1; j <= m; ++j)
			{
				if(i == j)
					B[i][j] = 1;
				else
					B[i][j] = 0;
			}
			A[i][i] = 1;
			if(i + 1 <= m)
				A[i + 1][i] = 1;
			if(i + 2 <= m)
				A[i + 2][i] = 1;
			if(i - 1 > 0)
				A[i - 1][i] = 1;
			if(i - 2 > 0)
				A[i - 2][i] = 1;
			if(i - 1 > 0 && i + 1 <= m)
				A[i][i] = 2;
		}
		if(n % 2 == 1)
		{
			n--;
			LgPut(n / 2);
			for(i = 1; i <= m; ++i)
				for(j = 1; j <= m; ++j)
				{
					sol += B[i][j];
					if(sol >= MOD)
						sol -= MOD;
				}
		}
		else
		{
			nr[1] = nr[m] = 1;
			for(i = 2; i < m; ++i)
				nr[i] = 2;
			n -= 2;
			LgPut(n / 2);
			for(i = 1; i <= m; ++i)
				for(j = 1; j <= m; ++j)
				{
					sol += (1LL * nr[i] * B[i][j]) % MOD;
					if(sol >= MOD)
						sol -= MOD;
				}
		}
		for(i = 1; i <= m; ++i)
			for(j = 1; j <= m; ++j)
				A[i][j] = B[i][j] = 0;
		cout << sol << "\n";
	}
	return 0;
}
