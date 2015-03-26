#include <iostream>
using namespace std;
int n, sol = 20, ord[12], nrpas;
bool exista[100], existacol[100], existacif[100], ask1[100], ask2[100];

inline void Verif()
{
	int i, j, k, p, r1, r2, nrc = 0;
	r1 = r2 = 5;
	for(i = 10; i <= 50; i += 10)
		if(!existacol[i])
		{
			ask1[i] = true;
			r1--;
		}
		else
			ask1[i] = false;
	for(i = 1; i <= 5; ++i)
		if(!existacif[i])
		{
			ask2[i] = true;
			r2--;
		}
		else
			ask2[i] = false;
	if(r1 == 1 && r2 == 1)
	{
		sol = 0;
		return;
	}
	for(i = 1; i <= 5; ++i)
		for(j = 1; j <= 5; ++j)
		{
			if(exista[i * 10 + j])
				nrc++;
		}
	k = 1;
	while(ord[k])
	{
		if(ord[k] <= 5)
		{
			ask2[ord[k]] = true;
			r2--;
		}
		else
		{
			ask1[ord[k]] = true;
			r1--;
		}
		k++;
	}
	for(i = 1; i <= 5; ++i)
	{
		for(j = 1; j <= 5; ++j)
		{
			if(exista[i * 10 + j])
			{
				if((ask1[i * 10] || r1 == 1) && (ask2[j] || r2 == 1))
					continue;
				else
				{
					if(ask1[i * 10] || r1 == 1)
					{
						for(p = 1; p <= 5; ++p)
						{
							if(exista[i * 10 + p] && p != j && !(ask2[p] || r2 == 1))
								return;
						}
					}
					else
					{
						if(ask2[j] || r2 == 1)
						{
							for(p = 1; p <= 5; ++p)
							{
								if(exista[p * 10 + j] && p != i && !(ask1[p * 10] || r1 == 1))
									return;
							}
						}
						else
							return;
					}
				}
			}
		}
	}
	sol = min(sol, k - 1);
}

inline void Back(int pas)
{
	Verif();
	if(pas == nrpas + 1)
		return;
	int i;
	for(i = 1; i <= 5; ++i)
		if(i > ord[pas - 1] && existacif[i])
		{
			ord[pas] = i;
			Back(pas + 1);
			ord[pas] = 0;
		}
	for(i = 10; i <= 50; i += 10)
		if(i > ord[pas - 1] && existacol[i])
		{
			ord[pas] = i;
			Back(pas + 1);
			ord[pas] = 0;
		}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, x;
	char now[5];
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> now;
		if(now[0] == 'R')
			x = 1;
		if(now[0] == 'G')
			x = 2;
		if(now[0] == 'B')
			x = 3;
		if(now[0] == 'Y')
			x = 4;
		if(now[0] == 'W')
			x = 5;
		existacol[x * 10] = true;
		existacif[now[1] - '0'] = true;
		x = x * 10 + now[1] - '0';
		exista[x] = true;
	}
	for(i = 1; i <= 5; ++i)
		if(existacif[i])
			nrpas++;
	for(i = 10; i <= 50; i += 10)
		if(existacol[i])
			nrpas++;
	Back(1);
	cout << sol << "\n";
	return 0;
}
