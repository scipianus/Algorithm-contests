#include <iostream>
#include <cmath>
#include <deque>
#define MOD 1000000007
using namespace std;
int n, K, A[100100], pred[100100], sol;
double v[100100], best[100100];
deque <int> D;

int main()
{
	int i;
	cin >> n >> K;
	for(i = 1; i <= n; ++i)
	{
		cin >> A[i];
		v[i] = log10(1.0 * A[i]);
	}
	best[1] = v[1];
	D.push_back(1);
	for(i = 2; i <= n; ++i)
	{
		best[i] = v[i] + best[D.front()];
		pred[i] = D.front();
		while(!D.empty() && best[D.back()] >= best[i])
			D.pop_back();
		D.push_back(i);
		while(i - D.front() >= K)
			D.pop_front();
	}
	sol = 1;
	i = n;
	while(i)
	{
		sol = (1LL * sol * A[i]) % MOD;
		i = pred[i];
	}
	cout << sol << "\n";
	return 0;
}
