#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, start, nrc[2], sol1, sol2;
struct Candy
{
	int h, m;
	bool operator <(const Candy &A) const
	{
		if(h == A.h)
			return m > A.m;
		return h < A.h;
	}
};
Candy v[2][2010];
bool uz[2][2010];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, now, p, tip, h, m;
	cin >> n >> start;
	for(i = 1; i <= n; ++i)
	{
		cin >> tip >> h >> m;
		nrc[tip]++;
		v[tip][nrc[tip]].h = h;
		v[tip][nrc[tip]].m = m;
	}
	sort(v[0] + 1, v[0] + nrc[0] + 1);
	sort(v[1] + 1, v[1] + nrc[1] + 1);
	// incep cu 0
	now = start;
	p = 0;
	while(1)
	{
		j = 0;
		for(i = 1; i <= nrc[p]; ++i)
		{
			if(!uz[p][i])
			{
				if(v[p][i].h <= now && (!j || v[p][i].m > v[p][j].m))
					j = i;
			}
		}
		if(!j)
			break;
		uz[p][j] = true;
		now += v[p][j].m;
		sol1++;
		p = 1 - p;
	}
	for(i = 1; i <= nrc[0]; ++i)
		uz[0][i] = false;
	for(i = 1; i <= nrc[1]; ++i)
		uz[1][i] = false;
	// incep cu 1
	now = start;
	p = 1;
	while(1)
	{
		j = 0;
		for(i = 1; i <= nrc[p]; ++i)
		{
			if(!uz[p][i])
			{
				if(v[p][i].h <= now && (!j || v[p][i].m > v[p][j].m))
					j = i;
			}
		}
		if(!j)
			break;
		uz[p][j] = true;
		now += v[p][j].m;
		sol2++;
		p = 1 - p;
	}
	cout << max(sol1, sol2) << "\n";
	return 0;
}
