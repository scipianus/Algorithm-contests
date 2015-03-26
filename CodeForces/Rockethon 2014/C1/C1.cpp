#include <iostream>
using namespace std;
int n, K, pct[20], eff[20];
long long sol = 2000000000000000000LL;
bool win[20];

inline void Verif()
{
	int i, poz = 1, p = 0, v[20];
	long long now = 0;
	for(i = 1; i <= n; ++i)
	{
		if(win[i])
		{
			now += 1LL * eff[i];
			p++;
			v[i] = pct[i];
		}
		else
			v[i] = pct[i] + 1;
	}
	for(i = 1; i <= n; ++i)
		if(p < v[i] || (p == v[i] && win[i] == false))
			poz++;
	if(poz > K)
		return;
	sol = min(sol, now);
}

inline void Back(int pas)
{
	if(pas == n + 1)
		Verif();
	else
	{
		win[pas] = false;
		Back(pas + 1);
		win[pas] = true;
		Back(pas + 1);
		win[pas] = false;
	}
}

int main()
{
	int i;
	cin >> n >> K;
	for(i = 1; i <= n; ++i)
		cin >> pct[i] >> eff[i];
	Back(1);
	if(sol == 2000000000000000000LL)
		cout << "-1\n";
	else
		cout << sol << "\n";
	return 0;
}
