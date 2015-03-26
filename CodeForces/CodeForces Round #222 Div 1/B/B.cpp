#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
long long S;
struct Task
{
	int a, ind;
	bool operator <(const Task &X) const
	{
		return a > X.a;
	}
};
Task op[100100];
struct Student
{
	int b, c, ind;
	bool operator <(const Student &X) const
	{
		if(b == X.b)
			return c < X.c;
		return b > X.b;
	}
};
Student elev[100100];
int ord[100100], afis[100100];
vector <int> H;

inline bool Sortare(int x, int y)
{
	return elev[x].c > elev[y].c;
}

inline bool Posibil(int nrzile)
{
	long long now = 0LL;
	int i, j, k, sz = 0, nr;
	H.clear();
	i = 1;
	j = 1;
	while(i <= m && now <= S)
	{
		while(j <= n && elev[j].b >= op[i].a)
		{
			H.push_back(j);
			push_heap(H.begin(), H.end(), Sortare);
			sz++;
			j++;
		}
		if(sz > 0)
		{
			sz--;
			k = H[0];
			pop_heap(H.begin(), H.end(), Sortare);
			H.pop_back();
			now += 1LL * elev[k].c;
			if(now > S)
				return false;
			nr = nrzile;
			while(i <= m && nr > 0)
			{
				ord[op[i].ind] = elev[k].ind;
				i++;
				nr--;
			}
		}
		else
			return false;
	}
	if(i == m + 1 && now <= S)
	{
		for(j = 1; j <= m; ++j)
			afis[j] = ord[j];
		return true;
	}
	return false;
}

inline bool CautareBinara()
{
	int st, dr, mij;
	bool ok = false;
	st = 1;
	dr = m;
	while(st <= dr)
	{
		mij = (st + dr) / 2;
		if(Posibil(mij))
		{
			ok = true;
			dr = mij - 1;
		}
		else
			st = mij + 1;
	}
	return ok;
}

int main()
{
	int i;
	bool solutie;
	cin >> n >> m >> S;
	for(i = 1; i <= m; ++i)
	{
		cin >> op[i].a;
		op[i].ind = i;
	}
	for(i = 1; i <= n; ++i)
		cin >> elev[i].b;
	for(i = 1; i <= n; ++i)
	{
		cin >> elev[i].c;
		elev[i].ind = i;
	}
	sort(op + 1, op + m + 1);
	sort(elev + 1, elev + n + 1);
	
	solutie = CautareBinara();
	if(!solutie)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for(i = 1; i <= m; ++i)
			cout << afis[i] << ' ';
		cout << "\n";
	}
	return 0;
}
