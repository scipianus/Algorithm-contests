#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define pii pair<int, int>
using namespace std;
int n, Q, X[200100], Y[200100], ultim[200100], A[800100], B[800100], costnext[200100];
int cost[19][200100], stramos[19][200100], sol;

inline void Actualizeaza(int nod, int st, int dr, int poz)
{
	if(st == dr)
	{
		A[nod] = max(A[nod], ultim[poz]);
		return;
	}
	int mij = (st + dr) / 2;
	if(poz <= mij)
		Actualizeaza(2 * nod, st, mij, poz);
	else
		Actualizeaza(2 * nod + 1, mij + 1, dr, poz);
	A[nod] = max(A[2 * nod], A[2 * nod + 1]);
}

inline int Maxim(int nod, int st, int dr, int L, int R)
{
	if(L <= st && dr <= R)
		return A[nod];
	int mij = (st + dr) / 2, rez = 0;
	if(L <= mij)
		rez = max(rez, Maxim(2 * nod, st, mij, L, R));
	if(mij + 1 <= R)
		rez = max(rez, Maxim(2 * nod + 1, mij + 1, dr, L, R));
	return rez;
}

inline void Build(int nod, int st, int dr)
{
	if(st == dr)
	{
		B[nod] = X[st] + Y[st];
		return;
	}
	int mij = (st + dr) / 2;
	Build(2 * nod, st, mij);
	Build(2 * nod + 1, mij + 1, dr);
	B[nod] = max(B[2 * nod], B[2 * nod + 1]);
}

inline int Query(int nod, int st, int dr, int L, int R)
{
	if(L <= st && dr <= R)
		return B[nod];
	int mij = (st + dr) / 2, rez = 0;
	if(L <= mij)
		rez = max(rez, Query(2 * nod, st, mij, L, R));
	if(mij + 1 <= R)
		rez = max(rez, Query(2 * nod + 1, mij + 1, dr, L, R));
	return rez;
}

int main()
{
	int i, j, k, start, final, maxim, best, total, x;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> X[i] >> Y[i];
	X[n + 1] = 2000000000;
	for(i = n; i > 0; --i)
	{
		j = upper_bound(X + i, X + n + 1, X[i] + Y[i]) - X - 1;
		ultim[i] = Maxim(1, 1, n, i, j);
		if(ultim[i] < i)
			ultim[i] = i;
		Actualizeaza(1, 1, n, i);
	}
	memset(A, 0, sizeof(A));
	Build(1, 1, n);
	for(i = 1; i <= n; ++i)
	{
		if(ultim[i] == n)
			continue;
		maxim = Query(1, 1, n, i, ultim[i]);
		costnext[i] = X[ultim[i] + 1] - maxim;
	}
	for(i = 1; i <= n; ++i)
	{
		stramos[0][i] = ultim[i];
		cost[0][i] = 0;
		if(ultim[i] == n)
		{
			stramos[1][i] = n;
			cost[1][i] = 0;
		}
		else
		{
			stramos[1][i] = ultim[ultim[i] + 1];
			cost[1][i] = costnext[i];
		}
	}
	for(k = 2; k < 19; ++k)
	{
		for(i = 1; i <= n; ++i)
		{
			if(stramos[k - 1][i] == n)
			{
				stramos[k][i] = n;
				cost[k][i] = cost[k - 1][i];
			}
			else
			{
				stramos[k][i] = stramos[k - 1][stramos[k - 1][i] + 1];
				maxim = Query(1, 1, n, i, stramos[k - 1][i]);
				cost[k][i] = cost[k - 1][i] + cost[k - 1][stramos[k - 1][i] + 1] + X[stramos[k - 1][i] + 1] - maxim; 
				j = k - 2;
				x = i;
				while(j >= 0)
				{
					total += cost[j][x];
					x = stramos[j][x] + 1;
					maxim = Query(1, 1, n, x, stramos[k - 1][i]);
					best = total + cost[j][x] + cost[k - 1][stramos[k - 1][i] + 1] + X[stramos[k - 1][i] + 1] - maxim; 
					cost[k][i] = min(cost[k][i], best);
					j--;
				}
			}
		}
	}
	cin >> Q;
	while(Q--)
	{
		cin >> start >> final;
		if(ultim[start] >= final)
			sol = 0;
		else
		{
			k = 18;
			while(k >= 0 && stramos[k][start] >= final)
				k--;
			k++;
			sol = cost[k][start];
		}
		cout << sol << "\n";
	}
	return 0;
}
