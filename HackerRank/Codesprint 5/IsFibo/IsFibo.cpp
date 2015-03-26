#include <iostream>
#include <algorithm>
using namespace std;
int T, nrfib;
long long N, fib[55];

int main()
{
	int poz;
	fib[++nrfib] = 1LL;
	fib[++nrfib] = 1LL;
	while(fib[nrfib] <= 10000000000LL)
	{
		nrfib++;
		fib[nrfib] = fib[nrfib - 1] + fib[nrfib - 2];
	}
	cin >> T;
	while(T--)
	{
		cin >> N;
		poz = lower_bound(fib + 1, fib + nrfib + 1, N) - fib;
		if(fib[poz] == N)
			cout << "IsFibo\n";
		else
			cout << "IsNotFibo\n";
	}
	return 0;
}
