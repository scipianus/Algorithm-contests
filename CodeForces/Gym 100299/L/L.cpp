#include <iostream>
using namespace std;
int T, K;

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> K;
		cout << ((1 << K) - 1) << "\n";
	}
	return 0;
}
