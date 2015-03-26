#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;
int n, ns, nop, cifra[10], lg[10];
char s[100100];
string op[100100];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, cif, rest, lgnow;
	for(i = 0; i < 10; ++i)
	{
		cifra[i] = i;
		lg[i] = 10;
	}
	cin >> (s + 1);
	ns = strlen(s + 1);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> op[i];
	for(i = n; i > 0; --i)
	{
		cif = op[i][0] - '0';
		nop = op[i].size();
		j = 3;
		if(j == nop)
		{
			cifra[cif] = 0;
			lg[cif] = 1;
		}
		else
		{
			rest = 0;
			lgnow = 1LL;
			while(j < nop)
			{
				lgnow = (1LL * lgnow * lg[op[i][j] - '0']) % MOD;
				rest = (1LL * rest * lg[op[i][j] - '0'] + 1LL * cifra[op[i][j] - '0']) % MOD;
				j++;
			}
			cifra[cif] = rest;
			lg[cif] = lgnow;
		}
	}
	rest = 0;
	for(i = 1; i <= ns; ++i)
		rest = (1LL * rest * lg[s[i] - '0'] + 1LL * cifra[s[i] - '0']) % MOD;
	cout << rest << "\n";
	return 0;
}
