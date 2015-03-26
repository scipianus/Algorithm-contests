#include <iostream>
#include <set>
using namespace std;
int n, m, W, v[100100], sol;
multiset <int> S;

inline bool Posibil(int L)
{
	int i, ramas = m, H, now = 0, dif;
	multiset <int>::iterator it;
	S.clear();
	for(i = 1; i <= n; ++i)
	{
		H = v[i] + now;
		if(H < L)
		{
			dif = L - H;
			ramas -= dif;
			if(ramas < 0)
				return false;
			now += dif;
			while(dif--)
				S.insert(i + W - 1);
		}
		if(now)
		{
			it = S.find(i);
			while(it != S.end())
			{
				now--;
				S.erase(it);
				it = S.find(i);
			}
		}
	}
	return true;
}

inline void CautareBinara()
{
	int st, dr, mij;
	st = 1;
	dr = 1001000000;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		if(Posibil(mij))
		{
			sol = mij;
			st = mij + 1;
		}
		else
			dr = mij - 1;
	}
}

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m >> W;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	CautareBinara();
	cout << sol << "\n";
	return 0;
}
