#include <iostream>
#include <cstring>
using namespace std;
int ns, m, sol[100100], vf, necesar, maxim[100100];
bool gresit;
char s[100100];

int main()
{
	int i, aux;
	std::ios_base::sync_with_stdio(false);
	cin >> (s + 1);
	ns = strlen(s + 1);
	for(i = 1; i <= ns; ++i)
	{
		if(s[i] == '(')
			vf++;
		else
		{
			vf--;
			if(vf < 0)
				gresit = true;
			if(s[i] == '#')
			{
				m++;
				maxim[i] = vf;
			}
		}
	}
	if(gresit)
	{
		cout << "-1\n";
		return 0;
	}
	aux = m;
	necesar = vf;
	for(i = ns; i > 0; --i)
	{
		if(s[i] == '#')
		{
			sol[aux] = 1 + min(necesar, maxim[i]);
			necesar = necesar - sol[aux] + 1;
			aux--;
		}
	}
	if(necesar > 0)
	{
		cout << "-1\n";
		return 0;
	}
	for(i = 1; i <= m; ++i)
		cout << sol[i] << "\n";
	return 0;
}
