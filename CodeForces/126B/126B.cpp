#include <iostream>
#include <cstring>
using namespace std;
int n, Z[1000100], last, sol;
char s[1000100];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, last = 0;
	cin >> (s + 1);
	n = strlen(s + 1);

	for(i = 2; i <= n; ++i)
	{
		if(last + Z[last] - 1 < i)
		{
			j = 0;
			while(i + j <= n && s[j + 1] == s[i + j])
				j++;
			Z[i] = j;
		}
		else
		{
			j = i - last + 1;
			if(i + Z[j] - 1 < last + Z[last] - 1)
				Z[i] = Z[j];
			else
			{
				j = last + Z[last] - i;
				while(i + j <= n && s[j + 1] == s[i + j])
					j++;
				Z[i] = j;
			}
		}
		if(last + Z[last] - 1 < i + Z[i] - 1)
			last = i;
	}
	last = 0;
	for(i = n; i > 1; --i)
	{
		if(Z[i] >= last)
			sol = max(sol, last);
		if(i + Z[i] - 1 == n)
			last = Z[i];
	}
	
	if(sol)
	{
		s[sol + 1] = 0;
		cout << (s + 1) << "\n";
	}
	else
		cout << "Just a legend\n";
	return 0;
}
