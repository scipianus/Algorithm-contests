#include <iostream>
#include <cstring>
#include <map>
#include <set>
using namespace std;
map <int, bool> blocked;
map <int, int> X;
map <int, set <int> > S;

int main()
{
	char op;
	int tr, itm;
	while(cin >> op)
	{
		if(op == '#')
			break;
		cin >> tr >> itm;
		if(blocked[tr] == true)
		{
			cout << "IGNORED\n";
			continue;
		}
		if(op == 'X')
		{
			if(X[itm] > 0 && X[itm] != tr)
			{
				cout << "DENIED\n";
				blocked[tr] = true;
				continue;
			}
			if(S[itm].size() == 0)
			{
				cout << "GRANTED\n";
				X[itm] = tr;
				continue;
			}
			if(S[itm].size() == 1 && *(S[itm].begin()) == tr)
			{
				//S[itm].erase(tr);
				X[itm] = tr;
				cout << "GRANTED\n";
				continue;
			}
			cout << "DENIED\n";
			blocked[tr] = true;
			continue;
		}
		if(X[itm] > 0)
		{
			if(X[itm] == tr)
			{
				//X[itm] = 0;
				S[itm].insert(tr);
				cout << "GRANTED\n";
				continue;
			}
			cout << "DENIED\n";
			blocked[tr] = true;
			continue;
		}
		S[itm].insert(tr);
		cout << "GRANTED\n";
	}
	return 0;
}
