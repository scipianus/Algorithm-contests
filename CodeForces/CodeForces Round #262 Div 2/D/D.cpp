#include <iostream>
#include <cassert>
using namespace std;
long long L, R;
int n;

int main()
{
	cin >> L >> R >> n;
	assert(1LL * n <= R - L + 1LL);
	if(n == 1) // pot alege maxim un numar, deci il aleg pe cel mai mic
	{
		cout << L << "\n";
		cout << "1\n";
		cout << L << "\n";
		return 0;
	}
	// altfel pot alege cel putin doua numere
	if(R - L + 1LL == 2LL) // am fix doua numere, deci ori ambele ori cel mai mic
	{
		long long rez = (L ^ R);
		if(rez < L) // ambele
		{
			cout << rez << "\n";
			cout << "2\n";
			cout << L << ' ' << R << "\n";
		}
		else // cel mai mic
		{
			cout << L << "\n";
			cout << "1\n";
			cout << L << "\n";
		}
		return 0;
	}
	if(n >= 3 && R - L + 1LL <= 5000LL)
	{
		long long a, b, c;
		for(a = L; a <= R; ++a)
			for(b = a + 1LL; b <= R; ++b)
			{
				c = (a ^ b);
				if(a != c && c != b && L <= c && c <= R)
				{
					cout << "0\n";
					cout << "3\n";
					cout << a << ' ' << b << ' ' << c << "\n";
					return 0;
				}
			}
	}
	if(n >= 4) // daca pot alege par, impar, par, impar atunci am xor 0
	{
		if(L % 2LL == 0LL)
		{
			cout << "0\n";
			cout << "4\n";
			cout << L << ' ' << (L + 1LL) << ' ' << (L + 2LL) << ' ' << (L + 3LL) << "\n";
			return 0;
		}
		if(R - L + 1LL >= 5LL)
		{
			cout << "0\n";
			cout << "4\n";
			cout << (L + 1LL) << ' ' << (L + 2LL) << ' ' << (L + 3LL) << ' ' << (L + 4LL) << "\n";
			return 0;
		}
	}
	if(n >= 3) // daca pot face xor 0 cu 3 numere
	{
		long long put = 1LL;
		while(put < R)
		{
			if(L < put)
			{
				if(L + put <= R)
				{
					cout << "0\n";
					cout << "3\n";
					cout << L << ' ' << put << ' ' << (L + put) << "\n";
					return 0;
				}
				break;
			}
			put *= 2LL;
		}
	}
	// altfel nu pot face suma xor 0, deci o fac 1
	// avand de ales minim 2 numere din minim 3
	if(L % 2LL == 0LL)
	{
		cout << "1\n";
		cout << "2\n";
		cout << L << ' ' << (L + 1LL) << "\n";
	}
	else
	{
		cout << "1\n";
		cout << "2\n";
		cout << (L + 1LL) << ' ' << (L + 2LL) << "\n";
	}
	return 0;
}
