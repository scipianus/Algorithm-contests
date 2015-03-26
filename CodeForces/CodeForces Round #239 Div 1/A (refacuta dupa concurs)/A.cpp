#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int a, b, x[2], y[2];

inline int Cmmdc(int c, int d)
{
	int r;
	while(d)
	{
		r = c % d;
		c = d;
		d = r;
	}
	return c;
}

int main()
{
	int i, j, i1, j1, i2, j2, c;
	std::ios_base::sync_with_stdio(false);
	cin >> a >> b;
	for(i = 1; i < a && x[1] == 0; ++i)
	{
		j = (int)sqrt(1.0 * (a * a - i * i));
		if(fabs(1.0 * j - sqrt(1.0 * (a * a - i * i))) < 0.00000001)
		{
			x[0] = i;
			y[0] = j;
			c = Cmmdc(i, j);
			i1 = i / c;
			j1 = j / c;
			i2 = j2 = 0;
			while(i2 <= b && i2 * i2 + j2 * j2 < b * b)
			{
				i2 += j1;
				j2 -= i1;
			}
			if(abs(i2 - x[0]) > 0 && abs(j2 - y[0]) > 0 && i2 * i2 + j2 * j2 == b * b)
			{
				x[1] = i2;
				y[1] = j2;
			}
		}
	}
	swap(a, b);
	for(i = 1; i < a && x[1] == 0; ++i)
	{
		j = (int)sqrt(1.0 * (a * a - i * i));
		if(fabs(1.0 * j - sqrt(1.0 * (a * a - i * i))) < 0.00000001)
		{
			x[0] = i;
			y[0] = j;
			c = Cmmdc(i, j);
			i1 = i / c;
			j1 = j / c;
			i2 = j2 = 0;
			while(i2 <= b && i2 * i2 + j2 * j2 < b * b)
			{
				i2 += j1;
				j2 -= i1;
			}
			if(abs(i2 - x[0]) > 0 && abs(j2 - y[0]) > 0 && i2 * i2 + j2 * j2 == b * b)
			{
				x[1] = i2;
				y[1] = j2;
			}
		}
	}
	if(x[1] == 0)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		cout << "0 0\n";
		cout << x[0] << ' ' << y[0] << "\n";
		cout << x[1] << ' ' << y[1] << "\n";
	}
	return 0;
}
