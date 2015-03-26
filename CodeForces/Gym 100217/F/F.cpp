#include <fstream>
#include <cmath>
#include <cstdio>
#define PI 3.14159265359
using namespace std;
double frac, lambda, sol;

int main()
{
	double a, b, c, delta, x1, x2, angle, tg, y;
	ifstream fin("painting.in");
	fin >> frac >> lambda;
	fin.close();
	
	angle = PI - asin(1.0 / lambda);
	tg = tan(angle);
	a = tg * tg + 1.0;
	b = 2.0 * frac * tg - 2.0 * tg * tg * sqrt(1.0 - frac * frac);
	c = frac * frac + tg * tg * (1.0 - frac * frac) - 2.0 * frac * tg * sqrt(1.0 - frac * frac) - 1.0;
	delta = b * b - 4.0 * a * c;
	x1 = (-1.0 * b - sqrt(delta)) / (2.0 * a);
	x2 = (-1.0 * b + sqrt(delta)) / (2.0 * a);
	if(-1.0 < x1 && x1 < 0.0)
		y = sqrt(1.0 - x1 * x1);
	else
		y = sqrt(1.0 - x2 * x2);
	sol = (y + 1.0) / (frac + 1.0);
	
	freopen("painting.out","w",stdout);
	printf("%.7lf\n",sol);
	return 0;
}
