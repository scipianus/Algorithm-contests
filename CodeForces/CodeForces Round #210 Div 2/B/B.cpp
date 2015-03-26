#include <iostream>
using namespace std;
int n, K, perm[100100];

int main()
{
	int i, now, dif;
	cin >> n >> K;
	for( i = 1; i <= n; ++i)
		perm[i] = i;
	now = n - 1;
	
	if(now < K)
	{
		cout << "-1\n";
		return 0;
	}
	dif = now - K + 1;
	for( i = 2; i <= dif; ++i)
		perm[i - 1] = i;
	perm[dif] = 1;
	for( i = 1; i <= n; ++i)
		cout << perm[i] << ' ';
	cout << "\n";
	return 0;
}
