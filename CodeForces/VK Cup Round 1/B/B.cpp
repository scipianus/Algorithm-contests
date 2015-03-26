#include <iostream>
#include <algorithm>
#include <set>
#define INF 2000000000000000000LL
using namespace std;
int n, W, H, jos;
struct Om{int h, w;};
Om v[1010];
long long sol = INF;
multiset <int> S;

int main()
{
	int i, j, now, sz;
	bool posibil;
	multiset <int>::iterator it;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i].w >> v[i].h;
	jos = n / 2;
	for(i = 1000; i > 0; --i)
	{
		now = 0;
		posibil = true;
		W = 0;
		H = i;
		S.clear();
		sz = 0;
		for(j = 1; j <= n && posibil; ++j)
		{
			if(v[j].h > i)
			{
				if(now == jos)
				{
					posibil = false;
					continue;
				}
				if(v[j].w > i)
				{
					posibil = false;
					continue;
				}
				now++;
				W += v[j].h;
			}
			else
			{
				W += v[j].w;
				if(v[j].w <= i)
				{
					S.insert(v[j].h - v[j].w);
					sz++;
				}
			}
		}
		if(!posibil)
			continue;
		while(now < jos && sz)
		{
			now++;
			sz--;
			it = S.begin();
			if(*it >= 0)
				break;
			W += *it;
			S.erase(it);
		}
		sol = min(sol, 1LL * W * H);
	}
	cout << sol << "\n";
	return 0;
}
