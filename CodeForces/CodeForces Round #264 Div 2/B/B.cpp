#include <iostream>
using namespace std;
int n, h[100100];
long long sol;

inline bool Posibil(long long S)
{
	int i;
	long long now;
	i = 0;
	now = 0LL;
	while(i < n)
	{
		now += 1LL * (h[i] - h[i + 1]);
		if(now < 0LL)
		{
			S += now;
			now = 0LL;
			if(S < 0LL)
				return false;
		}
		i++;
	}
	return true;
}

inline void CautareBinara()
{
	long long st, dr, mij;
	st = 0;
	dr = sol;
	while(st <= dr)
	{
		mij = (st + dr) / 2LL;
		if(Posibil(mij))
		{
			sol = mij;
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
}

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> h[i];
		sol += 1LL * h[i];
	}
	CautareBinara();
	cout << sol << "\n";
	return 0;
}
