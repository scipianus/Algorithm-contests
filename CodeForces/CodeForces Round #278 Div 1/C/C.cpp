#include <iostream>
using namespace std;
int n;
int prime[30100], nrp;
bool ciur[100100], prim[100100];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, gasit;
	prime[++nrp] = 2;
	for(i = 3; i < 100000; i += 2)
	{
		if(!ciur[i])
		{
			prime[++nrp] = i;
			if(i <= 400)
				for(j = i * i; j < 100000; j += 2 * i)
					ciur[j] = true;
		}
	}
	for(i = 1; i <= nrp; ++i)
		prim[prime[i]] = true;
	
	cin >> n;
	if(n == 1)
	{
		cout << "YES\n";
		cout << "1\n";
		return 0;
	}
	if(prim[n])
	{
		cout << "YES\n";
		
	}
	else
	{
		gasit = 0;
		for(i = 1; prime[i] * prime[i] <= n; ++i)
		{
			if(prime[i] * prime[i] == n)
			{
				gasit = i;
				break;
			}
		}
		if(!gasit)
		{
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
	}
	return 0;
}
