#include <iostream>
using namespace std;
int n, m, K, sol, uz[2];

int main()
{
	int i, tip;
	cin >> n >> m >> K;
	for(i = 1; i <= n; ++i)
	{
		cin >> tip;
		if(tip == 2)
		{
			if(uz[1] < K)
				uz[1]++;
			else
			{
				if(uz[0] < m)
					uz[0]++;
				else
					sol++;
			}
		}
		else
		{
			if(uz[0] < m)
				uz[0]++;
			else
				sol++;
		}
	}
	cout << sol << "\n";
	return 0;
}
