#include <iostream>
#include <cstring>
using namespace std;
int T, need[10], have[10], n, sol;
char s[210];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, cif;
	cin >> T;
	cin >> (s + 1);
	if(T == 0)
		need[0] = 1;
	else
	{
		while(T)
		{
			cif = T % 10;
			if(cif == 5)
				need[2]++;
			else
			{
				if(cif == 9)
					need[6]++;
				else
					need[cif]++;
			}
			T /= 10;
		}
	}
	n = strlen(s + 1);
	for(i = 1; i <= n; ++i)
	{
		if(s[i] == '5')
			have[2]++;
		else
		{
			if(s[i] == '9')
				have[6]++;
			else
				have[s[i] - '0']++;
		}
	}
	sol = 1000;
	for(i = 0; i < 10; ++i)
		if(need[i])
			sol = min(sol, have[i] / need[i]);
	cout << sol << "\n";
	return 0;
}
