#include <iostream>
#include <algorithm>
using namespace std;
int T, n, K, S, A[2010], perm[2010];

inline bool Sortare(int x, int y)
{
	return A[x] > A[y];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i;
	cin >> T;
	while(T--)
	{
		cin >> n >> K >> S;
		for(i = 1; i <= n; ++i)
		{
			cin >> A[i];
			perm[i] = i;
		}
		//sort(perm + 1, perm + n + 1, Sortare);
		std::random_shuffle(perm + 1, perm + n + 1);
		for(i = 1; i <= n; ++i)
			cout << perm[i] << ' ';
		cout << "\n";
	}
	return 0;
}
