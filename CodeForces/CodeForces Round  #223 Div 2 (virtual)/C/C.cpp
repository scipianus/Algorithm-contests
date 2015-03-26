#include <iostream>
using namespace std;
int n, m, L[100100], C[100100], val[100100];
int prefix[100100];
long long total, sum[100100];

inline int CautareBinara(long long poz)
{
	int st, dr, mij, gr;
	st = 1;
	dr = n;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		if(sum[mij - 1] < poz && poz <= sum[mij])
		{
			gr = mij;
			st = dr + 1;
		}
		else
		{
			if(sum[mij] < poz)
				st = mij + 1;
			else
				dr = mij - 1;
		}
	}
	if(val[gr] != 0)
		return val[gr];
	poz -= sum[gr - 1];
	if(poz % L[gr] == 0)
		return prefix[L[gr]];
	poz %= L[gr];
	return prefix[poz];
}

int main()
{
	int i, j, k, tip;
	long long poz;
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> tip;
		if(tip == 1)
		{
			cin >> val[i];
			if(total < 100000LL)
				prefix[++total] = val[i];
			sum[i] = sum[i - 1] + 1LL;
		}
		else
		{
			cin >> L[i] >> C[i];
			for(k = C[i]; k > 0; --k)
			{
				for(j = 1; j <= L[i]; ++j)
				{
					if(total < 100000LL)
						prefix[++total] = prefix[j];
					else
					{
						j = L[i];
						k = 0;
					}
				}
			}
			sum[i] = sum[i - 1] + 1LL * L[i] * C[i];
		}
	}
	cin >> m;
	for(i = 1; i <= m; ++i)
	{
		cin >> poz;
		cout << CautareBinara(poz) << ' ';
	}
	cout << "\n";
	return 0;
}
