#include <iostream>
#include <cstring>
using namespace std;
int n, m, sol;
char mat[1010][1010];
bool deja[1010];

inline void Check(int j)
{
	int i;
	bool ok = true;
	for(i = 1; i < n; ++i)
	{
		if(deja[i] == true)
			continue;
		if(mat[i][j] > mat[i + 1][j])
			ok = false;
	}
	if(!ok)
	{
		sol++;
		return;
	}
	for(i = 1; i < n; ++i)
	{
		if(deja[i] == true)
			continue;
		if(mat[i][j] < mat[i + 1][j])
			deja[i] = true;
	}
}

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(i = 1; i <= n; ++i)
		cin >> (mat[i] + 1);
	for(i = 1; i <= m; ++i)
		Check(i);
	cout << sol << "\n";
	return 0;
}
