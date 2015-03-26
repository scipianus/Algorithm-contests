#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
double sol;

inline double LgPut(double baz, int put)
{
	double rez = 1.0;
	while(put > 0)
	{
		if(put % 2 == 1)
		{
			rez = rez * baz;
			put--;
		}
		baz = baz * baz;
		put /= 2;
	}
	return rez;
}

int main()
{
	int i;
	double p, pn, sum = 0.0;
	std::ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for(i = m; i > 0; --i)
	{
		p = 1.0 * (i - 1) / (1.0 * m);
		pn = LgPut(p, n);
		sol += 1.0 * i * (1.0 - pn - sum);
		sum += 1.0 - pn - sum;
	}
	printf("%.10lf\n", sol);
	return 0;
}
