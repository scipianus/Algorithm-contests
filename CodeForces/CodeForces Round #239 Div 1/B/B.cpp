#include <iostream>
#define MOD 1000000007
using namespace std;
int n, p[1010], lg[1010], sol;

int main()
{
	int i;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> p[i];
	lg[2] = 2;
	for(i = 2; i <= n; ++i)
	{
		lg[i + 1] = (lg[i] + lg[i] - lg[p[i]] + 2) % MOD;
		if(lg[i + 1] < 0)
			lg[i + 1] += MOD;
	}
	sol = lg[n + 1];
	cout << sol << "\n";
	return 0;
}
