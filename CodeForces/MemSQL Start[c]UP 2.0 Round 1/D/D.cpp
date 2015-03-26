#include <iostream>
#include <set>
using namespace std;
int K[4], n1, n2, n3, t1, t2, t3, sol, n;
multiset <int> S[3];

int main()
{
	multiset <int>::iterator it;
	cin >> K[0] >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	n = K[0];
	sol = 0;
	while(1)
	{
		if(!S[0].empty())
		{
			it = S[0].begin();
			while(*it == sol)
			{
				S[0].erase(it);
				K[1]++;
				if(S[0].empty())
					break;
				it = S[0].begin();
			}
		}
		while(S[0].size() < n1 && K[0])
		{
			K[0]--;
			S[0].insert(sol + t1);
		}
		if(!S[1].empty())
		{
			it = S[1].begin();
			while(*it == sol)
			{
				S[1].erase(it);
				K[2]++;
				if(S[1].empty())
					break;
				it = S[1].begin();
			}
		}
		while(S[1].size() < n2 && K[1])
		{
			K[1]--;
			S[1].insert(sol + t2);
		}
		if(!S[2].empty())
		{
			it = S[2].begin();
			while(*it == sol)
			{
				S[2].erase(it);
				K[3]++;
				if(S[2].empty())
					break;
				it = S[2].begin();
			}
		}
		while(S[2].size() < n3 && K[2])
		{
			K[2]--;
			S[2].insert(sol + t3);
		}
		if(K[3] == n)
			break;
		sol++;
	}
	cout << sol << "\n";
	return 0;
}
