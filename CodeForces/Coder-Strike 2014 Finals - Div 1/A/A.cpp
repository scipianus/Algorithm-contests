#include <iostream>
#include <cstring>
using namespace std;
int ns;
char s[100100];
bool fr[30];
char interzis[] = "ZSRPQNLKJGFEDCB";

inline bool LitereBune()
{
	int i;
	for(i = 0; i < strlen(interzis); ++i)
		if(fr[interzis[i] - 'A'])
			return false;
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	bool ok = true;
	int i, j;
	cin >> (s + 1);
	ns = strlen(s + 1);
	for(i = 1; i <= ns; ++i)
		fr[s[i] - 'A'] = true;
	i = 1;
	j = ns;
	while(i < j && ok)
	{
		if(s[i] != s[j])
			ok = false;
		else
		{
			i++;
			j--;
		}
	}
	if(ok && LitereBune())
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
