#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int n, m, nr[30], sol, fact[100100], L, R;
char s[100100];
struct Treap
{
	int sum, rotire;
	Treap *L, *R;
	Treap()
	{
		sum = 0;
		rotire = 0;
		L = R = NULL;
	}
};
Treap *T[10];

inline int LgPut(int baz, int put)
{
	int rez = 1;
	while(put)
	{
		if(put % 2 == 1)
		{
			rez = (1LL * rez * baz) % MOD;
			put--;
		}
		baz = (1LL * baz * baz) % MOD;
		put /= 2;
	}
	return rez;
}

inline void Build(Treap *nod, int st, int dr, char c)
{
	if(st == dr)
	{
		if(s[st] == c)
			nod->sum = 1;
		else
			nod->sum = 0;
		return;
	}
	int mij = (st + dr) / 2;
	if(nod->L == NULL)
		nod->L = new Treap();
	Build(nod->L, st, mij, c);
	if(nod->R == NULL)
		nod->R = new Treap();
	Build(nod->R, mij + 1, dr, c);
	nod->sum = nod->L->sum + nod->R->sum;
}

inline int Query(Treap *nod, int st, int dr)
{
	if(L <= st && dr <= R)
		return nod->sum;
	int mij = (st + dr) / 2, rez = 0;
	Treap *aux = new Treap();
	if(nod->rotire)
	{
		aux = nod->L;
		nod->L = nod->R;
		nod->R = aux;
		nod->rotire = 0;
		nod->L->rotire = 1 - nod->L->rotire;
		nod->R->rotire = 1 - nod->R->rotire;
	}
	if(L <= mij)
		rez += Query(nod->L, st, mij);
	if(mij + 1 <= R)
		rez += Query(nod->R, mij + 1, dr);
	return rez;
}

inline void Rotate(Treap *nod, int st, int dr)
{
	if(st == dr)
		return;
	Treap *aux = new Treap();
	if(nod->rotire)
	{
		aux = nod->L;
		nod->L = nod->R;
		nod->R = aux;
		nod->rotire = 0;
		nod->L->rotire = 1 - nod->L->rotire;
		nod->R->rotire = 1 - nod->R->rotire;
	}
	if(L <= st && dr <= R)
	{
		if(!nod->rotire)
		{
			aux = nod->L;
			nod->L = nod->R;
			nod->R = aux;
		}
		nod->rotire = 0;
		nod->L->rotire = 1 - nod->L->rotire;
		nod->R->rotire = 1 - nod->R->rotire;
		return;
	}
	int mij = (st + dr) / 2;
	if(L <= mij)
		Rotate(nod->L, st, mij);
	if(mij + 1 <= R)
		Rotate(nod->R, mij + 1, dr);
}

int main()
{
	int i, j, op, impar;
	cin >> n >> m;
	cin >> (s + 1);
	fact[0] = 1;
	for(i = 1; i <= n; ++i)
		fact[i] = (1LL * fact[i - 1] * i) %MOD;
	if(n <= 40000 && m <= 40000)
	{
		while(m--)
		{
			cin >> op >> L >> R;
			if(op == 1)
			{
				for(i = L, j = R; i <= j; ++i, --j)
					swap(s[i], s[j]);
			}
			else
			{
				for(i = L; i <= R; ++i)
					nr[s[i] - 'a']++;
				impar = -1;
				sol = 1;
				for(i = 0; i < 10; ++i)
				{
					if(nr[i] % 2 == 1)
					{
						if(impar < 0)
							impar = i;
						else
							sol = 0;
					}
				}
				if(!sol)
					cout << sol << "\n";
				else
				{
					sol = fact[(R - L + 1) / 2];
					for(i = 0; i < 10; ++i)
						if(nr[i])
							sol = (1LL * sol * LgPut(fact[nr[i] / 2], MOD - 2)) % MOD;
					cout << sol << "\n";
				}
				for(i = L; i <= R; ++i)
					nr[s[i] - 'a']--;
			}
		}
	}
	else
	{
		for(i = 0; i < 10; ++i)
		{
			T[i] = new Treap();
			Build(T[i], 1, n, 'a' + i);
		}
		while(m--)
		{
			cin >> op >> L >> R;
			if(op == 1)
			{
				for(i = 0; i < 10; ++i)
					Rotate(T[i], 1, n);
			}
			else
			{
				for(i = 0; i < 10; ++i)
					nr[i] = Query(T[i], 1, n);
				impar = -1;
				sol = 1;
				for(i = 0; i < 10; ++i)
				{
					if(nr[i] % 2 == 1)
					{
						if(impar < 0)
							impar = i;
						else
							sol = 0;
					}
				}
				if(!sol)
					cout << sol << "\n";
				else
				{
					sol = fact[(R - L + 1) / 2];
					for(i = 0; i < 10; ++i)
						if(nr[i])
							sol = (1LL * sol * LgPut(fact[nr[i] / 2], MOD - 2)) % MOD;
					cout << sol << "\n";
				}
			}
		}
	}
	return 0;
}
