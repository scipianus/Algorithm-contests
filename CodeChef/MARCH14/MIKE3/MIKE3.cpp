#include <iostream>
#include <bitset>
using namespace std;
int n, m, sol;
bitset <20010> B[22], aux;
bool interzis[22][22];

inline void Back(int pas, int conf, int nr1)
{
	if(nr1 + m - pas <= sol)
		return;
	if(pas == m)
		sol = max(sol, nr1);
	else
	{
		int i;
		for(i = 0; i < pas; ++i)
			if((conf & (1 << i)) && interzis[pas][i])
				i = pas + 1;
		if(i == pas)
			Back(pas + 1, conf + (1 << pas), nr1 + 1);
		Back(pas + 1, conf, nr1);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, nr, x;
	cin >> n >> m;
	for(i = 0; i < m; ++i)
	{
		cin >> nr;
		for(j = 0; j < nr; ++j)
		{
			cin >> x;
			B[i][x] = true;
		}
	}
	for(i = 0; i < m; ++i)
	{
		for(j = i + 1; j < m; ++j)
		{
			aux = (B[i] & B[j]);
			if(aux.count() >= 1)
				interzis[i][j] = interzis[j][i] = true;
		}
	}
	Back(0, 0, 0);
	cout << sol << "\n";
	return 0;
}
