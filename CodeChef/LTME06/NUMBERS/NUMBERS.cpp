#include <iostream>
#include <algorithm>
#define pis pair<int, string>
using namespace std;
int T, n, sol;
pis v[10100];

int main()
{
	int i;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(i = 1; i <= n; ++i)
			cin >> v[i].second >> v[i].first;
		sort(v + 1, v + n + 1);
		sol = -1;
		v[n + 1].first = -1;
		for(i = 1; i <= n && sol < 0; ++i)
			if(v[i].first != v[i - 1].first && v[i].first != v[i + 1].first)
				sol = i;
		if(sol == -1)
			cout << "Nobody wins.\n";
		else
			cout << v[sol].second << "\n";
	}
	return 0;
}
