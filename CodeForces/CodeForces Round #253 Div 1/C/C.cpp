#include <iostream>
#include <vector>
using namespace std;
int n, v[500100], mijloc, aib[500100];
vector <int> G[1000100];
bool uz[500100];
long long sol;

inline void Aduna(int poz)
{
	while(poz <= n)
	{
		aib[poz]++;
		poz += (poz & -poz);
	}
}

inline int Suma(int poz)
{
	int rez = 0;
	while(poz > 0)
	{
		rez += aib[poz];
		poz -= (poz & -poz);
	}
	return rez;
}

inline void CautareBinara(int poz, int nr)
{
	int st, dr, mij, rez, sum;
	rez = 1000000;
	st = 1;
	dr = poz - 1;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		sum = Suma(mij);
		if(sum >= nr)
		{
			if(sum == nr && uz[mij])
				rez = min(rez, v[mij]);
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
	nr++;
	st = poz + 1;
	dr = n;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		sum = Suma(mij);
		if(sum >= nr)
		{
			if(sum == nr && uz[mij])
				rez = min(rez, v[mij]);
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
	sol += 1LL * rez;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i;
	vector <int>::iterator it;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	if(n <= 2)
	{
		cout << "0\n";
		return 0;
	}
	if(v[1] <= v[n])
	{
		for(i = 2; i < n; ++i)
			G[v[i]].push_back(i);
	}
	else
	{
		for(i = n - 1; i > 1; --i)
			G[v[i]].push_back(i);
	}
	mijloc = min(v[1], v[n]);
	Aduna(1); uz[1] = true;
	Aduna(n); uz[n] = true;
	for(i = mijloc + 1; i <= 1000000; ++i)
	{
		for(it = G[i].begin(); it != G[i].end(); ++it)
		{
			CautareBinara(*it, Suma(*it));
			Aduna(*it);
			uz[*it] = true;
		}
	}
	for(i = mijloc - 1; i > 0; --i)
	{
		for(it = G[i].begin(); it != G[i].end(); ++it)
		{
			CautareBinara(*it, Suma(*it));
			Aduna(*it);
			uz[*it] = true;
		}
	}
	cout << sol << "\n";
	return 0;
}
