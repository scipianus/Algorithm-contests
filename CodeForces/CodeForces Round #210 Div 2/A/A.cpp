#include <iostream>
using namespace std;
int n, K;

int main()
{
	int i, j;
	cin >> n >> K;
	for( i = 1; i <= n; ++i)
	{
		for( j = 1; j <=n; ++j)
		{
			if(i != j)
				cout << "0 ";
			else
				cout << K << ' ';
		}
		cout << "\n";
	}
	return 0;
}
