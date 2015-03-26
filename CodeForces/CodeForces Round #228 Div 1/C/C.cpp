#include <iostream>
#include <algorithm>
#define pii pair <int, int>
using namespace std;
int n, v[110], sum, sol;
pii dif[110];

inline bool Sortare(pii a, pii b)
{
	return a.first - a.second > b.first - b.second;
}

int main()
{
	int i, j, size, sa, sb;
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> size;
		for(j = 1; j <= size; ++j)
		{
			cin >> v[j];
			sum += v[j];
		}
		if(size % 2 == 1)
		{
			sa = sb = 0;
			for(j = 1; j <= size / 2; ++j)
				sa += v[j];
			for(j = size / 2 + 2; j <= size; ++j)
				sb += v[j];
			j = size / 2 + 1;
			dif[i].first = sa + v[j] - sb;
			dif[i].second = sa - v[j] - sb;
		}
		else
		{
			sa = sb = 0;
			for(j = 1; j <= size / 2; ++j)
				sa += v[j];
			for(j = size / 2 + 1; j <= size; ++j)
				sb += v[j];
			dif[i].first = sa - sb;
			dif[i].second = sa - sb;
		}
	}
	sort(dif + 1, dif + n + 1, Sortare);
	for(i = 1; i <= n; ++i)
	{
		if(i % 2 == 1)
			sol += dif[i].first;
		else
			sol += dif[i].second;
	}
	sa = (sum - sol) / 2 + sol;
	sb = (sum - sol) / 2;
	cout << sa << ' ' << sb << "\n";
	return 0;
}
