#include <iostream>
#include <algorithm>
using namespace std;
int m, v[100100];
long long n, sol;

inline bool Sortare(int a, int b)
{
	return a > b;
}

int main()
{
	int i;
	long long nr, sum = 0LL;
	cin >> n >> m;
	for(i = 1; i <= m; ++i)
		cin >> nr >> v[i];
	sort(v + 1, v + m + 1, Sortare);
	for(i = 1; i <= m; ++i)
	{
		sum += 1LL * v[i];
		if(i % 2 == 1)
			nr = 1LL * i * (i - 1) / 2LL;
		else
			nr = 1LL * i * (i - 1) / 2LL + 1LL * i / 2LL - 1LL;
		if(nr <= n - 1LL)
			sol = max(sol, sum);
	}
	cout << sol << "\n";
	return 0;
}
