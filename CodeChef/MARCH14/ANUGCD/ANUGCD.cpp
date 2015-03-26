#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, v[100100], G, L, R, sol, nrsol, fsol;
struct Nod
{
	vector <int> f, best, nr;
};
Nod A[400100];
int prime[50100], nrp;
bool ciur[100100];

inline void Build(int nod, int st, int dr)
{
	if(st == dr)
	{
		int x = v[st], k = 1;
		while(prime[k] * prime[k] <= x)
		{
			if(x % prime[k] == 0)
			{
				A[nod].f.push_back(prime[k]);
				A[nod].best.push_back(v[st]);
				A[nod].nr.push_back(1);
				while(x % prime[k] == 0)
					x /= prime[k];
			}
			k++;
		}
		if(x > 1)
		{
			A[nod].f.push_back(x);
			A[nod].best.push_back(v[st]);
			A[nod].nr.push_back(1);
		}
		return;
	}
	int mij = (st + dr) / 2;
	Build(2 * nod, st, mij);
	Build(2 * nod + 1, mij + 1, dr);
	int i, j, n1, n2, nr;
	n1 = A[2 * nod].f.size();
	n2 = A[2 * nod + 1].f.size();
	i = j = 0;
	while(i < n1 && j < n2)
	{
		if(A[2 * nod].f[i] < A[2 * nod + 1].f[j])
		{
			A[nod].f.push_back(A[2 * nod].f[i]);
			A[nod].best.push_back(A[2 * nod].best[i]);
			A[nod].nr.push_back(A[2 * nod].nr[i]);
			i++;
		}
		else
		{
			if(A[2 * nod].f[i] > A[2 * nod + 1].f[j])
			{
				A[nod].f.push_back(A[2 * nod + 1].f[j]);
				A[nod].best.push_back(A[2 * nod + 1].best[j]);
				A[nod].nr.push_back(A[2 * nod + 1].nr[j]);
				j++;
			}
			else
			{
				A[nod].f.push_back(A[2 * nod].f[i]);
				if(A[2 * nod].best[i] > A[2 * nod + 1].best[j])
				{
					A[nod].best.push_back(A[2 * nod].best[i]);
					A[nod].nr.push_back(A[2 * nod].nr[i]);
				}
				else
				{
					if(A[2 * nod].best[i] < A[2 * nod + 1].best[j])
					{
						A[nod].best.push_back(A[2 * nod + 1].best[j]);
						A[nod].nr.push_back(A[2 * nod + 1].nr[j]);
					}
					else
					{
						A[nod].best.push_back(A[2 * nod].best[i]);
						nr = A[2 * nod].nr[i] + A[2 * nod + 1].nr[j];
						A[nod].nr.push_back(nr);
					}
				}
				i++;
				j++;
			}
		}
	}
	while(i < n1)
	{
		A[nod].f.push_back(A[2 * nod].f[i]);
		A[nod].best.push_back(A[2 * nod].best[i]);
		A[nod].nr.push_back(A[2 * nod].nr[i]);
		i++;
	}
	while(j < n2)
	{
		A[nod].f.push_back(A[2 * nod + 1].f[j]);
		A[nod].best.push_back(A[2 * nod + 1].best[j]);
		A[nod].nr.push_back(A[2 * nod + 1].nr[j]);
		j++;
	}
}

inline void Query(int nod, int st, int dr, int p)
{
	if(L <= st && dr <= R)
	{
		vector <int>::iterator it;
		it = lower_bound(A[nod].f.begin(), A[nod].f.end(), p);
		if(it == A[nod].f.end() || *it != p)
			return;
		int poz = it - A[nod].f.begin();
		if(sol < A[nod].best[poz])
		{
			sol = A[nod].best[poz];
			nrsol = A[nod].nr[poz];
			fsol = p;
		}
		else
			if(sol == A[nod].best[poz] && fsol == p)
				nrsol += A[nod].nr[poz];
		return;
	}
	int mij = (st + dr) / 2;
	if(L <= mij)
		Query(2 * nod, st, mij, p);
	if(mij + 1 <= R)
		Query(2 * nod + 1, mij + 1, dr, p);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j;
	prime[++nrp] = 2;
	for(i = 3; i < 100000; i += 2)
	{
		if(!ciur[i])
		{
			prime[++nrp] = i;
			if(i < 400)
			{
				for(j = i * i; j < 100000; j += 2 * i)
					ciur[j] = true;
			}
		}
	}
	prime[++nrp] = 400;
	cin >> n >> m;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	Build(1, 1, n);
	while(m--)
	{
		cin >> G >> L >> R;
		sol = -1;
		nrsol = -1;
		fsol = -1;
		i = 1;
		while(prime[i] * prime[i] <= G)
		{
			if(G % prime[i] == 0)
			{
				Query(1, 1, n, prime[i]);
				while(G % prime[i] == 0)
					G /= prime[i];
			}
			i++;
		}
		if(G > 1)
			Query(1, 1, n, G);
		cout << sol << ' ' << nrsol << "\n";
	}
	return 0;
}
