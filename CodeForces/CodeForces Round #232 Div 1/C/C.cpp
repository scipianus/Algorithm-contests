#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int n, m, tata[300100], st[300100], dr[300100], vf, adancime[300100];
vector <int> G[300100];
bool viz[300100];
int aib[3][600100];
// aib[0] tine suma de X
// aib[1] tine suma de K
// aib[2] tine sume de K * adancime

inline void DFS(int x, int level)
{
	adancime[x] = level;
    st[x] = ++vf;
    viz[x] = true;
    vector <int>::iterator it;
    for(it = G[x].begin(); it != G[x].end(); it++)
        if(!viz[*it])
            DFS(*it, level + 1);
    dr[x] = ++vf;
}

inline void Aduna(int poz, int val, int ind)
{
	if(val < 0)
		val += MOD;
	while(poz <= 2 * n)
	{
		aib[ind][poz] += val;
		if(aib[ind][poz] >= MOD)
			aib[ind][poz] -= MOD;
		poz += (poz & -poz);
	}
}

inline int Query(int poz, int ind)
{
	int rez = 0;
	while(poz > 0)
	{
		rez += aib[ind][poz];
		if(rez >= MOD)
			rez -= MOD;
		poz -= (poz & -poz);
	}
	return rez;
}

int main()
{
	int i, op, nod, X, K, levelK;
	cin >> n;
	for(i = 2; i <= n; ++i)
	{
		cin >> tata[i];
		G[tata[i]].push_back(i);
	}
	DFS(1, 0);
	cin >> m;
	while(m--)
	{
		cin >> op;
		if(op == 1)
		{
			cin >> nod >> X >> K;
			Aduna(st[nod], X, 0);
			Aduna(dr[nod], -X, 0);
			Aduna(st[nod], K, 1);
			Aduna(dr[nod], -K, 1);
			Aduna(st[nod], (1LL * adancime[nod] * K) % MOD, 2);
			Aduna(dr[nod], -((1LL * adancime[nod] * K) % MOD), 2);
		}
		else
		{
			cin >> nod;
			X = Query(st[nod], 0);
			K = Query(st[nod], 1);
			levelK = (1LL * K * adancime[nod]) % MOD - Query(st[nod], 2) + MOD;
			levelK %= MOD;
			X = X - levelK + MOD;
			X %= MOD;
			cout << X << "\n";
		}
	}
	return 0;
}
