#include <fstream>
#include <vector>
using namespace std;
int n, prime[40], nrp, sol, v[160];
bool ciur[160];
long long Desc[160];

inline void Back(int now, int pas, long long conf)
{
	if(now == n)
	{
		sol++;
		return;
	}
	int i, first;
	long long newconf;
	if(v[pas - 1]==1)
		first = 1;
	else
		first = v[pas - 1] + 1;
	for( i = first; i + now <= n; ++i)
	{
		if(conf & Desc[i])
			continue;
		v[pas] = i;
		newconf = (conf | Desc[i]);
		Back(now + i, pas + 1, newconf);
	}
}

int main()
{
	int i, j;
	ifstream fin("prime.in");
	fin >> n;
	fin.close();
	
	prime[++nrp] = 2;
	for( i = 3; i <= n; i += 2)
	{
		if(!ciur[i])
		{
			prime[++nrp] = i;
			for( j = i * i; j <= n; j += 2 * i)
				ciur[j]=true;
		}
	}
	for( i = 1; i <= n; ++i)
		for( j = 1; j <= nrp; ++j)
			if(i % prime[j] == 0)
				Desc[i]|=(1LL << (1LL * (j-1)));
	Back(0,1,0);
	
	ofstream fout("prime.out");
	fout << sol << "\n";
	fout.close();
	return 0;
}
