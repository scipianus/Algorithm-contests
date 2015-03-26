#include <iostream>
#include <vector>
using namespace std;
int n, v[500500];
bool interzis[1000100];
vector <int> sol;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i;
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> v[i];
		interzis[v[i]] = true;
	}
	for(i = 1; i <= n; ++i)
	{
		if(!interzis[1000001 - v[i]])
		{
			interzis[1000001 - v[i]] = true;
			sol.push_back(1000001 - v[i]);
			swap(v[i], v[n]);
			n--;
			i--;
		}
	}
	i = 1;
	while(n > 0)
	{
		if(!interzis[i] && !interzis[1000001 - i])
		{
			interzis[i] = true;
			interzis[1000001 - i] = true;
			sol.push_back(i);
			sol.push_back(1000001 - i);
			n -= 2;
		}
		i++;
	}
	cout << sol.size() << "\n";
	for(i = 0; i < sol.size(); ++i)
		cout << sol[i] << ' ';
	cout << "\n";
	return 0;
}
