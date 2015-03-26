#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int T, ns;
string s, animal;
map <string, bool> notfox;

int main()
{
	int i;
	string cuv;
	cin >> T;
	cin.get();
	while(T--)
	{
		getline(cin, s);
		ns = s.size();
		getline(cin, animal);
		while(!(animal[0] == 'w' && animal[1] == 'h' && animal[2] == 'a' && animal[3] == 't'))
		{
			cuv.clear();
			i = 0;
			while(animal[i] != ' ')
				i++;
			i++;
			while(animal[i] != ' ')
				i++;
			i++;
			while(i < animal.size())
			{
				cuv += animal[i];
				i++;
			}
			notfox[cuv] = true;
			getline(cin, animal);
		}
		i = 0;
		while(i < ns)
		{
			cuv.clear();
			while(i <ns && s[i] != ' ')
			{
				cuv += s[i];
				i++;
			}
			i++;
			if(!notfox.count(cuv))
				cout << cuv << ' ';
		}
		cout << "\n";
		notfox.clear();
	}
	return 0;
}
