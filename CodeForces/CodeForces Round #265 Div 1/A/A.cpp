#include <iostream>
using namespace std;
int n, P;
char s[1010];
bool gasit;

inline bool Bun()
{
	int i;
	for(i = 1; i < n; ++i)
		if(s[i] == s[i + 1])
			return false;
	for(i = 1; i < n - 1; ++i)
		if(s[i] == s[i + 2])
			return false;
	return true;
}

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> P;
	cin >> (s + 1);
	while(1)
	{
		i = n;
		while(s[i] == 'a' + P - 1)
		{
			s[i] = 'a';
			i--;
		}
		if(i == 0)
			break;
		s[i]++;
		if(Bun())
		{
			gasit = true;
			break;
		}
	}
	if(!gasit)
		cout << "NO\n";
	else
		cout << (s + 1) << "\n";
	return 0;
}
