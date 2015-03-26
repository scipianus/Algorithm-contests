#include <iostream>
#include <cstring>
using namespace std;
string s, St[100100];
int vf;

int main()
{
	int i, j, lim;
	bool gasit;
	string afisat;
	cin >> s;
	St[++vf] = s;
	cout << s << "\n";
	while(cin >> s)
	{
		if(s.size() == 0 || !('a' <= s[0] && s[0] <= 'z'))
			break;
		gasit = false;
		while(vf && !gasit)
		{
			lim = min(s.size(), St[vf].size());
			for(i = 0; i < lim; ++i)
				if(s[i] != St[vf][i])
					break;
			if(i >= vf)
			{
				afisat.clear();
				for(j = 0; j < vf; ++j)
					afisat += " ";
				afisat += s;
				cout << afisat << "\n";
				St[++vf] = s;
				gasit = true;
			}
			else
				vf--;
		}
		if(!gasit)
		{
			St[++vf] = s;
			cout << s << "\n";
		}
	}
	return 0;
}
