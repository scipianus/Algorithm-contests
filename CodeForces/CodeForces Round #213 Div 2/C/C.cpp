#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;
int n, N, A, v[4010], sum[4010];
char s[4010];
long long sol;
int nr[40000];

int main()
{
	int i, j;
	//ifstream fin("C.in");
	cin >> A;
	cin >> (s + 1);
	//fin.close();
	n = strlen(s + 1);
	
	for(i = 1; i <= n; ++i)
	{
		v[i] = s[i] - '0';
		sum[i] = sum[i - 1] + v[i];
	}
	for(i = 1; i <= n; ++i)
		for(j = i; j <= n; ++j)
			nr[sum[j] - sum[i - 1]]++;
	if(A > 0)
	{
		for(i = 1; i * i <= A; ++i)
		{
			if(A % i == 0 && (A / i) <= n * 9)
			{
				if(i * i == A)
					sol += 1LL * nr[i] * (nr[i] - 1) + 1LL * nr[i];
				else
					sol += 2LL * nr[i] * nr[A / i];
			}
		}
	}
	else
	{
		sol = 1LL * nr[0] * nr[0];
		for(i = 1; i <= 9 * n; ++i)
			sol += 2LL * nr[i] * nr[0];
	}
		
	cout << sol << "\n";
	return 0;
}
