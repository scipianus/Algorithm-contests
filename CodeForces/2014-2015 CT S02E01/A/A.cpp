#include <iostream>
using namespace std;
int n, K;
bool pos[2][110];

int main()
{
	int i, j, x;
	cin >> n >> K;
	pos[0][0] = true;
	for(i = 1; i <= n; ++i)
	{
		cin >> x;
		for(j = 0; j < K; ++j)
		{
			if(pos[0][j])
			{
				pos[1][(j + x % K + 2 * K) % K] = true;
				pos[1][(j - x % K + 2 * K) % K] = true;
			}
		}
		for(j = 0; j < K; ++j)
		{
			pos[0][j] = pos[1][j];
			pos[1][j] = false;
		}
	}
	if(pos[0][0])
		cout << "Divisible\n";
	else
		cout << "Not divisible\n";
	return 0;
}
