#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, p[301000];
struct Interval{
	int st, dr;
	bool operator <(const Interval &A) const
	{
		if(st == A.st)
			return dr < A.dr;
		return st < A.st;
	}
};
Interval I[301000];
struct Nod{vector <int> Y;};
Nod Aint[1510000];

inline void Construire_ArboreIntervale(int nod, int st, int dr)
{
    if(st == dr)
    {
        Aint[nod].Y.push_back(I[st].dr);
        return;
    }
    int mij = (st + dr) / 2, fiu = 2 * nod;
    Construire_ArboreIntervale(fiu, st, mij);
    Construire_ArboreIntervale(fiu + 1, mij + 1, dr);
    Aint[nod].Y.resize(dr - st + 1);
    merge(Aint[fiu].Y.begin(), Aint[fiu].Y.end(), Aint[fiu+1].Y.begin(), Aint[fiu+1].Y.end(), Aint[nod].Y.begin());
}
 
inline int Query(int nod, int st, int dr, int first, int last, int val)
{
    if(first <= st && dr <= last)
    {
        int poz;
        poz = lower_bound(Aint[nod].Y.begin(), Aint[nod].Y.end(), val) - Aint[nod].Y.begin();
        return ((dr - st + 1) - poz);
    }
	if(st == dr)
		return 0;
    int mij = (st + dr) / 2, fiu = 2 * nod, rez = 0;
    if(first <= mij)
        rez += Query(fiu, st, mij, first, last, val);
    if(mij + 1 <= last)
        rez += Query(fiu + 1, mij + 1, dr, first, last, val);
	return rez;
}

inline int CautareBinara(int val)
{
	int st, dr, mij, rez = n + 1;
	st = 1;
	dr = n;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		if(I[mij].st > val)
		{
			rez = min(rez, mij);
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
	return rez;
}

int main()
{
	int i, sz, cnt, poz1, poz2;
	cin >> n >> m;
	for(i = 1; i <= n; ++i)
		cin >> I[i].st >> I[i].dr;
	sort(I + 1, I + n + 1);
	Construire_ArboreIntervale(1, 1, n);
	while(m--)
	{
		cin >> sz;
		cnt = 0;
		for(i = 1; i <= sz; ++i)
			cin >> p[i];
		sort(p + 1, p + sz + 1);
		for(i = 1; i <= sz; ++i)
		{
			poz1 = CautareBinara(p[i - 1]);
			poz2 = CautareBinara(p[i]) - 1;
			if(poz1 > poz2)
				continue;
			cnt += Query(1, 1, n, poz1, poz2, p[i]); 
		}
		cout << cnt << "\n";
	}
	return 0;
}
