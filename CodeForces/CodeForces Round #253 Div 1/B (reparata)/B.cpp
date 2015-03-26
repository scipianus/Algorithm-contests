#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
double p[110], sol, prod[110];

int main()
{
	std::ios_base::sync_with_stdio(false);
	double now;
	int i, j;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> p[i];
	sort(p + 1, p + n + 1);
	prod[n + 1] = 1.0;
	for(i = n; i > 0; --i)
		prod[i] = prod[i + 1] * (1.0 - p[i]);
	sol = p[n];
	for(i = 1; i < n; ++i)
	{
		now = 0.0;
		for(j = n - i; j <= n; ++j)
			now += prod[n - i] * p[j] / (1.0 - p[j]);
		sol = max(sol, now);
	}
	printf("%.10lf\n", sol);
	return 0;
}
