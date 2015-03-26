#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int A, B, C, nr;
vector <int> sol;

inline int Sumcif(long long x)
{
	int rez = 0;
	while(x)
	{
		rez += (x % 10LL);
		x /= 10LL;
	}
	return rez;
}

int main()
{
	cin >> A >> B >> C;
	int i, j;
	long long x;
	for(i = 0; i <= 81; ++i)
	{
		x = 1LL * B;
		for(j = 1; j <= A; ++j)
			x = 1LL * x * i;
		x += 1LL * C;
		if(0LL < x && x < 1000000000LL && Sumcif(x) == i)
			sol.push_back(x);
	}
	sort(sol.begin(), sol.end());
	nr = sol.size();
	cout << nr << "\n";
	for(i = 0; i < nr; ++i)
		cout << sol[i] << ' ';
	cout << "\n";
	return 0;
}
