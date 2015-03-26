#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int T;
double B, L, R1, R2;

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> B >> L;
		R1 = sqrt(L * L - B * B);
		R2 = sqrt(L * L + B * B);
		printf("%.06lf %.06lf\n", R1, R2);
	}
	return 0;
}
