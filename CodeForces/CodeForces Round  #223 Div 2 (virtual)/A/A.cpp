#include <iostream>
using namespace std;
int n, v[1010], scor[2];

int main()
{
	int i, st, dr, move = 0;
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	st = 1; 
	dr = n;
	while(st <= dr)
	{
		if(v[st] < v[dr])
		{
			scor[move] += v[dr];
			dr--;
		}
		else
		{
			scor[move] += v[st];
			st++;
		}
		move = 1 - move;
	}
	cout << scor[0] << ' ' << scor[1] << "\n";
	return 0;
}
