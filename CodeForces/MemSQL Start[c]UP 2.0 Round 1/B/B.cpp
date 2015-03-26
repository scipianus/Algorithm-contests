#include <iostream>
#include <cmath>
using namespace std;
int n, m;
int X[4], Y[4];
double sol;

inline double Dist(int xa, int ya, int xb, int yb)
{
	return sqrt(1.0 * (xa - xb) * (xa - xb) + 1.0 * (ya - yb) * (ya - yb));
}

inline double Solve(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd)
{
	return Dist(xa, ya, xb, yb) + Dist(xb, yb, xc, yc) + Dist(xc, yc, xd, yd);
}

int main()
{
	double now;
	cin >> n >> m;
	if(n == 0)
	{
		X[0] = 0; Y[0] = 1;
		X[1] = 0; Y[1] = m;
		X[2] = 0; Y[2] = 0;
		X[3] = 0; Y[3] = m - 1;
	}
	else
	{
		if(m == 0)
		{
			X[0] = 1; Y[0] = 0;
			X[1] = n; Y[1] = 0;
			X[2] = 0; Y[2] = 0;
			X[3] = n - 1; Y[3] = 0;
		}
		else
		{
			if(n >= m)
			{
				X[0] = 0; Y[0] = 0;
				X[1] = n; Y[1] = m;
				X[2] = 0; Y[2] = m;
				X[3] = n; Y[3] = 0;
			}
			else
			{
				X[0] = 0; Y[0] = 0;
				X[1] = n; Y[1] = m;
				X[2] = n; Y[2] = 0;
				X[3] = 0; Y[3] = m;
			}
		}
	}
	sol = Solve(X[0], Y[0], X[1], Y[1], X[2], Y[2], X[3], Y[3]);
	if(n >= 1 && m >= 1)
	{
		int a, b, c, d;
		for(a = 0; a < 2; ++a)
			for(b = 0; b < 2; ++b)
				for(c = 0; c < 2; ++c)
					for(d = 0; d < 2; ++d)
					{
						if(a == n && b == m)
							continue;
						if(a == 0 && b == 0)
							continue;
						if(a == n - c && b == m - d)
							continue;
						if(n == n - c && m == m - d)
							continue;
						if(n - c == 0 && m - d == 0)
							continue;
						now = Solve(a, b, n, m, 0, 0, n - c, m - d);
						if(now > sol)
						{
							sol = now;
							X[0] = a; Y[0] = b;
							X[1] = n; Y[1] = m;
							X[2] = 0; Y[2] = 0;
							X[3] = n - c; Y[3] = m - d;
						}
					}
	}
	for(int i = 0; i < 4; ++i)
		cout << X[i] << ' ' << Y[i] << "\n";
	return 0;
}
