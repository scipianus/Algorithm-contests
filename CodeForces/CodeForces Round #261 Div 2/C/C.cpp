#include <iostream>
using namespace std;
int n, D, K, sol[1010][1010];

int main()
{
	int i, j, k;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> K >> D;
	for(i = 1; i <= D; ++i)
		sol[i][1] = 1;
	i = 2;
	while(1)
	{
		if(i == n + 1)
			break;
		for(k = 1; k <= D; ++k)
			sol[k][i] = sol[k][i - 1];
		j = 1;
		while(j <= D && sol[j][i - 1] == K)
			j++;
		if(j == D + 1)
			break;
		for(k = 1; k < j; ++k)
			sol[k][i] = 1;
		sol[j][i]++;
		i++;
	}
	if(i <= n)
		cout << "-1\n";
	else
	{
		for(i = 1; i <= D; ++i)
		{
			for(j = 1; j <= n; ++j)
				cout << sol[i][j] << ' ';
			cout << "\n";
		}
	}
	return 0;
}
