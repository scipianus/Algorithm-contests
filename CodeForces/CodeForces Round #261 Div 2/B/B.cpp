#include <iostream>
#include <algorithm>
using namespace std;
int n, v[200100];
long long sol;

int main()
{
	int i, j;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	sort(v + 1, v + n + 1);
	i = 1;
	while(i + 1 <= n && v[i + 1] == v[1])
		i++;
	j = n;
	while(j - 1 > 0 && v[j - 1] == v[n])
		j--;
	if(i != n)
		sol = 1LL * i * (n - j + 1);
	else
		sol = 1LL * n * (n - 1) / 2LL;
	cout << (v[n] - v[1]) << ' ' << sol << "\n";
	return 0;
}
