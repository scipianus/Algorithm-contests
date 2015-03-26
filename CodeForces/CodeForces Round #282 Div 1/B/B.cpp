#include <iostream>
#include <cstring>
#include <vector>
#define MOD 1000000007
using namespace std;
char A[100100], B[100100];
int na, nb, pi[100100], sol;
vector <int> match;
int nr[100100], sum[100100], sumsum[100100];

int main()
{
	int i, k;
	std::ios_base::sync_with_stdio(false);
	cin >> (A + 1);
	cin >> (B + 1);
	na = strlen(A + 1);
	nb = strlen(B + 1);
	
	pi[1] = 0;
	k = 0;
	for(i = 2; i <= nb; ++i)
	{
		while(k && B[k + 1] != B[i])
			k = pi[k];
		if(B[k + 1] == B[i])
			k++;
		pi[i] = k;
	}
	k = 0;
	for(i = 1; i <= na; ++i)
	{
		while(k && B[k + 1] != A[i])
			k = pi[k];
		if(B[k + 1] == A[i])
			k++;
		if(k == nb)
		{
			match.push_back(i - nb + 1);
			k = pi[k];
		}
	}
	
	if(match.size() == 0)
	{
		cout << "0\n";
		return 0;
	}
	k = -1;
	for(i = 1; i <= na; ++i)
	{
		if(k + 1 < match.size() && match[k + 1] + nb - 1 <= i)
			k++;
		if(k >= 0)
			nr[i] = sumsum[match[k] - 1] + match[k];
		if(nr[i] >= MOD)
			nr[i] -= MOD;
		sum[i] = sum[i - 1] + nr[i];
		if(sum[i] >= MOD)
			sum[i] -= MOD;
		sumsum[i] = sumsum[i - 1] + sum[i];
		if(sumsum[i] >= MOD)
			sumsum[i] -= MOD;
	}
	sol = sum[na];
	cout << sol << "\n";
	return 0;
}
