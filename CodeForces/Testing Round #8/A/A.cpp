#include <iostream>
#include <cmath>
using namespace std;
int a, b, c, d, r;
double q, e;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> a >> b >> c >> d;
	// aritmetic
	if(b - a == c - b && d - c == c - b)
	{
		r = b - a;
		cout << (d + r) << "\n";
		return 0;
	}
	// geometric
	if(a * c == b * b && b * d == c * c)
	{
		q = 1.0 * b / (1.0 * a);
		e = 1.0 * d * q;
		if(fabs(e - 1.0 * ((int)e)) < 0.0000001)
			cout << ((int)e) << "\n";
		else
			cout << "42\n";
		return 0;
	}
	cout << "42\n";
	return 0;
}
