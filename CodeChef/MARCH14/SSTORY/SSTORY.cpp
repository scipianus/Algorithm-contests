#include <iostream>
#include <cstring>
#include <vector>
#define MOD 123457
#define H 19
using namespace std;
int n1, n2, lgsol, poz;
char S1[250100], S2[250100];
vector <int> Hash[MOD];

inline bool Valid(int i, int j, int lg)
{
	int k;
	for(k = 0; k < lg; ++k)
		if(S1[i + k] != S2[j + k])
			return false;
	return true;
}

inline bool Found(int conf, int i, int lg)
{
	vector <int>::iterator it;
	for(it = Hash[conf].begin(); it != Hash[conf].end(); ++it)
		if(Valid(*it, i, lg))
			return true;
	return false;
}

inline bool Gasit(int lg)
{
	int i, conf = 0, p = 1;
	for(i = 0; i < MOD; ++i)
		Hash[i].clear();
	for(i = 1; i <= lg; ++i)
	{
		conf = (1LL * conf * H + S1[i]) % MOD;
		if(i < lg)
			p = (1LL * p * H) % MOD;
	}
	Hash[conf].push_back(1);
	for(i = lg + 1; i <= n1; ++i)
	{
		conf = conf - (1LL * p * S1[i - lg]) % MOD + MOD;
		conf = (1LL * conf * H + S1[i]) % MOD;
		Hash[conf].push_back(i - lg + 1);
	}
	conf = 0;
	for(i = 1; i <= lg; ++i)
		conf = (1LL * conf * H + S2[i]) % MOD;
	if(Found(conf, 1, lg))
	{
		poz = 1;
		return true;
	}
	for(i = lg + 1; i <= n2; ++i)
	{
		conf = conf - (1LL * p * S2[i - lg]) % MOD + MOD;
		conf = (1LL * conf * H + S2[i]) % MOD;
		if(Found(conf, i - lg + 1, lg))
		{
			poz = i - lg + 1;
			return true;
		}
	}
	return false;
}

inline void CautareBinara()
{
	int st, dr, mij;
	st = 1;
	dr = n2;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		if(Gasit(mij))
		{
			lgsol = mij;
			st = mij + 1;
		}
		else
			dr = mij - 1;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	
	cin >> (S1 + 1); n1 = strlen(S1 + 1);
	cin >> (S2 + 1); n2 = strlen(S2 + 1);
	
	CautareBinara();
	
	if(lgsol == 0)
		cout << "0\n";
	else
	{
		for(int i = poz; i < poz + lgsol; ++i)
			cout << S2[i];
		cout << "\n";
		cout << lgsol << "\n";
	}
	return 0;
}
