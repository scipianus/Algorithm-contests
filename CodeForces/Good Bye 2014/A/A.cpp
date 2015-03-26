#include <iostream>
using namespace std;
int n, T, nr[30100];
bool pos[30100];

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> T;
	for(i = 1; i < n; ++i)
		cin >> nr[i];
	pos[1] = true;
	for(i = 1; i < T; ++i)
		if(pos[i])
			pos[i + nr[i]] = true;
	if(pos[T])
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
