#include <iostream>
using namespace std;
int T, n, p;

int main()
{
	int i, j, nr;
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> n >> p;
		nr = 0;
		i = 1;
		j = 2;
		while(nr < 2 * n + p)
		{
			cout << i << ' ' << j << "\n";
			nr++;
			j++;
			if(j > n)
			{
				i++;
				j = i + 1;
			}
		}
	}
	return 0;
}
