#include <iostream>
#include <algorithm>
#include <map>
#define pii pair<int, int>
using namespace std;
int n, P, A[300100], B[300100], nr[300100], nrminus[300100], aib[300100];
map <pii, int> nrp;
map <pii, bool> ales, viz;
long long sol;

inline void Update(int poz, int val)
{
	while(poz > 0)
	{
		aib[poz] += val;
		poz -= (poz & -poz);
	}
}

inline int Query(int poz)
{
	int rez = 0;
	while(poz <= n)
	{
		rez += aib[poz];
		poz += (poz & -poz);
	}
	return rez;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, now;
	cin >> n >> P;
	for(i = 1; i <= n; ++i)
	{
		cin >> A[i] >> B[i];
		if(A[i] > B[i])
			swap(A[i], B[i]);
		nr[A[i]]++;
		nr[B[i]]++;
		nrp[make_pair(A[i], B[i])]++;
	}
	for(i = 1; i <= n; ++i)
	{
		if(!ales[make_pair(A[i], B[i])])
		{
			now = nr[A[i]] + nr[B[i]] - nrp[make_pair(A[i], B[i])];
			if(now >= P)
			{
				sol++;
				ales[make_pair(A[i], B[i])] = true;
			}
		}
		if(!viz[make_pair(A[i], B[i])])
		{
			now = nr[A[i]] + nr[B[i]];
			if(now >= P)
			{
				nrminus[A[i]]++;
				viz[make_pair(A[i], B[i])] = true;
			}
		}
	}
	for(i = 1; i <= n; ++i)
		Update(nr[i], 1);
	for(i = 1; i <= n; ++i)
	{
		Update(nr[i], -1);
		if(nr[i] >= P)
			sol += 1LL * (n - i - nrminus[i]);
		else
			sol += 1LL * Query(P - nr[i]) - 1LL * nrminus[i];
	}
	cout << sol << "\n";
	return 0;
}
