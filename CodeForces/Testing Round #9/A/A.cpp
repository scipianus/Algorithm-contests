#include <iostream>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
int n;
pii v[1010];

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v + 1, v + n + 1);
	cout<< v[n].second << ' ' << v[n - 1].first << "\n";
	return 0;
}
