#include <iostream>
#include <vector>
using namespace std;
int T, n, grumpy[110];
vector <int> haters, lovers;
// haters = grumpy-haters + grumpy-neutrals (cel putin un grumpy-hater)
// lovers = grumpy-lovers + grumpy-neutrals (cel putin un grumpy-lover)
// grumpy[i] = 1 pentru grumpy-lovers
// grumpy[i] = 2 pentru grumpy-haters
// grumpy[i] = 3 pentru grumpy-neutrals

int main()
{
	int i, rez;
	vector <int>::iterator it, jt;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(i = 1; i <= n; ++i)
		{
			cout << "1\n";
			cout << i << "\n";
			cout.flush();
			cin >> rez;
			if(rez == 0)
				haters.push_back(i);
			else
				lovers.push_back(i);
		}
		for(it = haters.begin(); it != haters.end(); ++it)
		{
			cout << (1 + lovers.size()) << "\n";
			cout << *it << ' ';
			for(jt = lovers.begin(); jt != lovers.end(); ++jt)
				cout << *jt << ' ';
			cout << "\n";
			cout.flush();
			cin >> rez;
			if(rez == lovers.size() + 1)
				grumpy[*it] = 3; // neutral
			else
				grumpy[*it] = 2; // hater
		}
		for(it = lovers.begin(); it != lovers.end(); ++it)
		{
			cout << (1 + haters.size()) << "\n";
			cout << *it << ' ';
			for(jt = haters.begin(); jt != haters.end(); ++jt)
				cout << *jt << ' ';
			cout << "\n";
			cout.flush();
			cin >> rez;
			if(rez == 0)
				grumpy[*it] = 3; // neutral
			else
				grumpy[*it] = 1; // lover
		}
		cout << "-1\n";
		for(i = 1; i <= n; ++i)
			cout << grumpy[i] << ' ';
		cout << "\n";
		cout.flush();
		haters.clear();
		lovers.clear();
	}
	return 0;
}
