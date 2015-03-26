#include <iostream>
using namespace std;
int n;
long long sum;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, x;
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> x;
		sum += 1LL * x;
	}
	if(sum == 1LL * n * (n + 1) / 2LL)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
