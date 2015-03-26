#include <iostream>
#include <cstring>
using namespace std;
int ns;
char s[110];
bool ok[3];

int main()
{
	int i;
	cin >> (s + 1);
	ns = strlen(s + 1);
	for(i = 1; i <= ns; ++i)
	{
		if('a' <= s[i] && s[i] <= 'z')
			ok[0] = true;
		if('A' <= s[i] && s[i] <= 'Z')
			ok[1] = true;
		if('0' <= s[i] && s[i] <= '9')
			ok[2] = true;
	}
	if(ns >= 5 && ok[0] && ok[1] && ok[2])
		cout << "Correct\n";
	else
		cout << "Too weak\n";
	return 0;
}
