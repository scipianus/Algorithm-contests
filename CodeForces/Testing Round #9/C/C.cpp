#include <iostream>
#include <cstring>
using namespace std;
int ns, nr[26], dif, nrsol;
char s[300100];
long long sol;

int main()
{
	int i, st, dr, k, now;
	std::ios_base::sync_with_stdio(false);
	cin >> (s + 1);
	ns = strlen(s + 1);
	for(i = 1; i <= ns; ++i)
	{
		nr[s[i] - 'a']++;
		if(nr[s[i] - 'a'] == 1)
			nrsol++;
	}
	cout << nrsol << "\n";
	memset(nr, 0, sizeof(nr));
	for(k = 1; k <= nrsol; ++k)
	{
		sol = 0LL;
		st = dr = 1;
		nr[s[1] - 'a']++;
		dif = 1;
		now = 1;
		if(k == 1)
			sol++;
		while(dr + 1 <= ns)
		{
			dr++;
			nr[s[dr] - 'a']++;
			if(nr[s[dr] - 'a'] == 1)
				dif++;
			while(dif > k)
			{
				now = 1;
				if(nr[s[st] - 'a'] == 1)
					dif--;
				nr[s[st] - 'a']--;
				st++;
			}
			if(dif == k)
			{
				while(dif == k && nr[s[st] - 'a'] > 1)
				{
					nr[s[st] - 'a']--;
					st++;
					now++;
				}
				sol += 1LL * now;
			}
		}
		cout << sol << "\n";
		memset(nr, 0, sizeof(nr));
	}
	return 0;
}
