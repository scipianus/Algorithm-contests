#include <iostream>
#include <cstring>
using namespace std;
int T, n, m, maxim = -1;
string s, cuv[110], sol;
bool qmark[110];

inline void Verif()
{
	int i, rez = 0;
	for(i = 1; i <= m; ++i)
	{
		size_t poz = s.find(cuv[i], 0);
		while( poz != string::npos)
		{
			rez++;
			poz = s.find(cuv[i], poz + 1);
		}
	}
	if(rez > maxim)
	{
		maxim = rez;
		sol = s;
	}
	else
		if(rez == maxim && s.compare(sol) < 0)
			sol = s;
}

inline void Back(int pas)
{
	if(pas == n)
		Verif();
	else
	{
		if(!qmark[pas])
			Back(pas + 1);
		else
		{
			s[pas] = 'a';
			Back(pas + 1);
			s[pas] = 'b';
			Back(pas + 1);
			s[pas] = 'c';
			Back(pas + 1);
		}
	}
}

int main()
{
	int i;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		cin >> s;
		for(i = 0; i < n; ++i)
		{
			if(s[i] == '?')
				qmark[i] = true;
			else
				qmark[i] = false;
		}
		for(i = 1; i <= m; ++i)
			cin >> cuv[i];
		maxim = -1;
		Back(0);
		cout << maxim << "\n" << sol << "\n";
	}
	return 0;
}
