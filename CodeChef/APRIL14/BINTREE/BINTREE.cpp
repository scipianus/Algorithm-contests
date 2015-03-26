#include <iostream>
using namespace std;
int T;

inline int Nivel(int x)
{
	int i = 30;
	while(i && (x & (1 << i)) == 0)
		i--;
	return i;
}

inline int Solve(int x, int y)
{
	int nr1, nr2, sol;
	nr1 = Nivel(x);
	nr2 = Nivel(y);
	sol = nr1 + nr2;
	while(nr1 != nr2)
	{
		if(nr1 < nr2)
		{
			y /= 2;
			nr2--;
		}
		else
		{
			x /= 2;
			nr1--;
		}
	}
	while(x != y)
	{
		x /= 2;
		y /= 2;
		nr1--;
		nr2--;
	}
	sol -= 2 * nr1;
	return sol;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int x, y;
	cin >> T;
	while(T--)
	{
		cin >> x >> y;
		cout << Solve(x, y) << "\n";
	}
	return 0;
}
