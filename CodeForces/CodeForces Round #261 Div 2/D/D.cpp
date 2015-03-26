#include <iostream>
#include <map>
using namespace std;
int n, v[1000100], rez[2][1000100], aib[2000100];
long long sol;
map <int, int> nr;

inline void Aduna(int poz, int val)
{
	while(poz <= n)
	{
		aib[poz] += val;
		poz += (poz & -poz);
	}
}

inline int Suma(int poz)
{
	int sum = 0;
	while(poz > 0)
	{
		sum += aib[poz];
		poz -= (poz & -poz);
	}
	return sum;
}

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	for(i = 1; i <= n; ++i)
	{
		nr[v[i]]++;
		rez[0][i] = nr[v[i]];
	}
	nr.clear();
	for(i = n; i > 0; --i)
	{
		nr[v[i]]++;
		rez[1][i] = nr[v[i]];
	}
	for(i = 1; i <= n; ++i)
		Aduna(rez[1][i], 1);
	for(i = 1; i < n; ++i)
	{
		Aduna(rez[1][i], -1);
		sol += 1LL * Suma(rez[0][i] - 1);
	}
	cout << sol << "\n";
	return 0;
}
