#include <iostream>
using namespace std;
int n, K, lg, lgmax, put[22];
char mat[1010][1010];

inline void Build(int rad, int nr)
{
	int i, j, k, k2;
	mat[rad][n + 1] = mat[n + 1][rad] = 'Y';
	mat[rad][n + 2] = mat[n + 2][rad] = 'Y';
	mat[rad][n + 3] = mat[n + 3][rad] = 'Y';
	for(i = 2, j = 1; i <= nr; ++i, j += 3)
	{
		for(k = 0; k < 3; ++k)
			for(k2 = 3; k2 < 6; ++k2)
				mat[n + j + k][n + j + k2] = mat[n + j + k2][n + j + k] = 'Y';
	}
	mat[n + j][2] = mat[2][n + j] = 'Y';
	mat[n + j + 1][2] = mat[2][n + j + 1] = 'Y';
	mat[n + j + 2][2] = mat[2][n + j + 2] = 'Y';
	n = n + j + 2;
}

int main()
{
	int i, j, last;
	cin >> K;
	n = 2;
	put[0] = 1;
	for(i = 1; i < 19; ++i)
		put[i] = 3 * put[i - 1];
	put[19] = 2000000000;
	if(K == 1)
	{
		cout << "2\n";
		cout << "NY\n";
		cout << "YN\n";
		return 0;
	}
	for(i = 1; i <= 1000; ++i)
		for(j = 1; j <= 1000; ++j)
			mat[i][j] = 'N';
	while(K > put[lg])
		lg++;
	if(K < put[lg])
		lg--;
	lgmax = lg;
	while(K >= 3)
	{
		lg = 0;
		while(K > put[lg])
			lg++;
		if(K < put[lg])
			lg--;
		K -= put[lg];
		if(lg != lgmax)
		{
			n++;
			mat[1][n] = mat[n][1] = 'Y';
			for(i = 2; i <= lgmax - lg; ++i)
			{
				n++;
				mat[n - 1][n] = mat[n][n - 1] = 'Y';
			}
			last = n;
		}
		else
			last = 1;
		Build(last, lg);
	}
	while(K)
	{
		n++;
		mat[1][n] = mat[n][1] = 'Y';
		for(i = 2; i <= lgmax; ++i)
		{
			n++;
			mat[n - 1][n] = mat[n][n - 1] = 'Y';
		}
		mat[n][2] = mat[2][n] = 'Y';
		K--;
	}
	cout << n << "\n";
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
			cout << mat[i][j];
		cout << "\n";
	}
	return 0;
}
