#include <iostream>
#include <cstdlib>
using namespace std;
int X1, Y1, X2, Y2;

int main()
{
	int L;
	cin >> X1 >> Y1 >> X2 >> Y2;
	if(X1 != X2)
	{
		if(Y1 == Y2)
		{
			L = abs(X2 - X1);
			cout << X1 << ' ' << (Y1 + L) << ' ' << X2 << ' ' << (Y2 + L) << "\n";
		}
		else
		{
			if(abs(X1 - X2) == abs(Y1 - Y2))
				cout << X1 << ' ' << Y2 << ' ' << X2 << ' ' << Y1 << "\n";
			else
				cout << "-1\n";
		}
	}
	else
	{
		L = abs(Y1 - Y2);
		cout << (X1 + L) << ' ' << Y1 << ' ' << (X2 + L) << ' ' << Y2 << "\n";
	}
	return 0;
}
