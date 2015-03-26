#include <iostream>
#include <algorithm>
using namespace std;
int n, Q, bg, v[100100], aib[100100], lgnow, invers;

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
	int rez = 0;
	while(poz > 0)
	{
		rez += aib[poz];
		poz -= (poz & -poz);
	}
	return rez;
}

int main()
{
	int i, j, tip, L, R, poz, aux, sum;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> Q;
	bg = 0;
	lgnow = n;
	for(i = 1; i <= n; ++i)
	{
		v[i] = 1;
		Aduna(i, 1);
	}
	while(Q--)
	{
		cin >> tip;
		if(tip == 1)
		{
			cin >> poz;
			if(!invers)
			{
				aux = poz;
				i = poz + 1;
				j = poz;
				if(aux <= lgnow - aux)
				{
					lgnow -= aux;
					i += bg;
					j += bg;
					bg += aux;
					while(aux--)
					{
						Aduna(i, v[j]);
						Aduna(j, -v[j]);
						v[i] += v[j];
						v[j] = 0;
						i++;
						j--;
					}
				}
				else
				{
					lgnow -= aux;
					swap(aux, lgnow);
					swap(i, j);
					i += bg;
					j += bg;
					while(aux--)
					{
						Aduna(i, v[j]);
						Aduna(j, -v[j]);
						v[i] += v[j];
						v[j] = 0;
						i--;
						j++;
					}
					invers = 1 - invers;
				}
			}
			else
			{
				poz = lgnow - poz + bg;
				///
			}
		}
		else
		{
			cin >> L >> R;
			if(!invers)
			{
				L += bg + 1;
				R += bg;
			}
			if(invers)
			{
				L = lgnow - L + bg;
				R = lgnow - R + bg + 1;
				swap(L, R);
			}
			sum = Suma(R) - Suma(L - 1);
			cout << sum << "\n";
		}
	}
	return 0;
}
