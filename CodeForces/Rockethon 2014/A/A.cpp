#include <iostream>
#include <cstring>
using namespace std;
int ns, sol;
char s[110];

int main()
{
	char last;
	int i, now = 1;
	cin >> (s + 1);
	ns = strlen(s + 1);
	last = s[1];
	for(i = 2; i <= ns; ++i)
	{
		if(s[i] == last)
			now++;
		else
		{
			if(now % 2 == 0)
				sol++;
			now = 1;
			last = s[i];
		}
	}
	if(now % 2 == 0)
		sol++;
	cout << sol << "\n";
	return 0;
}
