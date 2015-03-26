#include <iostream>
#include <cstring>
#include <map>
#define pii pair<int, int>
using namespace std;
int n, nr[3];
char s[1000100];
long long sol;
map <pii, int> M;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i;
	cin >> (s + 1);
	n = strlen(s + 1);
	M[make_pair(0, 0)] = 1;
	for(i = 1; i <= n; ++i)
	{
		nr[s[i] - 'A']++;
		if(M.count(make_pair(nr[1] - nr[0], nr[2] - nr[0])))
			sol += 1LL * M[make_pair(nr[1] - nr[0], nr[2] - nr[0])];
		M[make_pair(nr[1] - nr[0], nr[2] - nr[0])]++;
	}
	cout << sol << "\n";
	return 0;
}
