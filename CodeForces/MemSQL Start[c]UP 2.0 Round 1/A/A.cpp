#include <iostream>
#include <cstring>
using namespace std;
int n, m;
char s[100];
string nume[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
	int i, j;
	bool ok;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	for(i = 0; i < 8; ++i)
	{
		m = nume[i].length();
		if(n != m)
			continue;
		ok = true;
		for(j = 0; j < n; ++j)
		{
			if(s[j] == '.')
				continue;
			if(s[j] != nume[i][j])
				ok = false;
		}
		if(ok)
		{
			cout << nume[i] << "\n";
			return 0;
		}
	}
	return 0;
}
