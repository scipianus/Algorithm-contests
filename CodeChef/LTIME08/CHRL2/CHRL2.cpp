#include <iostream>
#include <cstring>
using namespace std;
int ns, sol, nr[3];
char s[100100];

int main()
{
	int i;
	cin >> (s + 1);
	ns = strlen(s + 1);
	for(i = 1; i <= ns; ++i)
	{
		if(s[i] == 'C')
			nr[0]++;
		if(s[i] == 'H')
		{
			if(nr[0] > nr[1])
				nr[1]++;
		}
		if(s[i] == 'E')
		{
			if(nr[0] >= nr[1] && nr[1] > nr[2])
				nr[2]++;
		}
		if(s[i] == 'F')
		{
			if(nr[0] >= nr[1] && nr[1] >= nr[2] && nr[2] > 0)
			{
				nr[0]--;
				nr[1]--;
				nr[2]--;
				sol++;
			}
		}
	}
	cout << sol << "\n";
	return 0;
}
