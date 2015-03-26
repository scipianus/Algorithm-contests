#include <iostream>
using namespace std;
int n, m, sol;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m;
	while(n)
	{
		sol++;
		n--;
		if(sol % m == 0)
			n++;
	}
	cout << sol << "\n";
	return 0;
}
