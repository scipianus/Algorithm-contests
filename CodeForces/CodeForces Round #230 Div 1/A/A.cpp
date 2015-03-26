#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
long long sol, n2;

int main()
{
	int i, j;
	long long i2;
	cin >> n;
	if(n == 0)
	{
		cout << "1\n";
		return 0;
	}
	n2 = 1LL * n * n;
	int last = 0;
	j = 1;
	for(i = n - 1; i > 0; --i)
	{
		i2 = 1LL * i * i;
		while(1LL * (j + 1) * (j + 1) <= n2 - i2)
			j++;
		if(j > last)
		{
			sol += 1LL * (j - last);
			last = j;
		}
		else
			if(j == last)
				sol += 1LL;
	}
	sol *= 4LL;
	sol += 4LL;
	cout << sol << "\n";
	return 0;
}
