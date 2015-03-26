#include <iostream>
using namespace std;
int n, v[100100], sol;

int main()
{
	int i, j;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	
	if(n == 1)
		sol = 1;
	else
	{
		sol = 2;
		j = 1;
		for(i = 3; i <= n; ++i)
		{
			if(v[i] == v[i - 1] + v[i - 2])
				sol = max(sol, i - j + 1);
			else
				j = i - 1;
		}
	}
	
	cout << sol << "\n";
	return 0;
}
