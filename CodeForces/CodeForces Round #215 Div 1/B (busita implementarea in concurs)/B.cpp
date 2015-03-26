#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, P, A[200100], B[200100], fr[2][200100], aux[200100], total, sol;
bool viz[200100], bun[200100];

int main()
{
	int i, j, last;
	cin >> n >> m >> P;
	for(i = 1; i <= n; ++i)
		cin >> A[i];
	for(i = 1; i <= m; ++i)
	{
		cin >> B[i];
		aux[i] = B[i];
	}
	sort(B + 1, B + m + 1);
	sort(aux + 1, aux + m + 1);
	for(i = 1; i <= m; ++i)
	{
		B[i] = lower_bound(aux + 1, aux + m + 1, B[i]) - aux;
		fr[1][B[i]]++;
	}
	for(i = 1; i <= n; ++i)
	{
		j = lower_bound(aux + 1, aux + m + 1, A[i]) - aux;
		if(aux[j] == A[i])
			A[i] = j;
		else
			A[i] = 0;
	}
	
	for(i = 1; 1LL * i + 1LL * (m - 1) * P <= 1LL * n && !viz[i]; ++i)
	{
		total = 0;
		last = i;
		for(j = 0; j < m; ++j)
		{
			viz[i + j * P] = true;
			fr[0][A[i + j * P]]++;
			if(fr[0][A[i + j * P]] <= fr[1][A[i + j * P]])
				total++;
		}
		if(total == m)
			bun[i] = true;
		while(i + j * P <= n)
		{
			fr[0][A[last]]--;
			if(fr[0][A[last]] < fr[1][A[last]])
				total--;
			last += P;
			viz[i + j * P] = true;
			fr[0][A[i + j * P]]++;
			if(fr[0][A[i + j * P]] <= fr[1][A[i + j * P]])
				total++;
			if(total == m)
				bun[last] = true;
			j++;
		}
		for(j = 0; i + j * P <= n; ++j)
			fr[0][A[i + j * P]] = 0;
	}
	for(i = 1; i <= n; ++i)
		if(bun[i])
			sol++;
	
	cout << sol << "\n";
	for(i = 1; i <= n; ++i)
		if(bun[i])
			cout << i << ' ';
	cout << "\n";
	return 0;
}
