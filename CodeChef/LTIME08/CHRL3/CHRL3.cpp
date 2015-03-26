#include <iostream>
#include <algorithm>
using namespace std;
int n, v[100100], lcs[100100], sol;

inline int CautareBinara(int val)
{
	int st, dr, mij, rez = -1;
	st = 1;
	dr = sol;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		if(lcs[mij] > val)
			st = mij + 1;
		else
		{
			rez = mij;
			dr = mij - 1;
		}
	}
	return rez;
}

int main()
{
	int i, poz;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	lcs[++sol] = v[1];
	for(i = 2; i <= n; ++i)
	{
		poz = CautareBinara(v[i]);
		if(poz == -1)
			lcs[++sol] = v[i];
		else
			lcs[poz] = v[i];
	}
	cout << sol << "\n";
	return 0;
}
