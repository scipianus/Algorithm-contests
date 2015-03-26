/*
PROB: sight
LANG: C++
*/
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, R;
struct Punct{int x, y;};
Punct P[50100];
long long sol;

inline bool Apartine(double x, double y, Punct A, Punct B)
{
	double a, b, c;
	a = 1.0 * (A.y - B.y);
	b = 1.0 * (B.x - A.x);
	c = 1.0 * A.x * B.y - 1.0 * A.y * B.x;
	if(fabs(a * x + b * y + c) < 0.000001)
		return true;
	return false;
}

inline bool Intersect(Punct A, Punct B)
{
	double a, b, c, delta, y1, y2, x1, x2;
	a = 1.0 * (A.y - B.y);
	b = 1.0 * (B.x - A.x);
	c = 1.0 * A.x * B.y - 1.0 * A.y * B.x;
	delta = 4.0 * b * b * c * c - 4.0 * (a * a + b * b) * (c * c - a * a * R * R);
	if(delta >= 0.0)
	{
		y1 = (-2.0 * b * c - sqrt(delta)) / (2.0 * (a * a + b * b));
		y2 = (-2.0 * b * c + sqrt(delta)) / (2.0 * (a * a + b * b));
		if(y1 > y2)
			swap(y1, y2);
		if(A.y != B.y)
		{
			if(1.0 * min(A.y, B.y) < y1 && y2 < 1.0 * max(A.y, B.y))
				return true;
			return false;
		}
		else
		{
			x1 = sqrt(1.0 * R * R - y1 * y1);
			if(!Apartine(x1, y1, A, B))
				x1 = -x1;
			x2 = sqrt(1.0 * R * R - y2 * y2);
			if(!Apartine(x2, y2, A, B))
				x2 = -x2;
			if(x1 > x2)
				swap(x1, x2);
			if(1.0 * min(A.x, B.x) < x1 && x2 < 1.0 * max(A.x, B.x))
				return true;
			return false;
		}
	}
	return false;
}

int main()
{
	int i, j;
	ifstream fin("sight.in");
	fin >> n >> R;
	for(i = 1; i <= n; ++i)
		fin >> P[i].x >> P[i].y;
	fin.close();
	
	sol = 1LL * n * (n - 1) / 2LL;
	for(i = 1; i <= n; ++i)
	{
		for(j = i + 1; j <= n; ++j)
		{
			if(Intersect(P[i], P[j]))
				sol -= 1LL;
		}
	}
	
	ofstream fout("sight.out");
	fout << sol << "\n";
	fout.close();
	return 0;
}
