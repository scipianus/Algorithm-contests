#include <iostream>
#include <cstdio>
using namespace std;
int T, n;

inline int Gcd(int a, int b)
{
	int r;
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int i, x, gcd;
	std::ios_base::sync_with_stdio(false);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		scanf("%d", &gcd);
		for(i = 2; i <= n; ++i)
		{
			scanf("%d", &x);
			gcd = Gcd(gcd, x);
		}
		if(gcd == 1)
			printf("%d\n", n);
		else
			printf("-1\n");
	}
	return 0;
}
