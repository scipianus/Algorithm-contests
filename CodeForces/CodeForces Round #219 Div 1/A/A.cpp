#include <iostream>
#include <algorithm>
using namespace std;
int n, v[500100], sol[2];
bool uz[2][500100];

int main()
{
	int i, j;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	sort(v + 1, v + n + 1);
	
	sol[0] = sol[1] = n;
	for(i = n, j = n / 2; i > 0 && j > 0; --i)
	{
		if(uz[0][i])
			continue;
		while(j && 2 * v[j] > v[i])
			j--;
		if(j > 0)
		{
			uz[0][j] = true;
			sol[0]--;
			j--;
		}
	}
	for(i = 1, j = n/2 + n % 2; i <= n && j <= n; ++i)
	{
		if(uz[1][i])
			continue;
		while(j <= n && 2 * v[i] > v[j])
			j++;
		if(j <= n)
		{
			uz[1][j] = true;
			sol[1]--;
			j++;
		}
	}
	
	cout << min(sol[0], sol[1]) << "\n";
	return 0;
}
