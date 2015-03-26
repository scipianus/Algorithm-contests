#include <iostream>
#include <algorithm>
#include <set>
#define pii pair<int, int>
#define INF 1000000
using namespace std;
int W, H, n;
set <pii> S[2];
set <pair <int, pair<int, int> > > L[2];

int main()
{
	int coord, ind;
	char tip;
	pii now;
	set <pii>::iterator it;
	set <pair <int, pair<int, int> > >::iterator jt, kt;
	std::ios_base::sync_with_stdio(false);
	cin >> W >> H >> n;
	S[0].insert(make_pair(0, W));
	S[1].insert(make_pair(0, H));
	L[0].insert(make_pair(-W, make_pair(0, W)));
	L[1].insert(make_pair(-H, make_pair(0, H)));
	while(n--)
	{
		cin >> tip >> coord;
		if(tip == 'H')
			ind = 1;
		else
			ind = 0;
		it = S[ind].upper_bound(make_pair(coord, INF));
		it--;
		now = *it;
		jt = L[ind].lower_bound(make_pair(now.first - now.second, now));
		L[ind].erase(jt);
		S[ind].erase(it);
		S[ind].insert(make_pair(now.first, coord));
		S[ind].insert(make_pair(coord, now.second));
		L[ind].insert(make_pair(now.first - coord, make_pair(now.first, coord)));
		L[ind].insert(make_pair(coord - now.second, make_pair(coord, now.second)));
		jt = L[0].begin();
		kt = L[1].begin();
		cout << (1LL * (*jt).first * (*kt).first) << "\n";
	}
	return 0;
}
