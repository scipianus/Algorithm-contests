#include <iostream>
#include <cstring>
using namespace std;
int n, m, mat[1010][1010], sum, nr;
string sol;

int main()
{
	int i, j, k, tip;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			cin >> mat[i][j];
	for(i = 1; i <= n; ++i)
	{
		for(j = 1, k = 1; j <= n; ++j, ++k)
			sum += mat[j][i] * mat[i][k];
		sum %= 2;
	}
	cin >> m;
	while(m--)
	{
		cin >> tip;
		if(tip <= 2)
		{
			cin >> i;
			nr++;
		}
		else
		{
			if(nr % 2 == 0)
				sol += (sum + '0');
			else
				sol += (1 - sum + '0');
		}
	}
	cout << sol << "\n";
	return 0;
}
