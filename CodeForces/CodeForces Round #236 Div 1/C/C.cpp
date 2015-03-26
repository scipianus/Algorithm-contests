#include <iostream>
using namespace std;
int n;
bool uzlin[2010], uzcol[2010];

int main()
{
	int i, j, x;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			cin >> x;
			if(x > 0 && i != j)
			{
				uzlin[i] = uzcol[j] = true;
			}
		}
	}
	for(i = 1; i <= n; ++i)
	{
		if(!uzlin[i] || !uzcol[i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
