#include <iostream>
using namespace std;
int n, m, nr[10][100100], B1, B2;
char s[100100];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, c, poz;
	cin >> n >> m;
	cin >> (s + 1);
	for(i = 1; i <= n; ++i)
	{
		for(c = 0; c < 10; ++c)
			nr[c][i] = nr[c][i - 1];
		nr[s[i] - '0'][i]++;
	}
	while(m--)
	{
		cin >> poz;
		c = s[poz] - '0';
		B1 = B2 = 0;
		for(i = 0; i < c; ++i)
			B1 += nr[i][poz] * (c - i);
		for(i = c + 1; i < 10; ++i)
			B2 += nr[i][poz] * (c - i);
		cout << (B1 - B2) << "\n";
	}
	return 0;
}
