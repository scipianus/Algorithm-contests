#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n, sol = 1;
char s[1010];
vector <int> poz[30];

int main()
{
	int i, j, last, c, lg;
	cin >> (s + 1);
	n = strlen(s + 1);
	for(i = 1; i <= n; ++i)
		poz[s[i] - 'A'].push_back(i);
	for(i = 1; i <= n; ++i)
	{
		last = i;
		j = 0;
		c = s[i] - 'A';
		while(j < poz[c].size() && poz[c][j] <= last)
			j++;
		lg = 1;
		while(j < poz[c].size())
		{
			if((poz[c][j] - last) % 2 == 1)
			{
				lg++;
				last = poz[c][j];
			}
			j++;
		}
		sol = max(sol, lg);
	}
	cout << sol << "\n";
	return 0;
}
