#include <iostream>
#include <cstring>
using namespace std;
int n, nr[10], r[100];
char A[1000100], rez[1000100];
bool gasit;

inline void Back(int k, int rest)
{
	if(gasit)
		return;
	if(k == n + 1)
	{
		if(rest == 0)
			gasit = true;
		return;
	}
	int i;
	if(k > 1 && nr[0])
	{
		nr[0]--;
		rez[k] = '0';
		Back(k + 1, r[rest * 10]);
		nr[0]++;
	}
	for(i = 1; i < 10 && !gasit; ++i)
	{
		if(nr[i])
		{
			nr[i]--;
			rez[k] = (char)(i + '0');
			Back(k + 1, r[rest * 10 + i]);
			nr[i]++;
		}
	}
}

int main()
{
	int i;
	for(i = 0; i < 100; ++i)
		r[i] = i % 7;
	cin >> (A + 1);
	n = strlen(A + 1);
	for(i = 1; i <= n; ++i)
		nr[A[i] - '0']++;
	Back(1, 0);
	if(gasit)
		cout << (rez + 1) << "\n";
	else
		cout << "0\n";
	return 0;
}
