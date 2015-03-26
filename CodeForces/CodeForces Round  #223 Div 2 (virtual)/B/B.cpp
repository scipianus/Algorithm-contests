#include <iostream>
using namespace std;
int m, n, nr[5010];
int v[10010];

int main()
{
	int i, x, vf = 0;
	cin >> m;
	for(i = 1; i <= m; ++i)
	{
		cin >> x;
		nr[x]++;
	}
	for(i = 1; i <= 5000; ++i)
	{
		if(nr[i])
		{
			v[++n] = i;
			nr[i]--;
			vf = i;
		}
	}
	for(i = vf - 1; i > 0; --i)
	{
		if(nr[i])
		{
			v[++n] = i;
			nr[i]--;
		}
	}
	
	cout << n << "\n";
	for(i = 1; i <= n; ++i)
		cout << v[i] << ' ';
	cout << "\n";
	return 0;
}
