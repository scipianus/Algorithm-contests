#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int T, ns, sol;
char s[1010];
map <char, int> val;

int main()
{
	val['0'] = 0;
	val['1'] = 1;
	val['2'] = 2;
	val['3'] = 3;
	val['4'] = 4;
	val['5'] = 5;
	val['6'] = 6;
	val['7'] = 7;
	val['8'] = 8;
	val['9'] = 9;
	val['a'] = 10;
	val['b'] = 11;
	val['c'] = 12;
	val['d'] = 13;
	val['e'] = 14;
	val['f'] = 15;
	int i, j;
	long long a, b, c;
	bool ok, gasit;
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> (s + 1);
		ns = strlen(s + 1);
		ok = true;
		gasit = false;
		for(i = 16; i > 1 && ok && !gasit; --i)
		{
			a = b = c = 0;
			j = 1;
			while(s[j] != '+')
			{
				a = 1LL * a * i + 1LL * val[s[j]];
				if(val[s[j]] >= i)
					ok = false;
				j++;
			}
			j++;
			while(s[j] != '=')
			{
				b = 1LL * b * i + 1LL * val[s[j]];
				if(val[s[j]] >= i)
					ok = false;
				j++;
			}
			j++;
			while(j <= ns)
			{
				c = 1LL * c * i + 1LL * val[s[j]];
				if(val[s[j]] >= i)
					ok = false;
				j++;
			}
			if(ok && a + b == c)
				gasit = true;
		}
		if(gasit)
			sol++;
		for(j = 0; j <= ns; ++j)
			s[j] = 0;
	}
	cout << sol << "\n";
	return 0;
}
