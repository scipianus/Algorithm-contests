#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, per[1000100], sol[100100], aib[1000100];
char s[1000100];
int St[1000100], vf;
struct Intrebare
{
	int st, dr, ind;
	bool operator <(const Intrebare &A) const
	{
		return dr < A.dr;
	}
};
Intrebare Q[100100];

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
	int i, j;
	cin >> (s + 1);
	n = strlen(s + 1);
	for(i = 1; i <= n; ++i)
	{
		if(s[i] == '(')
			St[++vf] = i;
		else
		{
			if(vf > 0)
			{
				per[i] = St[vf];
				vf--;
			}
		}
	}
	cin >> m;
	for(i = 1; i <= m; ++i)
	{
		cin >> Q[i].st >> Q[i].dr;
		Q[i].ind = i;
	}
	sort(Q + 1, Q + m + 1);
	for(i = j = 1; i <= n && j <= m; ++i)
	{
		if(per[i])
			Aduna(per[i]);
		while(j <= m && Q[j].dr == i)
		{
			sol[Q[j].ind] = 2 * (Suma(i) - Suma(Q[j].st - 1));
			j++;
		}
	}
	for(i = 1; i <= m; ++i)
		cout << sol[i] << "\n";
	return 0;
}
