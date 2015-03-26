#include <iostream>
using namespace std;
int n, K, sol;
bool exista[12];

int main()
{
	int x;
	bool ok;
	cin >> n >> K;
	while(n--)
	{
		cin >> x;
		while(x)
		{
			if(x % 10 <= K)
				exista[x % 10] = true;
			x /= 10;
		}
		ok = true;
		for(int i = 0; i <= K; ++i)
		{
			if(!exista[i] && i <= K)
				ok = false;
			exista[i] = false;
		}
		if(ok)
			sol++;
	}
	cout << sol << "\n";
	return 0;
}
