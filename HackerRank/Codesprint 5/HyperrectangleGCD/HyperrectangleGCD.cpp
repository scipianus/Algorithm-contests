#include <iostream>
#define MOD 1000000007
using namespace std;
int T, K, n[510], sol;

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

inline void Back(int pas, int last)
{
	if(pas == K + 1)
	{
		sol += last;
		if(sol >= MOD)
			sol -= MOD;
		return;
	}
	int i, gcd;
	for(i = 1; i <= n[pas]; ++i)
	{
		gcd = Gcd(i, last);
		Back(pas + 1, gcd);
	}
}

int main()
{
	int i;
	cin >> T;
	while(T--)
	{
		cin >> K;
		for(i = 1; i <= K; ++i)
			cin >> n[i];
		sol = 0;
		for(i = 1; i <= n[1]; ++i)
			Back(2, i);
		cout << sol << "\n";
	}
	return 0;
}
