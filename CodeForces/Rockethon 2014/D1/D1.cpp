#include <iostream>
using namespace std;
int n1, n2, X1[1010], X2[1010], Y1[1010], Y2[1010], L1[1010], L2[1010];
int sol;

int main()
{
	int i, j, now;
	cin >> n1 >> n2;
	for(i = 1; i <= n1; ++i)
		cin >> X1[i] >> Y1[i] >> L1[i];
	for(i = 1; i <= n2; ++i)
		cin >> X2[i] >> Y2[i] >> L2[i];
	for(i = 1; i <= n1; ++i)
	{
		for(j = 1; j <= n2; ++j)
		{
			now = min(min(Y2[j] - Y1[i], Y1[i] + L1[i] - Y2[j]), min(X1[i] - X2[j], X2[j] + L2[j] - X1[i]));
			sol = max(sol, now);
		}
	}
	cout << sol << "\n";
	return 0;
}
