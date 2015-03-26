#include <iostream>
using namespace std;
int hp[2], atk[2], def[2], price[3], sol, obligat;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> hp[0] >> atk[0] >> def[0];
	cin >> hp[1] >> atk[1] >> def[1];
	cin >> price[0] >> price[1] >> price[2];
	
	int i, j, k, nrture, a, b;
	sol = 2000000000;
	if(atk[0] <= def[1])
	{
		obligat = (def[1] + 1 - atk[0]) * price[1];
		atk[0] = def[1] + 1;
	}
	for(i = 0; i <= 10000; ++i)
	{
		if(i * price[1] >= sol)
			continue;
		for(j = 0; j <= 10000; ++j)
		{
			if(i * price[1] + j * price[2] >= sol)
			{
				j = 10000;
				continue;
			}
			a = atk[0] + i - def[1];
			b = max(atk[1] - def[0] - j, 0);
			if(hp[1] % a == 0)
				nrture = hp[1] / a;
			else
				nrture = hp[1] / a + 1;
			k = max(1 + nrture * b - hp[0], 0);
			sol = min(sol, k * price[0] + i * price[1] + j * price[2]);
		}
	}
	sol += obligat;
	cout << sol << "\n";
	return 0;
}
