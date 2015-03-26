#include <iostream>
#include <algorithm>
using namespace std;
int n, v[110], pile[110];

inline bool Posibil(int m)
{
	int i, j;
	for(i = n, j = 1; i > 0 && j <= m; --i, ++j)
		pile[j] = v[i];
	j = 1;
	while(i > 0)
	{
		sort(pile + 1, pile + m + 1);
		if(pile[m] == 0)
			return false;
		pile[m] = min(pile[m] - 1, v[i]);
		i--;
	}
	return true;
}

inline int CautareBinara()
{
	int st, dr, mij, rez;
	st = 1;
	dr = rez = n;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		if(Posibil(mij))
		{
			rez = mij;
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
	return rez;
}

int main()
{
	int i;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	sort(v + 1, v + n + 1);
	cout << CautareBinara() << "\n";
	return 0;
}
