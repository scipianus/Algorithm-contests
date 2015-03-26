#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, aib[3][100100];
char s[100100];

inline void Aduna(int p, int poz)
{
	while(poz <= n)
	{
		aib[p][poz]++;
		poz += (poz & -poz);
	}
}

inline int Suma(int p, int poz)
{
	int sum = 0;
	while(poz > 0)
	{
		sum += aib[p][poz];
		poz -= (poz & -poz);
	}
	return sum;
}

int main()
{
	int i, st, dr, nr[3];
	cin >> (s+1);
	n = strlen(s + 1);
	for(i = 1; i <= n; ++i)
		Aduna(s[i] - 'x', i);
	cin >> m;
	while(m--)
	{
		cin >> st >> dr;
		if(dr - st + 1 < 3)
		{
			cout << "YES\n";
			continue;
		}
		for(i = 0; i < 3; ++i)
			nr[i] = Suma(i, dr) - Suma(i, st - 1);
		sort(nr, nr + 3);
		if(nr[2] - nr[0] > 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
