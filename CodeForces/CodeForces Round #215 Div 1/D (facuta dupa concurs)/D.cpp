#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, D, sz[22], st[22], dr[22], grup[100100], sol = 22;
vector <int> v[22];
bool bad[1100000];

int main()
{
	int i, j, x, conf, nr;
	cin >> n >> m >> D;
	for(i = 0; i < m; ++i)
	{
		cin >> sz[i];
		for(j = 1; j <= sz[i]; ++j)
		{
			cin >> x;
			grup[x] = i;
			v[i].push_back(x);
		}
		sort(v[i].begin(), v[i].end());
	}
	
	conf = 0;
	for(j = 0; j < m; ++j)
	{
		dr[j] = -1;
		while(dr[j] + 1 < sz[j] && v[j][dr[j] + 1] <= D)
			dr[j]++;
		if(dr[j] - st[j] + 1 <= 0)
			conf += (1 << j);
	}
	bad[conf] = true;
	for(i = D + 1; i <= n; ++i)
	{
		st[grup[i - D]]++;
		if(dr[grup[i - D]] - st[grup[i - D]] + 1 <= 0)
			conf += (1 << grup[i - D]);
		dr[grup[i]]++;
		if(dr[grup[i]] - st[grup[i]] + 1 == 1)
			conf -= (1 << grup[i]);
		bad[conf] = true;
	}
	for(conf = (1 << m) - 1; conf > 0; --conf)
	{
		if(bad[conf])
		{
			for(i = 0; i < m; ++i)
				if(conf & (1 << i))
					bad[conf - (1 << i)] = true;
		}
		else
		{
			nr = 0;
			for(i = 0; i < m; ++i)
				if(conf & (1 << i))
					nr++;
			sol = min(sol, nr);
		}
	}
	
	cout << sol << "\n";
	return 0;
}
